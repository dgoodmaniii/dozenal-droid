#!/usr/bin/perl
# +AMDG

my @fill = ( 1, 4, 5, 6, 7, 9, 11, 15, 16, 17, 21 );
my @newarray;
my $pastdate;

$pastdate = $fill[0];
foreach my $var (@fill) {
	while (($var - $pastdate) > 1) {
		if (($var - $pastdate) > 1) {
			push(@newarray,++$pastdate);
		} else {
			push(@newarray, $var);
		}
	}
}

foreach my $var (@newarray) {
	print $var." ";
}
