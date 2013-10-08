#!/bin/bash
#+AMDG

pdftk A=full.pdf cat A50 A51 output spread.pdf;
convert spread.pdf spread.png;
convert spread-0.png spread-1.png +append spread.png;
