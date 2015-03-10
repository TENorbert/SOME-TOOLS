//// ---------------------------------------------------------------------------------------
// ------------------ Function to do slicing and fitting of plots ------------------------
void doFinalPlots()
{
  for (int sliceX=0; sliceX<AeffNBins_; sliceX++)  {//looping on the X axis, at constant Aeff
    for (int binY=0; binY<numDtBins_; binY++)  {// looping in Delta t bins
      dtSliceVSAeffAny_[sliceX]   ->SetBinContent( (binY+1), (dtVSAeffHistAny_->GetBinContent((sliceX+1),(binY+1))) ); 
      dtSliceVSAeffEB_[sliceX]    ->SetBinContent( (binY+1), (dtVSAeffHistEB_->GetBinContent((sliceX+1),(binY+1))) ); 
      dtSliceVSAeffEE_[sliceX]    ->SetBinContent( (binY+1), (dtVSAeffHistEE_->GetBinContent((sliceX+1),(binY+1))) ); 
      dtSliceVSAeffAnyPeak_[sliceX] ->SetBinContent( (binY+1), (dtVSAeffHistAnyPeak_->GetBinContent((sliceX+1),(binY+1))) ); 
      dtSliceVSAeffEBPeak_[sliceX] ->SetBinContent( (binY+1), (dtVSAeffHistEBPeak_->GetBinContent((sliceX+1),(binY+1))) ); 
      dtSliceVSAeffEEPeak_[sliceX] ->SetBinContent( (binY+1), (dtVSAeffHistEEPeak_->GetBinContent((sliceX+1),(binY+1))) ); 

      // Dt slices for seeds/clusters in Aeff bins
      dtSeedsSlicesVsAeffDoubleClusterHist_[sliceX]       ->SetBinContent( (binY+1), (dtSeedsVsAeffDoubleClusterHist_->GetBinContent((sliceX+1),(binY+1))) ); 
      dtSeedsSlicesVsAeffDoubleClusterHistEE_[sliceX]     ->SetBinContent( (binY+1), (dtSeedsVsAeffDoubleClusterHistEE_->GetBinContent((sliceX+1),(binY+1))) ); 
      dtSeedsSlicesVsAeffDoubleClusterHistEB_[sliceX]     ->SetBinContent( (binY+1), (dtSeedsVsAeffDoubleClusterHistEB_->GetBinContent((sliceX+1),(binY+1))) ); 
      dtSlicesVsAeffDoubleClusterHist_[sliceX]            ->SetBinContent( (binY+1), (dtVsAeffDoubleClusterHist_->GetBinContent((sliceX+1),(binY+1))) ); 
      dtSlicesVsAeffDoubleClusterHistEE_[sliceX]          ->SetBinContent( (binY+1), (dtVsAeffDoubleClusterHistEE_->GetBinContent((sliceX+1),(binY+1))) ); 
      dtSlicesVsAeffDoubleClusterHistEB_[sliceX]          ->SetBinContent( (binY+1), (dtVsAeffDoubleClusterHistEB_->GetBinContent((sliceX+1),(binY+1))) ); 

      // Dt slices for seeds/clusters in Aeff bins under pi0 peak
      dtSeedsSlicesVsAeffDoubleClusterHistPi0Peak_[sliceX]       ->SetBinContent( (binY+1), (dtSeedsVsAeffDoubleClusterHistPi0Peak_->GetBinContent((sliceX+1),(binY+1))) ); 
      dtSeedsSlicesVsAeffDoubleClusterHistPi0PeakEE_[sliceX]     ->SetBinContent( (binY+1), (dtSeedsVsAeffDoubleClusterHistPi0PeakEE_->GetBinContent((sliceX+1),(binY+1))) ); 
      dtSeedsSlicesVsAeffDoubleClusterHistPi0PeakEB_[sliceX]     ->SetBinContent( (binY+1), (dtSeedsVsAeffDoubleClusterHistPi0PeakEB_->GetBinContent((sliceX+1),(binY+1))) ); 
      dtSlicesVsAeffDoubleClusterHistPi0Peak_[sliceX]            ->SetBinContent( (binY+1), (dtVsAeffDoubleClusterHistPi0Peak_->GetBinContent((sliceX+1),(binY+1))) ); 
      dtSlicesVsAeffDoubleClusterHistPi0PeakEE_[sliceX]          ->SetBinContent( (binY+1), (dtVsAeffDoubleClusterHistPi0PeakEE_->GetBinContent((sliceX+1),(binY+1))) ); 
      dtSlicesVsAeffDoubleClusterHistPi0PeakEB_[sliceX]          ->SetBinContent( (binY+1), (dtVsAeffDoubleClusterHistPi0PeakEB_->GetBinContent((sliceX+1),(binY+1))) ); 

    }// end loop on Ybins 

    // do slices RMS and fitting for  Any 
    if( dtSliceVSAeffAny_[sliceX] -> Integral()  >= minEntriesForFit_ ){
      // extract RMS and sigma for each Aeff=const slice
      float RMS       = dtSliceVSAeffAny_[sliceX] -> GetRMS();
      float RMSErr    = dtSliceVSAeffAny_[sliceX] -> GetRMSError();
      dtRMSVSAeffAny_ -> SetBinContent(sliceX+1, RMS);
      dtRMSVSAeffAny_ -> SetBinError(sliceX+1, RMSErr);
      
      TF1 *gauss = new TF1("dtFit","gaus",-DtMax_,DtMax_); // require min number entries
      gauss                    ->SetParLimits(1,-5,5); // limit on gaussian central 
      gauss                    ->SetParameter(1,0);    // initialize mean on central value
      //TFitResultPtr Fit(TF1 *f1 ,Option_t *option ,Option_t *goption, Double_t xxmin, Double_t xxmax)
      if (!limitFit_) dtSliceVSAeffAny_[sliceX]->Fit("dtFit",fitOption_.c_str());
      else            dtSliceVSAeffAny_[sliceX]->Fit("dtFit",fitOption_.c_str(),"",-3*RMS,+3*RMS);
      float sigma     = gauss -> GetParameter(2);
      float sigmaErr  = gauss -> GetParError(2);
      if(limitFit_)   dtSliceVSAeffAny_[sliceX]->Fit("dtFit",fitOption_.c_str(),"",-2*sigma,+2*sigma);
      sigma     = gauss -> GetParameter(2);
      sigmaErr  = gauss -> GetParError(2);
      // setting histogram and arrays with sigmas and their errros + abcsissa bins
      dtSigmaAeffAny_ -> SetBinContent(sliceX+1, sigma);    sigmaAeffAny_[sliceX]=sigma;
      dtSigmaAeffAny_ -> SetBinError(sliceX+1, sigmaErr);   sigmaAeffErrAny_[sliceX]=sigmaErr;
      //       AeffBinCentersAny_[sliceX]    = dtSigmaAeffAny_->GetXaxis()->GetBinCenter(sliceX+1);
      //       AeffBinCentersErrAny_[sliceX] = dtSigmaAeffAny_->GetXaxis()->GetBinWidth(sliceX+1)/2;
      AeffBinCentersAny_[sliceX]    = AeffSliceAny_[sliceX]->GetMean();
      AeffBinCentersErrAny_[sliceX] = AeffSliceAny_[sliceX]->GetMeanError();
    }// slices for Any

    // do slices RMS and fitting for EB
    if( dtSliceVSAeffEB_[sliceX] -> Integral()  >= minEntriesForFit_ ){
      // extract RMS and sigma for each Aeff=const slice
      float RMS       = dtSliceVSAeffEB_[sliceX] -> GetRMS();
      float RMSErr    = dtSliceVSAeffEB_[sliceX] -> GetRMSError();
      dtRMSVSAeffEB_ -> SetBinContent(sliceX+1, RMS);
      dtRMSVSAeffEB_ -> SetBinError(sliceX+1, RMSErr);

      TF1 *gauss = new TF1("dtFitEB","gaus",-DtMax_,DtMax_); // require min number entries
      gauss                    ->SetParLimits(1,-5,5); // limit on gaussian central 
      gauss                    ->SetParameter(1,0);    // initialize mean on central value
      if (!limitFit_) dtSliceVSAeffEB_[sliceX]->Fit("dtFitEB",fitOption_.c_str());
      else            dtSliceVSAeffEB_[sliceX]->Fit("dtFitEB",fitOption_.c_str(),"",-3*RMS,+3*RMS);
      float sigma     = gauss -> GetParameter(2);
      float sigmaErr  = gauss -> GetParError(2);
      if (limitFit_)   dtSliceVSAeffEB_[sliceX]->Fit("dtFitEB",fitOption_.c_str(),"",-2*sigma,+2*sigma);
      sigma     = gauss -> GetParameter(2);
      sigmaErr  = gauss -> GetParError(2);
      // settnig histogram and arrays with sigmas and their errros + abcsissa bins
      dtSigmaAeffEB_ -> SetBinContent(sliceX+1, sigma);    sigmaAeffEB_[sliceX]=sigma;
      dtSigmaAeffEB_ -> SetBinError(sliceX+1, sigmaErr);   sigmaAeffErrEB_[sliceX]=sigmaErr;
      //       AeffBinCentersEB_[sliceX]    = dtSigmaAeffEB_->GetXaxis()->GetBinCenter(sliceX+1);
      //       AeffBinCentersErrEB_[sliceX] = dtSigmaAeffEB_->GetXaxis()->GetBinWidth(sliceX+1)/2;
      AeffBinCentersEB_[sliceX]    = AeffSliceEB_[sliceX]->GetMean();
      AeffBinCentersErrEB_[sliceX] = AeffSliceEB_[sliceX]->GetMeanError();
    }// slices for EB

    // do slices RMS and fitting for EE
    if( dtSliceVSAeffEE_[sliceX] -> Integral()  >= minEntriesForFit_ ){
      // extract RMS and sigma for each Aeff=const slice
      float RMS       = dtSliceVSAeffEE_[sliceX] -> GetRMS();
      float RMSErr    = dtSliceVSAeffEE_[sliceX] -> GetRMSError();
      dtRMSVSAeffEE_ -> SetBinContent(sliceX+1, RMS);
      dtRMSVSAeffEE_ -> SetBinError(sliceX+1, RMSErr);
      TF1 *gauss = new TF1("dtFitEE","gaus",-DtMax_,DtMax_); // require min number entries
      gauss                    ->SetParLimits(1,-5,5); // limit on gaussian central 
      gauss                    ->SetParameter(1,0);    // initialize on central value
      if (!limitFit_) dtSliceVSAeffEE_[sliceX]->Fit("dtFitEE",fitOption_.c_str());
      else            dtSliceVSAeffEE_[sliceX]->Fit("dtFitEE",fitOption_.c_str(),"",-3*RMS,+3*RMS);
      float sigma     = gauss -> GetParameter(2);
      float sigmaErr  = gauss -> GetParError(2);
      if(limitFit_) dtSliceVSAeffEE_[sliceX]->Fit("dtFitEE",fitOption_.c_str(),"",-2*sigma,+2*sigma);
      sigma     = gauss -> GetParameter(2);
      sigmaErr  = gauss -> GetParError(2);
      // setting histogram and arrays with sigmas and their errros + abcsissa bins
      dtSigmaAeffEE_ -> SetBinContent(sliceX+1, sigma);  sigmaAeffEE_[sliceX]=sigma;
      dtSigmaAeffEE_ -> SetBinError(sliceX+1, sigmaErr); sigmaAeffErrEE_[sliceX]=sigmaErr;
      AeffBinCentersEE_[sliceX]    = AeffSliceEE_[sliceX]->GetMean();
      AeffBinCentersErrEE_[sliceX] = AeffSliceEE_[sliceX]->GetMeanError();
    }// slices for EE


    // **** cluster fits ****    

    // get sigma from fitting Cluster Seeds Any
    if( dtSeedsSlicesVsAeffDoubleClusterHist_[sliceX] -> Integral()  >= minEntriesForFit_ ){
      TF1 *gauss = new TF1("dtFitClus","gaus",-DtMax_,DtMax_); // require min number entries
      gauss ->SetParLimits(1,-5,5);   gauss ->SetParameter(1,0);
      dtSeedsSlicesVsAeffDoubleClusterHist_[sliceX]->Fit("dtFitClus",fitOption_.c_str());
      float sigma = gauss -> GetParameter(2);                 float sigmaErr  = gauss -> GetParError(2);
      dtSeedsSigmaAeffAny_ -> SetBinContent(sliceX+1, sigma); dtSeedsSigmaAeffAny_ -> SetBinError(sliceX+1, sigmaErr);
    }// slices for Cluster Seeds Any
    
    // get sigma from fitting Cluster Seeds EE
    if( dtSeedsSlicesVsAeffDoubleClusterHistEE_[sliceX] -> Integral()  >= minEntriesForFit_ ){
      TF1 *gauss = new TF1("dtFitClusEE","gaus",-DtMax_,DtMax_); // require min number entries
      gauss ->SetParLimits(1,-5,5);   gauss ->SetParameter(1,0);
      dtSeedsSlicesVsAeffDoubleClusterHistEE_[sliceX]->Fit("dtFitClusEE",fitOption_.c_str());
      float sigma = gauss -> GetParameter(2);                 float sigmaErr  = gauss -> GetParError(2);
      dtSeedsSigmaAeffEE_ -> SetBinContent(sliceX+1, sigma); dtSeedsSigmaAeffEE_ -> SetBinError(sliceX+1, sigmaErr);
    }// slices for Cluster Seeds EE

    // get sigma from fitting Cluster Seeds EB
    if( dtSeedsSlicesVsAeffDoubleClusterHistEB_[sliceX] -> Integral()  >= minEntriesForFit_ ){
      TF1 *gauss = new TF1("dtFitClusEB","gaus",-DtMax_,DtMax_); // require min number entries
      gauss ->SetParLimits(1,-5,5);   gauss ->SetParameter(1,0);
      dtSeedsSlicesVsAeffDoubleClusterHistEB_[sliceX]->Fit("dtFitClusEB",fitOption_.c_str());
      float sigma = gauss -> GetParameter(2);                 float sigmaErr  = gauss -> GetParError(2);
      dtSeedsSigmaAeffEB_ -> SetBinContent(sliceX+1, sigma); dtSeedsSigmaAeffEB_ -> SetBinError(sliceX+1, sigmaErr);
    }// slices for Cluster Seeds EB
    


    // get sigma from fitting Cluster (combined crystals) Any
    if( dtSlicesVsAeffDoubleClusterHist_[sliceX] -> Integral()  >= minEntriesForFit_ ){
      TF1 *gauss = new TF1("dtFitClusComb","gaus",-DtMax_,DtMax_); // require min number entries
      gauss ->SetParLimits(1,-5,5);   gauss ->SetParameter(1,0);
      dtSlicesVsAeffDoubleClusterHist_[sliceX]->Fit("dtFitClusComb",fitOption_.c_str());
      float sigma = gauss -> GetParameter(2);                 float sigmaErr  = gauss -> GetParError(2);
      dtClustersSigmaAeffAny_ -> SetBinContent(sliceX+1, sigma); dtClustersSigmaAeffAny_ -> SetBinError(sliceX+1, sigmaErr);
    }// slices for Cluster (combined crystals) Any
    
    // get sigma from fitting Cluster (combined crystals) EE
    if( dtSlicesVsAeffDoubleClusterHistEE_[sliceX] -> Integral()  >= minEntriesForFit_ ){
      TF1 *gauss = new TF1("dtFitClusCombEE","gaus",-DtMax_,DtMax_); // require min number entries
      gauss ->SetParLimits(1,-5,5);   gauss ->SetParameter(1,0);
      dtSlicesVsAeffDoubleClusterHistEE_[sliceX]->Fit("dtFitClusCombEE",fitOption_.c_str());
      float sigma = gauss -> GetParameter(2);                 float sigmaErr  = gauss -> GetParError(2);
      dtClustersSigmaAeffEE_ -> SetBinContent(sliceX+1, sigma); dtClustersSigmaAeffEE_ -> SetBinError(sliceX+1, sigmaErr);
    }// slices for Cluster (combined crystals) EE

    // get sigma from fitting Cluster (combined crystals) EB
    if( dtSlicesVsAeffDoubleClusterHistEB_[sliceX] -> Integral()  >= minEntriesForFit_ ){
      TF1 *gauss = new TF1("dtFitClusCombEB","gaus",-DtMax_,DtMax_); // require min number entries
      gauss ->SetParLimits(1,-5,5);   gauss ->SetParameter(1,0);
      dtSlicesVsAeffDoubleClusterHistEB_[sliceX]->Fit("dtFitClusCombEB",fitOption_.c_str());
      float sigma = gauss -> GetParameter(2);                 float sigmaErr  = gauss -> GetParError(2);
      dtClustersSigmaAeffEB_ -> SetBinContent(sliceX+1, sigma); dtClustersSigmaAeffEB_ -> SetBinError(sliceX+1, sigmaErr);
    }// slices for Cluster (combined crystals) EB
    

    // **** Peak fit for clusters ****
    
    // do slices RMS and fitting for any peak
    if( dtSliceVSAeffAnyPeak_[sliceX] -> Integral()  >= minEntriesForFit_ ){
      // extract RMS and sigma for each Aeff=const slice
      float RMS       = dtSliceVSAeffAnyPeak_[sliceX] -> GetRMS();
      float RMSErr    = dtSliceVSAeffAnyPeak_[sliceX] -> GetRMSError();
      dtRMSVSAeffAnyPeak_ -> SetBinContent(sliceX+1, RMS);
      dtRMSVSAeffAnyPeak_ -> SetBinError(sliceX+1, RMSErr);
      
      TF1 *gauss = new TF1("dtFitPeak","gaus",-DtMax_,DtMax_); // require min number entries
      gauss                    ->SetParLimits(1,-5,5); // limit on gaussian central 
      gauss                    ->SetParameter(1,0);    // initialize on central value
      dtSliceVSAeffAnyPeak_[sliceX]->Fit("dtFitPeak",fitOption_.c_str());
      float sigma     = gauss -> GetParameter(2);
      float sigmaErr  = gauss -> GetParError(2);
      dtSigmaAeffAnyPeak_ -> SetBinContent(sliceX+1, sigma);
      dtSigmaAeffAnyPeak_ -> SetBinError(sliceX+1, sigmaErr);
    }// slices for any peak
    
    // do slices RMS and fitting for EB
    if( dtSliceVSAeffEBPeak_[sliceX] -> Integral()  >= minEntriesForFit_ ){
      // extract RMS and sigma for each Aeff=const slice
      float RMS       = dtSliceVSAeffEBPeak_[sliceX] -> GetRMS();
      float RMSErr    = dtSliceVSAeffEBPeak_[sliceX] -> GetRMSError();
      dtRMSVSAeffEBPeak_ -> SetBinContent(sliceX+1, RMS);
      dtRMSVSAeffEBPeak_ -> SetBinError(sliceX+1, RMSErr);
      
      TF1 *gauss = new TF1("dtFitPeakEB","gaus",-DtMax_,DtMax_); // require min number entries
      gauss                    ->SetParLimits(1,-5,5); // limit on gaussian central 
      gauss                    ->SetParameter(1,0);    // initialize on central value
      dtSliceVSAeffEBPeak_[sliceX]->Fit("dtFitPeakEB",fitOption_.c_str());
      float sigma     = gauss -> GetParameter(2);
      float sigmaErr  = gauss -> GetParError(2);
      dtSigmaAeffEBPeak_ -> SetBinContent(sliceX+1, sigma);
      dtSigmaAeffEBPeak_ -> SetBinError(sliceX+1, sigmaErr);
    }// slices for EB
    
    // do slices RMS and fitting for EE
    if( dtSliceVSAeffEEPeak_[sliceX] -> Integral()  >= minEntriesForFit_ ){
      // extract RMS and sigma for each Aeff=const slice
      float RMS       = dtSliceVSAeffEEPeak_[sliceX] -> GetRMS();
      float RMSErr    = dtSliceVSAeffEEPeak_[sliceX] -> GetRMSError();
      dtRMSVSAeffEEPeak_ -> SetBinContent(sliceX+1, RMS);
      dtRMSVSAeffEEPeak_ -> SetBinError(sliceX+1, RMSErr);
      
      TF1 *gauss = new TF1("dtFitPeakEE","gaus",-DtMax_,DtMax_); // require min number entries
      gauss                    ->SetParLimits(1,-5,5); // limit on gaussian central 
      gauss                    ->SetParameter(1,0);    // initialize on central value
      dtSliceVSAeffEEPeak_[sliceX]->Fit("dtFitPeakEE",fitOption_.c_str());
      float sigma     = gauss -> GetParameter(2);
      float sigmaErr  = gauss -> GetParError(2);
      dtSigmaAeffEEPeak_ -> SetBinContent(sliceX+1, sigma);
      dtSigmaAeffEEPeak_ -> SetBinError(sliceX+1, sigmaErr);
    }// slices for EE


    // get sigma from fitting Cluster Seeds Under the peak Any
    if( dtSeedsSlicesVsAeffDoubleClusterHistPi0Peak_[sliceX] -> Integral()  >= minEntriesForFit_ ){
      TF1 *gauss = new TF1("dtFitSeed","gaus",-DtMax_,DtMax_); // require min number entries
      gauss ->SetParLimits(1,-5,5);   gauss ->SetParameter(1,0);
      dtSeedsSlicesVsAeffDoubleClusterHistPi0Peak_[sliceX]->Fit("dtFitSeed",fitOption_.c_str());
      float sigma = gauss -> GetParameter(2);                 float sigmaErr  = gauss -> GetParError(2);
      dtSeedsSigmaAeffPi0Peak_ -> SetBinContent(sliceX+1, sigma); dtSeedsSigmaAeffPi0Peak_ -> SetBinError(sliceX+1, sigmaErr);
    }// slices for Cluster Seeds Any
    
    // get sigma from fitting Cluster Seeds Under the peak EE
    if( dtSeedsSlicesVsAeffDoubleClusterHistPi0PeakEE_[sliceX] -> Integral()  >= minEntriesForFit_ ){
      TF1 *gauss = new TF1("dtFitSeedEE","gaus",-DtMax_,DtMax_); // require min number entries
      gauss ->SetParLimits(1,-5,5);   gauss ->SetParameter(1,0);
      dtSeedsSlicesVsAeffDoubleClusterHistPi0PeakEE_[sliceX]->Fit("dtFitSeedEE");
      float sigma = gauss -> GetParameter(2);                 float sigmaErr  = gauss -> GetParError(2);
      dtSeedsSigmaAeffPi0PeakEE_ -> SetBinContent(sliceX+1, sigma); dtSeedsSigmaAeffPi0PeakEE_ -> SetBinError(sliceX+1, sigmaErr);
    }// slices for Cluster Seeds EE

    // get sigma from fitting Cluster Seeds Under the peak EB
    if( dtSeedsSlicesVsAeffDoubleClusterHistPi0PeakEB_[sliceX] -> Integral()  >= minEntriesForFit_ ){
      TF1 *gauss = new TF1("dtFitSeedEB","gaus",-DtMax_,DtMax_); // require min number entries
      gauss ->SetParLimits(1,-5,5);   gauss ->SetParameter(1,0);
      dtSeedsSlicesVsAeffDoubleClusterHistPi0PeakEB_[sliceX]->Fit("dtFitSeedEB");
      float sigma = gauss -> GetParameter(2);                 float sigmaErr  = gauss -> GetParError(2);
      dtSeedsSigmaAeffPi0PeakEB_ -> SetBinContent(sliceX+1, sigma); dtSeedsSigmaAeffPi0PeakEB_ -> SetBinError(sliceX+1, sigmaErr);
    }// slices for Cluster Seeds EB
    


    // get sigma from fitting Cluster (combined crystals) Under the peak Any
    if( dtSlicesVsAeffDoubleClusterHistPi0Peak_[sliceX] -> Integral()  >= minEntriesForFit_ ){
      TF1 *gauss = new TF1("dtFitSeedComb","gaus",-DtMax_,DtMax_); // require min number entries
      gauss ->SetParLimits(1,-5,5);   gauss ->SetParameter(1,0);
      dtSlicesVsAeffDoubleClusterHistPi0Peak_[sliceX]->Fit("dtFitSeedComb");
      float sigma = gauss -> GetParameter(2);                 float sigmaErr  = gauss -> GetParError(2);
      dtClustersSigmaAeffPi0Peak_ -> SetBinContent(sliceX+1, sigma); dtClustersSigmaAeffPi0Peak_ -> SetBinError(sliceX+1, sigmaErr);
    }// slices for Cluster (combined crystals) Any
    
    // get sigma from fitting Cluster (combined crystals) Under the peak EE
    if( dtSlicesVsAeffDoubleClusterHistPi0PeakEE_[sliceX] -> Integral()  >= minEntriesForFit_ ){
      TF1 *gauss = new TF1("dtFitSeedCombEE","gaus",-DtMax_,DtMax_); // require min number entries
      gauss ->SetParLimits(1,-5,5);   gauss ->SetParameter(1,0);
      dtSlicesVsAeffDoubleClusterHistPi0PeakEE_[sliceX]->Fit("dtFitSeedCombEE");
      float sigma = gauss -> GetParameter(2);                 float sigmaErr  = gauss -> GetParError(2);
      dtClustersSigmaAeffPi0PeakEE_ -> SetBinContent(sliceX+1, sigma); dtClustersSigmaAeffPi0PeakEE_ -> SetBinError(sliceX+1, sigmaErr);
    }// slices for Cluster (combined crystals) EE

    // get sigma from fitting Cluster (combined crystals) Under the peak EB
    if( dtSlicesVsAeffDoubleClusterHistPi0PeakEB_[sliceX] -> Integral()  >= minEntriesForFit_ ){
      TF1 *gauss = new TF1("dtFitSeedCombEB","gaus",-DtMax_,DtMax_); // require min number entries
      gauss ->SetParLimits(1,-5,5);   gauss ->SetParameter(1,0);
      dtSlicesVsAeffDoubleClusterHistPi0PeakEB_[sliceX]->Fit("dtFitSeedCombEB");
      float sigma = gauss -> GetParameter(2);                 float sigmaErr  = gauss -> GetParError(2);
      dtClustersSigmaAeffPi0PeakEB_ -> SetBinContent(sliceX+1, sigma); dtClustersSigmaAeffPi0PeakEB_ -> SetBinError(sliceX+1, sigmaErr);
    }// slices for Cluster (combined crystals) EB
    


  }// end loop on Xslices
 

  for (int v=0; v<AoSigmaNBins_ ; v++){//initializing the four maps to values well far off 0
    for (int u=0; u<AoSigmaNBins_ ; u++){// to ease display of results...
      int bun = dtoSigmaSliceSAoSigmaVSAoSigmaEB_-> FindBin(AoSigmaBins_[v],AoSigmaBins_[u]);
      dtoSigmaSliceSAoSigmaVSAoSigmaEB_       -> SetBinContent(bun,-100);
      dtoSigmaSliceSAoSigmaVSAoSigmaEE_       -> SetBinContent(bun,-100);
      for (int k=0; k<3; k++) {
 	int bin = dtSliceSAoSigmaVSAoSigmaEB_[k]-> FindBin(AoSigmaBins_[v],AoSigmaBins_[u]);
 	dtSliceSAoSigmaVSAoSigmaEB_[k]         -> SetBinContent(bin,-100);
 	dtSliceSAoSigmaVSAoSigmaEE_[k]         -> SetBinContent(bin,-100);
      }}}
  
///////// Touble is here!


// From this part below , There is trouble!!!





// **** cluster for bias study ****    
  for (int v=0; v<AoSigmaNBins_ ; v++){// build histograms time difference between channels with ampli in two different AoSigmaBins_ ; loop on first bin
    for (int u=0; u<=v ; u++){// second bin (which can also be the same as the first one)
      
      //gf work in progress here
      for(int k=0; k<3; k++ ){//loop on k, which is topological selection on crystal pairs

        if( dtSliceVSAoSigmaEB_[v][u][k]->Integral()  >= minEntriesForFit_ ){// do fit for this bin in EB,  require min number entries
	
	  TF1 *gauss = new TF1("dtFitEBInAmpliBin","gaus",-DtMax_,DtMax_); 
	  
	  gauss ->SetParLimits(1,-5,5);   gauss ->SetParameter(1,0);
	  
	  dtSliceVSAoSigmaEB_[v][u][k] ->Fit("dtFitEBInAmpliBin");
	  float mu    = gauss -> GetParameter(1);                 float muErr     = gauss -> GetParError(1);
	  // filling two maps:

//  printf("Alive  Here @ G 7 !");
	  //
	  int bin = dtSliceSAoSigmaVSAoSigmaEB_[k]-> FindBin(AoSigmaBins_[v],AoSigmaBins_[u]);
	  dtSliceSAoSigmaVSAoSigmaEB_[k]  -> SetBinContent(bin,mu);           // fitted gaussian mu of time differences for a given pair of Ampli bins 
	  dtoSigmaSliceSAoSigmaVSAoSigmaEB_   -> SetBinContent(bin,mu/muErr);     // same as above, but relative to uncertainty on mu
	}//end EB



//	 printf("Alive  Here @ G 8 !");

	if( dtSliceVSAoSigmaEE_[v][u][k]->Integral()  >= minEntriesForFit_ ){// do fit for this bin in EE,  require min number entries
	  TF1 *gauss = new TF1("dtFitEEInAmpliBin","gaus",-DtMax_,DtMax_); 
	  gauss ->SetParLimits(1,-5,5);   gauss ->SetParameter(1,0);
	  dtSliceVSAoSigmaEE_[v][u][k] ->Fit("dtFitEEInAmpliBin");
	  float mu    = gauss -> GetParameter(1);                 float muErr     = gauss -> GetParError(1);
	  // filling two maps:
//  printf("Alive  Here @ G 9 !");
	  //
	  int bin = dtSliceSAoSigmaVSAoSigmaEE_[k]-> FindBin(AoSigmaBins_[v],AoSigmaBins_[u]);
	  dtSliceSAoSigmaVSAoSigmaEE_[k]          -> SetBinContent(bin,mu);           // fitted gaussian mu of time differences for a given pair of Ampli bins 
	  dtoSigmaSliceSAoSigmaVSAoSigmaEE_    -> SetBinContent(bin,mu/muErr);     // same as above, but relative to uncertainty on mu
	}//end EE

// printf("Alive  Here @ G 10 !");

      }//loop on k, which is topological selection on crystal pairs
      
    }//end loop on u
  }//end loop on v
  
  
  // fitting recHits times in bins of A/sigma, for EB
  TF1 *gaussEBlargelogSlicesFit = new TF1("timeVsAoSigmaEBlargelogSlicesFit","gaus",-7,7);
  TF1 *gaussMod1EBSlicesFit = new TF1("timeVsAoSigmaMod1EBSlicesFit","gaus",-7,7);
  TF1 *gaussMod2EBSlicesFit = new TF1("timeVsAoSigmaMod2EBSlicesFit","gaus",-7,7);
  TF1 *gaussMod3EBSlicesFit = new TF1("timeVsAoSigmaMod3EBSlicesFit","gaus",-7,7);
  TF1 *gaussMod4EBSlicesFit = new TF1("timeVsAoSigmaMod4EBSlicesFit","gaus",-7,7);
  for(int v=0; v<NSlices; v++){

    if( timeVsAoSigmaEBlargelogSlices_[v]->Integral()  >= minEntriesForFit_ ){// do fit for this bin in EB,  require min number entries
      float RMS       = timeVsAoSigmaEBlargelogSlices_[v] -> GetRMS();
      float mean      = timeVsAoSigmaEBlargelogSlices_[v] -> GetMean();
      //      float area      = timeVsAoSigmaEBlargelogSlices_[v] -> GetEntries();
      gaussEBlargelogSlicesFit        ->SetParLimits(1,-5,5);  // limit on gaussian central 
      gaussEBlargelogSlicesFit        ->SetParameter(1,mean);  // initialize on central value
      gaussEBlargelogSlicesFit        ->SetParameter(2,RMS);   // initialize on central value
      timeVsAoSigmaEBlargelogSlices_[v] -> Fit("timeVsAoSigmaEBlargelogSlicesFit","","",-7,+7); // fit on [-7,+7] ns range to stay away from spikes
      gaussEBlargelogSlicesFit        ->SetParameter(1,0);  // re-initialize on central value
      gaussEBlargelogSlicesFit        ->SetParameter(2,1);   // re-initialize on central value
      
      
      timeVsAoSigmaEBlargelog_  ->FitSlicesY(gaussEBlargelogSlicesFit,0,-1,0,"",0);  
   // FitSlicesY gives you the Historgrams for diff parameters but you do not check it these hist exist or not? why?

       
      fittedRMSVsAoSigmaEBlog_ = (TH1D*)gDirectory->Get("timeVsAoSigmaEBlargelog_2"); 
      fittedMeanVsAoSigmaEBlog_ = (TH1D*)gDirectory->Get("timeVsAoSigmaEBlargelog_1");
      fittedAreaVsAoSigmaEBlog_ = (TH1D*)gDirectory->Get("timeVsAoSigmaEBlargelog_0");
      chi2VsAoSigmaEBlog_       = (TH1D*)gDirectory->Get("timeVsAoSigmaEBlargelog_chi2");
    }

    if( timeVsAoSigmaMod1EBSlices_[v]->Integral()  >= minEntriesForFit_ ){// do fit for this bin in EB,  require min number entries
      float RMS       = timeVsAoSigmaMod1EBSlices_[v] -> GetRMS();
      float mean      = timeVsAoSigmaMod1EBSlices_[v] -> GetMean();
      //      float area      = timeVsAoSigmaMod1EBSlices_[v] -> GetEntries();
      gaussMod1EBSlicesFit        ->SetParLimits(1,-5,5);  // limit on gaussian central 
      gaussMod1EBSlicesFit        ->SetParameter(1,mean);  // initialize on central value
      gaussMod1EBSlicesFit        ->SetParameter(2,RMS);   // initialize on central value
      timeVsAoSigmaMod1EBSlices_[v] -> Fit("timeVsAoSigmaMod1EBSlicesFit","","",-7,+7); // fit on [-7,+7] ns range to stay away from spikes

      gaussMod1EBSlicesFit        ->SetParameter(1,0);  // re-initialize on central value
      gaussMod1EBSlicesFit        ->SetParameter(2,1);   // re-initialize on central value
      timeVsAoSigmaMod1EBlog_  ->FitSlicesY(gaussMod1EBSlicesFit,0,-1,0,"",0);  
      fittedRMSVsAoSigmaMod1EB_ = (TH1D*)gDirectory->Get("timeVsAoSigmaMod1EBlog_2");
      fittedMeanVsAoSigmaMod1EB_ = (TH1D*)gDirectory->Get("timeVsAoSigmaMod1EBlog_1");
      fittedAreaVsAoSigmaMod1EB_ = (TH1D*)gDirectory->Get("timeVsAoSigmaMod1EBlog_0");
      //chi2VsAoSigmaMod1EB_       = (TH1D*)gDirectory->Get("timeVsAoSigmaMod1EBlog_chi2");
    }
    if( timeVsAoSigmaMod2EBSlices_[v]->Integral()  >= minEntriesForFit_ ){// do fit for this bin in EB,  require min number entries
      float RMS       = timeVsAoSigmaMod2EBSlices_[v] -> GetRMS();
      float mean      = timeVsAoSigmaMod2EBSlices_[v] -> GetMean();
      //      float area      = timeVsAoSigmaMod2EBSlices_[v] -> GetEntries();
      gaussMod2EBSlicesFit        ->SetParLimits(1,-5,5);  // limit on gaussian central 
      gaussMod2EBSlicesFit        ->SetParameter(1,mean);  // initialize on central value
      gaussMod2EBSlicesFit        ->SetParameter(2,RMS);   // initialize on central value
      timeVsAoSigmaMod2EBSlices_[v] -> Fit("timeVsAoSigmaMod2EBSlicesFit","","",-7,+7); // fit on [-7,+7] ns range to stay away from spikes
      gaussMod2EBSlicesFit        ->SetParameter(1,0);  // re-initialize on central value
      gaussMod2EBSlicesFit        ->SetParameter(2,1);   // re-initialize on central value
      timeVsAoSigmaMod2EBlog_  ->FitSlicesY(gaussMod2EBSlicesFit,0,-1,0,"",0);  
      fittedRMSVsAoSigmaMod2EB_ = (TH1D*)gDirectory->Get("timeVsAoSigmaMod2EBlog_2");
//      fittedMeanVsAoSigmaMod2EB_ = (TH1D*)gDirectory->Get("timeVsAoSigmaMod2EBlog_1");
      fittedAreaVsAoSigmaMod2EB_ = (TH1D*)gDirectory->Get("timeVsAoSigmaMod2EBlog_0");
      //chi2VsAoSigmaMod2EB_       = (TH1D*)gDirectory->Get("timeVsAoSigmaMod2EBlog_chi2");
    }
    if( timeVsAoSigmaMod3EBSlices_[v]->Integral()  >= minEntriesForFit_ ){// do fit for this bin in EB,  require min number entries
      float RMS       = timeVsAoSigmaMod3EBSlices_[v] -> GetRMS();
      float mean      = timeVsAoSigmaMod3EBSlices_[v] -> GetMean();
      //      float area      = timeVsAoSigmaMod3EBSlices_[v] -> GetEntries();
      gaussMod3EBSlicesFit        ->SetParLimits(1,-5,5);  // limit on gaussian central 
      gaussMod3EBSlicesFit        ->SetParameter(1,mean);  // initialize on central value
      gaussMod3EBSlicesFit        ->SetParameter(2,RMS);   // initialize on central value
      timeVsAoSigmaMod3EBSlices_[v] -> Fit("timeVsAoSigmaMod3EBSlicesFit","","",-7,+7); // fit on [-7,+7] ns range to stay away from spikes
      gaussMod3EBSlicesFit        ->SetParameter(1,0);  // re-initialize on central value
      gaussMod3EBSlicesFit        ->SetParameter(2,1);   // re-initialize on central value
      timeVsAoSigmaMod3EBlog_  ->FitSlicesY(gaussMod3EBSlicesFit,0,-1,0,"",0);  
      fittedRMSVsAoSigmaMod3EB_ = (TH1D*)gDirectory->Get("timeVsAoSigmaMod3EBlog_2");
      fittedMeanVsAoSigmaMod3EB_ = (TH1D*)gDirectory->Get("timeVsAoSigmaMod3EBlog_1");
      fittedAreaVsAoSigmaMod3EB_ = (TH1D*)gDirectory->Get("timeVsAoSigmaMod3EBlog_0");
      chi2VsAoSigmaMod3EB_       = (TH1D*)gDirectory->Get("timeVsAoSigmaMod3EBlog_chi2");
    }

    if( timeVsAoSigmaMod4EBSlices_[v]->Integral()  >= minEntriesForFit_ ){// do fit for this bin in EB,  require min number entries
      float RMS       = timeVsAoSigmaMod4EBSlices_[v] -> GetRMS();
      float mean      = timeVsAoSigmaMod4EBSlices_[v] -> GetMean();
      //      float area      = timeVsAoSigmaMod4EBSlices_[v] -> GetEntries();
      gaussMod4EBSlicesFit        ->SetParLimits(1,-5,5);  // limit on gaussian central 
      gaussMod4EBSlicesFit        ->SetParameter(1,mean);  // initialize on central value
      gaussMod4EBSlicesFit        ->SetParameter(2,RMS);   // initialize on central value
      timeVsAoSigmaMod4EBSlices_[v] -> Fit("timeVsAoSigmaMod4EBSlicesFit","","",-7,+7); // fit on [-7,+7] ns range to stay away from spikes
      gaussMod4EBSlicesFit        ->SetParameter(1,0);  // re-initialize on central value
      gaussMod4EBSlicesFit        ->SetParameter(2,1);   // re-initialize on central value
      timeVsAoSigmaMod4EBlog_  ->FitSlicesY(gaussMod4EBSlicesFit,0,-1,0,"",0);  
      fittedRMSVsAoSigmaMod4EB_ = (TH1D*)gDirectory->Get("timeVsAoSigmaMod4EBlog_2");
      fittedMeanVsAoSigmaMod4EB_ = (TH1D*)gDirectory->Get("timeVsAoSigmaMod4EBlog_1");
      fittedAreaVsAoSigmaMod4EB_ = (TH1D*)gDirectory->Get("timeVsAoSigmaMod4EBlog_0");
    //  chi2VsAoSigmaMod4EB_       = (TH1D*)gDirectory->Get("timeVsAoSigmaMod4EBlog_chi2");
    }
  }

  // fitting recHits times in bins of A/sigma, for EE
  TF1 *gaussEElargelogSlicesFit = new TF1("timeVsAoSigmaEElargelogSlicesFit","gaus",-7,7);
  TF1 *gaussLowEESlicesFit = new TF1("timeVsAoSigmaLowEESlicesFit","gaus",-7,7);
  TF1 *gaussHighEESlicesFit = new TF1("timeVsAoSigmaHighEESlicesFit","gaus",-7,7);
  for(int v=0; v<NSlices; v++){
    if( timeVsAoSigmaEElargelogSlices_[v]->Integral()  >= minEntriesForFit_ ){// do fit for this bin in EE,  require min number entries
      float RMS       = timeVsAoSigmaEElargelogSlices_[v] -> GetRMS();
      float mean      = timeVsAoSigmaEElargelogSlices_[v] -> GetMean();
      //      float area      = timeVsAoSigmaEElargelogSlices_[v] -> GetEntries();
      gaussEElargelogSlicesFit        ->SetParLimits(1,-5,5);  // limit on gaussian central 
      gaussEElargelogSlicesFit        ->SetParameter(1,mean);  // initialize on central value
      gaussEElargelogSlicesFit        ->SetParameter(2,RMS);   // initialize on central value
      timeVsAoSigmaEElargelogSlices_[v] -> Fit("timeVsAoSigmaEElargelogSlicesFit","","",-7,+7);  // fit on [-7,+7] ns range to stay away from spikes
      gaussEElargelogSlicesFit        ->SetParameter(1,0);  // re-initialize on central value
      gaussEElargelogSlicesFit        ->SetParameter(2,1);   // re-initialize on central value
      timeVsAoSigmaEElargelog_  ->FitSlicesY(gaussEElargelogSlicesFit,0,-1,0,"",0);  
      fittedRMSVsAoSigmaEElog_ = (TH1D*)gDirectory->Get("timeVsAoSigmaEElargelog_2");
      fittedMeanVsAoSigmaEElog_ = (TH1D*)gDirectory->Get("timeVsAoSigmaEElargelog_1");
      fittedAreaVsAoSigmaEElog_ = (TH1D*)gDirectory->Get("timeVsAoSigmaEElargelog_0");
      chi2VsAoSigmaEElog_       = (TH1D*)gDirectory->Get("timeVsAoSigmaEElargelog_chi2");
    }
    if( timeVsAoSigmaLowEESlices_[v]->Integral()  >= minEntriesForFit_ ){// do fit for this bin in EE,  require min number entries
      float RMS       = timeVsAoSigmaLowEESlices_[v] -> GetRMS();
      float mean      = timeVsAoSigmaLowEESlices_[v] -> GetMean();
      //      float area      = timeVsAoSigmaLowEESlices_[v] -> GetEntries();
      gaussLowEESlicesFit        ->SetParLimits(1,-5,5);  // limit on gaussian central 
      gaussLowEESlicesFit        ->SetParameter(1,mean);  // initialize on central value
      gaussLowEESlicesFit        ->SetParameter(2,RMS);   // initialize on central value
      timeVsAoSigmaLowEESlices_[v] -> Fit("timeVsAoSigmaLowEESlicesFit","","",-7,+7);  // fit on [-7,+7] ns range to stay away from spikes
      gaussLowEESlicesFit        ->SetParameter(1,0);  // re-initialize on central value
      gaussLowEESlicesFit        ->SetParameter(2,1);   // re-initialize on central value
      timeVsAoSigmaLowEElog_  ->FitSlicesY(gaussLowEESlicesFit,0,-1,0,"",0);  
      fittedRMSVsAoSigmaLowEE_ = (TH1D*)gDirectory->Get("timeVsAoSigmaLowEElog_2");
   //   fittedMeanVsAoSigmaLowEE_ = (TH1D*)gDirectory->Get("timeVsAoSigmaLowEElog_1");
      fittedAreaVsAoSigmaLowEE_ = (TH1D*)gDirectory->Get("timeVsAoSigmaLowEElog_0");
      chi2VsAoSigmaLowEE_       = (TH1D*)gDirectory->Get("timeVsAoSigmaLowEElog_chi2");
    }
    if( timeVsAoSigmaHighEESlices_[v]->Integral()  >= minEntriesForFit_ ){// do fit for this bin in EE,  require min number entries
      float RMS       = timeVsAoSigmaHighEESlices_[v] -> GetRMS();
      float mean      = timeVsAoSigmaHighEESlices_[v] -> GetMean();
      //      float area      = timeVsAoSigmaHighEESlices_[v] -> GetEntries();
      gaussHighEESlicesFit        ->SetParLimits(1,-5,5);  // limit on gaussian central 
      gaussHighEESlicesFit        ->SetParameter(1,mean);  // initialize on central value
      gaussHighEESlicesFit        ->SetParameter(2,RMS);   // initialize on central value
      timeVsAoSigmaHighEESlices_[v] -> Fit("timeVsAoSigmaHighEESlicesFit","","",-7,+7);  // fit on [-7,+7] ns range to stay away from spikes
      gaussHighEESlicesFit        ->SetParameter(1,0);  // re-initialize on central value
      gaussHighEESlicesFit        ->SetParameter(2,1);   // re-initialize on central value
      timeVsAoSigmaHighEElog_  ->FitSlicesY(gaussHighEESlicesFit,0,-1,0,"",0);  
      fittedRMSVsAoSigmaHighEE_ = (TH1D*)gDirectory->Get("timeVsAoSigmaHighEElog_2");
      fittedMeanVsAoSigmaHighEE_ = (TH1D*)gDirectory->Get("timeVsAoSigmaHighEElog_1");
      fittedAreaVsAoSigmaHighEE_ = (TH1D*)gDirectory->Get("timeVsAoSigmaHighEElog_0");
      chi2VsAoSigmaHighEE_       = (TH1D*)gDirectory->Get("timeVsAoSigmaHighEElog_chi2");
    }
  }
}// end doFinalPlots

