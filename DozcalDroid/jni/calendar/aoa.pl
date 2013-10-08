#!/usr/bin/perl

my @AOA = ([25, 49, 33, 200], [145, 32], [11,121,78]);
foreach my $item1 (@AOA) {
	foreach my $item2 (sort {$b <=> $a} @{$item1}){
		print "$item2 ";
	}
	print "\n";
}
splice(@AOA,1,1);
foreach my $item1 (@AOA) {
	foreach my $item2 (sort {$b <=> $a} @{$item1}){
		print "$item2 ";
	}
	print "\n";
}
