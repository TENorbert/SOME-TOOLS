{
  //  TFile * file1 = new TFile("/data/tambe/EcalCreatTimeCalibs/EvenEvents17/rh-ElectronHad_Run2011A-PromptReco.170760-170901.outPutFile17.root");
   TFile * file1 = new TFile("/data/tambe/EcalCreatTimeCalibs/Run171484-172665/Even/EcalCreateTimeCalibsIOV15EVEN.root");
   //  TFile * file1 = new TFile("/data/tambe/EcalCreatTimeCalibs/Run170902-171484/Even/EcalCreateTimeCalibsIOV14EVEN.root");

  //   TFile * file1 = new TFile("/data/tambe/EcalCreatTimeCalibs/Run170902-171484/Even/EcalCreateTimeCalibsIOV14EVEN.root");
 
std::cout << "file input 1 is:" << file1->GetName() << std::endl;

//TFile * file2 = new TFile("/data/tambe/EcalCreatTimeCalibs/OddEvents17/rh-ElectronHad_Run2011A-PromptReco.170760-170901.outPutFile.root");
 TFile *file2 = new TFile("/data/tambe/EcalCreatTimeCalibs/Run171484-172665/Odd/EcalCreateTimeCalibsIOV15Odd.root");
 //    TFile* file2 = new TFile("/data/tambe/EcalCreatTimeCalibs/Run170902-171484/Odd/EcalCreateTimeCalibsIOV14Odd.root");
std::cout << "file input 2 is: " << file2->GetName() << std::endl;

// get hold of a pointer to a histogram inside each file
//TH2F * ebCalib1 =(TH2F*) file1->Get("createTimeCalibs/calibDiffMapEEM");
//TH2F * ebCalib2 =(TH2F*) file2->Get("createTimeCalibs/calibDiffMapEEM");
//TH2F * ebCalib1 =(TH2F*) file1->Get("createTimeCalibs/calibDiffMapEEP");
//TH2F * ebCalib2 =(TH2F*) file2->Get("createTimeCalibs/calibDiffMapEEP");
TH2F * ebCalib1 = (TH2F*) file1->Get("createTimeCalibs/calibDiffMapEB");
TH2F * ebCalib2 = (TH2F*) file2->Get("createTimeCalibs/calibDiffMapEB");

// if you want to see the list of the full content of the file
// file1->cd("createTimeCalibs");
// file1->ls();
// file1->Print();


std::cout << "ebCalib1 is: " 
          << ebCalib1->GetName() << " and has " 
          << ebCalib1->GetEntries() << " entries;" 
          << std::endl;
std::cout << "ebCalib2 is: " 
          << ebCalib2->GetName() << " and has " 
          << ebCalib2->GetEntries() << " entries;" 
          << std::endl;

// create a clone which has the same content as ebCalib1
//TH2F *  theClone =(TH2F *) ebCalib1->Clone("calibDiffMapEEMClone");
// TH2F *  theClone =(TH2F *) ebCalib1->Clone("calibDiffMapEEPClone");
 TH2F *  theClone = (TH2F *) ebCalib1->Clone("calibDiffMapEBClone"); 

// subtract bin-by-bin the content of ebCalib2
theClone->Add(ebCalib2,-1);

// prepared 1d histogram to hold the differences channel-by-channel
 TH1F * theCalibDifferences = new TH1F("the calib differences","#DeltaCalib/0.1ns EB",600,-0.3,0.3);
theCalibDifferences->GetYaxis()->SetTitle("");
theCalibDifferences->GetXaxis()->SetTitle("time calib differences [ns]");



// get the size of the histogram holding the differences
int numBinsX = ebCalib1->GetNbinsX();
int numBinsY = ebCalib1->GetNbinsY();
std::cout << "there are "<< numBinsX << " bins on x axis and " << numBinsY << " on Y axis " << std::endl;

for(int u=1; u<=numBinsX; u++){
for(int v=1; v<=numBinsY; v++){
  // if(v==86) continue;
  if ( fabs(ebCalib1->GetBinContent(u,v))>10 ) continue;  // remove channels which have non-physical values
  if ( fabs(ebCalib2->GetBinContent(u,v))>10 ) continue;
  theCalibDifferences->Fill(  theClone->GetBinContent(u,v)  );
}
}

// do the drawing
TCanvas * canvas1 = new TCanvas("canvas1","canvas1");
canvas1->cd(); ebCalib1->Draw("colz");
TCanvas * canvas2 = new TCanvas("canvas2","canvas2");
canvas2->cd(); ebCalib2->Draw("colz");
TCanvas * canvasDiff = new TCanvas("canvasDiff","canvasDiff");
 canvasDiff->cd();theClone->SetTitle("#DeltaCalib Map EB"); theClone->Draw("colz");
TCanvas * canvasDiff1d = new TCanvas("canvasDiff1d","canvasDiff1d");
canvasDiff1d->cd(); theCalibDifferences->Draw("");



}
