#!/bin/bash
# +AMDG

cat hello;
./dozstring -xA -eB -p'&' < hello;
echo  "------------------------------";
cat hello;
./dozstring -s -xA -eB -p'&' < hello;
