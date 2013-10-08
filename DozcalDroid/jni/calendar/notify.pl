#!/usr/bin/perl
# +AMDG

use Desktop::Notify;

my $notify = Desktop::Notify->new();

my $notification = $notify->create(summary => 'Desktop::Notify',
	body => 'Hello, world!',
	timeout => 5000);

$notification->show();

$notification->close();
