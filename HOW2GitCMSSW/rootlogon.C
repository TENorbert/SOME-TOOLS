{
  // Set up FW Lite for automatic loading of CMS libraries
  // and data formats.   As you may have other user-defined setup
  // in your rootlogon.C, the CMS setup is executed only if the CMS
  // environment is set up.
  //
  Unix.*.Root.UseTTFonts: true
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
  //gSystem->AddIncludePath("-I/wherever/RooFit/is/include");
    gSystem->AddIncludePath("-I${ROOFITSYS}/include");
    //gInterpreter->AddIncludePath("/local/cms/sw/slc5_amd64_gcc462/lcg/roofit/5.32.00-cms6/include");
  //gROOT->ProcessLine("/local/cms/sw/slc5_amd64_gcc462/lcg/roofit/5.32.00-cms6/include");
  TGaxis::SetMaxDigits(2); // Set Axis to be of the form 0.11 10^N

  //
//  void CMSStyle(){
    // use the 'plain' style for plots (white backgrounds, etc)
    // cout << "...using style 'Plain'" << endl;
    gROOT->SetStyle("Plain");
  
    // Create the 'CMS' style for approved plots. Note that this style may need
    // some fine tuning in your macro depending on what you are plotting, e.g.
    //
    // gStyle->SetMarkerSize(0.75); // use smaller markers in a histogram with many bins
    // gStyle->SetTitleOffset(0.65,"y"); // bring y axis label closer to narrow values
  
    TStyle *cmsStyle= new TStyle("CMS","CMS approved plots style");
  
    // use plain black on white colors
    cmsStyle->SetFrameBorderMode(0);
    cmsStyle->SetCanvasBorderMode(0);
    cmsStyle->SetPadBorderMode(0);
    cmsStyle->SetPadColor(0);
    cmsStyle->SetCanvasColor(0);
    cmsStyle->SetTitleColor(1);
    cmsStyle->SetStatColor(0);
    cmsStyle->SetFrameFillColor(0);

    // set the paper & margin sizes
    cmsStyle->SetPaperSize(20,26);
    cmsStyle->SetPadTopMargin(0.055);
    cmsStyle->SetPadRightMargin(0.055);
    cmsStyle->SetPadBottomMargin(0.15);
    cmsStyle->SetPadLeftMargin(0.15);

    // use large Times-Roman fonts
    cmsStyle->SetTextFont(132);
    cmsStyle->SetTextSize(0.08);
    cmsStyle->SetLabelFont(132,"x");
    cmsStyle->SetLabelFont(132,"y");
    cmsStyle->SetTitleOffset(1.15,"x");
    cmsStyle->SetTitleOffset(1.15,"y");
    cmsStyle->SetLabelFont(132,"z");
    cmsStyle->SetLabelSize(0.05,"x");
    cmsStyle->SetTitleSize(0.06,"x");
    cmsStyle->SetLabelSize(0.05,"y");
    cmsStyle->SetTitleSize(0.06,"y");
    cmsStyle->SetLabelSize(0.05,"z");
    cmsStyle->SetTitleSize(0.06,"z");

    // use bold lines and markers
    cmsStyle->SetMarkerStyle(8);
    cmsStyle->SetHistLineWidth(1.85);
    cmsStyle->SetLineStyleString(2,"[12 12]"); // postscript dashes

    // do not display any of the standard histogram decorations
    cmsStyle->SetOptTitle(0);
    cmsStyle->SetOptStat(111111);
    cmsStyle->SetOptFit(0);
    
    cmsStyle->SetPalette(1);

    // put tick marks on top and RHS of plots
    cmsStyle->SetPadTickX(1);
    cmsStyle->SetPadTickY(1);

    // cout << endl << " For approved plots use: gROOT->SetStyle(\"CMS\");"
    // << endl << " To add a CMS label use: CMSLabel();"
    // << endl << endl;

    // restore the plain style
    //gROOT->SetStyle("Plain");
    gROOT->SetStyle("CMS");
    //    return ;
    // }


  /*
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

  TENStyle->SetTitleFillColor(1);
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
  TENStyle->SetPadGridX(1);
  TENStyle->SetPadGridY(1);

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
// restore the plain style
     gROOT->SetStyle("Plain");
  //   gROOT->SetStyle("CMS");
     gROOT->ForceStyle(); 
 return ;
 
 cout << "Using TENStyle" << endl;
  //}
*/
}
