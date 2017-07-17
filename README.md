# SCOTS_GUI.0.1
SCOTS_GUI.0.1 is the graphic user interface for SCOTS which is a is a C++ tool to synthesize controller for
possibly perturbed nonlinear control systems with respect to safety and reachability specifications. 


Requirements:
 1. Linux system with QT 5.8. You can download Qt from here: https://info.qt.io/download-qt-for-application-development 
 2. SCOTSv0.2 from https://gitlab.lrz.de/matthias/SCOTSv0.2
 3. The CUDD library by Fabio Somenzi, which can be downloaded at: http://vlsi.colorado.edu/~fabio/. 

Installation guide:
 1. Download whole repository.
 2. Open mainwindow.h and change the line 36 i.e. std::string path_of_scots="/home/fmlab5/SCOTSv0.2";
     to std::string path_of_scots="Add the pathe where SCOTSv0.2 is";
 3. Then opne the file SCOTS_GUI.pro using QT.
 4. Build the project and you are good to go.
 5. For help on how to use the app see help.pdf in the repository.
   

