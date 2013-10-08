#!/bin/bash

./dozdate -f testfile.txt > results;
diff results answers.txt;
