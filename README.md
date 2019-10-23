# asld_analysis
Code for analysis of neutral B meson mixing in LHCb's run II data

Cleaning up still WIP

Compile with: g++ -o main.exe main.cpp Fit.cpp DmHist.cpp DecreaseTreeSizeAndCuts.cpp -lRooFitCore -lRooFit -lRooStats `root-config --cflags --libs` -lGenVector

Run with: ./main.exe /afs/cern.ch/work/z/zwolffs/public/data/DataRun/Data2016_Strip28r1_MagUp.root *Directory name (usually b2DpMuX)* *Decrease size by this amount*
