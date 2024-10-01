//-----------------------------------------------------------------------------
// t2_0/  : (P1+P2) rpc07b0s54r0100, full range
//-----------------------------------------------------------------------------
plot_data_t* plot_figure_0084(int Figure, int Print) {
    
  const char* rpc04b0s54 = "pipenu.rpc04b0s54r0100";
  //  const char* cele2b0s51 = "pipenu.cele2b0s51r0100";

  const char* book       = "pipenu";
  const char* ana_job    = "murat_drpc_ana.0000";
  const char* ana_module = "murat_DrpcAna";
  const char* hist_name  = "t2_1/smom_0";

  plot_data_t* pdata     = new plot_data_t(1);   // 1 histograms
  plot_data_t& p         = *pdata;
//-----------------------------------------------------------------------------
// 
//------------------------------------------------------------------------------
  p.hd[0]              = hist_data_t(catalog,book,rpc04b0s54,ana_job,ana_module,hist_name);
  p.hd[0].fNewName     = "p1+p2";
  p.hd[0].fRebin       = 1;
  p.hd[0].fLabel       = "P(e+) + P(e-), reconstructed";
  p.hd[0].fDrawOpt     = "h";
  p.hd[0].fLineColor   = kRed+2;
  p.hd[0].fLineWidth   = 2;
  p.hd[0].fStatFormat  = "6.5g";
  p.hd[0].fFitFormat   = "8.6g";
  // p.hd[0].fMarkerColor = kBlack;
  // p.hd[0].fMarkerStyle = 20;
  // p.hd[0].fMarkerSize  = 0.1;
    
   
  // p.fXMin              = 103.01;
  // p.fXMax              = 105;
  // p.fYMin              = 1e-4;
  // p.fYMax              = 1e3;
  p.fCanvasName        = Form("Figure_%04i",Figure);
  // p.fCanvasSizeX        = 800;
  // p.fCanvasSizeY        = 800;
  p.fName              = Form("figure_%05i",Figure);
  p.fLabel             = "photon energy ";
  p.fXAxisTitle        = "P1+P2, MeV/c";
  p.fYLogScale         = 0;

  p.fStatBoxXMin       = 0.70;
  p.fStatBoxXMax       = 0.90;
  p.fStatBoxYMax       = 0.90;
  p.fStatBoxYMin       = 0.70;

  p.fLegendXMin        = 0.30; p.fLegendXMax  = 0.70; p.fLegendYMin  = 0.7; p.fLegendYMax  = 0.82; 
    
  plot_hist_1d(&p,-1);

  // cb4* cbx = new cb4("x");
  // cbx->fHist = (TH1F*) p.hd[0].fHist;
  // cbx->init_parameters(1280,128.6,0.258,7.8,5,2,1.3,2.);
  // cbx->fit(124,132);
  
  p.fCanvas->Modified();
  p.fCanvas->Update();

  // TArrow* arr = new TArrow(200,100,200,20,0.015);
  // arr->Draw();

  printf(" plot.C p.fOutputFn = %s\n",p.fOutputFn.Data());
    
  if (Print == 1) p.print() ;

  return pdata;
}
