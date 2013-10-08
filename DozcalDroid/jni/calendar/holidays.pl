#!/usr/bin/perl
# +AMDG

use Date::Pcalendar::Profiles qw( $Profiles );
use Date::Pcalendar;

$calendar_US_AZ = Date::Pcalendar->new($Profiles->{'US-AZ'});

$year_2012_US_AZ = $calendar_US_AZ->year(2012);
print $year_2012_US_AZ->month;
