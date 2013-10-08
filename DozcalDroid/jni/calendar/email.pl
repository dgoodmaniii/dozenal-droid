#!/usr/bin/perl
# +AMDG

use Email::MIME;
use Email::Sender::Simple qw(sendmail);
use Email::Sender::Transport::SMTP qw();
use Try::Tiny;
use MIME::Lite::TT;

#my $message = Email::MIME->create(
#	header => [
#		From => "dgoodmaniii@gmail.com",
#		To => "dgoodmaniii@gmail.com",
#		Subject => "Testing Perl",
#	],
#	attributes => {
#		encoding => 'quoted-printable',
#		charset => 'UTF-8',
#	},
#	body => "Please please please work!",
#);
#
#try {
#	sendmail(
#		$message,
#		{
#			from => 'dgoodmaniii@gmail.com',
#			to => 'dgoodmaniii@gmail.com',
##			transport => Email::Sender::Transport::SMTP->new({
##				host => $SMTP_HOSTNAME,
##				port => $SMTP_PORT,
##			})
#		}
#	);
#} catch {
#	warn "sending failed:  $_";
#};

my $msg = MIME::Lite::TT->new(
	From => 'dgoodmaniii@gmail.com',
	To => 'dgoodmaniii@gmail.com',
	Subject => 'Testing with Perl',
	Body => 'Please work',
);
$msg->send;
