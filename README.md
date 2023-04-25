# MKL 2023

This git repo contains part of an installation of Intels oneMKL 2023.1.0.
This is for use in the CI pipeline of intact_simulation.

To create this repo, download the installer from here:
https://www.intel.com/content/www/us/en/developer/tools/oneapi/onemkl-download.html

Then, install it locally.

From there, create we create a repository from "C:\Program Files (x86)\Intel\oneAPI".
Some notes on that.

* We only need the compiler and mkl sections, as well as the set_vars scripts.
* Symlinks with git and windows are difficult. Just put everything in the latest directory for each instead of symlinking latest to the latest version.
  The latest directory is used in both the set var scripts and the cmake files, its easier this way.
* We need a small portion of the dlls and libs. Exclude as much as possible.
* Make sure all *.lib files are checked in with git lfs.
* If you have multiple versions of MKL installed, make sure only the latest version is commited.