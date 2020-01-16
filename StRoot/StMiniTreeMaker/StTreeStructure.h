const Int_t mMax = 2000;
struct StEvtData
{
	// event information
	Int_t    mRunId;
	Int_t    mEventId;
	Char_t   mShouldHaveRejectEvent;
	Char_t   mNTrigs;
	Int_t    mTrigId[64];
	Short_t  mRefMult;
	Short_t  mGRefMult;
	Float_t  mRefMultCorr;
	Float_t  mEvtWeight;
	Short_t  mCentrality;
	Float_t  mBBCRate;
	Float_t  mZDCRate;
	Float_t  mBField;
	Float_t  mVpdVz;
	Float_t  mVertexX;
    Float_t  mVertexY;
    Float_t  mVertexZ;
	Float_t  mVertexRanking;
	Float_t  mEtaPlusQx;
	Float_t  mEtaPlusQy;
	Float_t  mEtaPlusPtWeight;
	Short_t  mEtaPlusNTrks;
	Float_t  mEtaMinusQx;
	Float_t  mEtaMinusQy;
	Float_t  mEtaMinusPtWeight;
	Short_t  mEtaMinusNTrks;

	//track information
	Short_t  mNTrks;
	Short_t  mTrkId[mMax];
	Bool_t   mTPCeTrkFlag[mMax];
	Short_t  mBEMCTraitsIndex[mMax];
	Short_t  mMTDTraitsIndex[mMax];
	Char_t   mCharge[mMax];
	Float_t  mPt[mMax];
	Float_t  mEta[mMax];
	Float_t  mPhi[mMax];
	Float_t  mgPt[mMax];
	Float_t  mgEta[mMax];
	Float_t  mgPhi[mMax];
	Float_t  mgOriginX[mMax];
	Float_t  mgOriginY[mMax];
	Float_t  mgOriginZ[mMax];
	Char_t   mNHitsFit[mMax];
	Char_t   mNHitsPoss[mMax];
	Char_t   mNHitsDedx[mMax];
	Float_t  mDedx[mMax];
	Float_t  mDndx[mMax];
	Float_t  mDndxError[mMax];
	Float_t  mNSigmaE[mMax];
	Float_t  mDca[mMax];
	Float_t  mChi2[mMax];
	Float_t  mChi2Prob[mMax];
	Bool_t   mIsHFTTrk[mMax];
	Bool_t   mHasHFT4Layers[mMax];
	Char_t   mTOFMatchFlag[mMax];
	Float_t  mTOFLocalY[mMax];
	Float_t  mBeta2TOF[mMax];

	//BEMC pidTrait information
	Short_t  mNBEMCTrks;
	Short_t  mBEMCTrkIndex[mMax];
	Short_t  mBEMCAdc0[mMax];
	Float_t  mBEMCE0[mMax];
	Float_t  mBEMCE[mMax];
	Float_t  mBEMCZDist[mMax];
	Float_t  mBEMCPhiDist[mMax];
	Char_t   mBEMCnEta[mMax];
	Char_t   mBEMCnPhi[mMax];
	Float_t  mNSigmaPi[mMax];
	Float_t  mNSigmaK[mMax];
	Float_t  mNSigmaP[mMax];

	//MTD pidTrait information
	Short_t  mNMTDTrks;
	Short_t  mMTDTrkIndex[mMax];
	Char_t   mMTDBackleg[mMax]; 
	Char_t   mMTDModule[mMax];
	Char_t   mMTDCell[mMax];
	Char_t   mMTDMatchFlag[mMax];
	Bool_t   mMTDTriggerFlag[mMax];
	Bool_t   mMTDBEMCMatchFlag[mMax];
	UChar_t  mMTDDecayFlag[mMax];
	Float_t  mMTDnSigmaPi[mMax];
	Float_t  mMTDDeltaY[mMax];
	Float_t  mMTDDeltaZ[mMax];
	Float_t  mMTDDeltaTof[mMax];
	Float_t  mMTDBeta[mMax];
};
