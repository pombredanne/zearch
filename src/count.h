/*
	Description: Implementation of counting.
	For the given rule X → AB, computes data for X based on information stored about A and B.

	Properties:
		- Matches across lines are not considered.

	Author: Pedro Valero
	Date: 12-17
*/

#ifndef COUNT_H_
#define COUNT_H_

#define MIDDLE_STATE 1
#define INITIAL_FINAL_STATE 0

#include <stdbool.h>
#include "types.h"

bool expand; // Variable to indicate that a new match has been found and rule should be expanded to print it.

/*
	Description: Initializes counting information for a symbol, which
	should be a terminal, that connects the initial and a final state.
	Arguments:
		- symbol, symbol for which counting information should be initialized
	Return: Nothing.
*/
void incr_count_l1(int symbol);

/*
	Description: Computes counting information for a symbol, which
	should be a non-terminal, that connects the initial and a final state.

	Rule: X → AB
	trule: information related to X, to be computed.
	tleft: information related to A, already computed.
	tright: information related to B, already computed.

	Arguments:
		- middle, has value MIDDLE_STATE iff state q' is not q0 nor qf,
		where (q0,A,q') + (q',B,qf) → (q0, X, qf).
		Otherwise middle = INITAL_FINAL_STATE
	Return: Nothing.
*/
void prop_count();
void incr_count();

/*
	Description: Initializes counting information for a sequence of symbols.

	Rule: X1 → AB
	Sequence: X1 X2 X3 ....
	tsrule: information related to X1, to be computed.
	tleft: information related to A, already computed.
	tright: information related to B, already computed.

	Arguments:
		- middle, has value MIDDLE_STATE iff state q' is not q0 nor qf,
		where (q0,A,q') + (q',B,qf) → (q0, X, qf).
		Otherwise middle = INITAL_FINAL_STATE
	Return: Nothing.
*/
void incr_count_seq_1(short middle);

/*
	Description: Extends counting information for a sequence of symbols based
	on the next symbol.

	Sequence: ... Xi Xj Xk ....
	tsrule: information related to X1 ... Xk, to be computed.
	tsleft: information related to X1 ... Xj, already computed.
	tright: information related to Xk, already computed.

	Arguments:
		- middle, has value MIDDLE_STATE iff state q' is not q0 nor qf,
		where (q0,A,q') + (q',B,qf) → (q0, X, qf).
		Otherwise middle = INITAL_FINAL_STATE
	Return: Nothing.
*/
void prop_count_seq();
void incr_count_seq();

#endif