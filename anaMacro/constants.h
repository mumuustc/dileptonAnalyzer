#include "TMath.h"

const Double_t Mmuon = 0.105658367;
const Double_t Mpion = 0.13957018;
const Double_t Mkaon = 0.493677;
const Double_t Mproton = 0.93827231;
const Double_t Melectron = 0.00051099907;

//event cuts
const Double_t mVzCut = 30.;
const Double_t mVzDiffCut = 3.;
const Double_t mVrCut = 2.;

//electron cuts, using TPC+TOF to do the EID
const Double_t mPtCut = 0.2;
const Double_t mEtaCut = 1.;
const Int_t    mNHitsFitCut = 20;
const Double_t mNHitsFitRatioCut = 0.52;
const Int_t    mNHitsDedxCut = 15;
const Double_t mDcaCut = 1;
const Double_t mBeta2TOFCut = 0.025;
const Double_t mTOFLocalYCut = 1.8;
const Double_t mNSigmaECut[2] = {-1.5, 2.}; //assume the mean of electron nSigmaE is 0

const Double_t mPairYCut = 1.;
