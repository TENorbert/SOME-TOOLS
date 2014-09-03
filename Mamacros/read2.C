//------------------------------------------------------------------------------
//
// Example of how to read ASCII files
//
//------------------------------------------------------------------------------
#include "TFile.h"
#include "TH1.h"

#include <iostream>
#include <fstream>


void read2(TString  input  = "HZZ2l2nu_COUNT_DATA35pb_Electron__Nov10", Double_t weight = 1.0)       // Data
{
  TH1F* h_M2l             = new TH1F("h_M2l            ","", 100, 0, 200);
  TH1F* h_PT2l            = new TH1F("h_PT2l           ","", 100, 0, 500);
  TH1F* h_projMET         = new TH1F("h_projMET        ","", 100, 0, 500);           
  TH1F* h_nVertexes       = new TH1F("h_nVertexes      ","",  10, 0,  10);         
  TH1F* h_nJets           = new TH1F("h_nJets          ","",  10, 0,  10);             
  TH1F* h_MT              = new TH1F("h_MT             ","", 100, 0, 500);                
  TH1F* h_BTag            = new TH1F("h_BTag           ","", 100, 0, 100);             
  TH1F* h_PTMINoPTMAX     = new TH1F("h_PTMINoPTMAX    ","", 100, 0, 500);      
  TH1F* h_MET             = new TH1F("h_MET            ","", 150, 0, 150);              
  TH1F* h_dPhiJetMet      = new TH1F("h_dPhiJetMet     ","", 100, -10, 10);       
  TH1F* h_ThetaStar       = new TH1F("h_ThetaStar      ","", 100, -10, 10);        
  TH1F* h_Eta2l           = new TH1F("h_Eta2l          ","", 100, -10, 10);            
  TH1F* h_dPhiPtVsMET     = new TH1F("h_dPhiPtVsMET    ","", 100, -10, 10);      
  TH1F* h_dPhi2l          = new TH1F("h_dPhi2l         ","", 100, 0, 500);           
  TH1F* h_maxPt           = new TH1F("h_maxPt          ","", 100, 0, 500);            
  TH1F* h_minPt           = new TH1F("h_minPt          ","", 100, 0, 500);            
  TH1F* h_worstIso        = new TH1F("h_worstIso       ","", 100,-10, 10);         
  TH1F* h_minDelPhiLepMET = new TH1F("h_minDelPhiLepMET","", 100,-10, 10);  
  TH1F* h_sumET           = new TH1F("h_sumET          ","", 100, 0, 500);             
  TH1F* h_Run             = new TH1F("h_Run            ","", 100, 0, 100000000);               
  TH1F* h_LumiSec         = new TH1F("h_LumiSec        ","", 100, 0, 100000000);           
  TH1F* h_Event           = new TH1F("h_Event          ","", 100, 0, 100000000);             

  h_M2l            ->Sumw2();
  h_PT2l           ->Sumw2();
  h_projMET        ->Sumw2();        
  h_nVertexes      ->Sumw2();      
  h_nJets          ->Sumw2();          
  h_MT             ->Sumw2();             
  h_BTag           ->Sumw2();          
  h_PTMINoPTMAX    ->Sumw2();   
  h_MET            ->Sumw2();           
  h_dPhiJetMet     ->Sumw2();    
  h_ThetaStar      ->Sumw2();     
  h_Eta2l          ->Sumw2();         
  h_dPhiPtVsMET    ->Sumw2();   
  h_dPhi2l         ->Sumw2();        
  h_maxPt          ->Sumw2();         
  h_minPt          ->Sumw2();         
  h_worstIso       ->Sumw2();      
  h_minDelPhiLepMET->Sumw2();
  h_sumET          ->Sumw2();          
  h_Run            ->Sumw2();            
  h_LumiSec        ->Sumw2();        
  h_Event          ->Sumw2();          

  TString  name;
  Double_t M2l;              // invariant mass of two leptons
  Double_t PT2l;             // PT of the two lepton system
  Double_t projMET;          // projected transverse missing energy
  Double_t nVertexes;        // number of vertices
  Double_t nJets;            // number of jets
  Double_t MT;               // transverse mass
  Double_t BTag;             // Track Counting High Efficiency B-Jet Tag
  Double_t PTMINoPTMAX;      // ratio of PTs of two selected leptons (smaller of them to larger PT value)
  Double_t MET;              // transverse missing energy
  Double_t dPhiJetMet;       // dPhi between MET and closest to MET jet
  Double_t ThetaStar;        // angle between vector Z and charge=+1 lepton momentum direction in Z rest frame
  Double_t Eta2l;            // Eta of the 2l system
  Double_t dPhiPtVsMET;      // dPhi between MET and PT of the 2l system
  Double_t dPhi2l;           // dPhi between two selected leptons
  Double_t maxPt;            // maximum PT out of the two selected leptons
  Double_t minPt;            // minimum PT out of the two selected leptons
  Double_t worstIso;         // worst (largest) isolation variable value
  Double_t minDelPhiLepMET;  // dPhi between MET and closest to MET lepton
  Double_t sumET;            // sum of ET (jets and leptons)
  Double_t Run;              // run number
  Double_t LumiSec;          // lumi section
  Double_t Event;            // event number

  //TString filename = "/Users/piedra/ejterm/input/HZZ2l2nu_COUNT_" + input + ".dat";
  TString filename = input + ".dat";

  std::cout << "\n Reading " << filename.Data() << "\n" << std::endl;
    
  ifstream in(filename.Data());
  if (!in || in.bad()) return;

  Int_t iline = 0;
    
  while (!in.eof()) {

    iline++;

    if (iline%20000 == 0) {std::cout << "."; std::flush(std::cout);}

    in >> name
       >> M2l
       >> PT2l
       >> projMET
       >> nVertexes
       >> nJets
       >> MT
       >> BTag
       >> PTMINoPTMAX
       >> MET
       >> dPhiJetMet
       >> ThetaStar
       >> Eta2l
       >> dPhiPtVsMET
       >> dPhi2l
       >> maxPt
       >> minPt
       >> worstIso
       >> minDelPhiLepMET
       >> sumET
       >> Run
       >> LumiSec
       >> Event;

//        if (name.Contains("2el2nu") && 
//            worstIso < 0.7          &&
//	    maxPt    >  20          &&
//	    minPt    >  20          &&
//	    M2l      >  80          &&
//	    M2l      < 100) 
    //if( /*(M2l>86 && M2l<98) &&*/ (PT2l>50) && projMET>120 && MT>250 && BTag<10 && minDelPhiLepMET>2.0 ){
    //if( (M2l>82 && M2l<98) && (PT2l>70 && PT2l<230) && MET>48 && BTag<3 && MT>240 && dPhi2l<1.6 && (maxPt>50 && maxPt<165) && worstIso<0.1 &&
    //     minDelPhiLepMET>2 && (sumET>160 && sumET<460)){
    //      std::cout<<"VARIABLE="<<projMET<<std::endl;      

      h_M2l            ->Fill(M2l            , weight);
      h_PT2l           ->Fill(PT2l           , weight); 
      h_projMET        ->Fill(projMET        , weight);           
      h_nVertexes      ->Fill(nVertexes      , weight);   
      h_nJets          ->Fill(nJets          , weight);   
      h_MT             ->Fill(MT             , weight);   
      h_BTag           ->Fill(BTag           , weight);             
      h_PTMINoPTMAX    ->Fill(PTMINoPTMAX    , weight);      
      h_MET            ->Fill(MET            , weight);              
      h_dPhiJetMet     ->Fill(dPhiJetMet     , weight);       
      h_ThetaStar      ->Fill(ThetaStar      , weight);        
      h_Eta2l          ->Fill(Eta2l          , weight);            
      h_dPhiPtVsMET    ->Fill(dPhiPtVsMET    , weight);      
      h_dPhi2l         ->Fill(dPhi2l         , weight);           
      h_maxPt          ->Fill(maxPt          , weight);            
      h_minPt          ->Fill(minPt          , weight);            
      h_worstIso       ->Fill(worstIso       , weight);         
      h_minDelPhiLepMET->Fill(minDelPhiLepMET, weight);  
      h_sumET          ->Fill(sumET          , weight);             
      h_Run            ->Fill(Run            , weight);               
      h_LumiSec        ->Fill(LumiSec        , weight);           
      h_Event          ->Fill(Event          , weight);
    //}

  }

  std::cout << std::endl;

  in.close();

  
  // Save histogram to a file
  //----------------------------------------------------------------------------
   TFile* output = new TFile(input + "_afterCut.root", "recreate");
  // TFile* output = new TFile(input + "_beforeCut.root", "recreate");

  h_M2l->Write();
  h_PT2l           ->Write(); 
  h_projMET        ->Write();           
  h_nVertexes      ->Write();   
  h_nJets          ->Write();   
  h_MT             ->Write();   
  h_BTag           ->Write();             
  h_PTMINoPTMAX    ->Write();      
  h_MET            ->Write();              
  h_dPhiJetMet     ->Write();       
  h_ThetaStar      ->Write();        
  h_Eta2l          ->Write();            
  h_dPhiPtVsMET    ->Write();      
  h_dPhi2l         ->Write();           
  h_maxPt          ->Write();            
  h_minPt          ->Write();            
  h_worstIso       ->Write();         
  h_minDelPhiLepMET->Write();  
  h_sumET          ->Write();             
  h_Run            ->Write();               
  h_LumiSec        ->Write();           
  h_Event          ->Write(); 
  
  output->Close();
}

