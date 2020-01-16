//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Thu Jan 16 00:43:26 2020 by ROOT version 5.34/30
// from TTree miniDst/miniDst
// found on file: /star/u/syang/run18/dileptonAnalyzer/test/test.root
//////////////////////////////////////////////////////////

#ifndef MINIEVENT_h
#define MINIEVENT_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

// Fixed size dimensions of array or collections stored in the TTree if any.

class MINIEVENT {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   Int_t           mRunId;
   Int_t           mEventId;
   Char_t          mNTrigs;
   Int_t           mTrigId[64];   //[mNTrigs]
   Short_t         mRefMult;
   Short_t         mGRefMult;
   Float_t         mRefMultCorr;
   Float_t         mEvtWeight;
   Short_t         mCentrality;
   Float_t         mBBCRate;
   Float_t         mZDCRate;
   Float_t         mBField;
   Float_t         mVpdVz;
   Float_t         mVertexX;
   Float_t         mVertexY;
   Float_t         mVertexZ;
   Float_t         mVertexRanking;
   Float_t         mEtaPlusQx;
   Float_t         mEtaPlusQy;
   Float_t         mEtaPlusPtWeight;
   Short_t         mEtaPlusNTrks;
   Float_t         mEtaMinusQx;
   Float_t         mEtaMinusQy;
   Float_t         mEtaMinusPtWeight;
   Short_t         mEtaMinusNTrks;
   Short_t         mNTrks;
   Short_t         mTrkId[2000];   //[mNTrks]
   Bool_t          mTPCeTrkFlag[2000];   //[mNTrks]
   Short_t         mBEMCTraitsIndex[2000];   //[mNTrks]
   Char_t          mCharge[2000];   //[mNTrks]
   Float_t         mPt[2000];   //[mNTrks]
   Float_t         mEta[2000];   //[mNTrks]
   Float_t         mPhi[2000];   //[mNTrks]
   Char_t          mNHitsFit[2000];   //[mNTrks]
   Char_t          mNHitsPoss[2000];   //[mNTrks]
   Char_t          mNHitsDedx[2000];   //[mNTrks]
   Float_t         mDedx[2000];   //[mNTrks]
   Float_t         mNSigmaE[2000];   //[mNTrks]
   Float_t         mDca[2000];   //[mNTrks]
   Char_t          mTOFMatchFlag[2000];   //[mNTrks]
   Float_t         mTOFLocalY[2000];   //[mNTrks]
   Float_t         mBeta2TOF[2000];   //[mNTrks]
   Short_t         mNBEMCTrks;
   Short_t         mBEMCTrkIndex[2000];   //[mNBEMCTrks]
   Short_t         mBEMCAdc0[2000];   //[mNBEMCTrks]
   Float_t         mBEMCE0[2000];   //[mNBEMCTrks]
   Float_t         mBEMCE[2000];   //[mNBEMCTrks]
   Float_t         mBEMCZDist[2000];   //[mNBEMCTrks]
   Float_t         mBEMCPhiDist[2000];   //[mNBEMCTrks]
   Char_t          mBEMCnEta[2000];   //[mNBEMCTrks]
   Char_t          mBEMCnPhi[2000];   //[mNBEMCTrks]
   Float_t         mNSigmaPi[2000];   //[mNBEMCTrks]
   Float_t         mNSigmaK[2000];   //[mNBEMCTrks]
   Float_t         mNSigmaP[2000];   //[mNBEMCTrks]

   // List of branches
   TBranch        *b_mRunId;   //!
   TBranch        *b_mEventId;   //!
   TBranch        *b_mNTrigs;   //!
   TBranch        *b_mTrigId;   //!
   TBranch        *b_mRefMult;   //!
   TBranch        *b_mGRefMult;   //!
   TBranch        *b_mRefMultCorr;   //!
   TBranch        *b_mEvtWeight;   //!
   TBranch        *b_mCentrality;   //!
   TBranch        *b_mBBCRate;   //!
   TBranch        *b_mZDCRate;   //!
   TBranch        *b_mBField;   //!
   TBranch        *b_mVpdVz;   //!
   TBranch        *b_mVertexX;   //!
   TBranch        *b_mVertexY;   //!
   TBranch        *b_mVertexZ;   //!
   TBranch        *b_mVertexRanking;   //!
   TBranch        *b_mEtaPlusQx;   //!
   TBranch        *b_mEtaPlusQy;   //!
   TBranch        *b_mEtaPlusPtWeight;   //!
   TBranch        *b_mEtaPlusNTrks;   //!
   TBranch        *b_mEtaMinusQx;   //!
   TBranch        *b_mEtaMinusQy;   //!
   TBranch        *b_mEtaMinusPtWeight;   //!
   TBranch        *b_mEtaMinusNTrks;   //!
   TBranch        *b_mNTrks;   //!
   TBranch        *b_mTrkId;   //!
   TBranch        *b_mTPCeTrkFlag;   //!
   TBranch        *b_mBEMCTraitsIndex;   //!
   TBranch        *b_mCharge;   //!
   TBranch        *b_mPt;   //!
   TBranch        *b_mEta;   //!
   TBranch        *b_mPhi;   //!
   TBranch        *b_mNHitsFit;   //!
   TBranch        *b_mNHitsPoss;   //!
   TBranch        *b_mNHitsDedx;   //!
   TBranch        *b_mDedx;   //!
   TBranch        *b_mNSigmaE;   //!
   TBranch        *b_mDca;   //!
   TBranch        *b_mTOFMatchFlag;   //!
   TBranch        *b_mTOFLocalY;   //!
   TBranch        *b_mBeta2TOF;   //!
   TBranch        *b_mNBEMCTrks;   //!
   TBranch        *b_mBEMCTrkIndex;   //!
   TBranch        *b_mBEMCAdc0;   //!
   TBranch        *b_mBEMCE0;   //!
   TBranch        *b_mBEMCE;   //!
   TBranch        *b_mBEMCZDist;   //!
   TBranch        *b_mBEMCPhiDist;   //!
   TBranch        *b_mBEMCnEta;   //!
   TBranch        *b_mBEMCnPhi;   //!
   TBranch        *b_mNSigmaPi;   //!
   TBranch        *b_mNSigmaK;   //!
   TBranch        *b_mNSigmaP;   //!

   MINIEVENT(TTree *tree=0);
   virtual ~MINIEVENT();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef MINIEVENT_cxx
MINIEVENT::MINIEVENT(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("/star/u/syang/run18/dileptonAnalyzer/test/test.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("/star/u/syang/run18/dileptonAnalyzer/test/test.root");
      }
      f->GetObject("miniDst",tree);

   }
   Init(tree);
}

MINIEVENT::~MINIEVENT()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t MINIEVENT::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t MINIEVENT::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void MINIEVENT::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("mRunId", &mRunId, &b_mRunId);
   fChain->SetBranchAddress("mEventId", &mEventId, &b_mEventId);
   fChain->SetBranchAddress("mNTrigs", &mNTrigs, &b_mNTrigs);
   fChain->SetBranchAddress("mTrigId", mTrigId, &b_mTrigId);
   fChain->SetBranchAddress("mRefMult", &mRefMult, &b_mRefMult);
   fChain->SetBranchAddress("mGRefMult", &mGRefMult, &b_mGRefMult);
   fChain->SetBranchAddress("mRefMultCorr", &mRefMultCorr, &b_mRefMultCorr);
   fChain->SetBranchAddress("mEvtWeight", &mEvtWeight, &b_mEvtWeight);
   fChain->SetBranchAddress("mCentrality", &mCentrality, &b_mCentrality);
   fChain->SetBranchAddress("mBBCRate", &mBBCRate, &b_mBBCRate);
   fChain->SetBranchAddress("mZDCRate", &mZDCRate, &b_mZDCRate);
   fChain->SetBranchAddress("mBField", &mBField, &b_mBField);
   fChain->SetBranchAddress("mVpdVz", &mVpdVz, &b_mVpdVz);
   fChain->SetBranchAddress("mVertexX", &mVertexX, &b_mVertexX);
   fChain->SetBranchAddress("mVertexY", &mVertexY, &b_mVertexY);
   fChain->SetBranchAddress("mVertexZ", &mVertexZ, &b_mVertexZ);
   fChain->SetBranchAddress("mVertexRanking", &mVertexRanking, &b_mVertexRanking);
   fChain->SetBranchAddress("mEtaPlusQx", &mEtaPlusQx, &b_mEtaPlusQx);
   fChain->SetBranchAddress("mEtaPlusQy", &mEtaPlusQy, &b_mEtaPlusQy);
   fChain->SetBranchAddress("mEtaPlusPtWeight", &mEtaPlusPtWeight, &b_mEtaPlusPtWeight);
   fChain->SetBranchAddress("mEtaPlusNTrks", &mEtaPlusNTrks, &b_mEtaPlusNTrks);
   fChain->SetBranchAddress("mEtaMinusQx", &mEtaMinusQx, &b_mEtaMinusQx);
   fChain->SetBranchAddress("mEtaMinusQy", &mEtaMinusQy, &b_mEtaMinusQy);
   fChain->SetBranchAddress("mEtaMinusPtWeight", &mEtaMinusPtWeight, &b_mEtaMinusPtWeight);
   fChain->SetBranchAddress("mEtaMinusNTrks", &mEtaMinusNTrks, &b_mEtaMinusNTrks);
   fChain->SetBranchAddress("mNTrks", &mNTrks, &b_mNTrks);
   fChain->SetBranchAddress("mTrkId", mTrkId, &b_mTrkId);
   fChain->SetBranchAddress("mTPCeTrkFlag", mTPCeTrkFlag, &b_mTPCeTrkFlag);
   fChain->SetBranchAddress("mBEMCTraitsIndex", mBEMCTraitsIndex, &b_mBEMCTraitsIndex);
   fChain->SetBranchAddress("mCharge", mCharge, &b_mCharge);
   fChain->SetBranchAddress("mPt", mPt, &b_mPt);
   fChain->SetBranchAddress("mEta", mEta, &b_mEta);
   fChain->SetBranchAddress("mPhi", mPhi, &b_mPhi);
   fChain->SetBranchAddress("mNHitsFit", mNHitsFit, &b_mNHitsFit);
   fChain->SetBranchAddress("mNHitsPoss", mNHitsPoss, &b_mNHitsPoss);
   fChain->SetBranchAddress("mNHitsDedx", mNHitsDedx, &b_mNHitsDedx);
   fChain->SetBranchAddress("mDedx", mDedx, &b_mDedx);
   fChain->SetBranchAddress("mNSigmaE", mNSigmaE, &b_mNSigmaE);
   fChain->SetBranchAddress("mDca", mDca, &b_mDca);
   fChain->SetBranchAddress("mTOFMatchFlag", mTOFMatchFlag, &b_mTOFMatchFlag);
   fChain->SetBranchAddress("mTOFLocalY", mTOFLocalY, &b_mTOFLocalY);
   fChain->SetBranchAddress("mBeta2TOF", mBeta2TOF, &b_mBeta2TOF);
   fChain->SetBranchAddress("mNBEMCTrks", &mNBEMCTrks, &b_mNBEMCTrks);
   fChain->SetBranchAddress("mBEMCTrkIndex", &mBEMCTrkIndex, &b_mBEMCTrkIndex);
   fChain->SetBranchAddress("mBEMCAdc0", &mBEMCAdc0, &b_mBEMCAdc0);
   fChain->SetBranchAddress("mBEMCE0", &mBEMCE0, &b_mBEMCE0);
   fChain->SetBranchAddress("mBEMCE", &mBEMCE, &b_mBEMCE);
   fChain->SetBranchAddress("mBEMCZDist", &mBEMCZDist, &b_mBEMCZDist);
   fChain->SetBranchAddress("mBEMCPhiDist", &mBEMCPhiDist, &b_mBEMCPhiDist);
   fChain->SetBranchAddress("mBEMCnEta", &mBEMCnEta, &b_mBEMCnEta);
   fChain->SetBranchAddress("mBEMCnPhi", &mBEMCnPhi, &b_mBEMCnPhi);
   fChain->SetBranchAddress("mNSigmaPi", &mNSigmaPi, &b_mNSigmaPi);
   fChain->SetBranchAddress("mNSigmaK", &mNSigmaK, &b_mNSigmaK);
   fChain->SetBranchAddress("mNSigmaP", &mNSigmaP, &b_mNSigmaP);
   Notify();
}

Bool_t MINIEVENT::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void MINIEVENT::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t MINIEVENT::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef MINIEVENT_cxx
