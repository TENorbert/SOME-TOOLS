###############
// fxn takes two histograms and finds their bin by bin subtraction

#include "TProfile2D.h"

#include <iostream.h>

using namespace std;

TProfile2D* CCUTimingShiftFromLaser( TProfile2D* hprof_runA, TProfile2D* hprof_runB)
{
  if(!hprof_runA){cout << "No input histograms was put" << endl;}

  TProfile2D*  clonehprof = (TProfile2D*)hprof_runA->Clone("CCUMeantimeDiff");

  //subtract Histograms:
  clonehprof->Add(hprof_runB, -1);
  clonehprof->SetMinimum(-5);
  clonehprof->SetMaximum(-5);

  //  Tprofile2D* hprofdiff = new TProfile2D("

  return clonehprof;
}
