{

// Load all Rootfit Libraries
 gSystem->Load("libRooFit");
 gSystem->Load("libRooStats");
 gSystem->Load("libRooFitCore");

 using namespace RooFit;
 using namespace RooStats;
// Export Lib
//export LD_LIBRARY_PATH=$ROOTSYS/lib:$PYTHONDIR/lib:$LD_LIBRARY_PATH
//export PYTHONPATH=$ROOTSYS/lib:$PYTHONPATH 

  // Set up FW Lite for automatic loading of CMS libraries
  // and data formats.   As you may have other user-defined setup
  // in your rootlogon.C, the CMS setup is executed only if the CMS
  // environment is set up.
  //
  TString cmsswbase = getenv("CMSSW_BASE");
  if (cmsswbase.Length() > 0) {
    //
    // The CMSSW environment is defined (this is true even for FW Lite)
    // so set up the rest.
    //
    cout << "Loading FW Lite setup." << endl;
    gSystem->Load("libFWCoreFWLite.so");
    AutoLibraryLoader::enable();
    gSystem->Load("libDataFormatsFWLite.so");
    gSystem->Load("libDataFormatsPatCandidates.so");
   }
  // gstyle->SetPalette(11111);



  //void SetTENStyle()
  //{
  TStyle* TENStyle = new  TStyle("TENStyle", "OK Default Style");

  // Colors

  //set the background color to white
  TENStyle->SetFillColor(10);
  TENStyle->SetFrameFillColor(10);
  TENStyle->SetFrameFillStyle(0);
  TENStyle->SetFillStyle(0);
  TENStyle->SetCanvasColor(10);
  TENStyle->SetPadColor(10);

  TENStyle->SetTitleFillColor(0);
  TENStyle->SetStatColor(10);

  // Get rid of drop shadow on legends
  // This doesn't seem to work.  Call SetBorderSize(1) directly on your TLegends
  TENStyle->SetLegendBorderSize(1);

  //don't put a colored frame around the plots
  TENStyle->SetFrameBorderMode(0);
  TENStyle->SetCanvasBorderMode(0);
  TENStyle->SetPadBorderMode(0);

  //use the primary color palette
  TENStyle->SetPalette(1,0);

  //set the default line color for a histogram to be black
  TENStyle->SetHistLineColor(kBlack);

  //set the default line color for a fit function to be red
  TENStyle->SetFuncColor(kRed);

  //make the axis labels black
  TENStyle->SetLabelColor(kBlack,"xyz");

  //set the default title color to be black
  TENStyle->SetTitleColor(kBlack);

  //set the margins
  TENStyle->SetPadBottomMargin(0.15);
  TENStyle->SetPadLeftMargin(0.15);
  TENStyle->SetPadTopMargin(0.075);
  TENStyle->SetPadRightMargin(0.15);

  //set axis label and title text sizes
  TENStyle->SetLabelSize(0.05,"xyz");
  TENStyle->SetTitleSize(0.07,"xyz");
  TENStyle->SetTitleOffset(0.9,"xyz");
  TENStyle->SetStatFontSize(0.05);
  TENStyle->SetTextSize(0.07);
  TENStyle->SetTitleBorderSize(0);

  //set line widths
  TENStyle->SetHistLineWidth(2);
  TENStyle->SetFrameLineWidth(2);
  TENStyle->SetFuncWidth(2);

  // Misc

  //align the titles to be centered
  //TENStyle->SetTextAlign(22);

  //turn off xy grids
  TENStyle->SetPadGridX(0);
  TENStyle->SetPadGridY(0);

  //set the tick mark style
  TENStyle->SetPadTickX(1);
  TENStyle->SetPadTickY(1);

  //don't show the fit parameters in a box
  TENStyle->SetOptFit(11111);

  //set the default stats shown
  TENStyle->SetOptStat(111111);

  //marker settings
  TENStyle->SetMarkerStyle(8);
  TENStyle->SetMarkerSize(0.7);

  // Fonts
  TENStyle->SetStatFont(12);
  TENStyle->SetLabelFont(12,"xyz");
  TENStyle->SetTitleFont(12,"xyz");
  TENStyle->SetTextFont(12);

  // Set the paper size for output
  TENStyle->SetPaperSize(TStyle::kUSLetter);

  //done
  TENStyle->cd();

  cout << "Using TENStyle" << endl;
  //}
}
