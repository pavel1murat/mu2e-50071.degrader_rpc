//-----------------------------------------------------------------------------
// CE momentum
//-----------------------------------------------------------------------------
plot_data_t* plot_figure_0052(int Figure, int Print) {
    
  const char* cele0b0s51 = "pipenu.cele0b0s51r0100";
  const char* cele3b0s51 = "pipenu.cele3b0s51r0100";

  const char* book       = "pipenu";
  const char* ana_job    = "murat_trk_ana.0000";
  const char* ana_module = "TrackAna";
  const char* hist_name  = "trk_0/p";

  plot_data_t* pdata     = new plot_data_t(2);   // 2 histograms
  plot_data_t& p         = *pdata;
//-----------------------------------------------------------------------------
// 
//------------------------------------------------------------------------------
  p.hd[0]              = hist_data_t(catalog,book,cele0b0s51,ana_job,ana_module,hist_name);
  p.hd[0].fNewName     = "cele0b0";
  p.hd[0].fRebin       = 1;
  p.hd[0].fLabel       = "default";
  p.hd[0].fDrawOpt     = "h";
  p.hd[0].fLineColor   = kRed+2;
  p.hd[0].fLineWidth   = 2;
  // p.hd[0].fMarkerColor = kBlack;
  // p.hd[0].fMarkerStyle = 20;
  // p.hd[0].fMarkerSize  = 0.1;
    
  p.hd[1]              = hist_data_t(catalog,book,cele3b0s51,ana_job,ana_module,hist_name);
  p.hd[1].fNewName     = "cele3b0";
  p.hd[1].fRebin       = 1;
  p.hd[1].fLabel       = "degrader v4";
  p.hd[1].fDrawOpt     = "h";
  p.hd[1].fLineColor   = kBlue+3;
  p.hd[1].fFillColor   = kBlue+3;
  p.hd[1].fFillStyle   = 3004;
  // p.hd[1].fMarkerColor = kBlack;
  // p.hd[1].fMarkerStyle = 20;
  // p.hd[1].fMarkerSize  = 0.1;
    
   p.fXMin              = 103.01;
   p.fXMax              = 105;
  // p.fYMin              = 1e-4;
  // p.fYMax              = 1e3;
  p.fCanvasName        = Form("Figure_%04i",Figure);
  // p.fCanvasSizeX        = 800;
  // p.fCanvasSizeY        = 800;
  p.fName              = Form("figure_%05i",Figure);
  p.fLabel             = "reconstructed CE momentum";
  p.fXAxisTitle        = "P, MeV/c";
  p.fYLogScale         = 0;

  p.fStatBoxXMin       = 0.70;
  p.fStatBoxXMax       = 0.90;
  p.fStatBoxYMax       = 0.90;
  p.fStatBoxYMin       = 0.70;

  p.fLegendXMin        = 0.25; p.fLegendXMax  = 0.45; p.fLegendYMin  = 0.7; p.fLegendYMax  = 0.82; 
    
  plot_hist_1d(&p,-1);

  p.fCanvas->Modified();
  p.fCanvas->Update();

  // TArrow* arr = new TArrow(200,100,200,20,0.015);
  // arr->Draw();

  printf(" plot.C p.fOutputFn = %s\n",p.fOutputFn.Data());
    
  if (Print == 1) p.print() ;

  return pdata;
}
