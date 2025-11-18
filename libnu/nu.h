/* This file is part of the chess engine lisco.
 *
 * Copyright (C) 2002-2025 Guido Flohr.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef LISCO_H
# define LISCO_H        /* Allow multiple inclusion.  */

#ifdef HAVE_CONFIG_H
# include <config.h>
#endif

#include <stdint.h>

/* Boolean values. */
typedef enum lisco_bool {
	lisco_false = 0,
#define lisco_false lisco_false
	lisco_true = 1
#define lisco_true lisco_true
} lisco_bool;

#ifdef __cplusplus
# define LIBCHI_BEGIN_DECLS extern "C" {
# define LIBCHI_END_DECLS }
#else
# define LIBCHI_BEGIN_DECLS /* empty */
# define LIBCHI_END_DECLS /* empty */
#endif
typedef struct {
	// All pieces, black and white.
	uint64_t pieces[2];

	// Individual piece types, for both sides. Or with the pieces above for
	// accessing the pieces of one side.
	uint64_t pawns;
	uint64_t knights;
	uint64_t bishops;
	uint64_t rooks;
	uint64_t queens;
	uint64_t kings;

	// A bitboard with all pieces giving check. If not in check, the value is 0.
	uint64_t in_check;

	// Squares where the king can move out of check.
	uint64_t evasion_squares;

	// Zobrist key.
	uint64_t signature;

	// Bitmask of castling rights:
	//
	// - 0x1 for K
	// - 0x2 for Q
	//
	// Use the turn as the index into the array.
	uint8_t castling[2];

	// Number of half moves in the game.
	uint16_t half_moves;

	// Reversible clock. Irreversible are pawn moves, captures, first king
	// move of each side, first move of each rook of each side, and castlings.
	// This is important for testing a three-fold repetition.

	// Half-move-clock for the 50-moves rule. This is like the reversible
	// clock but only captures and pawn moves reset the clock.
	uint16_t half_move_clock;

	// For private use.
	uint16_t usr1;

	// The side that has to make the next move.
	uint8_t turn;

	// The shift of the square where an en passant capture ends or 0 if
	// en passant is not possible.
	uint8_t en_passant_shift;

	// The shift of the king of the side whose turn it us.
	uint8_t king_shift;

	// For private use.
	uint8_t usr2;
} Position;

typedef enum {
	chi_white = 0,
	chi_black = 1,
} chi_color_t;

typedef enum {
	chi_empty = 0,
	chi_pawn = 1,
	chi_knight = 2,
	chi_bishop = 3,
	chi_rook = 4,
	chi_queen = 5,
	chi_king = 6,
} chi_piece_t;

// How to evade a check?
typedef enum {
	chi_evasion_all = 0,
	chi_evastion_capture = 1,
	chi_evasion_king_move = 2,
} chi_evasion_t;

/* Masks for all light and dark fields.  A8 is a light field.  */
typedef enum {
	chi_light_mask = ((uint64_t) 0xaa55aa55aa55aa55ULL),
#define chi_white_mask chi_light_mask
	chi_dark_mask = ((uint64_t) 0x55aa55aa55aa55aaULL)
#define chi_black_mask chi_dark_mask
} chi_square_colour_t;

/* Bit shifts for fields.  */
#define CHI_A1 (7)
#define CHI_B1 (6)
#define CHI_C1 (5)
#define CHI_D1 (4)
#define CHI_E1 (3)
#define CHI_F1 (2)
#define CHI_G1 (1)
#define CHI_H1 (0)
#define CHI_A2 (15)
#define CHI_B2 (14)
#define CHI_C2 (13)
#define CHI_D2 (12)
#define CHI_E2 (11)
#define CHI_F2 (10)
#define CHI_G2 (9)
#define CHI_H2 (8)
#define CHI_A3 (23)
#define CHI_B3 (22)
#define CHI_C3 (21)
#define CHI_D3 (20)
#define CHI_E3 (19)
#define CHI_F3 (18)
#define CHI_G3 (17)
#define CHI_H3 (16)
#define CHI_A4 (31)
#define CHI_B4 (30)
#define CHI_C4 (29)
#define CHI_D4 (28)
#define CHI_E4 (27)
#define CHI_F4 (26)
#define CHI_G4 (25)
#define CHI_H4 (24)
#define CHI_A5 (39)
#define CHI_B5 (38)
#define CHI_C5 (37)
#define CHI_D5 (36)
#define CHI_E5 (35)
#define CHI_F5 (34)
#define CHI_G5 (33)
#define CHI_H5 (32)
#define CHI_A6 (47)
#define CHI_B6 (46)
#define CHI_C6 (45)
#define CHI_D6 (44)
#define CHI_E6 (43)
#define CHI_F6 (42)
#define CHI_G6 (41)
#define CHI_H6 (40)
#define CHI_A7 (55)
#define CHI_B7 (54)
#define CHI_C7 (53)
#define CHI_D7 (52)
#define CHI_E7 (51)
#define CHI_F7 (50)
#define CHI_G7 (49)
#define CHI_H7 (48)
#define CHI_A8 (63)
#define CHI_B8 (62)
#define CHI_C8 (61)
#define CHI_D8 (60)
#define CHI_E8 (59)
#define CHI_F8 (58)
#define CHI_G8 (57)
#define CHI_H8 (56)


/* Bit masks for files and ranks of the chess board.  */
#define CHI_A_MASK ((uint64_t) 0x8080808080808080)
#define CHI_B_MASK ((uint64_t) 0x4040404040404040)
#define CHI_C_MASK ((uint64_t) 0x2020202020202020)
#define CHI_D_MASK ((uint64_t) 0x1010101010101010)
#define CHI_E_MASK ((uint64_t) 0x0808080808080808)
#define CHI_F_MASK ((uint64_t) 0x0404040404040404)
#define CHI_G_MASK ((uint64_t) 0x0202020202020202)
#define CHI_H_MASK ((uint64_t) 0x0101010101010101)

#define CHI_1_MASK ((uint64_t) 0x00000000000000ff)
#define CHI_2_MASK ((uint64_t) 0x000000000000ff00)
#define CHI_3_MASK ((uint64_t) 0x0000000000ff0000)
#define CHI_4_MASK ((uint64_t) 0x00000000ff000000)
#define CHI_5_MASK ((uint64_t) 0x000000ff00000000)
#define CHI_6_MASK ((uint64_t) 0x0000ff0000000000)
#define CHI_7_MASK ((uint64_t) 0x00ff000000000000)
#define CHI_8_MASK ((uint64_t) 0xff00000000000000)

#endif
