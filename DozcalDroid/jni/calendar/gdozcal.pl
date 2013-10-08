#!/usr/bin/perl
# +AMDG  This document was begun on 15 June 11E9, the feast
# of St. Gregory Barbarigo, and it is humbly dedicated to
# him and to the Immaculate Heart of Mary for their prayers,
# and to the Sacred Heart of Jesus, for His mercy.

use Tk;
use Tk::Balloon;
use Tk::PNG;
use Tk::Photo;
use Tk::Bitmap;
use Tk::ROText;
use PAR;

# main window

my $mw = new MainWindow;
$mw->title('gdozcal v1.0');
my $shapeslogo = $mw->Photo(
	-file=>"logo_shapes_dozenal.png",-format=>'png');
$mw->idletasks;
$mw->update;
$mw->iconbitmap('');
$mw->iconbitmap('@logo_shapes_dozenal.xbm');
$mw->iconmask('');
$mw->iconmask('@logo_shapes_dozenal_mask.xbm');
$mw->idletasks;
$mw->update;

# arrow bitmaps

my $leftarrow = pack("b10" x 14,
	"...........",
	"........1..",
	".......11..",
	"......111..",
	".....1111..",
	"....11111..",
	"...111111..",
	"....11111..",
	".....1111..",
	"......111..",
	".......11..",
	"........1..",
	"...........");
$mw->DefineBitmap('leftarrow' => 10, 14, $leftarrow);
my $rtarrow = pack("b10" x 14,
	"...........",
	"..1........",
	"..11.......",
	"..111......",
	"..1111.....",
	"..11111....",
	"..111111...",
	"..11111....",
	"..1111.....",
	"..111......",
	"..11.......",
	"..1........",
	"...........");
$mw->DefineBitmap('rtarrow' => 10, 14, $rtarrow);

# for determining the day, month, or week to display
my $currentdate = qx(dozdate "%d %b %Y");
chomp($currentdate);

# get initial display text from $currentdate
my $curr_disptext = $currentdate;

# for the state of the current display
#	0 = daily; 1 = weekly; 2 = monthly
my $curr_display = 0;

my $daily = $mw -> Button(-width=>3,-text=>'Daily',
	-command=>[\&disp_daily])
	-> grid(-row=>1,-column=>1,-columnspan=>3);
my $weekly = $mw -> Button(-width=>3,-text=>'Weekly',
	-command=>[\&disp_weekly])
	-> grid(-row=>1,-column=>4,-columnspan=>3);
my $monthly = $mw -> Button(-width=>3,-text=>'Monthly',
	-command=>[\&disp_monthly])
	-> grid(-row=>1,-column=>7,-columnspan=>3);
my $addnew = $mw -> Button(-width=>19,-text=>'Add New',
	-command=>[\&add_new])
	-> grid(-row=>2,-column=>1,-columnspan=>9);

my $downone = $mw -> Button(-width=>3,
	-bitmap=>"leftarrow",-command=>[\&downone])
	-> grid(-row=>3,-column=>1);
my $datefield = $mw -> Label(-width=>18,-height=>1,
	-background=>'gray',-foreground=>'black',
	-text=>"$currentdate")
	-> grid(-row=>3,-column=>2,-columnspan=>7);
my $upone = $mw -> Button(-width=>3,
	-bitmap=>"rtarrow",-command=>[\&upone])
	-> grid(-row=>3,-column=>9);

my $textfield = $mw -> ROText(-width=>21,-height=>18,
	-background=>'white',-foreground=>'black',-wrap=>'word') 
	-> grid(-row=>4,-column=>1,-columnspan=>9);

# change to dozenal digits; takes the scalar integer,
# returnst he dozenal digit character

sub dozenize($)
{
	if (($_[0] >= 0) && ($_[0] <= 9)) {
		return $_[0];
	} else {
		return 'X' if ($_[0] == 10);
		return 'E' if ($_[0] == 11);
	}
}

# convert integers from decimal to dozenal; takes the scalar
# integer, returns the scalar string

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

# converts single dozenal digits to decimal digit

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

# converts dozenal integers into decimal integers; takes the
# dozenal integer as a scalar, returns the decimal integer
# as a scalar

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

# if it's a leap year

sub leap_year($)
{
	if (($_[0] % 4 == 0) && ($_[0] % 100 != 0)) {
		return 1;
	} else {
		return 0;
	}
}

# update the date display

sub update_date_display()
{
	chomp($currentdate);
	if ($curr_display == 0) {
		disp_daily();
	} elsif ($curr_display == 1) {
		disp_weekly();
	} else {
		disp_monthly();
	}
}

# for increasing the current display unit by one

sub upone()
{
	my @twoquasixmonths = ("09","04","06","0E");
	my $curr_date_form = qx(dozdate "%d %m %Y" -d"$currentdate");
	my @curr_parts=($curr_date_form=~/([0-9XE]+) ([0-9XE]+) ([0-9XE]+)/);
	if ($curr_display == 0) {
		$curr_parts[0] = dec_int($curr_parts[0]) + 1;
		if ($curr_parts[1] == 2) {
			if ($curr_parts[0] >= 28) {
				if (leap_year(dec_int($curr_parts[2]))) {
					if ($curr_parts[0] > 29) {
						$curr_parts[1] = "03";
						$curr_parts[0] = "01";
					}
				} else {
					if ($curr_parts[0] > 28) {
						$curr_parts[1] = "03";
						$curr_parts[0] = "01";
					}
				}
			}
		} elsif (grep(/$curr_parts[1]/,@twoquasixmonths)) {
			if ($curr_parts[0] > 30) {
				$curr_parts[0] = "01";
				$curr_parts[1] = doz_int(dec_int($curr_parts[1]) + 1);
			}
		} else {
			if ($curr_parts[0] > 31) {
				$curr_parts[0] = "01";
				$curr_parts[1] = doz_int(dec_int($curr_parts[1]) + 1);
			}
		}
		$curr_parts[0] = doz_int($curr_parts[0]);
		if ($urr_parts[1] == "11") {
			$curr_parts[1] = "01";
			$curr_parts[3] = doz_int(dec_int($curr_parts[2]) + 1);
		}
		$currentdate = qx(dozdate "%d %b %Y" -d"$curr_parts[2]-$curr_parts[1]-$curr_parts[0]");
		update_date_display();
	}
	if ($curr_display == 1) {
	}
	if ($curr_display == 2) {
	}
}

# for reducing the current display unit by one

sub downone()
{
	my @twoquasixmonths = ("09","04","06","0E");
	my $curr_date_form = qx(dozdate "%d %m %Y" -d"$currentdate");
	my @curr_parts=($curr_date_form=~/([0-9XE]+) ([0-9XE]+) ([0-9XE]+)/);
	if ($curr_display == 0) {
		$curr_parts[0] = dec_int($curr_parts[0]) - 1;
		if ($curr_parts[0] == 0) {
			$curr_parts[1] = doz_int(dec_int($curr_parts[1]) - 1);
			if ($curr_parts[1] == "2") {
				if (leap_year($curr_parts[2])) {
					$curr_parts[0] = 29;
				} else {
					$curr_parts[0] = 28;
				}
			}
			if (grep(/$curr_parts[1]/,@twoquasixmonths)) {
				$curr_parts[0] = 30;
			} else {
				$curr_parts[0] = 31;
			}
		}
		if ($curr_parts[1] == [0]) {
			$curr_parts[1] = "10";
			$curr_parts[0] = 31;
			$curr_parts[2] = doz_int(dec_int($curr_parts[2]) - 1);
		}
		$curr_parts[0] = doz_int($curr_parts[0]);
		$currentdate = qx(dozdate "%d %b %Y" -d"$curr_parts[2]-$curr_parts[1]-$curr_parts[0]");
		update_date_display();
	}
	if ($curr_display == 1) {
	}
	if ($curr_display == 2) {
		$curr_parts[1] = doz_int(dec_int($curr_parts[1]) - 1);
		if ($curr_parts[1] == "0") {
			$curr_parts[1] = "10";
			$curr_parts[2] = doz_int(dec_int($curr_parts[2]) - 1);
		}
		$currentdate = qx(dozdate "%d %b %Y" -d"$curr_parts[2]-$curr_parts[1]-$curr_parts[0]");
		update_date_display();
#FFF ensure that current day number is within range of new
#month
	}
}

sub disp_daily()
{
	$daily->configure(-background=>'red');
	$weekly->configure(-background=>'gray');
	$monthly->configure(-background=>'gray');
	$curr_disptext = qx(dozdate "%d %b %Y" -d"$currentdate");
	chomp($curr_disptext);
	$datefield->configure(-text=>$curr_disptext);
	$curr_display = 0;
}

sub disp_weekly()
{
	$daily->configure(-background=>'gray');
	$weekly->configure(-background=>'red');
	$monthly->configure(-background=>'gray');
	$curr_disptext = qx(dozdate "%d %b %Y" -d"$currentdate");
	chomp($curr_disptext);
	$curr_disptext = "Week of ".$curr_disptext;
	$datefield->configure(-text=>$curr_disptext);
	$curr_display = 1;
}

sub disp_monthly()
{
	$daily->configure(-background=>'gray');
	$weekly->configure(-background=>'gray');
	$monthly->configure(-background=>'red');
	$curr_disptext = qx(dozdate "%B %Y" -d"$currentdate");
	chomp($curr_disptext);
	$datefield->configure(-text=>$curr_disptext);
	$curr_display = 2;
}






MainLoop;
