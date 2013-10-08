#!/usr/bin/perl
# +AMDG

use Calendar::Hijri;

# subtract 579 from current year
my $calendar = Calendar::Hijri->new(1433,9,1);
print $calendar->get_calendar();
my $numdays = $calendar->days_in_month(1433,9);
for (my $i = 1; $i <= $numdays; $i++) {
	my $calendar = Calendar::Hijri->new(1433,9,$i);
	$calendar->get_calendar();
	my ($yyyy,$mm,$dd) = $calendar->to_gregorian();
	print "$yyyy $mm $dd\n";
}
