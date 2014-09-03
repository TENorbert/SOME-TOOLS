#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include "TROOT.h"
//#include<dealloc>
#include "TH1F.h"
#include "TFile.h"
#include "TSystem.h"
#include "TLegend.h"
#include "TText.h"
#include "TPaveText.h"
#include "TCanvas.h"
#include "TKey.h"

#include <iostream>

using namespace std;

#include "atlas_style.C"

void plot()
{

   gROOT->Reset();
   // initialize style
   //gROOT->ProcessLine(".L atlas_style.C");

   atlas_style();

   std::vector< TFile* > rootfiles;
   std::vector< std::string > root_subdirs;
   std::vector< std::string > histo_names;
   std::vector< double > histo_max_values;
   std::vector< std::string > generator_label;
   std::vector< std::string > histo_ext;
   std::vector< std::string > logscale_identifier;
   std::vector< double > crosssections;
   std::vector< int > NumberOfEvents;

   std::string targetdir;


   // ************************************************************************************************
   // ************************************************************************************************
   // Please modify these Parameters/Variables according to your needs

   // Set Output file format ... you can specify several formats (e.g. gif (wabpage) and eps (paper))
   histo_ext.push_back("eps");
   histo_ext.push_back("gif");
   histo_ext.push_back("png");
   //histo_ext.push_back("tiff");

   //If you want to compare another Generator than just specify the rootfile similar to the two above

   // Set the base directory ... The histogramms will be saved in this directory
   std::string pwd=gSystem->pwd();
   std::string baseDirectory;

   // if this flag is set to true, than the target directory will be created, if it does not exist 
   bool createTargetDir=true;
   // if this flag is set to true, HTML page will be created
   bool generateHTMLpage=true;

   // If the name contains this string than 
   // logscale will be enabled
   logscale_identifier.push_back("_logscale");

   // ************************************************************************************************
   // ************************************************************************************************

   std::cout << "Read Filelist: " << std::endl;
   string line;
   ifstream myfile ("plotFiles.list");

   if (myfile.is_open())
   {
      // read line by line of the file                                                                                                                                                                                 
      while (! myfile.eof() )
      {
         // write read lines into string line                                                                                                                                                                     
         getline(myfile,line);
         // check for Comments. If the line starts with # than skip the line                                                                                                                                     
         std::string::size_type pos = line.find("#");
         if(pos != std::string::npos) continue;
	    
         cout << line << endl;

         // now split the line into the subwords
         // and write the substrings into vector
         std::istringstream instring(line);
         std::string string1;
         std::string string2;
         std::string string3;

         // split the line again but using as numbers to read in
         // the crosssections 
         std::istringstream instring2(line);
         std::string temp;
         double mydouble1;
         double mydouble2;

         instring >> string1 >> string2 >> string3;
         instring2 >> temp >> temp >> temp >> mydouble1 >> mydouble2;

         if((string1 == "->") ||(string1 == "in") ){
            // check wether the file is a root-file
            std::string::size_type posExt = string3.find(".root");
            if(posExt == std::string::npos) continue;

            generator_label.push_back(string2);
            rootfiles.push_back(new TFile(string3.c_str()));
            crosssections.push_back(mydouble1);
            NumberOfEvents.push_back(mydouble2);
            if(!rootfiles.back()->IsOpen())
            {
               std::cout << string3 << " could not be opened! ... skip!" << std::endl;
               gROOT->ProcessLine(".q");
            }
         }
         else if((string1 == "<-") ||(string1 == "out") ) {
            //baseDirectory=string3 +"/"+string2;
            baseDirectory=string2;
            continue;
         }

      }
      myfile.close();
   }
   else {
      cout << "Unable to open file";
      gROOT->ProcessLine(".q");
   }




   // Kolmogorov test minimal value
   Double_t kt_min_result=0.1;
   Double_t kt_medium_result=0.7;

   // Default fill for First distribution drawn
   Double_t fillColor=0;

   // scale y-range with maximum
   Double_t scale_y=1.3;

   // constructor options for TCanvas
   Int_t wtopx=200;
   Int_t wtopy=10;
   Int_t ww=600;
   Int_t wh=400;

   // TLegend Properties
   Double_t tl_x1=0.775;
   Double_t tl_x2=0.975;
   Double_t tl_y1=0.9;
   Double_t tl_y2=0.92;
   Double_t tl_ystep=0.05;
   Double_t tl_textsize=0.035;


   //TPaveText Coordinates Pavetext1
   Double_t pt1_x1=0.505;
   Double_t pt1_x2=0.765;
   Double_t pt1_y1=0.8;
   Double_t pt1_y2=0.92;
   Double_t pt1_textsize=0.03;

   //TPaveText Coordinates Pavetext2
   Double_t pt2_x1=0.235;
   Double_t pt2_x2=0.495;
   Double_t pt2_y1=0.75;
   Double_t pt2_y2=0.92;
   Double_t pt2_ystep=0.0;
   Double_t pt2_textsize=0.03-0.01*(rootfiles.size()-2);

   // // check wether the target directory exists
   // if(!gSystem->cd(baseDirectory.c_str()))
   // {
   //     // if the variable createTargetDir is set to true, than the directory will be created
   //     std::cout << "target base Directory does not exist ..." << std::endl;
   //     if(createTargetDir){
   // 	gSystem->mkdir(baseDirectory.c_str(),true);
   // 	std::cout << "... create target base Directory!" << std::endl;
   //     }
   //     // otherwise you will be asked to create the directory and the programm will end
   //     else{
   // 	std::cout << "Please create the target directory first:" << std::endl;
   // 	std::cout << "mkdir -p " << baseDirectory.c_str() << std::endl;
   // 	std::cout << "... skip" << std::endl;
   // 	gROOT->ProcessLine(".q");
   //     }
   // }
   // change back to the working directory
   gSystem->cd(pwd.c_str());

   // need to scan rootfiles for subdirs and histograms
   TKey *key_dir;
   TKey *key_histo;


   std::cout << "First scan through the files to get the needed Information ..." << std::endl;

   // Loop  over the files
   for(unsigned int files=0; files<rootfiles.size(); files++) {

      // list the files
      std::cout << "File " << files+1 << " : " <<  rootfiles[files]->GetName() << std::endl;
      rootfiles[files]->cd();
    
      // get the iterator for the subdirectories in the file
      TIter nextkey(rootfiles[files]->GetListOfKeys());

      // loop over the TDirectories
      while (key_dir = (TKey*)nextkey()) {
         TDirectory * currentrootdir = (TDirectory*)key_dir->ReadObj();
         std::string classname= currentrootdir->ClassName();
         if(classname != std::string("TDirectoryFile")) continue;

         std::string currentrootdirname=currentrootdir->GetName();
	
         // get the name of the TDirectory
         bool direxists=false;
         for(unsigned int dir=0; dir < root_subdirs.size(); dir++){
            if(root_subdirs[dir]==currentrootdirname) direxists=true;
            if(direxists) break;
         }
         if(!direxists)
            root_subdirs.push_back(currentrootdirname);
	
         // Loop over the histograms in the TDirectory
         TIter nextkey2(currentrootdir->GetListOfKeys());
         while (key_histo=(TKey*)nextkey2()){
            TH1F* currenthisto = (TH1F*)key_histo->ReadObj();

            std::string classname2= currenthisto->ClassName();
            if(classname2 != std::string("TH1F")) continue;
	    
            // Number of bins of the current histogram
            int numberOfBins = currenthisto->GetNbinsX();
            for(int nbin=0; nbin <= numberOfBins; nbin++){
               double BinContent = max (0., currenthisto->GetBinContent(nbin));
               double BinError = currenthisto->GetBinError(nbin);
               double NewBinContent = BinContent * crosssections[files] / NumberOfEvents[files];
               double NewBinError = BinError * crosssections[files] / NumberOfEvents[files];
               currenthisto->SetBinContent(nbin, NewBinContent);
               currenthisto->SetBinError(nbin, NewBinError);
               //currenthisto->Sumw2();
            }
            double integral = currenthisto->Integral();
            if (integral)
            {
               currenthisto->Scale( 1. / integral );
            }
            //currenthisto->SetMaximum( 1.3 * currenthisto->GetMaximum() );

            // Name of the current histogram
            std::string currenthistoname=currenthisto->GetName();

            // Maximum of the current histogram
            double currentmax=currenthisto->GetMaximum();

            // check wether histogramname already filled in vector
            bool histoexists=false;
            for(unsigned int histo=0; histo < histo_names.size(); histo++){
               if(histo_names[histo]!=currenthistoname)  continue; 
               histoexists=true;
		
               // for histograms with same name (to be compared) set the maximum to the maximum of both histograms
               if(currentmax>histo_max_values[histo]) histo_max_values[histo]=currentmax;
		    
               // if histogramname found than, quit the loop 		        
               if(histoexists) break;
            }
	    
            // if it is not found than append name and maximum to the vector
            if(!histoexists){
               histo_names.push_back(currenthistoname);
               histo_max_values.push_back(currentmax );
            }
            delete currenthisto;
         }
	
         delete currentrootdir;
      } // while key_dir


   }  // for files

   std::cout << "Now actually plot the histograms ..." << std::endl;

   // create a TCanvas to generate the histograms
   TCanvas* c1 = new TCanvas("c1","Jet Validation",wtopx,wtopy,ww,wh);

   std::string command;
   std::string histo_filename;

   // Loop over the directories
   for(unsigned int dir=0; dir < root_subdirs.size(); dir++){

      cout << root_subdirs[dir].c_str() << endl;
      //targetdir= baseDirectory + "/" + root_subdirs[dir];
      targetdir= baseDirectory + "_" + root_subdirs[dir];

      // check wether the directory exists
      if(!gSystem->cd(targetdir.c_str())){
         std::cout << "Directory " << targetdir.c_str() << " does not exist! Will be created ..." << std::endl;
         gSystem->mkdir(targetdir.c_str());
         std::cout << "... done!" << std::endl;
      }
      else{
         // if directory exists, than clean up existing files.
         // They will be overwritten anyway, but do not want to mix up old and new files
         command="rm -rf ";
         for(unsigned int ext=0; ext<histo_ext.size(); ext++)
            command += targetdir + "/*." + histo_ext[ext] + " ";

         gSystem->Exec(command.c_str());
         std::cout << "Execute the command : " << command.c_str() << std::endl;
      }

      // Loop over the histograms
      for(unsigned int histo=0; histo < histo_names.size(); histo++){
         int colour=1;
         int lstyle=1;

         // Define the Legend and set the Properties
         TLegend* mylegend = new TLegend(tl_x1,tl_y1-rootfiles.size()*tl_ystep,tl_x2,tl_y2);
         mylegend->SetHeader("Generator Validation");
         mylegend->SetTextSize(tl_textsize);
         mylegend->SetFillColor(kWhite);

         bool histoexists=false;
         bool logscale=false;

         TH1F * firsthisto=0;

         // create TPaveText to show first Generator statistics
         TPaveText* pt1_text = new TPaveText(pt1_x1,pt1_y1,pt1_x2,pt1_y2,"NDC");
         pt1_text->SetTextSize(pt1_textsize);
         pt1_text->SetFillColor(kWhite);

         // create TPaveText to show other Generators statistics
         TPaveText* pt2_text = new TPaveText(pt2_x1,pt2_y1,pt2_x2,pt2_y2,"NDC");
         pt2_text->SetTextSize(pt2_textsize);
         //pt2_text->SetFillColor(kGreen);
         //currently set on white until Kolmogorov test is fully understood
         pt2_text->SetFillColor(kWhite);

         // Loop over the inputfiles
         for(unsigned int files=0; files<rootfiles.size(); files++){

            if((colour == 1) || (colour == 3) || (colour == 5)) colour++;
            if((colour == 1) || (colour == 3) || (colour == 5)) colour++;
            if((colour == 1) || (colour == 3) || (colour == 5)) colour++;

            rootfiles[files]->cd();
            TDirectory * currentrootdir = (TDirectory *)rootfiles[files]->Get(root_subdirs[dir].c_str());
            TH1F* currenthisto = (TH1F*)currentrootdir->Get(histo_names[histo].c_str());
            if(!currenthisto) continue;

            // according to the name the Canvas will be set to logscale
            if(currenthisto->GetEntries())
               for(unsigned int lscale=0; lscale<logscale_identifier.size(); lscale++)
                  if(histo_names[histo].find(logscale_identifier[lscale],0) != string::npos) 
                     logscale=true;
	    
            histoexists=true;
	    
            TPaveText* temp_pavetext;
            char temptext[100];
            TText* textline;

            // Draw the histograms in one Canvas

            // Number of bins of the current histogram
            int numberOfBins = currenthisto->GetNbinsX();
            for(int nbin=0; nbin <= numberOfBins; nbin++){
               double BinContent = std::max (0., currenthisto->GetBinContent(nbin));
               double BinError = currenthisto->GetBinError(nbin);
               double NewBinContent = BinContent * crosssections[files]  / NumberOfEvents[files];
               double NewBinError = BinError * crosssections[files]  / NumberOfEvents[files];
               currenthisto->SetBinContent(nbin, NewBinContent);
               currenthisto->SetBinError(nbin, NewBinError);
            }
            double integral = currenthisto->Integral();
            if (integral)
            {
               currenthisto->Scale ( 1. / integral );
            }
            currenthisto->SetLineColor(colour);
            currenthisto->SetLineStyle(lstyle++);

            if(files==0) 
            {
               firsthisto=currenthisto;
               temp_pavetext=pt1_text;

               //currenthisto->GetYaxis()->SetRangeUser(0.1*logscale,TMath::Max(histo_max_values[histo]*1.0,0.1*logscale)*scale_y*(1+logscale*50));
               //currenthisto->GetYaxis()->SetRangeUser(0.1*logscale*pow(histo_max_values[histo],2),TMath::Max(histo_max_values[histo]*1.0,0.1*logscale)*scale_y*(1+logscale*50));
               //currenthisto->GetYaxis()->SetRangeUser(0.1,TMath::Max(histo_max_values[histo]*1,0.1*logscale)*scale_y*(1+logscale*50));
               currenthisto->SetMaximum( 1.3 * currenthisto->GetMaximum() );

               currenthisto->SetFillColor(fillColor);
               currenthisto->Draw("HIST");
            }
            else{
               currenthisto->Draw("HIST SAME");
               temp_pavetext=pt2_text;
            }

            // fill Legend
            mylegend->AddEntry(currenthisto,generator_label[files].c_str(),"l");

            // Fill PaveText
            sprintf(temptext,"%s: ",generator_label[files].c_str());
            textline=temp_pavetext->AddText(temptext);
            textline->SetTextAlign(11);
            sprintf(temptext,"   Entries=%d",currenthisto->GetEntries());
            textline=temp_pavetext->AddText(temptext);
            textline->SetTextAlign(11);
            sprintf(temptext,"   #bar{x}=%.2g, RMS=%.2g",currenthisto->GetMean(),currenthisto->GetRMS());
            textline=temp_pavetext->AddText(temptext);
            textline->SetTextAlign(11);
            sprintf(temptext,"   UF=%.2g, OF=%.2g",currenthisto->GetBinContent(0),currenthisto->GetBinContent(currenthisto->GetNbinsX()+1));
            textline=temp_pavetext->AddText(temptext);
            textline->SetTextAlign(11);
            textline=temp_pavetext->AddText("");
            textline->SetTextSize(0.004);

            colour++;

            if(firsthisto==currenthisto) continue;

            double tempresult=0;
            double tempresult2=0;

            // only make test, if histogram not empty
            if(!currenthisto->GetEntries()) continue;

            tempresult=currenthisto->KolmogorovTest(firsthisto);
            tempresult2=currenthisto->Chi2Test(firsthisto,"WW CHI2/NDF");

            // If Kolmogorov test returns value less than kv_min, fill TPaveText red
            //currently set on white until Kolmogorov test is fully understood
            //if(tempresult<=kt_min_result) temp_pavetext->SetFillColor(kRed);
            //if(tempresult>kt_min_result && tempresult<=kt_medium_result) temp_pavetext->SetFillColor(kYellow);
            if(tempresult<=kt_min_result) temp_pavetext->SetFillColor(kWhite);
            if(tempresult>kt_min_result && tempresult<=kt_medium_result) temp_pavetext->SetFillColor(kWhite);

            textline=temp_pavetext->AddText("Tests:");
            textline->SetTextAlign(11);
            sprintf(temptext,"KS: %.3g , #chi^{2}/NDF: %.3g",tempresult,tempresult2);
            textline=temp_pavetext->AddText(temptext);
            textline->SetTextAlign(11);
            textline=temp_pavetext->AddText("");
            textline->SetTextSize(0.005);

         }

         // draw Legend
         mylegend->Draw();

         // draw TPaveText
         if(rootfiles.size()>1)
            pt2_text->Draw();
         pt1_text->Draw();

         // save the Canvas in a file ... according to the formats specified at the top of the script
         if(histoexists){
            for(unsigned int ext=0; ext<histo_ext.size(); ext++){
               //histo_filename=targetdir+"/"+histo_names[histo]+"."+histo_ext[ext];
               histo_filename=baseDirectory+"_"+root_subdirs[dir]+"/"+histo_names[histo]+"."+histo_ext[ext];
               // for some histograms also plot logscale
               c1->SetLogy(logscale);
               c1->Update();
               c1->SaveAs(histo_filename.c_str());
	      
            }
         }
         delete mylegend;
      }
      // If a HTML page is requested, than copy html-script to the targetdir and run script
      if(generateHTMLpage){
         command="cp " + pwd + "/mkHTML.py " + targetdir + "/.";
         //command="cp " + pwd + "/mkHTML.py " + baseDirectory+"_"+root_subdirs[dir] + "/.";
         gSystem->Exec(command.c_str());
         std::cout << "Execute the command : " << command.c_str() << std::endl;
      
         command = "cd " + targetdir;
         //command = "cd " + baseDirectory+"_"+root_subdirs[dir];
         gSystem->Exec(command.c_str());
         std::cout << "Execute the command : " << command.c_str() << std::endl;

         command = targetdir + "/mkHTML.py";
         //command = baseDirectory+"_"+root_subdirs[dir] + "/mkHTML.py";
         //command = "./mkHTML.py >test.txt";
         gSystem->Exec(command.c_str());
         std::cout << "Execute the command : " << command.c_str() << std::endl;
      
         command = "cd " + pwd;
         gSystem->Exec(command.c_str());
         std::cout << "Execute the command : " << command.c_str() << std::endl;
      }
   }

   // clean up pointer
   delete c1;

   // clean vector of Pointer
   while(!rootfiles.empty()){
      delete rootfiles.back();
      rootfiles.pop_back();
   }

   while(!root_subdirs.empty())
      root_subdirs.pop_back();

   while(!histo_names.empty())
      histo_names.pop_back();

   while(!histo_max_values.empty())
      histo_max_values.pop_back();

   while(!generator_label.empty())
      generator_label.pop_back();

   while(!histo_ext.empty())
      histo_ext.pop_back();

   while(!logscale_identifier.empty())
      logscale_identifier.pop_back();

}
