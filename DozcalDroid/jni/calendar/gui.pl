#!/usr/bin/perl

use warnings;
use strict;
use Wx;

package GUI;

use base 'Wx::App';

sub OnInit {
	my $self = shift;

	my $frame = Wx::Frame->new(
		undef,
		-1,
		'GUI for dozcal',
		&Wx::wxDefaultPosition,
		&Wx::wxDefaultSize,
		&Wx::wxMAXIMIZE_BOX | &Wx::wxCLOSE_BOX
	);
	$frame->Show;
}

GUI->new->MainLoop;
