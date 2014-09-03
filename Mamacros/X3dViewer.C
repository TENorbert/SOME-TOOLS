{
  gROOT->Reset();
  TH3F *h3a = new TH3F("h3a","testa fitz",20,-4,4,20,-4,4,20,0,20);
  TH3F *h3b = new TH3F("h3b","testb fitz",20,-4,4,20,-4,4,20,0,20);
  for (Int_t i=0;i<10000;i++) {
	Float_t x = gRandom->Gaus(0,1);
	Float_t y = gRandom->Gaus(0,1);
	Float_t z = gRandom->Gaus(10,4);
	h3a->Fill(x,y,z);
  }
  for (Int_t i=0;i<1000;i++) {
	Float_t x = gRandom->Gaus(0,1);
	Float_t y = gRandom->Gaus(0,1);
	Float_t z = gRandom->Gaus(10,4);
	h3b->Fill(x,y,z);
  }
  h3a->SetMarkerColor(kBlue);
  h3b->SetMarkerColor(kRed);
  h3a->Draw("box");
  h3b->Draw("boxsame");
}

