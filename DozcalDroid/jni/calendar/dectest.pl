#!/usr/bin/perl

sub decimalize($)
{
	if ($_[0] eq 'X') {
		return 10;
	} elsif ($_[0] eq 'E') {
		return 11;
	} else {
		return $_[0];
	}
}

sub dec_int($)
{
	my @digits;
	my $len;
	my $decnum;
	my $exp = 0;

	@digits = split(//,$_[0]);
	$exp = $#digits;
	foreach my $var (@digits) {
		$decnum += decimalize($var) * (12**($exp--));
	}
	return $decnum;
}

print dec_int("11E8");
