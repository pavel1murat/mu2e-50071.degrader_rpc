//-----------------------------------------------------------------------------
// RPC3B0, RPC4B0,RPC5B
//-----------------------------------------------------------------------------
plot_data_t* plot_figure_0013(int Figure, int Print) {
    
  const char* rpc03b0    = "pipenu.rpc03b0s44r0000";
  const char* rpc04b0    = "pipenu.rpc04b0s44r0000";
  const char* rpc05b0    = "pipenu.rpc05b0s44r0000";

  const char* book       = "pipenu";
  const char* ana_job    = "murat_drpc_ana.0000";
  const char* ana_module = "murat_DrpcAna";
  const char* hist_name  = "drpc_2/smvd13_0";

  plot_data_t* pdata     = new plot_data_t(3);   // 3 histograms overlaid
  plot_data_t& p         = *pdata;
//-----------------------------------------------------------------------------
// 100000: the number of generated pi+ --> e+ nu events in each sample
// 2.5e8 : the number of POT generated to get the pion stops
// 1.23e-4 : BR(pi --> e nu)
//------------------------------------------------------------------------------
  p.hd[1]              = hist_data_t(catalog,book,rpc03b0,ana_job,ana_module,hist_name);
  // p.hd[0]              = bpip0b0->GetHistData(catalog,book,bpip0b0,ana_job,ana_module,hist_name);
  p.hd[1].fRebin       = 1;
  p.hd[1].fLabel       = "1mm Au";
  // p.hd[0].fMarkerColor = kRed+1;
  // p.hd[0].fMarkerStyle = 20;
  p.hd[1].fDrawOpt     = "h";
  //  p.hd[0].fLumiSF      = gPipenu->GetChannel("rpc03b0s44r0100")->NormSF();

  p.hd[0]              = hist_data_t(catalog,book,rpc05b0,ana_job,ana_module,hist_name);
  p.hd[0].fRebin       = 1;
  p.hd[0].fLabel       = "0.2 mm Au";
  // p.hd[1].fMarkerColor = kBlue;
  // p.hd[1].fMarkerStyle = 21;
  // p.hd[1].fMarkerSize  = 0.8;
  p.hd[0].fLineWidth   = 2;
  p.hd[0].fDrawOpt     = "h";
  //  p.hd[1].fLumiSF      = gPipenu->GetChannel("rpc04bs44r0000")->NormSF();
    
  p.hd[2]              = hist_data_t(catalog,book,rpc04b0,ana_job,ana_module,hist_name);
  p.hd[2].fRebin       = 1;
  p.hd[2].fLabel       = "0.1 mm Au";
  p.hd[2].fLineColor   = kRed+1;
  p.hd[2].fFillColor   = kRed+1;
  p.hd[2].fFillStyle   = 3004;
  // p.hd[2].fMarkerColor = kGreen;
  // p.hd[2].fMarkerStyle = 22;
  // p.hd[2].fMarkerSize  = 0.8;
  p.hd[2].fDrawOpt     = "h";
  p.hd[2].fLumiSF      = 1./100; // gPipenu->GetChannel("bpip3b0s51r0100")->NormSF();
    
  p.fXMin              = 0.;
  p.fXMax              = 200;
  p.fYMin              = 0; // 1e-16;
  p.fYMax              = 70.; // 8e-12;
  p.fCanvasName        = Form("Figure_%04i",Figure);
  p.fName              = Form("figure_%05i",Figure);
  p.fLabel             = "";
  p.fXAxisTitle        = "P1+P2, MeV/c";
  p.fYLogScale         = 0;

  p.fStatBoxXMin       = 0.75;
  p.fStatBoxXMax       = 0.90;
  p.fStatBoxYMax       = 0.90;
  p.fStatBoxYMin       = 0.75;

  p.fLegendXMin        = 0.45; p.fLegendXMax  = 0.65; p.fLegendYMin  = 0.7; p.fLegendYMax  = 0.85; 
    
  plot_hist_1d(&p,-1);

  p.fCanvas->Modified();
  p.fCanvas->Update();

  // TArrow* arr = new TArrow(200,100,200,20,0.015);
  // arr->Draw();

  printf(" plot.C p.fOutputFn = %s\n",p.fOutputFn.Data());
    
  if (Print == 1) p.print() ;

  return pdata;
}
