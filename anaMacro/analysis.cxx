#include "/star/u/syang/Macro/headers.h"
#include "constants.h"
#include "MINIEVENT.h"

void bookHistograms();
void writeHistograms(char* outFile);

Bool_t passEvent(MINIEVENT const* const event);
Bool_t passTrack(MINIEVENT const* const event, Int_t const& i);
void   makeRealPairs();

Double_t centrality, reWeight;

Int_t iran=0;

struct ParticleInfo
{
	Int_t   charge;
	Float_t pt;
	Float_t eta;
	Float_t phi;
};
vector<ParticleInfo> eInfo;

//********* define function and histograms *********
TH2D *hVertexYvsX;
TH2D *hVpdVzvsTpcVz;
TH2D *hVzDiffvsCentrality;
TH2D *hRefMultvsRefMultCorr;
TH1D *hCentrality;
TH1D *hBField;

//make pair
TH3D *hULMvsPtvsCen;
TH3D *hLPosMvsPtvsCen;
TH3D *hLNegMvsPtvsCen;

int main(int argc, char** argv)
{
	if(argc!=1&&argc!=3) return -1;

	TString inFile="test.list";
	char outFile[1024];
	sprintf(outFile,"test");
	if(argc==3){
		inFile = argv[1];
		sprintf(outFile,"%s",argv[2]);
	}

	//+---------------------------------+
	//| open files and add to the chain |
	//+---------------------------------+
	TChain *chain = new TChain("miniDst");

	Int_t ifile=0;
	char filename[512];
	ifstream *inputStream = new ifstream;
	inputStream->open(inFile.Data());
	if (!(inputStream)) {
		printf("can not open list file\n");
		return 0;
	}
	for(;inputStream->good();){
		inputStream->getline(filename,512);
		if(inputStream->good()) {
			TFile *ftmp = new TFile(filename);
			if(!ftmp||!(ftmp->IsOpen())||!(ftmp->GetNkeys())) {
				cout<<"something wrong"<<endl;
			} else {
				cout<<"read in "<<ifile<<"th file: "<<filename<<endl;
				chain->Add(filename);
				ifile++;
			}
			delete ftmp;
		}
	}
	delete inputStream;

	bookHistograms();

	//+-------------+
	//| loop events |
	//+-------------+
	MINIEVENT *event = new MINIEVENT(chain);
	Int_t nEvts = chain->GetEntries();
	cout<<nEvts<<" events"<<endl;
	for(int i=0; i<nEvts; i++){
		//cout<<"evt:"<<i<<endl;
		if(i%(nEvts/10)==0) cout << "begin " << i << "th entry...." << endl;
		event->GetEntry(i);

		if(!passEvent(event)) continue; 

		eInfo.clear();

		Int_t nTrks = event->mNTrks;
		for(Int_t j=0; j<nTrks; j++) passTrack(event, j);

		if(eInfo.size()==0) continue;

		makeRealPairs();
	}

	writeHistograms(outFile);
	delete chain;

	cout<<"end of program"<<endl;
	return 0;
}
//________________________________________________________________
Bool_t passEvent(MINIEVENT const* const event)
{
	Bool_t validTrig = kFALSE;
	Int_t mNTrigs = event->mNTrigs;
	for(Int_t i=0; i<mNTrigs; i++){
		if(600002 == event->mTrigId[i]) validTrig = kTRUE;
		if(600012 == event->mTrigId[i]) validTrig = kTRUE;
		if(600022 == event->mTrigId[i]) validTrig = kTRUE;
		if(600032 == event->mTrigId[i]) validTrig = kTRUE;
		if(600042 == event->mTrigId[i]) validTrig = kTRUE;
	}
	if(!validTrig) return kFALSE;

	Double_t vx = event->mVertexX;
	Double_t vy = event->mVertexY;
	Double_t vz = event->mVertexZ;
	Double_t vr = sqrt(vx*vx + vy*vy);
	Double_t vpdVz = event->mVpdVz;
	Double_t vzDiff = vz - vpdVz;
	Double_t refMult = event->mRefMult;
	Double_t refMultCorr = event->mRefMultCorr;    
	Double_t bField = event->mBField;

	//reWeight   = event->mEvtWeight;
	reWeight   = 1; 

	hVertexYvsX->Fill(vx,vy);
	hVpdVzvsTpcVz->Fill(vz,vpdVz);
	hVzDiffvsCentrality->Fill(centrality, vzDiff);
	hBField->Fill(bField);

	if(TMath::Abs(vz)>mVzCut)         return kFALSE;
	if(vr>mVrCut)                     return kFALSE;
	if(TMath::Abs(vzDiff)>mVzDiffCut) return kFALSE;

	if(centrality<0) return kFALSE;

	hRefMultvsRefMultCorr->Fill(refMultCorr,refMult, reWeight);
	hCentrality->Fill(centrality, reWeight);

	return kTRUE;
}
//______________________________________________________________
Bool_t passTrack(MINIEVENT const* const event, Int_t const& i)
{
	Int_t    charge     = event->mCharge[i];
	Int_t    nHitsFit   = event->mNHitsFit[i];
	Int_t    nHitsPoss  = event->mNHitsPoss[i];
	Double_t ratio      = 1.*nHitsFit/nHitsPoss;
	Int_t    nHitsDedx  = event->mNHitsDedx[i];
	Double_t dca        = event->mDca[i];
	Double_t pt         = event->mPt[i];
	Double_t eta        = event->mEta[i];
	Double_t phi        = event->mPhi[i];
	Double_t nSigmaE    = event->mNSigmaE[i];
	Double_t beta       = event->mBeta2TOF[i];
	Double_t localY     = event->mTOFLocalY[i];

	// apply p dependent nSigmaE cut
	//TVector3 mom;
	//mom.SetPtEtaPhi(pt, eta, phi);
	//Double_t p = mom.Mag(); 

	if(pt<mPtCut)               return kFALSE;
	if(TMath::Abs(eta)>mEtaCut) return kFALSE;
	if(nHitsFit<mNHitsFitCut)   return kFALSE;
	if(ratio<mNHitsFitRatioCut) return kFALSE;
	if(nHitsDedx<mNHitsDedxCut) return kFALSE;
	if(dca>mDcaCut)             return kFALSE;

	if(nSigmaE<mNSigmaECut[0] || nSigmaE>mNSigmaECut[1]) return kFALSE;

	if(beta<0 || TMath::Abs(1 - 1/beta)>mBeta2TOFCut)    return kFALSE;
	if(TMath::Abs(localY)>mTOFLocalYCut)                 return kFALSE;

	ParticleInfo parInfo;
	parInfo.charge  = charge;
	parInfo.pt      = pt;
	parInfo.eta     = eta;
	parInfo.phi     = phi;

	eInfo.push_back(parInfo);

	return kTRUE;
}
//____________________________________________________________
void makeRealPairs()
{
	TLorentzVector eePair(0,0,0,0);

	Int_t nElectrons  = eInfo.size();

	for(Int_t i=0; i<nElectrons-1; i++){
		TLorentzVector e1(0, 0, 0, 0);
		e1.SetPtEtaPhiM(eInfo[i].pt, eInfo[i].eta, eInfo[i].phi, Melectron);

		for(Int_t j=i+1; j<nElectrons; j++){
			TLorentzVector e2(0, 0, 0, 0);
			e2.SetPtEtaPhiM(eInfo[j].pt, eInfo[j].eta, eInfo[j].phi, Melectron);

			eePair = e1 + e2;

			if(TMath::Abs(eePair.Rapidity())<=mPairYCut){
				if(eInfo[i].charge*eInfo[j].charge<0){
					hULMvsPtvsCen->Fill(centrality, eePair.Pt(), eePair.M(), reWeight);
				}
				if(eInfo[i].charge>0 && eInfo[j].charge>0){
					hLPosMvsPtvsCen->Fill(centrality, eePair.Pt(), eePair.M(), reWeight);
				}
				if(eInfo[i].charge<0 && eInfo[j].charge<0){
					hLNegMvsPtvsCen->Fill(centrality, eePair.Pt(), eePair.M(), reWeight);
				}
			}
		}//end of e2 loop
	}//end of e1 loop
}
//____________________________________________________________
void bookHistograms()
{
	hVertexYvsX   = new TH2D("hVertexYvsX","hVertexYvsX; VertexX (cm); VertexY (cm)",500,-2.5,2.5,500,-2.5,2.5);
	hVpdVzvsTpcVz = new TH2D("hVpdVzvsTpcVz","hVpdVzvsTpcVz; TPC VertexZ (cm); VPD VertexZ (cm)",2000,-200,200,2000,-200,200);
	hVzDiffvsCentrality   = new TH2D("hVzDiffvsCentrality","hVzDiffvsCentrality; Centrality; Vz_{TPC} - Vz_{VPD} (cm)",16,0,16,200,-10,10);
	hRefMultvsRefMultCorr = new TH2D("hRefMultvsRefMultCorr","hRefMultvsRefMultCorr;refMultCorr;refMult",1000,0,1000,1000,0,1000);
	hCentrality    = new TH1D("hCentrality","hCentrality; centrality",16,0,16);
	hBField        = new TH1D("hBField","hBField;Magnetic Filed (KiloGauss);Counts",400,-10,10);

	const Int_t    nAllCenBins = 16;
	const Int_t    nPtBins   = 1000;
	const Double_t ptLow     = 0;
	const Double_t ptHi      = 10;
	const Int_t    nMassBins = 500;
	const Double_t massLow   = 0;
	const Double_t massHi    = 5;

	hULMvsPtvsCen = new TH3D("hULMvsPtvsCen","hULMvsPtvsCen;Centrality;p_{T} (GeV/c);M_{ee} (GeV/c^{2})",nAllCenBins,0,nAllCenBins,nPtBins,ptLow,ptHi,nMassBins,massLow,massHi);
	hLPosMvsPtvsCen = new TH3D("hLPosMvsPtvsCen","hLPosMvsPtvsCen;Centrality;p_{T} (GeV/c);M_{ee} (GeV/c^{2})",nAllCenBins,0,nAllCenBins,nPtBins,ptLow,ptHi,nMassBins,massLow,massHi);
	hLNegMvsPtvsCen = new TH3D("hLNegMvsPtvsCen","hLNegMvsPtvsCen;Centrality;p_{T} (GeV/c);M_{ee} (GeV/c^{2})",nAllCenBins,0,nAllCenBins,nPtBins,ptLow,ptHi,nMassBins,massLow,massHi);
	hULMvsPtvsCen->Sumw2();
	hLPosMvsPtvsCen->Sumw2();
	hLNegMvsPtvsCen->Sumw2();
}
//____________________________________________________________
void writeHistograms(char* outFile)
{
	char buf[1024];
	sprintf(buf,"%s.histo.root",outFile);
	cout<<"Writing histograms into "<<buf<<endl;
	TFile *mFile = new TFile(buf,"recreate");
	mFile->cd();

	hVertexYvsX->Write();
	hVpdVzvsTpcVz->Write();
	hVzDiffvsCentrality->Write();
	hRefMultvsRefMultCorr->Write();
	hCentrality->Write();
	hBField->Write();

	//main function
	hULMvsPtvsCen->Write();
	hLPosMvsPtvsCen->Write();
	hLNegMvsPtvsCen->Write();
}
