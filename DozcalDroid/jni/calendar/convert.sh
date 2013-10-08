#!/usr/bin/perl

open($file,"<","./test") || die $!;
while (<$file>) {
	$_ =~ /(\d+)/;
	$number = $1;
	$number = qx(doz $number);
	chomp($number);
	$line = $_;
	$line =~ s/\d+/$number/;
	print $line;
}
