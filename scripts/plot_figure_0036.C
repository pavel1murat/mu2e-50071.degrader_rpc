//-----------------------------------------------------------------------------
// bpim0b0s24 : ystop:xstop
//-----------------------------------------------------------------------------
plot_data_t* plot_figure_0036(int Figure, int Print) {
    
  const char* bpim0b0s21 = "pipenu.bpim0b0s21r0000";
  const char* bpim0b0s24 = "pipenu.bpim0b0s24r0000";
  const char* bpim0b0s25 = "pipenu.bpim0b0s25r0000";

  const char* book       = "pipenu";
  const char* ana_job    = "murat_spmc_ana.0000";
  const char* ana_module = "murat_SpmcAna";
  const char* hist_name  = "simp_205/ye_vs_p";

  plot_data_t* pdata     = new plot_data_t(1);   // 1 histogram
  plot_data_t& p         = *pdata;
//-----------------------------------------------------------------------------
// 100000: the number of generated pi+ --> e+ nu events in each sample
// 2.5e8 : the number of POT generated to get the pion stops
// 1.23e-4 : BR(pi --> e nu)
//------------------------------------------------------------------------------
  p.hd[0]              = hist_data_t(catalog,book,bpim0b0s24,ana_job,ana_module,hist_name);
  p.hd[0].fNewName     = "y_vs_p_ch2";
  p.hd[0].fRebin       = 1;
  p.hd[0].fLabel       = "CH2";
  p.hd[0].fMarkerColor = kBlack;
  p.hd[0].fMarkerStyle = 20;
  p.hd[0].fMarkerSize  = 0.1;
  // p.hd[0].fLineWidth   = 2;
  // p.hd[0].fDrawOpt     = "scat";
    
  p.fXMin              =  0.;
  p.fXMax              = 100;
  // p.fYMin              = 1e-4;
  // p.fYMax              = 1e3;
  p.fCanvasName        = Form("Figure_%04i",Figure);
  p.fCanvasSizeX        = 800;
  p.fCanvasSizeY        = 800;
  p.fName              = Form("figure_%05i",Figure);
  p.fLabel             = "";
  p.fXAxisTitle        = "P, MeV/c";
  p.fYLogScale         = 0;

  p.fStatBoxXMin       = 0.75;
  p.fStatBoxXMax       = 0.90;
  p.fStatBoxYMax       = 0.90;
  p.fStatBoxYMin       = 0.75;

  p.fLegendXMin        = 0.25; p.fLegendXMax  = 0.45; p.fLegendYMin  = 0.7; p.fLegendYMax  = 0.85; 
    
  plot_hist_2d(&p,-1);

  p.fCanvas->Modified();
  p.fCanvas->Update();

  // TArrow* arr = new TArrow(200,100,200,20,0.015);
  // arr->Draw();

  printf(" plot.C p.fOutputFn = %s\n",p.fOutputFn.Data());
    
  if (Print == 1) p.print() ;

  return pdata;
}
