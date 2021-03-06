import math
 
 class ABCDCalculator(object):
 """Class to calculate background using the ABCD method"""
 def __init__(self, x, y):
 self.x = x
 self.y = y
 def set_x_data(self, data):
 """Give the calculator the x data"""
 self.x = data
 def set_y_data(self, data):
 """Give the calculator the y data"""
 self.y = data
 def set_x_background(self, low, high):
 """Set the background region for the x variable"""
 self.x_bkg_low = low
 self.x_bkg_high = high
 def set_y_background(self, low, high):
 """Set the background region for the y variable"""
 self.y_bkg_low = low
 self.y_bkg_high = high
 def set_x_signal( self, low, high):
 """Set the signal region for the x variable"""
 self.x_sig_low = low
 self.x_sig_high = high
 def set_y_signal( self, low, high):
 """Set the signal region for the y variable"""
 self.y_sig_low = low
 self.y_sig_high = high
 def get_background_estimate( self ):
 """Return the background estimate in the signal region"""
 return 1.*self.B()*self.C()/self.A()
 def get_background_estimate_uncertainty( self):
 """Return the uncertainty on the background estimate."""
 return self.get_background_estimate()*math.sqrt(1./self.B()+1./self.C()-1./self.A())
 def A(self):
 """Return number of events in the A region"""
 return len([(x,y) for (x,y) in zip(self.x, self.y) if\
 self.x_bkg_low < x < self.x_bkg_high and\
 self.y_bkg_low < y < self.y_bkg_high])
 def B(self):
 """Return number of events in the B region"""
 return len([(x,y) for (x,y) in zip(self.x, self.y) if\
 self.x_bkg_low < x < self.x_bkg_high and\
 self.y_sig_low < y < self.y_sig_high])
 def C(self):
 """Return the number of events in the C region"""
 return len([(x,y) for (x,y) in zip(self.x, self.y) if\
 self.x_sig_low < x < self.x_sig_high and\
 self.y_bkg_low < y < self.y_bkg_high])
 def D(self):
 """Return the number of events in the C region"""
 return len([(x,y) for (x,y) in zip(self.x, self.y) if\
 self.x_sig_low < x < self.x_sig_high and\
 self.y_sig_low < y < self.y_sig_high]) 
