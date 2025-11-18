#! /usr/bin/env perl

use strict;

use Chess::Plisco;

my ($fen) = join ' ', @ARGV;
$fen = 'rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1' unless defined $fen;

print <<"EOF";
START_TEST(test_ FILL IN TEST NAME!)
{
	const char *fen = 
		"$fen";
	const char *wanted[] = {
EOF

my $pos = Chess::Plisco->new($fen);

my @moves;
foreach my $move ($pos->legalMoves) {
	push @moves, $pos->LAN($move);
};

my $count = 0;

my $moves = join ', ', map { qq{"$_"} } sort @moves;

my $count = 0;
$moves =~ s/, /++$count % 8 == 0 ? ",\n\t\t" : ', '/ge;

print <<"EOF";
		$moves
	};

	TEST_MOVE_GEN(fen, wanted)
}
EOF
