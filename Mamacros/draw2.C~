#include "TFile.h"
#include "TH1.h"
#include "THStack.h"
#include "TCanvas.h"
#include "TString.h"
#include <iostream>
#include <fstream>

void draw2(TString variable = "h_MET",
	   TString suffix   = "_beforeCut")
{
  TFile* fData_MU        = new TFile("HZZ2l2nu_COUNT_DATA35pb_MU__Nov10"                     + suffix + ".root",                       "read");
  TFile* fData_Electron  = new TFile("HZZ2l2nu_COUNT_DATA35pb_Electron__Nov10" + suffix + ".root", "read");
  TFile* fData_EG        = new TFile("HZZ2l2nu_COUNT_DATA35pb_EG__Nov10"       + suffix + ".root", "read");
  TFile* fHZZ2el2nu_p400 = new TFile("HZZ2l2nu_COUNT_HZZ2el2nu_p400"           + suffix + ".root", "read"); //  signal
  TFile* fZgamma         = new TFile("HZZ2l2nu_COUNT_Zgamma_2l_enriched__Nov10" + suffix + ".root", "read");
  TFile* fTTbar_2l       = new TFile("HZZ2l2nu_COUNT_TTbar_2l__Nov10"          + suffix + ".root", "read");
  TFile* fWJets          = new TFile("HZZ2l2nu_COUNT_WJets_madgraph__Nov10"    + suffix + ".root", "read");
  TFile* fWW_2l          = new TFile("HZZ2l2nu_COUNT_WW_2l__Nov10"             + suffix + ".root", "read");
  TFile* fWZ_3l          = new TFile("HZZ2l2nu_COUNT_WZ_3l__Nov10"             + suffix + ".root", "read");
  TFile* fZZ_2l2nu       = new TFile("HZZ2l2nu_COUNT_ZZ_2l2nu_Spr10__Nov10"    + suffix + ".root", "read");


  TH1F* hData_Electron  = (TH1F*)fData_Electron ->Get(variable);  // data with electrons
  TH1F* hData_EG        = (TH1F*)fData_EG       ->Get(variable);  // data with electrons
  TH1F* hData_MU        = (TH1F*)fData_MU      ->Get(variable);   // data with muons
  TH1F* hHZZ2el2nu_p400 = (TH1F*)fHZZ2el2nu_p400->Get(variable);  // signal
  TH1F* hZgamma         = (TH1F*)fZgamma        ->Get(variable);
  TH1F* hTTbar_2l       = (TH1F*)fTTbar_2l      ->Get(variable);
  TH1F* hWJets          = (TH1F*)fWJets         ->Get(variable);
  TH1F* hWW_2l          = (TH1F*)fWW_2l         ->Get(variable);
  TH1F* hWZ_3l          = (TH1F*)fWZ_3l         ->Get(variable);
  TH1F* hZZ_2l2nu       = (TH1F*)fZZ_2l2nu      ->Get(variable);

  hZgamma        ->SetFillColor(1);  
  hTTbar_2l      ->SetFillColor(3); 
  hWJets         ->SetFillColor(4); 
  hWW_2l         ->SetFillColor(5); 
  hWZ_3l         ->SetFillColor(5); 
  hZZ_2l2nu      ->SetFillColor(6); 

  hHZZ2el2nu_p400->SetFillColor(7); 

  TH1F* hData = (TH1F*)hData_MU->Clone("hData");
  hData->Add(hData_Electron);
  hData->Add(hData_EG);

  //TH1F* hZgamma = (TH1F*)fZgamma->Get("h_M2l");

  THStack* hs = new THStack("hs","qwerty");
  hs->Add(hTTbar_2l); 
  hs->Add(hWJets); 
  hs->Add(hWW_2l); 
  hs->Add(hWZ_3l); 
  hs->Add(hZZ_2l2nu); 
  hs->Add(hZgamma); 


  // Draw
  //----------------------------------------------------------------------------
  TCanvas* c1 = new TCanvas("c1", "c1");

  c1->cd();

//  c1->SetLogy();

  //hZgamma->SetFillColor(kRed);
  //hZgamma->SetLineColor(kRed);
  hZgamma->SetFillColor(2);
  hZgamma->SetLineColor(2);
  hData  ->SetMarkerStyle(kFullCircle);
  hHZZ2el2nu_p400->SetMarkerStyle(kStar);
 

  //hZgamma->Draw("hist,same");
  hData           ->Draw("ep");
  hs              ->Draw("hist,same");
  hHZZ2el2nu_p400 ->Draw("hist,same"); 
  hData           ->Draw("ep,same");
  
  //  hData->SetMinimum(1e-3);


  // Print
  //----------------------------------------------------------------------------
  std::cout << "   data: "     << hData  ->GetSumOfWeights() << std::endl;

  std::cout << " Zgamma: "     << hZgamma->GetSumOfWeights() << std::endl;

  std::cout << " Background: " << hTTbar_2l->GetSumOfWeights() + hWJets   ->GetSumOfWeights() + hWW_2l ->GetSumOfWeights()+ 
                                  hWZ_3l   ->GetSumOfWeights() + hZZ_2l2nu->GetSumOfWeights() + hZgamma->GetSumOfWeights()  << std::endl;

  std::cout << " Signal: "     << hHZZ2el2nu_p400->GetSumOfWeights() << std::endl;
}
