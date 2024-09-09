//-----------------------------------------------------------------------------
// bpim0b0s24 : ystop:xstop
//-----------------------------------------------------------------------------
plot_data_t* plot_figure_0044(int Figure, int Print) {
    
  const char* rpc04b0s44 = "pipenu.rpc04b0s44r0000";

  const char* book       = "pipenu";
  const char* ana_job    = "murat_drpc_ana.0000";
  const char* ana_module = "DegraderRpcAna";
  //  const char* hist_name  = "simp_205/y_vs_x";

  plot_data_t* pdata     = new plot_data_t(3);   // 1 histogram
  plot_data_t& p         = *pdata;
//-----------------------------------------------------------------------------
// 100000: the number of generated pi+ --> e+ nu events in each sample
// 2.5e8 : the number of POT generated to get the pion stops
// 1.23e-4 : BR(pi --> e nu)
//------------------------------------------------------------------------------
  p.hd[0]              = hist_data_t(catalog,book,rpc04b0s44,ana_job,ana_module,"drpc_2/smvd09_1");
  p.hd[0].fNewName     = "vd09";
  p.hd[0].fRebin       = 1;
  p.hd[0].fLabel       = "vd09";
  p.hd[0].fDrawOpt     = "h";
  p.hd[0].fLineColor   = kRed+2;
  // p.hd[0].fMarkerColor = kBlack;
  // p.hd[0].fMarkerStyle = 20;
  // p.hd[0].fMarkerSize  = 0.1;
    
  p.hd[1]              = hist_data_t(catalog,book,rpc04b0s44,ana_job,ana_module,"drpc_2/smvd10_1");
  p.hd[1].fNewName     = "vd10";
  p.hd[1].fRebin       = 1;
  p.hd[1].fLabel       = "vd10";
  p.hd[1].fDrawOpt     = "h";
  p.hd[1].fLineColor   = kBlue+2;
  p.hd[1].fFillColor   = kBlue+2;
  p.hd[1].fFillStyle   = 3004;
  // p.hd[1].fMarkerColor = kBlack;
  // p.hd[1].fMarkerStyle = 20;
  // p.hd[1].fMarkerSize  = 0.1;
    
  p.hd[2]              = hist_data_t(catalog,book,rpc04b0s44,ana_job,ana_module,"drpc_2/smvd13_1");
  p.hd[2].fNewName     = "vd13";
  p.hd[2].fRebin       = 1;
  p.hd[2].fLabel       = "vd13";
  p.hd[2].fDrawOpt     = "h";
  p.hd[2].fLineColor   = kGreen+2;
  p.hd[2].fFillColor   = kGreen+2;
  p.hd[2].fFillStyle   = 3005;
  // p.hd[2].fMarkerColor = kBlack;
  // p.hd[2].fMarkerStyle = 20;
  // p.hd[2].fMarkerSize  = 0.1;
    
   p.fXMin              = 120.;
   p.fXMax              = 135;
  // p.fYMin              = 1e-4;
  // p.fYMax              = 1e3;
  p.fCanvasName        = Form("Figure_%04i",Figure);
  // p.fCanvasSizeX        = 800;
  // p.fCanvasSizeY        = 800;
  p.fName              = Form("figure_%05i",Figure);
  p.fLabel             = "100 um Au converter";
  p.fXAxisTitle        = "P1+P2, MeV/c";
  p.fYLogScale         = 0;

  p.fStatBoxXMin       = 0.75;
  p.fStatBoxXMax       = 0.90;
  p.fStatBoxYMax       = 0.90;
  p.fStatBoxYMin       = 0.75;

  p.fLegendXMin        = 0.25; p.fLegendXMax  = 0.45; p.fLegendYMin  = 0.7; p.fLegendYMax  = 0.85; 
    
  plot_hist_1d(&p,-1);

  p.fCanvas->Modified();
  p.fCanvas->Update();

  // TArrow* arr = new TArrow(200,100,200,20,0.015);
  // arr->Draw();

  printf(" plot.C p.fOutputFn = %s\n",p.fOutputFn.Data());
    
  if (Print == 1) p.print() ;

  return pdata;
}
