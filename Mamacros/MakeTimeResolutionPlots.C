#include "string.h"
#include "TChain.h"
#include "TH1.h"
#include "TFile.h"
#include "TCanvas.h"
#include "TPad.h"
#include "TLegend.h"
#include "TMath.h"
#include"Riostream.h"

//gStyle->SetPalette(1);

  using namespace std;


  void MakeTimeResolutionPlots(char *file11, char *file10)
{

std::cout << " File Read is:" << file11 << "for 2011" << std::endl;
  std::cout << "File Read is:" << file10 << "for 2010" << std::endl;
  TFile * f11 =new TFile(file11);

  TFile *f10 = new TFile(file10);

  //    TFile *f11 = new TFile ("EleHadskimLCorrAndOldGTV6/UnCalibrated_Elehad_v6_Run2011A_LCorr_with_OldGT_run172801-173692.root");
  // f11->cd("single-bias");
  // cout << "What is in the Directory?" << f11->ls()<< endl;


  // TFile *f10 = new TFile ("ZSkimLCorrAndOldGTV6/UnRecalibZskim_Run2011A-v6-Run172801-173692-LCorrAndOldGT.root");
  //f10-> cd("single-bias");
  // cout << "what is in the Directory?" << f10->ls()<< endl;


  
  // Mean Time plots here!

              TH1F* timeVsAmpli11_EBMod4 =(TH1F*)f11->Get("single-bias/timeVsAoSigmaMod4EBlog_1");
              TH1F* timeVsAmpli11_EBMod1 =(TH1F*)f11->Get("single-bias/timeVsAoSigmaMod1EBlog_1");
              TH1F* timeVsAmpli11_EBMod2 =(TH1F*)f11->Get("single-bias/timeVsAoSigmaMod2EBlog_1");
              TH1F* timeVsAmpli11_EBMod3 =(TH1F*)f11->Get("single-bias/timeVsAoSigmaMod3EBlog_1");
              TH1F* timeVsAmpli10_EBMod4 =(TH1F*)f10->Get("single-bias/timeVsAoSigmaMod4EBlog_1");
              TH1F* timeVsAmpli10_EBMod1 =(TH1F*)f10->Get("single-bias/timeVsAoSigmaMod1EBlog_1");
              TH1F* timeVsAmpli10_EBMod2 =(TH1F*)f10->Get("single-bias/timeVsAoSigmaMod2EBlog_1");
              TH1F* timeVsAmpli10_EBMod3 =(TH1F*)f10->Get("single-bias/timeVsAoSigmaMod3EBlog_1");
           
	      //                       TH1F* timeVsAmpli10_L =(TH1F*)f10->Get("single-bias/timeVsAoSigmaMod4EBlog_1");
                       TH1F* timeVsAmpli10_L =(TH1F*)f10->Get("single-bias/timeVsAoSigmaLowEElog_1");
        	       TH1F* timeVsAmpli11_L =(TH1F*)f11->Get("single-bias/timeVsAoSigmaLowEElog_1");
		       TH1F* timeVsAmpli10_H = (TH1F*)f10->Get("single-bias/timeVsAoSigmaHighEElog_1");
		       TH1F* timeVsAmpli11_H = (TH1F*)f11->Get("single-bias/timeVsAoSigmaHighEElog_1");
		       //4 EB
                       TH1F* timeVsAmpli10_EB =(TH1F*)f10->Get("single-bias/timeVsAoSigmaEBlog_1");
                       TH1F* timeVsAmpli11_EB =(TH1F*)f11->Get("single-bias/timeVsAoSigmaEBlog_1");
		       //4 EE
                       TH1F* timeVsAmpli10_EE =(TH1F*)f10->Get("single-bias/timeVsAoSigmaEElog_1");
                       TH1F* timeVsAmpli11_EE =(TH1F*)f11->Get("single-bias/timeVsAoSigmaEElog_1");


		       // sigma of Mean Time Plots here!


              TH1F* SigmatimeVsAmpli11_EBMod4 =(TH1F*)f11->Get("single-bias/timeVsAoSigmaMod4EBlog_2");
              TH1F* SigmatimeVsAmpli11_EBMod1 =(TH1F*)f11->Get("single-bias/timeVsAoSigmaMod1EBlog_2");
              TH1F* SigmatimeVsAmpli11_EBMod2 =(TH1F*)f11->Get("single-bias/timeVsAoSigmaMod2EBlog_2");
              TH1F* SigmatimeVsAmpli11_EBMod3 =(TH1F*)f11->Get("single-bias/timeVsAoSigmaMod3EBlog_2");
              TH1F* SigmatimeVsAmpli10_EBMod4 =(TH1F*)f10->Get("single-bias/timeVsAoSigmaMod4EBlog_2");
              TH1F* SigmatimeVsAmpli10_EBMod1 =(TH1F*)f10->Get("single-bias/timeVsAoSigmaMod1EBlog_2");
              TH1F* SigmatimeVsAmpli10_EBMod2 =(TH1F*)f10->Get("single-bias/timeVsAoSigmaMod2EBlog_2");
              TH1F* SigmatimeVsAmpli10_EBMod3 =(TH1F*)f10->Get("single-bias/timeVsAoSigmaMod3EBlog_2");
           
	      //                       TH1F* timeVsAmpli10_L =(TH1F*)f10->Get("single-bias/timeVsAoSigmaMod4EBlog_2");
                       TH1F* SigmatimeVsAmpli10_L =(TH1F*)f10->Get("single-bias/timeVsAoSigmaLowEElog_2");
        	       TH1F* SigmatimeVsAmpli11_L =(TH1F*)f11->Get("single-bias/timeVsAoSigmaLowEElog_2");
		       TH1F* SigmatimeVsAmpli10_H = (TH1F*)f10->Get("single-bias/timeVsAoSigmaHighEElog_2");
 		       TH1F* SigmatimeVsAmpli11_H = (TH1F*)f11->Get("single-bias/timeVsAoSigmaHighEElog_2");
		       //Sigma EB
	              TH1F* SigmatimeVsAmpli10_EB =(TH1F*)f10->Get("single-bias/timeVsAoSigmaEBlog_2");
	              TH1F* SigmatimeVsAmpli11_EB =(TH1F*)f11->Get("single-bias/timeVsAoSigmaEBlog_2");
		      // sigma EE
	              TH1F* SigmatimeVsAmpli10_EE =(TH1F*)f10->Get("single-bias/timeVsAoSigmaEElog_2");
	              TH1F* SigmatimeVsAmpli11_EE =(TH1F*)f11->Get("single-bias/timeVsAoSigmaEElog_2");



  float minMeanTime = -1.0;
  float maxMeanTime = 1.0;
  float MinSigmaTime = 0.0;
  float MaxSigmaTime= 4.0;
  float MinAmpli = 25.0;
  float MaxAmpli = 100000;

         
 std::cout << "timeVsAmpli11_L is:" 
          << timeVsAmpli11_L->GetName() << " and has " 
          << timeVsAmpli11_L->GetEntries() << " entries;" 
          << std::endl;
std::cout << "timeVsAmpli10_L is: " 
          << timeVsAmpli10_L->GetName() << " and has " 
          << timeVsAmpli10_L->GetEntries() << " entries;" 
          << std::endl;



TCanvas *c1 = new TCanvas("c1", "timeVsAmpliLowEE");
TLegend*  Leg1 = new TLegend(0.4,0.7, 0.67,0.85);
 Leg1->SetHeader("Legend");
 Leg1->SetFillColor(0);
 Leg1->SetTextSize(0.04);
 // c->Divide(1,2);
  c1->cd();
  // timeVsAmpli11_L->Fit("gaus");            //E = A*0.063 (GeV)
  timeVsAmpli11_L->GetXaxis()->SetTitle("Amplitude(ADC counts)");// E =A*0.039(GeV) 4 EB
  timeVsAmpli11_L->GetYaxis()->SetTitle("Mean Time[ns]");
  timeVsAmpli11_L->GetYaxis()->SetRangeUser(minMeanTime,maxMeanTime);
  timeVsAmpli11_L->GetXaxis()->SetRangeUser(MinAmpli, MaxAmpli);
  timeVsAmpli11_L->SetTitle("Mean Time Vs Amplitude, Crys in EE  |#eta|<2.2");

  timeVsAmpli11_L->SetTitleSize(0.06,"x");
  timeVsAmpli11_L->SetTitleOffset(1.,"x");
  timeVsAmpli11_L->SetTitleSize(0.06,"y");
  timeVsAmpli11_L->SetTitleOffset(1.,"y");

  timeVsAmpli11_L->SetLineColor(8);
  timeVsAmpli11_L->SetLineStyle(1);
  timeVsAmpli11_L->SetMarkerStyle(20);
  timeVsAmpli11_L->SetMarkerSize(1.);
  timeVsAmpli11_L->SetMarkerColor(kGreen);
  gPad->SetBottomMargin(0.15);
  gPad->SetLeftMargin(0.15);
  gPad->SetLogx(1);

   gPad->Modified(1);
   c1->SetGridx(1);
   c1->SetGridy(1);
   c1->SetLogx(1);
  //  cd->cd(2);
  // timeVsAmpli10_L->Fit("gaus");

  timeVsAmpli10_L->GetXaxis()->SetTitle("Amplitude(ADC counts)");// E =A*0.039(GeV) 4 EB
  timeVsAmpli10_L->GetYaxis()->SetTitle("Mean Time[ns]");
  timeVsAmpli10_L->GetYaxis()->SetRangeUser(minMeanTime,maxMeanTime);
  timeVsAmpli10_L->GetXaxis()->SetRangeUser(MinAmpli, MaxAmpli);
  timeVsAmpli10_L->SetTitle("Mean Time Vs Amplitude, Crys in EE |#eta|< 2.2");

  timeVsAmpli10_L->SetTitleSize(0.06,"x");
  timeVsAmpli10_L->SetTitleOffset(1.,"x");
  timeVsAmpli10_L->SetTitleSize(0.06,"y");
  timeVsAmpli10_L->SetTitleOffset(1.,"y");

  timeVsAmpli10_L->SetMarkerStyle(20);
  timeVsAmpli10_L->SetMarkerSize(1.);
  timeVsAmpli10_L->SetMarkerColor(kBlue);
  timeVsAmpli10_L->SetLineStyle(1);
  timeVsAmpli10_L->SetLineColor(4);

//   gPad->SetBottomMargin(0.15);
//   gPad->SetLeftMargin(0.15);
//   gPad->SetLogx(0);
//   gPad->Modified();
  
  
  timeVsAmpli11_L->Draw("p");
  timeVsAmpli10_L->Draw("psame");
  
  Leg1->AddEntry(timeVsAmpli10_L,"Base","p");
  Leg1->AddEntry(timeVsAmpli11_L, "Corr-Base","p");
  Leg1->Draw();



 std::cout << "timeVsAmpli11_H is: " 
          << timeVsAmpli11_H->GetName() << " and has " 
          << timeVsAmpli11_H->GetEntries() << " entries;" 
          << std::endl;
std::cout << "timeVsAmpli10_H is: " 
          << timeVsAmpli10_H->GetName() << " and has " 
          << timeVsAmpli10_H->GetEntries() << " entries;" 
          << std::endl;

  TCanvas *c2 = new TCanvas("c2", "timeVsAmpliHighEE");
  //TCanvas *c1 = new TCanvas("c1", "c");
TLegend*  Leg2 = new TLegend(0.4,0.7, 0.67,0.85);
 Leg2->SetHeader("Legend");
 Leg2->SetFillColor(0);
 Leg2->SetTextSize(0.04);
 // c->Divide(1,2);
  c2->cd();
  // timeVsAmpli11_L->Fit("gaus");            //E = A*0.063 (GeV)
  timeVsAmpli11_H->GetXaxis()->SetTitle("Amplitude(ADC counts)");// E =A*0.039(GeV) 4 EB
  timeVsAmpli11_H->GetYaxis()->SetTitle("Mean Time[ns]");
  timeVsAmpli11_H->GetYaxis()->SetRangeUser(minMeanTime,maxMeanTime);
  timeVsAmpli11_H->GetXaxis()->SetRangeUser(MinAmpli, MaxAmpli);
  timeVsAmpli11_H->SetTitle("Mean Time Vs Amplitude, Crys in EE |#eta|> 2.2");

  timeVsAmpli11_H->SetTitleSize(0.06,"x");
  timeVsAmpli11_H->SetTitleOffset(1.,"x");
  timeVsAmpli11_H->SetTitleSize(0.06,"y");
  timeVsAmpli11_H->SetTitleOffset(1.,"y");

  timeVsAmpli11_H->SetLineColor(8);
  timeVsAmpli11_H->SetLineStyle(1);
  timeVsAmpli11_H->SetMarkerStyle(20);
  timeVsAmpli11_H->SetMarkerSize(1.);
  timeVsAmpli11_H->SetMarkerColor(kGreen);
  gPad->SetBottomMargin(0.15);
  gPad->SetLeftMargin(0.15);
  gPad->SetLogx(1);

   gPad->Modified(1);
   c2->SetGridx(1);
   c2->SetGridy(1);
   c2->SetLogx(1);
  //  cd->cd(2);
  // timeVsAmpli10_L->Fit("gaus");

  timeVsAmpli10_H->GetXaxis()->SetTitle("Amplitude(ADC counts)");// E =A*0.039(GeV) 4 EB
  timeVsAmpli10_H->GetYaxis()->SetTitle("Mean Time[ns]");
  timeVsAmpli10_H->GetYaxis()->SetRangeUser(minMeanTime,maxMeanTime);
  timeVsAmpli10_H->GetXaxis()->SetRangeUser(MinAmpli, MaxAmpli);
  timeVsAmpli10_H->SetTitle("Mean Time Vs Amplitude, Crys in EE |#eta|> 2.2");

  timeVsAmpli10_H->SetTitleSize(0.06,"x");
  timeVsAmpli10_H->SetTitleOffset(1.,"x");
  timeVsAmpli10_H->SetTitleSize(0.06,"y");
  timeVsAmpli10_H->SetTitleOffset(1.,"y");

  timeVsAmpli10_H->SetMarkerStyle(20);
  timeVsAmpli10_H->SetMarkerSize(1.);
  timeVsAmpli10_H->SetMarkerColor(kBlue);
  timeVsAmpli10_H->SetLineStyle(1);
  timeVsAmpli10_H->SetLineColor(4);

//   gPad->SetBottomMargin(0.15);
//   gPad->SetLeftMargin(0.15);
//   gPad->SetLogx(0);
//   gPad->Modified();
  
  
  timeVsAmpli11_H->Draw("p");
  timeVsAmpli10_H->Draw("psame");
  
  Leg2->AddEntry(timeVsAmpli10_H,"Base","p");
  Leg2->AddEntry(timeVsAmpli11_H, "Corr-Base","p");
  Leg2->Draw();




std::cout << " timeVsAmpli11_EBMod4 is: " 
          <<  timeVsAmpli11_EBMod4->GetName() << " and has " 
          <<  timeVsAmpli11_EBMod4->GetEntries() << " entries;" 
          << std::endl;
std::cout << " timeVsAmpli10_EBMod4 is: " 
          <<  timeVsAmpli10_EBMod4->GetName() << " and has " 
          <<  timeVsAmpli10_EBMod4->GetEntries() << " entries;" 
          << std::endl;


 TCanvas *c3 = new TCanvas("c3", "timeVsAmpli_EB_Mod4");
  //TCanvas *c1 = new TCanvas("c1", "c");
TLegend*  Leg3 = new TLegend(0.4,0.7, 0.67,0.85);
 Leg3->SetHeader("Legend");
 Leg3->SetFillColor(0);
 Leg3->SetTextSize(0.04);
 // c->Divide(1,2);
  c3->cd();
  // timeVsAmpli11_L->Fit("gaus");            //E = A*0.063 (GeV)
  timeVsAmpli11_EBMod4->GetXaxis()->SetTitle("Amplitude(ADC Counts)");// E =A*0.039(GeV) 4 EB
  timeVsAmpli11_EBMod4->GetYaxis()->SetTitle("Mean Time[ns]");
  timeVsAmpli11_EBMod4->GetYaxis()->SetRangeUser(minMeanTime,maxMeanTime);
  timeVsAmpli11_EBMod4->GetXaxis()->SetRangeUser(MinAmpli, MaxAmpli);
  timeVsAmpli11_EBMod4->SetTitle("Mean Time Vs Amplitude, Crys in EB Module4");

  timeVsAmpli11_EBMod4->SetTitleSize(0.06,"x");
  timeVsAmpli11_EBMod4->SetTitleOffset(1.,"x");
  timeVsAmpli11_EBMod4->SetTitleSize(0.06,"y");
  timeVsAmpli11_EBMod4->SetTitleOffset(1.,"y");

  timeVsAmpli11_EBMod4->SetLineColor(8);
  timeVsAmpli11_EBMod4->SetLineStyle(1);
  timeVsAmpli11_EBMod4->SetMarkerStyle(20);
  timeVsAmpli11_EBMod4->SetMarkerSize(1.);
  timeVsAmpli11_EBMod4->SetMarkerColor(kGreen);
  gPad->SetBottomMargin(0.15);
  gPad->SetLeftMargin(0.15);
  gPad->SetLogx(1);

   gPad->Modified(1);
   c3->SetGridx(1);
   c3->SetGridy(1);
   c3->SetLogx(1);
  //  cd->cd(2);
  // timeVsAmpli10_L->Fit("gaus");

  timeVsAmpli10_EBMod4->GetXaxis()->SetTitle("Amplitude(ADC Counts)");// E =A*0.039(GeV) 4 EB
  timeVsAmpli10_EBMod4->GetYaxis()->SetTitle("Mean Time[ns]");
  timeVsAmpli10_EBMod4->GetYaxis()->SetRangeUser(minMeanTime,maxMeanTime);
  timeVsAmpli10_EBMod4->GetXaxis()->SetRangeUser(MinAmpli, MaxAmpli);
  timeVsAmpli10_EBMod4->SetTitle("Mean Time Vs Amplitude, Crys in EB Module4");

 //  timeVsAmpli10_EBMod4->SetTitleSize(0.06,"x");
//   timeVsAmpli10_EBMod4->SetTitleOffset(1.,"x");
//   timeVsAmpli10_EBMod4->SetTitleSize(0.06,"y");
//   timeVsAmpli10_EBMod4->SetTitleOffset(1.,"y");

  timeVsAmpli10_EBMod4->SetMarkerStyle(20);
  timeVsAmpli10_EBMod4->SetMarkerSize(1.);
  timeVsAmpli10_EBMod4->SetMarkerColor(kBlue);
  timeVsAmpli10_EBMod4->SetLineStyle(1);
  timeVsAmpli10_EBMod4->SetLineColor(4);

//   gPad->SetBottomMargin(0.15);
//   gPad->SetLeftMargin(0.15);
//   gPad->SetLogx(0);
//   gPad->Modified();
  
  
  timeVsAmpli11_EBMod4->Draw("p");
  timeVsAmpli10_EBMod4->Draw("psame");
  
  Leg3->AddEntry(timeVsAmpli10_EBMod4,"Base","p");
  Leg3->AddEntry(timeVsAmpli11_EBMod4, "Corr-Base","p");
  Leg3->Draw();



 
 std::cout << "SigmatimeVsAmpli11_EBMod4 is: " 
          <<  SigmatimeVsAmpli11_EBMod4->GetName() << " and has " 
          << SigmatimeVsAmpli11_EBMod4->GetEntries() << " entries;" 
          << std::endl;
std::cout << "SigmatimeVsAmpli10_EBMod4 is: " 
          <<  SigmatimeVsAmpli10_EBMod4->GetName() << " and has " 
          <<  SigmatimeVsAmpli10_EBMod4->GetEntries() << " entries;" 
          << std::endl;



 TCanvas *c4 = new TCanvas("c4", "SigmatimeVsAmpli_EB_Mod4");
  //TCanvas *c1 = new TCanvas("c1", "c");
TLegend*  Leg4 = new TLegend(0.4,0.7, 0.67,0.85);
 Leg4->SetHeader("Legend");
 Leg4->SetFillColor(0);
 Leg4->SetTextSize(0.04);
 // c->Divide(1,2);
  c4->cd();
  // SigmatimeVsAmpli11_L->Fit("gaus");            //E = A*0.063 (GeV)
  SigmatimeVsAmpli11_EBMod4->GetXaxis()->SetTitle("Amplitude(ADC Counts)");// E =A*0.039(GeV) 4 EB
  SigmatimeVsAmpli11_EBMod4->GetYaxis()->SetTitle("#sigma[ns]");
  SigmatimeVsAmpli11_EBMod4->GetYaxis()->SetRangeUser(MinSigmaTime,MaxSigmaTime);
  SigmatimeVsAmpli11_EBMod4->GetXaxis()->SetRangeUser(MinAmpli, MaxAmpli);
  SigmatimeVsAmpli11_EBMod4->SetTitle("Std Dev Vs Amplitude, Crys in EB Module4");

  SigmatimeVsAmpli11_EBMod4->SetTitleSize(0.06,"x");
  SigmatimeVsAmpli11_EBMod4->SetTitleOffset(1.,"x");
  SigmatimeVsAmpli11_EBMod4->SetTitleSize(0.06,"y");
  SigmatimeVsAmpli11_EBMod4->SetTitleOffset(1.,"y");

  SigmatimeVsAmpli11_EBMod4->SetLineColor(8);
  SigmatimeVsAmpli11_EBMod4->SetLineStyle(1);
  SigmatimeVsAmpli11_EBMod4->SetMarkerStyle(20);
  SigmatimeVsAmpli11_EBMod4->SetMarkerSize(1.);
  SigmatimeVsAmpli11_EBMod4->SetMarkerColor(kGreen);
  gPad->SetBottomMargin(0.15);
  gPad->SetLeftMargin(0.15);
  gPad->SetLogx(1);

   gPad->Modified(1);
   c4->SetGridx(1);
   c4->SetGridy(1);
   c4->SetLogx(1);
  //  cd->cd(2);
  // SigmatimeVsAmpli10_L->Fit("gaus");

  SigmatimeVsAmpli10_EBMod4->GetXaxis()->SetTitle("Amplitude(ADC Counts)");// E =A*0.039(GeV) 4 EB
  SigmatimeVsAmpli10_EBMod4->GetYaxis()->SetTitle("#sigma[ns]");
  SigmatimeVsAmpli10_EBMod4->GetYaxis()->SetRangeUser(MinSigmaTime,MaxSigmaTime);
  SigmatimeVsAmpli10_EBMod4->GetXaxis()->SetRangeUser(MinAmpli, MaxAmpli);
  SigmatimeVsAmpli10_EBMod4->SetTitle("Std Dev Vs Amplitude, Crys in EB Module4");

 //  SigmatimeVsAmpli10_EBMod4->SetTitleSize(0.06,"x");
//   SigmatimeVsAmpli10_EBMod4->SetTitleOffset(1.,"x");
//   SigmatimeVsAmpli10_EBMod4->SetTitleSize(0.06,"y");
//   SigmatimeVsAmpli10_EBMod4->SetTitleOffset(1.,"y");

  SigmatimeVsAmpli10_EBMod4->SetMarkerStyle(20);
  SigmatimeVsAmpli10_EBMod4->SetMarkerSize(1.);
  SigmatimeVsAmpli10_EBMod4->SetMarkerColor(kBlue);
  SigmatimeVsAmpli10_EBMod4->SetLineStyle(1);
  SigmatimeVsAmpli10_EBMod4->SetLineColor(4);

//   gPad->SetBottomMargin(0.15);
//   gPad->SetLeftMargin(0.15);
//   gPad->SetLogx(0);
//   gPad->Modified();
  
  
  SigmatimeVsAmpli11_EBMod4->Draw("p");
  SigmatimeVsAmpli10_EBMod4->Draw("psame");
  
  Leg4->AddEntry(SigmatimeVsAmpli10_EBMod4, "Base","p");
  Leg4->AddEntry(SigmatimeVsAmpli11_EBMod4, "Corr-Base","p");
  Leg4->Draw();




 std::cout << "SigmatimeVsAmpli11_L is: " 
          << SigmatimeVsAmpli11_L->GetName() << " and has " 
          << SigmatimeVsAmpli11_L->GetEntries() << " entries;" 
          << std::endl;
std::cout << "SigmatimeVsAmpli10_L is: " 
          << SigmatimeVsAmpli10_L->GetName() << " and has " 
          << SigmatimeVsAmpli10_L->GetEntries() << " entries;" 
          << std::endl;

TCanvas *c5= new TCanvas("c5", "SigmatimeVsAmpliLowEE");
TLegend*  Leg5 = new TLegend(0.4,0.7, 0.67,0.85);
 Leg5->SetHeader("Legend");
 Leg5->SetFillColor(0);
 Leg5->SetTextSize(0.04);
 // c->Divide(1,2);
  c5->cd();
  // SigmatimeVsAmpli11_L->Fit("gaus");            //E = A*0.063 (GeV)
  SigmatimeVsAmpli11_L->GetXaxis()->SetTitle("Amplitude(ADC counts)");// E =A*0.039(GeV) 4 EB
  SigmatimeVsAmpli11_L->GetYaxis()->SetTitle("#sigma[ns]");
  SigmatimeVsAmpli11_L->GetYaxis()->SetRangeUser(MinSigmaTime,MaxSigmaTime);
  SigmatimeVsAmpli11_L->GetXaxis()->SetRangeUser(MinAmpli, MaxAmpli);
  SigmatimeVsAmpli11_L->SetTitle("Std Dev Vs Amplitude, Crys in EE |#eta|< 2.2");

  SigmatimeVsAmpli11_L->SetTitleSize(0.06,"x");
  SigmatimeVsAmpli11_L->SetTitleOffset(1.,"x");
  SigmatimeVsAmpli11_L->SetTitleSize(0.06,"y");
  SigmatimeVsAmpli11_L->SetTitleOffset(1.,"y");

  SigmatimeVsAmpli11_L->SetLineColor(8);
  SigmatimeVsAmpli11_L->SetLineStyle(1);
  SigmatimeVsAmpli11_L->SetMarkerStyle(20);
  SigmatimeVsAmpli11_L->SetMarkerSize(1.);
  SigmatimeVsAmpli11_L->SetMarkerColor(kGreen);
  gPad->SetBottomMargin(0.15);
  gPad->SetLeftMargin(0.15);
  gPad->SetLogx(1);

   gPad->Modified(1);
   c5->SetGridx(1);
   c5->SetGridy(1);
   c5->SetLogx(1);
  //  cd->cd(2);
  // SigmatimeVsAmpli10_L->Fit("gaus");

  SigmatimeVsAmpli10_L->GetXaxis()->SetTitle("Amplitude(ADC counts)");// E =A*0.039(GeV) 4 EB
  SigmatimeVsAmpli10_L->GetYaxis()->SetTitle("#sigma[ns]");
  SigmatimeVsAmpli10_L->GetYaxis()->SetRangeUser(MinSigmaTime,MaxSigmaTime);
  SigmatimeVsAmpli10_L->GetXaxis()->SetRangeUser(MinAmpli, MaxAmpli);
  SigmatimeVsAmpli10_L->SetTitle("Std Dev Vs Amplitude, Crys in EE |#eta|< 2.2");

 //  SigmatimeVsAmpli10_L->SetTitleSize(0.06,"x");
//   SigmatimeVsAmpli10_L->SetTitleOffset(1.,"x");
//   SigmatimeVsAmpli10_L->SetTitleSize(0.06,"y");
//   SigmatimeVsAmpli10_L->SetTitleOffset(1.,"y");

  SigmatimeVsAmpli10_L->SetMarkerStyle(20);
  SigmatimeVsAmpli10_L->SetMarkerSize(1.);
  SigmatimeVsAmpli10_L->SetMarkerColor(kBlue);
  SigmatimeVsAmpli10_L->SetLineStyle(1);
  SigmatimeVsAmpli10_L->SetLineColor(4);

//   gPad->SetBottomMargin(0.15);
//   gPad->SetLeftMargin(0.15);
//   gPad->SetLogx(0);
//   gPad->Modified();
  
  
  SigmatimeVsAmpli11_L->Draw("p");
  SigmatimeVsAmpli10_L->Draw("psame");
  
  Leg5->AddEntry(SigmatimeVsAmpli10_L,"Base","p");
  Leg5->AddEntry(SigmatimeVsAmpli11_L, "Corr-Base","p");
  Leg5->Draw();



std::cout << " SigmatimeVsAmpli11_H is: " 
          <<  SigmatimeVsAmpli11_H->GetName() << " and has " 
          << SigmatimeVsAmpli11_H->GetEntries() << " entries;" 
          << std::endl;
std::cout << "SigmatimeVsAmpli10_H is: " 
          <<  SigmatimeVsAmpli10_H->GetName() << " and has " 
          <<  SigmatimeVsAmpli10_H->GetEntries() << " entries;" 
          << std::endl;


TCanvas *c6 = new TCanvas("c6", "SigmatimeVsAmpli_HighEE");
TLegend*  Leg6 = new TLegend(0.4,0.7, 0.67,0.85);
 Leg6->SetHeader("Legend");
 Leg6->SetFillColor(0);
 Leg6->SetTextSize(0.04);
 // c->Divide(1,2);
  c6->cd();
  // SigmatimeVsAmpli11_H->Fit("gaus");            //E = A*0.063 (GeV)
  SigmatimeVsAmpli11_H->GetXaxis()->SetTitle("Amplitude(ADC counts)");// E =A*0.039(GeV) 4 EB
  SigmatimeVsAmpli11_H->GetYaxis()->SetTitle("#sigma[ns]");
  SigmatimeVsAmpli11_H->GetYaxis()->SetRangeUser(MinSigmaTime,MaxSigmaTime);
  SigmatimeVsAmpli11_H->GetXaxis()->SetRangeUser(MinAmpli, MaxAmpli);
  SigmatimeVsAmpli11_H->SetTitle("Std Dev Vs Amplitude, Crys in EE |#eta|> 2.2");

  SigmatimeVsAmpli11_H->SetTitleSize(0.06,"x");
  SigmatimeVsAmpli11_H->SetTitleOffset(1.,"x");
  SigmatimeVsAmpli11_H->SetTitleSize(0.06,"y");
  SigmatimeVsAmpli11_H->SetTitleOffset(1.,"y");

  SigmatimeVsAmpli11_H->SetLineColor(8);
  SigmatimeVsAmpli11_H->SetLineStyle(1);
  SigmatimeVsAmpli11_H->SetMarkerStyle(20);
  SigmatimeVsAmpli11_H->SetMarkerSize(1.);
  SigmatimeVsAmpli11_H->SetMarkerColor(kGreen);
  gPad->SetBottomMargin(0.15);
  gPad->SetLeftMargin(0.15);
  gPad->SetLogx(1);

   gPad->Modified(1);
   c6->SetGridx(1);
   c6->SetGridy(1);
   c6->SetLogx(1);
  //  cd->cd(2);
  // SigmatimeVsAmpli10_H->Fit("gaus");

  SigmatimeVsAmpli10_H->GetXaxis()->SetTitle("Amplitude(ADC counts)");// E =A*0.039(GeV) 4 EB
  SigmatimeVsAmpli10_H->GetYaxis()->SetTitle("#sigma[ns]");
  SigmatimeVsAmpli10_H->GetYaxis()->SetRangeUser(MinSigmaTime,MaxSigmaTime);
  SigmatimeVsAmpli10_H->GetXaxis()->SetRangeUser(MinAmpli, MaxAmpli);
  SigmatimeVsAmpli10_H->SetTitle("Std Dev Vs Amplitude, Crys in EE |#eta|> 2.2");

  SigmatimeVsAmpli10_H->SetTitleSize(0.06,"x");
  SigmatimeVsAmpli10_H->SetTitleOffset(1.,"x");
  SigmatimeVsAmpli10_H->SetTitleSize(0.06,"y");
  SigmatimeVsAmpli10_H->SetTitleOffset(1.,"y");

  SigmatimeVsAmpli10_H->SetMarkerStyle(20);
  SigmatimeVsAmpli10_H->SetMarkerSize(1.);
  SigmatimeVsAmpli10_H->SetMarkerColor(kBlue);
  SigmatimeVsAmpli10_H->SetLineStyle(1);
  SigmatimeVsAmpli10_H->SetLineColor(4);

//   gPad->SetBottomMargin(0.15);
//   gPad->SetLeftMargin(0.15);
//   gPad->SetLogx(0);
//   gPad->Modified();
  
  
  SigmatimeVsAmpli11_H->Draw("p");
  SigmatimeVsAmpli10_H->Draw("psame");
  
  Leg6->AddEntry(SigmatimeVsAmpli10_H,"Base","p");
  Leg6->AddEntry(SigmatimeVsAmpli11_H, "Corr-Base","p");
  Leg6->Draw();


std::cout << " timeVsAmpli11_EBMod3 is: " 
          <<  timeVsAmpli11_EBMod3->GetName() << " and has " 
          <<  timeVsAmpli11_EBMod3->GetEntries() << " entries;" 
          << std::endl;
std::cout << " timeVsAmpli10_EBMod3 is: " 
          <<  timeVsAmpli10_EBMod3->GetName() << " and has " 
          <<  timeVsAmpli10_EBMod3->GetEntries() << " entries;" 
          << std::endl;
 

 TCanvas *c7 = new TCanvas("c7", "timeVsAmpli_EB_Mod3");
  //TCanvas *c1 = new TCanvas("c1", "c");
TLegend*  Leg7 = new TLegend(0.3,0.7, 0.67,0.85);
 Leg7->SetHeader("Legend");
 Leg7->SetFillColor(0);
 Leg7->SetTextSize(0.04);
 // c->Divide(1,2);
  c7->cd();
  // timeVsAmpli11_L->Fit("gaus");            //E = A*0.063 (GeV)
  timeVsAmpli11_EBMod3->GetXaxis()->SetTitle("Amplitude(ADC Counts)");// E =A*0.039(GeV) 3 EB
  timeVsAmpli11_EBMod3->GetYaxis()->SetTitle("Mean Time[ns]");
  timeVsAmpli11_EBMod3->GetYaxis()->SetRangeUser(minMeanTime,maxMeanTime);
  timeVsAmpli11_EBMod3->GetXaxis()->SetRangeUser(MinAmpli, MaxAmpli);
  timeVsAmpli11_EBMod3->SetTitle("Mean Time Vs Amplitude, Crys in EB Module3");

  timeVsAmpli11_EBMod3->SetTitleSize(0.06,"x");
  timeVsAmpli11_EBMod3->SetTitleOffset(1.,"x");
  timeVsAmpli11_EBMod3->SetTitleSize(0.06,"y");
  timeVsAmpli11_EBMod3->SetTitleOffset(1.,"y");

  timeVsAmpli11_EBMod3->SetLineColor(8);
  timeVsAmpli11_EBMod3->SetLineStyle(1);
  timeVsAmpli11_EBMod3->SetMarkerStyle(20);
  timeVsAmpli11_EBMod3->SetMarkerSize(1.);
  timeVsAmpli11_EBMod3->SetMarkerColor(kGreen);
  gPad->SetBottomMargin(0.15);
  gPad->SetLeftMargin(0.15);
  gPad->SetLogx(1);

   gPad->Modified(1);
   c7->SetGridx(1);
   c7->SetGridy(1);
   c7->SetLogx(1);
  //  cd->cd(2);
  // timeVsAmpli10_L->Fit("gaus");

  timeVsAmpli10_EBMod3->GetXaxis()->SetTitle("Amplitude(ADC Counts)");// E =A*0.039(GeV) IN EB
  timeVsAmpli10_EBMod3->GetYaxis()->SetTitle("Mean Time[ns]");
  timeVsAmpli10_EBMod3->GetYaxis()->SetRangeUser(minMeanTime,maxMeanTime);
  timeVsAmpli10_EBMod3->GetXaxis()->SetRangeUser(MinAmpli, MaxAmpli);
  timeVsAmpli10_EBMod3->SetTitle("Mean Time Vs Amplitude, Crys in EB Module3");

  timeVsAmpli10_EBMod3->SetTitleSize(0.06,"x");
  timeVsAmpli10_EBMod3->SetTitleOffset(1.,"x");
  timeVsAmpli10_EBMod3->SetTitleSize(0.06,"y");
  timeVsAmpli10_EBMod3->SetTitleOffset(1.,"y");

  timeVsAmpli10_EBMod3->SetMarkerStyle(20);
  timeVsAmpli10_EBMod3->SetMarkerSize(1.);
  timeVsAmpli10_EBMod3->SetMarkerColor(kBlue);
  timeVsAmpli10_EBMod3->SetLineStyle(1);
  timeVsAmpli10_EBMod3->SetLineColor(3);

//   gPad->SetBottomMargin(0.15);
//   gPad->SetLeftMargin(0.15);
//   gPad->SetLogx(0);
//   gPad->Modified();
  
  
  timeVsAmpli11_EBMod3->Draw("p");
  timeVsAmpli10_EBMod3->Draw("psame");
  
  Leg7->AddEntry(timeVsAmpli10_EBMod3,"Base","p");
  Leg7->AddEntry(timeVsAmpli11_EBMod3, "Corr-Base","p");
  Leg7->Draw();



std::cout << " SigmatimeVsAmpli11_EBMod3 is: " 
          <<  SigmatimeVsAmpli11_EBMod3->GetName() << " and has " 
          << SigmatimeVsAmpli11_EBMod3->GetEntries() << " entries;" 
          << std::endl;
std::cout << "SigmatimeVsAmpli10_EBMod3 is: " 
          <<  SigmatimeVsAmpli10_EBMod3->GetName() << " and has " 
          <<  SigmatimeVsAmpli10_EBMod3->GetEntries() << " entries;" 
          << std::endl;



 TCanvas *c8 = new TCanvas("c8", "SigmatimeVsAmpli_EB_Mod3");
  //TCanvas *c1 = new TCanvas("c1", "c");
TLegend*  Leg8 = new TLegend(0.3,0.7, 0.67,0.85);
 Leg8->SetHeader("Legend");
 Leg8->SetFillColor(0);
 Leg8->SetTextSize(0.04);
 // c->Divide(1,2);
  c8->cd();
  // SigmatimeVsAmpli11_L->Fit("gaus");            //E = A*0.063 (GeV)
  SigmatimeVsAmpli11_EBMod3->GetXaxis()->SetTitle("Amplitude(ADC Counts)");// E =A*0.039(GeV) 3 EB
  SigmatimeVsAmpli11_EBMod3->GetYaxis()->SetTitle("#sigma[ns]");
  SigmatimeVsAmpli11_EBMod3->GetYaxis()->SetRangeUser(MinSigmaTime,MaxSigmaTime);
  SigmatimeVsAmpli11_EBMod3->GetXaxis()->SetRangeUser(MinAmpli, MaxAmpli);
  SigmatimeVsAmpli11_EBMod3->SetTitle("Std Dev Vs Amplitude, Crys in EB Module3");

  SigmatimeVsAmpli11_EBMod3->SetTitleSize(0.06,"x");
  SigmatimeVsAmpli11_EBMod3->SetTitleOffset(1.,"x");
  SigmatimeVsAmpli11_EBMod3->SetTitleSize(0.06,"y");
  SigmatimeVsAmpli11_EBMod3->SetTitleOffset(1.,"y");

  SigmatimeVsAmpli11_EBMod3->SetLineColor(8);
  SigmatimeVsAmpli11_EBMod3->SetLineStyle(1);
  SigmatimeVsAmpli11_EBMod3->SetMarkerStyle(20);
  SigmatimeVsAmpli11_EBMod3->SetMarkerSize(1.);
  SigmatimeVsAmpli11_EBMod3->SetMarkerColor(kGreen);
  gPad->SetBottomMargin(0.15);
  gPad->SetLeftMargin(0.15);
  gPad->SetLogx(1);

   gPad->Modified(1);
   c8->SetGridx(1);
   c8->SetGridy(1);
   c8->SetLogx(1);
  //  cd->cd(2);
  // SigmatimeVsAmpli10_L->Fit("gaus");

  SigmatimeVsAmpli10_EBMod3->GetXaxis()->SetTitle("Amplitude(ADC Counts)");// E =A*0.039(GeV) IN EB
  SigmatimeVsAmpli10_EBMod3->GetYaxis()->SetTitle("#sigma[ns]");
  SigmatimeVsAmpli10_EBMod3->GetYaxis()->SetRangeUser(MinSigmaTime,MaxSigmaTime);
  SigmatimeVsAmpli10_EBMod3->GetXaxis()->SetRangeUser(MinAmpli, MaxAmpli);
  SigmatimeVsAmpli10_EBMod3->SetTitle("Std Dev Vs Amplitude, Crys in EB Module3");

  SigmatimeVsAmpli10_EBMod3->SetTitleSize(0.06,"x");
  SigmatimeVsAmpli10_EBMod3->SetTitleOffset(1.,"x");
  SigmatimeVsAmpli10_EBMod3->SetTitleSize(0.06,"y");
  SigmatimeVsAmpli10_EBMod3->SetTitleOffset(1.,"y");

  SigmatimeVsAmpli10_EBMod3->SetMarkerStyle(20);
  SigmatimeVsAmpli10_EBMod3->SetMarkerSize(1.);
  SigmatimeVsAmpli10_EBMod3->SetMarkerColor(kBlue);
  SigmatimeVsAmpli10_EBMod3->SetLineStyle(1);
  SigmatimeVsAmpli10_EBMod3->SetLineColor(3);

//   gPad->SetBottomMargin(0.15);
//   gPad->SetLeftMargin(0.15);
//   gPad->SetLogx(0);
//   gPad->Modified();
  
  
  SigmatimeVsAmpli11_EBMod3->Draw("p");
  SigmatimeVsAmpli10_EBMod3->Draw("psame");
  
  Leg8->AddEntry(SigmatimeVsAmpli10_EBMod3, "Base","p");
  Leg8->AddEntry(SigmatimeVsAmpli11_EBMod3, "Corr-Base","p");
  Leg8->Draw();




std::cout << " timeVsAmpli11_EBMod2 is: " 
          <<  timeVsAmpli11_EBMod2->GetName() << " and has " 
          <<  timeVsAmpli11_EBMod2->GetEntries() << " entries;" 
          << std::endl;
std::cout << " timeVsAmpli10_EBMod2 is: " 
          <<  timeVsAmpli10_EBMod2->GetName() << " and has " 
          <<  timeVsAmpli10_EBMod2->GetEntries() << " entries;" 
          << std::endl;



 TCanvas *c9 = new TCanvas("c9", "timeVsAmpli_EB_Mod2");
  //TCanvas *c1 = new TCanvas("c1", "c");
TLegend*  Leg9 = new TLegend(0.2,0.7, 0.67,0.85);
 Leg9->SetHeader("Legend");
 Leg9->SetFillColor(0);
 Leg9->SetTextSize(0.04);
 // c->Divide(1,2);
  c9->cd();
  // timeVsAmpli11_L->Fit("gaus");            //E = A*0.062 (GeV)
  timeVsAmpli11_EBMod2->GetXaxis()->SetTitle("Amplitude(ADC Counts)");// E =A*0.039(GeV) IN EB
  timeVsAmpli11_EBMod2->GetYaxis()->SetTitle("Mean Time[ns]");
  timeVsAmpli11_EBMod2->GetYaxis()->SetRangeUser(minMeanTime,maxMeanTime);
  timeVsAmpli11_EBMod2->GetXaxis()->SetRangeUser(MinAmpli, MaxAmpli);
  timeVsAmpli11_EBMod2->SetTitle("Mean Time Vs Amplitude, Crys in EB Module2");

  timeVsAmpli11_EBMod2->SetTitleSize(0.06,"x");
  timeVsAmpli11_EBMod2->SetTitleOffset(1.,"x");
  timeVsAmpli11_EBMod2->SetTitleSize(0.06,"y");
  timeVsAmpli11_EBMod2->SetTitleOffset(1.,"y");

  timeVsAmpli11_EBMod2->SetLineColor(8);
  timeVsAmpli11_EBMod2->SetLineStyle(1);
  timeVsAmpli11_EBMod2->SetMarkerStyle(20);
  timeVsAmpli11_EBMod2->SetMarkerSize(1.);
  timeVsAmpli11_EBMod2->SetMarkerColor(kGreen);
  gPad->SetBottomMargin(0.15);
  gPad->SetLeftMargin(0.15);
  gPad->SetLogx(1);

   gPad->Modified(1);
   c9->SetGridx(1);
   c9->SetGridy(1);
   c9->SetLogx(1);
  //  cd->cd(2);
  // timeVsAmpli10_L->Fit("gaus");

  timeVsAmpli10_EBMod2->GetXaxis()->SetTitle("Amplitude(ADC Counts)");// E =A*0.039(GeV) IN EB
  timeVsAmpli10_EBMod2->GetYaxis()->SetTitle("Mean Time[ns]");
  timeVsAmpli10_EBMod2->GetYaxis()->SetRangeUser(minMeanTime,maxMeanTime);
  timeVsAmpli10_EBMod2->GetXaxis()->SetRangeUser(MinAmpli, MaxAmpli);
  timeVsAmpli10_EBMod2->SetTitle("Mean Time Vs Amplitude, Cry in EB Module2");

  timeVsAmpli10_EBMod2->SetTitleSize(0.06,"x");
  timeVsAmpli10_EBMod2->SetTitleOffset(1.,"x");
  timeVsAmpli10_EBMod2->SetTitleSize(0.06,"y");
  timeVsAmpli10_EBMod2->SetTitleOffset(1.,"y");

  timeVsAmpli10_EBMod2->SetMarkerStyle(20);
  timeVsAmpli10_EBMod2->SetMarkerSize(1.);
  timeVsAmpli10_EBMod2->SetMarkerColor(kBlue);
  timeVsAmpli10_EBMod2->SetLineStyle(1);
  timeVsAmpli10_EBMod2->SetLineColor(2);

//   gPad->SetBottomMargin(0.15);
//   gPad->SetLeftMargin(0.15);
//   gPad->SetLogx(0);
//   gPad->Modified();
  
  
  timeVsAmpli11_EBMod2->Draw("p");
  timeVsAmpli10_EBMod2->Draw("psame");
  
  Leg9->AddEntry(timeVsAmpli10_EBMod2,"Base","p");
  Leg9->AddEntry(timeVsAmpli11_EBMod2, "Corr-Base","p");
  Leg9->Draw();


std::cout << " SigmatimeVsAmpli11_EBMod2 is: " 
          <<  SigmatimeVsAmpli11_EBMod2->GetName() << " and has " 
          << SigmatimeVsAmpli11_EBMod2->GetEntries() << " entries;" 
          << std::endl;
std::cout << "SigmatimeVsAmpli10_EBMod2 is: " 
          <<  SigmatimeVsAmpli10_EBMod2->GetName() << " and has " 
          <<  SigmatimeVsAmpli10_EBMod2->GetEntries() << " entries;" 
          << std::endl;


 TCanvas *c10 = new TCanvas("c10", "SigmatimeVsAmpli_EB_Mod2");
  //TCanvas *c1 = new TCanvas("c1", "c");
TLegend*  Leg10 = new TLegend(0.2,0.7, 0.67,0.85);
 Leg10->SetHeader("Legend");
 Leg10->SetFillColor(0);
 Leg10->SetTextSize(0.04);
 // c->Divide(1,2);
  c10->cd();
  // SigmatimeVsAmpli11_L->Fit("gaus");            //E = A*0.063 (GeV)
  SigmatimeVsAmpli11_EBMod2->GetXaxis()->SetTitle("Amplitude(ADC Counts)");// E =A*0.039(GeV) IN EB
  SigmatimeVsAmpli11_EBMod2->GetYaxis()->SetTitle("#sigma[ns]");
  SigmatimeVsAmpli11_EBMod2->GetYaxis()->SetRangeUser(MinSigmaTime,MaxSigmaTime);
  SigmatimeVsAmpli11_EBMod2->GetXaxis()->SetRangeUser(MinAmpli, MaxAmpli);
  SigmatimeVsAmpli11_EBMod2->SetTitle("Std Dev Vs Amplitude, Crys in EB Module2");

  SigmatimeVsAmpli11_EBMod2->SetTitleSize(0.06,"x");
  SigmatimeVsAmpli11_EBMod2->SetTitleOffset(1.,"x");
  SigmatimeVsAmpli11_EBMod2->SetTitleSize(0.06,"y");
  SigmatimeVsAmpli11_EBMod2->SetTitleOffset(1.,"y");

  SigmatimeVsAmpli11_EBMod2->SetLineColor(8);
  SigmatimeVsAmpli11_EBMod2->SetLineStyle(1);
  SigmatimeVsAmpli11_EBMod2->SetMarkerStyle(20);
  SigmatimeVsAmpli11_EBMod2->SetMarkerSize(1.);
  SigmatimeVsAmpli11_EBMod2->SetMarkerColor(kGreen);
  gPad->SetBottomMargin(0.15);
  gPad->SetLeftMargin(0.15);
  gPad->SetLogx(1);

   gPad->Modified(1);
   c10->SetGridx(1);
   c10->SetGridy(1);
   c10->SetLogx(1);
  //  cd->cd(2);
  // SigmatimeVsAmpli10_L->Fit("gaus");

  SigmatimeVsAmpli10_EBMod2->GetXaxis()->SetTitle("Amplitude(ADC Counts)");// E =A*0.039(GeV) IN EB
  SigmatimeVsAmpli10_EBMod2->GetYaxis()->SetTitle("#sigma[ns]");
  SigmatimeVsAmpli10_EBMod2->GetYaxis()->SetRangeUser(MinSigmaTime,MaxSigmaTime);
  SigmatimeVsAmpli10_EBMod2->GetXaxis()->SetRangeUser(MinAmpli, MaxAmpli);
  SigmatimeVsAmpli10_EBMod2->SetTitle("Std Dev Vs Amplitude, Crys in EB Module2");

 //  SigmatimeVsAmpli10_EBMod2->SetTitleSize(0.06,"x");
//   SigmatimeVsAmpli10_EBMod2->SetTitleOffset(1.,"x");
//   SigmatimeVsAmpli10_EBMod2->SetTitleSize(0.06,"y");
//   SigmatimeVsAmpli10_EBMod2->SetTitleOffset(1.,"y");

  SigmatimeVsAmpli10_EBMod2->SetMarkerStyle(20);
  SigmatimeVsAmpli10_EBMod2->SetMarkerSize(1.);
  SigmatimeVsAmpli10_EBMod2->SetMarkerColor(kBlue);
  SigmatimeVsAmpli10_EBMod2->SetLineStyle(1);
  SigmatimeVsAmpli10_EBMod2->SetLineColor(2);

//   gPad->SetBottomMargin(0.15);
//   gPad->SetLeftMargin(0.15);
//   gPad->SetLogx(0);
//   gPad->Modified();
  
  
  SigmatimeVsAmpli11_EBMod2->Draw("p");
  SigmatimeVsAmpli10_EBMod2->Draw("psame");
  
  Leg10->AddEntry(SigmatimeVsAmpli10_EBMod2, "Base","p");
  Leg10->AddEntry(SigmatimeVsAmpli11_EBMod2, "Corr-Base","p");
  Leg10->Draw();


std::cout << " timeVsAmpli11_EBMod1 is: " 
          <<  timeVsAmpli11_EBMod1->GetName() << " and has " 
          <<  timeVsAmpli11_EBMod1->GetEntries() << " entries;" 
          << std::endl;
std::cout << " timeVsAmpli10_EBMod1 is: " 
          <<  timeVsAmpli10_EBMod1->GetName() << " and has " 
          <<  timeVsAmpli10_EBMod1->GetEntries() << " entries;" 
          << std::endl;

 TCanvas *c11 = new TCanvas("c11", "timeVsAmpli_EB_Mod1");
  //TCanvas *c1 = new TCanvas("c1", "c");
TLegend*  Leg11 = new TLegend(0.1,0.7, 0.67,0.85);
 Leg11->SetHeader("Legend");
 Leg11->SetFillColor(0);
 Leg11->SetTextSize(0.04);
 // c->Divide(1,2);
  c11->cd();
  // timeVsAmpli11_L->Fit("gaus");            //E = A*0.063 (GeV)
  timeVsAmpli11_EBMod1->GetXaxis()->SetTitle("Amplitude(ADC Counts)");// E =A*0.039(GeV) IN EB
  timeVsAmpli11_EBMod1->GetYaxis()->SetTitle("Mean Time[ns]");
  timeVsAmpli11_EBMod1->GetYaxis()->SetRangeUser(minMeanTime,maxMeanTime);
  timeVsAmpli11_EBMod1->GetXaxis()->SetRangeUser(MinAmpli, MaxAmpli);
  timeVsAmpli11_EBMod1->SetTitle("Mean Time Vs Amplitude, Crys in EB Module1");

  timeVsAmpli11_EBMod1->SetTitleSize(0.06,"x");
  timeVsAmpli11_EBMod1->SetTitleOffset(1.,"x");
  timeVsAmpli11_EBMod1->SetTitleSize(0.06,"y");
  timeVsAmpli11_EBMod1->SetTitleOffset(1.,"y");

  timeVsAmpli11_EBMod1->SetLineColor(8);
  timeVsAmpli11_EBMod1->SetLineStyle(1);
  timeVsAmpli11_EBMod1->SetMarkerStyle(20);
  timeVsAmpli11_EBMod1->SetMarkerSize(1.);
  timeVsAmpli11_EBMod1->SetMarkerColor(kGreen);
  gPad->SetBottomMargin(0.15);
  gPad->SetLeftMargin(0.15);
  gPad->SetLogx(1);

   gPad->Modified(1);
   c11->SetGridx(1);
   c11->SetGridy(1);
   c11->SetLogx(1);
  //  cd->cd(2);
  // timeVsAmpli10_L->Fit("gaus");

  timeVsAmpli10_EBMod1->GetXaxis()->SetTitle("Amplitude(ADC Counts)");// E =A*0.039(GeV) IN EB
  timeVsAmpli10_EBMod1->GetYaxis()->SetTitle("Mean Time[ns]");
  timeVsAmpli10_EBMod1->GetYaxis()->SetRangeUser(minMeanTime,maxMeanTime);
  timeVsAmpli10_EBMod1->GetXaxis()->SetRangeUser(MinAmpli, MaxAmpli);
  timeVsAmpli10_EBMod1->SetTitle("Mean Time Vs Amplitude, Cry in EB Module1");

  timeVsAmpli10_EBMod1->SetTitleSize(0.06,"x");
  timeVsAmpli10_EBMod1->SetTitleOffset(1.,"x");
  timeVsAmpli10_EBMod1->SetTitleSize(0.06,"y");
  timeVsAmpli10_EBMod1->SetTitleOffset(1.,"y");

  timeVsAmpli10_EBMod1->SetMarkerStyle(20);
  timeVsAmpli10_EBMod1->SetMarkerSize(1.);
  timeVsAmpli10_EBMod1->SetMarkerColor(kBlue);
  timeVsAmpli10_EBMod1->SetLineStyle(1);
  timeVsAmpli10_EBMod1->SetLineColor(1);

//   gPad->SetBottomMargin(0.15);
//   gPad->SetLeftMargin(0.15);
//   gPad->SetLogx(0);
//   gPad->Modified();
  
  
  timeVsAmpli11_EBMod1->Draw("p");
  timeVsAmpli10_EBMod1->Draw("psame");
  
  Leg11->AddEntry(timeVsAmpli10_EBMod1,"Base","p");
  Leg11->AddEntry(timeVsAmpli11_EBMod1, "Corr-Base","p");
  Leg11->Draw();



std::cout << " SigmatimeVsAmpli11_EBMod1 is: " 
          <<  SigmatimeVsAmpli11_EBMod1->GetName() << " and has " 
          << SigmatimeVsAmpli11_EBMod1->GetEntries() << " entries;" 
          << std::endl;
std::cout << "SigmatimeVsAmpli10_EBMod1 is: " 
          <<  SigmatimeVsAmpli10_EBMod1->GetName() << " and has " 
          <<  SigmatimeVsAmpli10_EBMod1->GetEntries() << " entries;" 
          << std::endl;

 TCanvas *c12 = new TCanvas("c12", "SigmatimeVsAmpli_EB_Mod1");
  //TCanvas *c1 = new TCanvas("c1", "c");
TLegend*  Leg12 = new TLegend(0.1,0.7, 0.67,0.85);
 Leg12->SetHeader("Legend");
 Leg12->SetFillColor(0);
 Leg12->SetTextSize(0.04);
 // c->Divide(1,2);
  c12->cd();
  // SigmatimeVsAmpli11_L->Fit("gaus");            //E = A*0.063 (GeV)
  SigmatimeVsAmpli11_EBMod1->GetXaxis()->SetTitle("Amplitude(ADC Counts)");// E =A*0.039(GeV) IN EB
  SigmatimeVsAmpli11_EBMod1->GetYaxis()->SetTitle("#sigma[ns]");
  SigmatimeVsAmpli11_EBMod1->GetYaxis()->SetRangeUser(MinSigmaTime,MaxSigmaTime);
  SigmatimeVsAmpli11_EBMod1->GetXaxis()->SetRangeUser(MinAmpli, MaxAmpli);
  SigmatimeVsAmpli11_EBMod1->SetTitle("Std Dev Vs Amplitude, Crys in EB Module1");

  SigmatimeVsAmpli11_EBMod1->SetTitleSize(0.06,"x");
  SigmatimeVsAmpli11_EBMod1->SetTitleOffset(1.,"x");
  SigmatimeVsAmpli11_EBMod1->SetTitleSize(0.06,"y");
  SigmatimeVsAmpli11_EBMod1->SetTitleOffset(1.,"y");

  SigmatimeVsAmpli11_EBMod1->SetLineColor(8);
  SigmatimeVsAmpli11_EBMod1->SetLineStyle(1);
  SigmatimeVsAmpli11_EBMod1->SetMarkerStyle(20);
  SigmatimeVsAmpli11_EBMod1->SetMarkerSize(1.);
  SigmatimeVsAmpli11_EBMod1->SetMarkerColor(kGreen);
  gPad->SetBottomMargin(0.15);
  gPad->SetLeftMargin(0.15);
  gPad->SetLogx(1);

   gPad->Modified(1);
   c12->SetGridx(1);
   c12->SetGridy(1);
   c12->SetLogx(1);
  //  cd->cd(2);
  // SigmatimeVsAmpli10_L->Fit("gaus");

  SigmatimeVsAmpli10_EBMod1->GetXaxis()->SetTitle("Amplitude(ADC Counts)");// E =A*0.039(GeV) IN EB
  SigmatimeVsAmpli10_EBMod1->GetYaxis()->SetTitle("#sigma[ns]");
  SigmatimeVsAmpli10_EBMod1->GetYaxis()->SetRangeUser(MinSigmaTime,MaxSigmaTime);
  SigmatimeVsAmpli10_EBMod1->GetXaxis()->SetRangeUser(MinAmpli, MaxAmpli);
  SigmatimeVsAmpli10_EBMod1->SetTitle("Std Dev Vs Amplitude, Crys in EB Module1");

  SigmatimeVsAmpli10_EBMod1->SetTitleSize(0.06,"x");
  SigmatimeVsAmpli10_EBMod1->SetTitleOffset(1.,"x");
  SigmatimeVsAmpli10_EBMod1->SetTitleSize(0.06,"y");
  SigmatimeVsAmpli10_EBMod1->SetTitleOffset(1.,"y");

  SigmatimeVsAmpli10_EBMod1->SetMarkerStyle(20);
  SigmatimeVsAmpli10_EBMod1->SetMarkerSize(1.);
  SigmatimeVsAmpli10_EBMod1->SetMarkerColor(kBlue);
  SigmatimeVsAmpli10_EBMod1->SetLineStyle(1);
  SigmatimeVsAmpli10_EBMod1->SetLineColor(1);

//   gPad->SetBottomMargin(0.15);
//   gPad->SetLeftMargin(0.15);
//   gPad->SetLogx(0);
//   gPad->Modified();
  
  
  SigmatimeVsAmpli11_EBMod1->Draw("p");
  SigmatimeVsAmpli10_EBMod1->Draw("psame");
  
  Leg12->AddEntry(SigmatimeVsAmpli10_EBMod1, "Base","p");
  Leg12->AddEntry(SigmatimeVsAmpli11_EBMod1, "Corr-Base","p");
  Leg12->Draw();

  
  //  gPad->Print("Tming Resolution.png");
  //  c->SaveAs("TimingResolution.png");
  //f11->Close();
  //f10->Close();


std::cout << " timeVsAmpli11_EB is: " 
          <<  timeVsAmpli11_EB->GetName() << " and has " 
          <<  timeVsAmpli11_EB->GetEntries() << " entries;" 
          << std::endl;
std::cout << " timeVsAmpli10_EB is: " 
          <<  timeVsAmpli10_EB->GetName() << " and has " 
          <<  timeVsAmpli10_EB->GetEntries() << " entries;" 
          << std::endl;


 TCanvas *c13 = new TCanvas("c13", "timeVsAmpli_EB");
  //TCanvas *c1 = new TCanvas("c1", "c");
TLegend*  Leg13 = new TLegend(0.4,0.7, 0.67,0.85);
 Leg13->SetHeader("Legend");
 Leg13->SetFillColor(0);
 Leg13->SetTextSize(0.04);
 // c->Divide(1,2);
  c13->cd();
  // timeVsAmpli11_L->Fit("gaus");            //E = A*0.063 (GeV)
  timeVsAmpli11_EB->GetXaxis()->SetTitle("Amplitude(ADC Counts)");// E =A*0.039(GeV) 4 EB
  timeVsAmpli11_EB->GetYaxis()->SetTitle("Mean Time[ns]");
  timeVsAmpli11_EB->GetYaxis()->SetRangeUser(minMeanTime,maxMeanTime);
  timeVsAmpli11_EB->GetXaxis()->SetRangeUser(MinAmpli, MaxAmpli);
  timeVsAmpli11_EB->SetTitle("Mean Time Vs Amplitude, Crys in EB");

  timeVsAmpli11_EB->SetTitleSize(0.06,"x");
  timeVsAmpli11_EB->SetTitleOffset(1.,"x");
  timeVsAmpli11_EB->SetTitleSize(0.06,"y");
  timeVsAmpli11_EB->SetTitleOffset(1.,"y");

  timeVsAmpli11_EB->SetLineColor(8);
  timeVsAmpli11_EB->SetLineStyle(1);
  timeVsAmpli11_EB->SetMarkerStyle(20);
  timeVsAmpli11_EB->SetMarkerSize(1.);
  timeVsAmpli11_EB->SetMarkerColor(kGreen);
  gPad->SetBottomMargin(0.15);
  gPad->SetLeftMargin(0.15);
  gPad->SetLogx(1);

   gPad->Modified(1);
   c13->SetGridx(1);
   c13->SetGridy(1);
   c13->SetLogx(1);
  //  cd->cd(2);
  // timeVsAmpli10_EB->Fit("gaus");

  timeVsAmpli10_EB->GetXaxis()->SetTitle("Amplitude(ADC Counts)");// E =A*0.039(GeV) 4 EB
  timeVsAmpli10_EB->GetYaxis()->SetTitle("Mean Time[ns]");
  timeVsAmpli10_EB->GetYaxis()->SetRangeUser(minMeanTime,maxMeanTime);
  timeVsAmpli10_EB->GetXaxis()->SetRangeUser(MinAmpli, MaxAmpli);
  timeVsAmpli10_EB->SetTitle("Mean Time Vs Amplitude, Crys in EB");

 //  timeVsAmpli10_EB->SetTitleSize(0.06,"x");
//   timeVsAmpli10_EB->SetTitleOffset(1.,"x");
//   timeVsAmpli10_EB->SetTitleSize(0.06,"y");
//   timeVsAmpli10_EB->SetTitleOffset(1.,"y");

  timeVsAmpli10_EB->SetMarkerStyle(20);
  timeVsAmpli10_EB->SetMarkerSize(1.);
  timeVsAmpli10_EB->SetMarkerColor(kBlue);
  timeVsAmpli10_EB->SetLineStyle(1);
  timeVsAmpli10_EB->SetLineColor(4);

//   gPad->SetBottomMargin(0.15);
//   gPad->SetLeftMargin(0.15);
//   gPad->SetLogx(0);
//   gPad->Modified();
  
  
  timeVsAmpli11_EB->Draw("p");
  timeVsAmpli10_EB->Draw("psame");
  
  Leg13->AddEntry(timeVsAmpli10_EB,"Base","p");
  Leg13->AddEntry(timeVsAmpli11_EB, "Corr-Base","p");
  Leg13->Draw();



 
 std::cout << "SigmatimeVsAmpli11_EB is: " 
          <<  SigmatimeVsAmpli11_EB->GetName() << " and has " 
          << SigmatimeVsAmpli11_EB->GetEntries() << " entries;" 
          << std::endl;
std::cout << "SigmatimeVsAmpli10_EB is: " 
          <<  SigmatimeVsAmpli10_EB->GetName() << " and has " 
          <<  SigmatimeVsAmpli10_EB->GetEntries() << " entries;" 
          << std::endl;



 TCanvas *c14 = new TCanvas("c14", "SigmatimeVsAmpli_EB");
  //TCanvas *c1 = new TCanvas("c1", "c");
TLegend*  Leg14 = new TLegend(0.4,0.7, 0.67,0.85);
 Leg14->SetHeader("Legend");
 Leg14->SetFillColor(0);
 Leg14->SetTextSize(0.04);
 // c->Divide(1,2);
  c14->cd();
  // SigmatimeVsAmpli11_EB->Fit("gaus");            //E = A*0.063 (GeV)
  SigmatimeVsAmpli11_EB->GetXaxis()->SetTitle("Amplitude(ADC Counts)");// E =A*0.039(GeV) 4 EB
  SigmatimeVsAmpli11_EB->GetYaxis()->SetTitle("#sigma[ns]");
  SigmatimeVsAmpli11_EB->GetYaxis()->SetRangeUser(MinSigmaTime,MaxSigmaTime);
  SigmatimeVsAmpli11_EB->GetXaxis()->SetRangeUser(MinAmpli, MaxAmpli);
  SigmatimeVsAmpli11_EB->SetTitle("Std Dev Vs Amplitude, Crys in EB");

  SigmatimeVsAmpli11_EB->SetTitleSize(0.06,"x");
  SigmatimeVsAmpli11_EB->SetTitleOffset(1.,"x");
  SigmatimeVsAmpli11_EB->SetTitleSize(0.06,"y");
  SigmatimeVsAmpli11_EB->SetTitleOffset(1.,"y");

  SigmatimeVsAmpli11_EB->SetLineColor(8);
  SigmatimeVsAmpli11_EB->SetLineStyle(1);
  SigmatimeVsAmpli11_EB->SetMarkerStyle(20);
  SigmatimeVsAmpli11_EB->SetMarkerSize(1.);
  SigmatimeVsAmpli11_EB->SetMarkerColor(kGreen);
  gPad->SetBottomMargin(0.15);
  gPad->SetLeftMargin(0.15);
  gPad->SetLogx(1);

   gPad->Modified(1);
   c14->SetGridx(1);
   c14->SetGridy(1);
   c14->SetLogx(1);
  //  cd->cd(2);
  // SigmatimeVsAmpli10_EB->Fit("gaus");

  SigmatimeVsAmpli10_EB->GetXaxis()->SetTitle("Amplitude(ADC Counts)");// E =A*0.039(GeV) 4 EB
  SigmatimeVsAmpli10_EB->GetYaxis()->SetTitle("#sigma[ns]");
  SigmatimeVsAmpli10_EB->GetYaxis()->SetRangeUser(MinSigmaTime,MaxSigmaTime);
  SigmatimeVsAmpli10_EB->GetXaxis()->SetRangeUser(MinAmpli, MaxAmpli);
  SigmatimeVsAmpli10_EB->SetTitle("Std Dev Vs Amplitude, Crys in EB");

 //  SigmatimeVsAmpli10_EB->SetTitleSize(0.06,"x");
//   SigmatimeVsAmpli10_EB->SetTitleOffset(1.,"x");
//   SigmatimeVsAmpli10_EB->SetTitleSize(0.06,"y");
//   SigmatimeVsAmpli10_EB->SetTitleOffset(1.,"y");

  SigmatimeVsAmpli10_EB->SetMarkerStyle(20);
  SigmatimeVsAmpli10_EB->SetMarkerSize(1.);
  SigmatimeVsAmpli10_EB->SetMarkerColor(kBlue);
  SigmatimeVsAmpli10_EB->SetLineStyle(1);
  SigmatimeVsAmpli10_EB->SetLineColor(4);

//   gPad->SetBottomMargin(0.15);
//   gPad->SetLeftMargin(0.15);
//   gPad->SetLogx(0);
//   gPad->Modified();
  
  
  SigmatimeVsAmpli11_EB->Draw("p");
  SigmatimeVsAmpli10_EB->Draw("psame");
  
  Leg14->AddEntry(SigmatimeVsAmpli10_EB, "Base","p");
  Leg14->AddEntry(SigmatimeVsAmpli11_EB, "Corr-Base","p");
  Leg14->Draw();



std::cout << " timeVsAmpli11_EE is: " 
          <<  timeVsAmpli11_EE->GetName() << " and has " 
          <<  timeVsAmpli11_EE->GetEntries() << " entries;" 
          << std::endl;
std::cout << " timeVsAmpli10_EE is: " 
          <<  timeVsAmpli10_EE->GetName() << " and has " 
          <<  timeVsAmpli10_EE->GetEntries() << " entries;" 
          << std::endl;


 TCanvas *c15 = new TCanvas("c15", "timeVsAmpli_EE");
  //TCanvas *c1 = new TCanvas("c1", "c");
TLegend*  Leg15 = new TLegend(0.4,0.7, 0.67,0.85);
 Leg15->SetHeader("Legend");
 Leg15->SetFillColor(0);
 Leg15->SetTextSize(0.04);
 // c->Divide(1,2);
  c15->cd();
  // timeVsAmpli11_L->Fit("gaus");            //E = A*0.063 (GeV)
  timeVsAmpli11_EE->GetXaxis()->SetTitle("Amplitude(ADC counts)");// E =A*0.039(GeV) 4 EB
  timeVsAmpli11_EE->GetYaxis()->SetTitle("Mean Time[ns]");
  timeVsAmpli11_EE->GetYaxis()->SetRangeUser(minMeanTime,maxMeanTime);
  timeVsAmpli11_EE->GetXaxis()->SetRangeUser(MinAmpli, MaxAmpli);
  timeVsAmpli11_EE->SetTitle("Mean Time Vs Amplitude, Crys in EE");

  timeVsAmpli11_EE->SetTitleSize(0.06,"x");
  timeVsAmpli11_EE->SetTitleOffset(1.,"x");
  timeVsAmpli11_EE->SetTitleSize(0.06,"y");
  timeVsAmpli11_EE->SetTitleOffset(1.,"y");

  timeVsAmpli11_EE->SetLineColor(8);
  timeVsAmpli11_EE->SetLineStyle(1);
  timeVsAmpli11_EE->SetMarkerStyle(20);
  timeVsAmpli11_EE->SetMarkerSize(1.);
  timeVsAmpli11_EE->SetMarkerColor(kGreen);
  gPad->SetBottomMargin(0.15);
  gPad->SetLeftMargin(0.15);
  gPad->SetLogx(1);

   gPad->Modified(1);
   c15->SetGridx(1);
   c15->SetGridy(1);
   c15->SetLogx(1);
  //  cd->cd(2);
  // timeVsAmpli10_EE->Fit("gaus");

  timeVsAmpli10_EE->GetXaxis()->SetTitle("Amplitude(ADC counts)");// E =A*0.039(GeV) 4 EB
  timeVsAmpli10_EE->GetYaxis()->SetTitle("Mean Time[ns]");
  timeVsAmpli10_EE->GetYaxis()->SetRangeUser(minMeanTime,maxMeanTime);
  timeVsAmpli10_EE->GetXaxis()->SetRangeUser(MinAmpli, MaxAmpli);
  timeVsAmpli10_EE->SetTitle("Mean Time Vs Amplitude, Crys in EE");

 //  timeVsAmpli10_EE->SetTitleSize(0.06,"x");
//   timeVsAmpli10_EE->SetTitleOffset(1.,"x");
//   timeVsAmpli10_EE->SetTitleSize(0.06,"y");
//   timeVsAmpli10_EE->SetTitleOffset(1.,"y");

  timeVsAmpli10_EE->SetMarkerStyle(20);
  timeVsAmpli10_EE->SetMarkerSize(1.);
  timeVsAmpli10_EE->SetMarkerColor(kBlue);
  timeVsAmpli10_EE->SetLineStyle(1);
  timeVsAmpli10_EE->SetLineColor(4);

//   gPad->SetBottomMargin(0.15);
//   gPad->SetLeftMargin(0.15);
//   gPad->SetLogx(0);
//   gPad->Modified();
  
  
  timeVsAmpli11_EE->Draw("p");
  timeVsAmpli10_EE->Draw("psame");
  
  Leg15->AddEntry(timeVsAmpli10_EE,"Base","p");
  Leg15->AddEntry(timeVsAmpli11_EE, "Corr-Base","p");
  Leg15->Draw();



 
 std::cout << "SigmatimeVsAmpli11_EE is: " 
          <<  SigmatimeVsAmpli11_EE->GetName() << " and has " 
          << SigmatimeVsAmpli11_EE->GetEntries() << " entries;" 
          << std::endl;
std::cout << "SigmatimeVsAmpli10_EE is: " 
          <<  SigmatimeVsAmpli10_EE->GetName() << " and has " 
          <<  SigmatimeVsAmpli10_EE->GetEntries() << " entries;" 
          << std::endl;



 TCanvas *c16 = new TCanvas("c16", "SigmatimeVsAmpli_EE");
  //TCanvas *c1 = new TCanvas("c1", "c");
TLegend*  Leg16 = new TLegend(0.4,0.7, 0.67,0.85);
 Leg16->SetHeader("Legend");
 Leg16->SetFillColor(0);
 Leg16->SetTextSize(0.04);
 // c->Divide(1,2);
  c16->cd();
  // SigmatimeVsAmpli11_EE->Fit("gaus");            //E = A*0.063 (GeV)
  SigmatimeVsAmpli11_EE->GetXaxis()->SetTitle("Amplitude(ADC counts)");// E =A*0.039(GeV) 4 EB
  SigmatimeVsAmpli11_EE->GetYaxis()->SetTitle("#sigma[ns]");
  SigmatimeVsAmpli11_EE->GetYaxis()->SetRangeUser(MinSigmaTime,MaxSigmaTime);
  SigmatimeVsAmpli11_EE->GetXaxis()->SetRangeUser(MinAmpli, MaxAmpli);
  SigmatimeVsAmpli11_EE->SetTitle("Std Dev Vs Amplitude, Crys in EE");

  SigmatimeVsAmpli11_EE->SetTitleSize(0.06,"x");
  SigmatimeVsAmpli11_EE->SetTitleOffset(1.,"x");
  SigmatimeVsAmpli11_EE->SetTitleSize(0.06,"y");
  SigmatimeVsAmpli11_EE->SetTitleOffset(1.,"y");

  SigmatimeVsAmpli11_EE->SetLineColor(8);
  SigmatimeVsAmpli11_EE->SetLineStyle(1);
  SigmatimeVsAmpli11_EE->SetMarkerStyle(20);
  SigmatimeVsAmpli11_EE->SetMarkerSize(1.);
  SigmatimeVsAmpli11_EE->SetMarkerColor(kGreen);
  gPad->SetBottomMargin(0.15);
  gPad->SetLeftMargin(0.15);
  gPad->SetLogx(1);

   gPad->Modified(1);
   c16->SetGridx(1);
   c16->SetGridy(1);
   c16->SetLogx(1);
  //  cd->cd(2);
  // SigmatimeVsAmpli10_EE->Fit("gaus");

  SigmatimeVsAmpli10_EE->GetXaxis()->SetTitle("Amplitude(ADC counts)");// E =A*0.039(GeV) 4 EB
  SigmatimeVsAmpli10_EE->GetYaxis()->SetTitle("#sigma[ns]");
  SigmatimeVsAmpli10_EE->GetYaxis()->SetRangeUser(MinSigmaTime,MaxSigmaTime);
  SigmatimeVsAmpli10_EE->GetXaxis()->SetRangeUser(MinAmpli, MaxAmpli);
  SigmatimeVsAmpli10_EE->SetTitle("Std Dev Vs Amplitude, Crys in EE");

 //  SigmatimeVsAmpli10_EE->SetTitleSize(0.06,"x");
//   SigmatimeVsAmpli10_EE->SetTitleOffset(1.,"x");
//   SigmatimeVsAmpli10_EE->SetTitleSize(0.06,"y");
//   SigmatimeVsAmpli10_EE->SetTitleOffset(1.,"y");

  SigmatimeVsAmpli10_EE->SetMarkerStyle(20);
  SigmatimeVsAmpli10_EE->SetMarkerSize(1.);
  SigmatimeVsAmpli10_EE->SetMarkerColor(kBlue);
  SigmatimeVsAmpli10_EE->SetLineStyle(1);
  SigmatimeVsAmpli10_EE->SetLineColor(4);

//   gPad->SetBottomMargin(0.15);
//   gPad->SetLeftMargin(0.15);
//   gPad->SetLogx(0);
//   gPad->Modified();
  
  
  SigmatimeVsAmpli11_EE->Draw("p");
  SigmatimeVsAmpli10_EE->Draw("psame");
  
  Leg16->AddEntry(SigmatimeVsAmpli10_EE, "Base","p");
  Leg16->AddEntry(SigmatimeVsAmpli11_EE, "Corr-Base","p");
  Leg16->Draw();






}
