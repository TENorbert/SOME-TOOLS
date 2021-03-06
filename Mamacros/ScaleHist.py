#  Tool Scales and put Histograms  in same file for HisFactory
## Aurthor Tambe E. Norbert a.k.a TEN (norbert@physics.umn.edu)

#!/usr/bin/env python
""" Scale and put histograms in same root file!"""
__version__ = "1.0"

import sys
import optparse
import shutil
import os
import re
from ROOT import *
from array import array

# ROOT general options
gROOT.SetBatch(kTRUE)
gROOT.SetStyle("Plain")
gStyle.SetOptStat("emruo")

#Get files
fmea = TFile("data_bg_file.root")
fsig = TFile("sig_gmbs6000.root")

#Get Histograms
h_data = fmea.Get("data_bg_file.root/h_dataTime")
h_bg   = fmea.Get("data_bg_file.root/h_bgTime")
h_sg   = fsig.Get("sig_gmsb6000.root/h_sgTime")
