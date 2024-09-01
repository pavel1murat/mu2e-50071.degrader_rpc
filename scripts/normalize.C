
//
#include "eff_vs_egamma.C"

int normalize(TH1F* Hist) {

  TH1F* h = (TH1F*) Hist->Clone("h");

  int nb = h->GetNbinsX();

  for (int i=1; i<=nb; i++) {
    double e = Hist->GetBinCenter(i);
    double eff = eff_vs_egamma(e);
    
    double val(0);
    if (eff  > 0) val = h->GetBinContent(i)/eff;

    h->SetBinContent(i,val);
    h->SetBinError(i,0);
  }

  h->Draw();
  return 0;
}
