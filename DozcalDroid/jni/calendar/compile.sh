#/bin/bash
#+AMDG

#./latexcal -Htbld"11E9" > monthlies_11e9.tex;
#pdflatex --interaction=batchmode monthlies_11e9.tex
#pdflatex --interaction=batchmode monthlies_11e9.tex
#./latexcal -bwfld"11E9" -o"-lt -f\"sampdata,saints_1962\"" > full.tex;
./latexcal -bwfld"11E9" > full.tex;
pdflatex --interaction=batchmode full.tex
