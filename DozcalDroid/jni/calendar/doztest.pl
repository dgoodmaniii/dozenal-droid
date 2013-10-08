#!/usr/bin/perl

sub dozenize($)
{
	if (($_[0] >= 0) && ($_[0] <= 9)) {
		return $_[0];
	} else {
		return 'X' if ($_[0] == 10);
		return 'E' if ($_[0] == 11);
	}
}

sub doz_int($)
{
	my $decnum = $_[0];
	my $holder = 1;
	my $doznum = "";

	while ($decnum >= 12) {
		$holder = $decnum % 12;
		$holder = dozenize($holder);
		$doznum .= $holder;
		$decnum /= 12;
	}
	$holder = $decnum % 12;
	$holder = dozenize($holder);
	$doznum .= $holder;
	return scalar reverse($doznum);
}


print doz_int(2011);
