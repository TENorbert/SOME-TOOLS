#ifndef GenStudy_H
#define GenStudy_H

// -*- C++ -*-
//
// Package:    GenStudy
// Class:      GenStudy
// 
/**\class GenStudy GenStudy.cc EXO/GenStudy/src/GenStudy.cc

 Description: [one line class summary]

 Implementation:
     [Notes on implementation]
*/
//
// Original Author:  Shih-Chuan Kao
//         Created:  Thu Mar 15 12:51:07 CDT 2012
// $Id: GenStudy.h,v 1.1 2012/04/20 17:58:38 tambe Exp $
//
//


// system include files
#include <memory>

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"

#include "DataFormats/HepMCCandidate/interface/GenParticle.h" 
#include "DataFormats/Candidate/interface/Particle.h" 
#include "DataFormats/Candidate/interface/Candidate.h"
#include "DataFormats/Candidate/interface/CandidateFwd.h"
#include "DataFormats/RecoCandidate/interface/RecoCandidate.h"

#include <TMath.h>
#include <Math/VectorUtil.h>
#include <TRandom.h>
#include "TFile.h"
#include "TTree.h"
#include "TLorentzVector.h"

#include "Ntuple.h"
//
// class declaration
//
using namespace std ;
typedef math::XYZTLorentzVector LorentzVector;

//class GenStudy : public edm::EDAnalyzer {
class GenStudy {
   public:
      explicit GenStudy(const edm::ParameterSet& );
      ~GenStudy();

      void GetGen(const edm::Event&, Ntuple leaves );

   private:

      bool Propagator( LorentzVector v, double& x, double& y, double& z, double& t , double ctaugamma = 999999. );

      TRandom* expPDF ;

      // ----------member data ---------------------------
      double ctau ;
	  double seedGenNum ; 
      edm::InputTag genSrc ;


};

#endif
