///////////////////////////////////////////////////////////////////////////////
// HistDir and FiguresDir have to be defined before init_local_files.C
// always print in .eps, convert to .png or .pdf in GNUMakefile
//
///////////////////////////////////////////////////////////////////////////////
const char* Mu2eNotesDir        = "/exp/mu2e/data/projects/pipenu/notes";     // mu2egpvm*
const char* Mu2eHistDir         = "/exp/mu2e/data/projects/pipenu/hist";      // mu2egpvm*

const char* NoteRepo            = "mu2e-50071.degrader_rpc";

char  FiguresDir    [500] = "";
char  pipenu_HistDir[500] = "";

double BR_pienu   = 1.23e-4;
double NPOT_pienu = 2.5e8;          // 500(s1 jobs)x500,000(events per s1 job)

#include <stdio.h>
#include <string.h>
#include "Stntuple/val/stn_catalog.hh"
#include "Stntuple/scripts/plot_hist_1D.C"
#include "Stntuple/scripts/plot_hist_2D.C"
#include "pipenu/ana/Analysis.hh"

stn_catalog*      catalog;           // has to be global
pipenu::Analysis* gPipenu;           // same

#include "pipenu/ana/scripts/init_pipenu_datasets.C"

#include "plot_figure_0010.C"           // sum mom at VD10
#include "plot_figure_0013.C"           // sum mom at VD13
#include "plot_figure_0021.C"           // stopped pion time, weighted
#include "plot_figure_0022.C"           // stopped pion momentum, weighted
#include "plot_figure_0031.C"           // stopped pions y:x CH2
#include "plot_figure_0034.C"           // stopped pions y:x CH2
#include "plot_figure_0035.C"           // stopped pions y:x CH2
#include "plot_figure_0036.C"           // stopped pions y:p CH2
#include "plot_figure_0037.C"           // stopped pions y:p CH2
//-----------------------------------------------------------------------------
// real [machine-dependent] values of Mu2eNotesDir and Mu2eHistDir 
// should be defined in .rootrc
// it is assumed that the note has been checed out into $mu2e.NotesDir/$NoteRepo
// and all needed histograms are located in $mu2e.HistDir/su2020
//-----------------------------------------------------------------------------
void init() {
  
  stn_book* book;

  const char* notes_dir = gEnv->GetValue("mu2e.pipenu.NotesDir",Mu2eNotesDir);
  sprintf(FiguresDir,"%s/%s/figures",notes_dir,NoteRepo);
  gEnv->SetValue("FiguresDir",FiguresDir);

  const char* hist_dir = gEnv->GetValue("mu2e.pipenu.HistDir",Mu2eHistDir);
  sprintf(pipenu_HistDir,"%s",hist_dir);

  catalog = new stn_catalog("my");
  
  book = new stn_book("pipenu",pipenu_HistDir);
  init_pipenu_datasets(book);
  catalog->AddBook(book);

  gPipenu = new pipenu::Analysis("a");
  
  printf(" after init_local\n");
}

//-----------------------------------------------------------------------------
plot_data_t* plot(int Figure, int Print = 0) {
  plot_data_t* pdata;

  init();
//-----------------------------------------------------------------------------
// fig   10, 13: 
//-----------------------------------------------------------------------------
  if      (Figure ==   10) pdata = plot_figure_0010(Figure,Print);  // P1+P2 at VD10
  if      (Figure ==   13) pdata = plot_figure_0013(Figure,Print);  // P1+P2 at VD12
  if      (Figure ==   21) pdata = plot_figure_0021(Figure,Print);  // stopped pion time
  if      (Figure ==   22) pdata = plot_figure_0022(Figure,Print);  // stopped pion momntum
  if      (Figure ==   31) pdata = plot_figure_0031(Figure,Print);  // ST stopped pion Y:X
  if      (Figure ==   34) pdata = plot_figure_0034(Figure,Print);  // CH2 stopped pion Y:X
  if      (Figure ==   35) pdata = plot_figure_0035(Figure,Print);  // Pb stopped pion Y:X
  if      (Figure ==   36) pdata = plot_figure_0036(Figure,Print);  // CH2 stopped pion Y vs P
  if      (Figure ==   37) pdata = plot_figure_0037(Figure,Print);  // CH2 stopped pion Y vs P

  return pdata;
}
