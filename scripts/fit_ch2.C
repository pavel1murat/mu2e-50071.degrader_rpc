//

#include "make_ch2.C"
#include "make_h2.C"
#include "make_c12.C"

TH1F *h_ch2(nullptr), *h_h2(nullptr), *h_c12(nullptr);
TF1* fun;
//-----------------------------------------------------------------------------
double fitf(double* X, double* P) {

  int bin = h_ch2->FindBin(X[0]);

  double f = P[0]*h_h2->GetBinContent(bin) + P[1]*h_c12->GetBinContent(bin);

  return f;
}


//-----------------------------------------------------------------------------
int fit_ch2() {

  // make histograms

  make_ch2(h_ch2);
  h_ch2->Scale(1/h_ch2->Integral());
  make_h2(h_h2);
  h_h2->Scale(1/h_h2->Integral());
  make_c12(h_c12);
  h_c12->Scale(1/h_c12->Integral());

  fun = new TF1("fitf",fitf,50,150,2);

  fun->SetParameter(0,0.5);
  fun->SetParameter(1,0.5);

  h_ch2->Fit(fun,"","",50,150);

  return 0;
}
