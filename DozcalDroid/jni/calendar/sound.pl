#!/usr/bin/perl
#+AMDG

 use MIDI::Music;
 use MIDI::Simple;

 new_score;
 text_event 'http://www.ely.anglican.org/parishes/camgsm/bells/chimes.html';
 text_event 'Lord through this hour/ be Thou our guide';
 text_event 'so, by Thy power/ no foot shall slide';
 set_tempo 500000;  # 1 qn => .5 seconds (500,000 microseconds)
 patch_change 1, 8;  # Patch 8 = Celesta

 noop c1, f, o5;  # Setup
 # Now play
 n qn, Cs;    n F;   n Ds;  n hn, Gs_d1;
 n qn, Cs;    n Ds;  n F;   n hn, Cs;
 n qn, F;     n Cs;  n Ds;  n hn, Gs_d1;
 n qn, Gs_d1; n Ds;  n F;   n hn, Cs;

 write_score 'westmister_chimes.mid';

my $mm = new MIDI::Music;

$mm->playmidifile('westmister_chimes.mid') || die $mm->errstr;
