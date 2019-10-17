#include <stdio.h>
#include <stdlib.h>
#include "board.h"

struct curse cal(struct board BIT, int num, WINDOW* wow) {

	/*
	for (int i = 0; i < BIT.row; i++) {
	for (int j = 0; j < BIT.col; j++) {
	mvwaddch(dow,i,j,BIT.bcc[i][j]);
	wrefresh(dow);
	refresh();
	}
	}
	*/
	/*
	for (int i = 0; i < BIT.row; i++) {
	for (int j = 0; j < BIT.col; j++) {
	printf(" %c ", BIT.bcc[i][j]);
	}
	printf("\n");
	}
	*/


	for (int i = 0; i < BIT.row; i++) {
		for (int j = 0; j < BIT.col; j++) {
			if (BIT.bcc[i][j] == 'X') {
				int add = 1;
				if (num == 1) {
					struct curse hel = {};
					hel.carlos = 'X';
					return hel;
				}
				while (BIT.bcc[i][j + add] == 'X') {
					add += 1;
					if (add == num) {
						struct curse hell = {};
						hell.row = i;
						hell.col = j + add - 1;
						hell.carlos = 'X';
						return hell;
					}

				}
				add = 0;
			}
			else if (BIT.bcc[i][j] == 'O') {
				int add1 = 1;
				while (BIT.bcc[i][j + add1] == 'O') {
					add1 += 1;
					if (add1 == num) {
						struct curse hell = {};
						hell.row = i;
						hell.col = j + add1 - 1;
						hell.carlos = 'O';
						return hell;
					}
				}
				add1 = 0;

			}

		}

	}



	for (int i1 = 0; i1 < BIT.col; i1++) {
		for (int j1 = 0; j1 < BIT.row; j1++) {
			if (BIT.bcc[j1][i1] == 'X') {
				int addc = 1;
				if (j1 + addc < BIT.row) {
					while (j1 + addc <BIT.row && BIT.bcc[j1 + addc][i1] == 'X') {
						addc += 1;
						if (addc == num) {
							struct curse hello = {};
							hello.row = j1 + addc;
							hello.col = i1 - 1;
							hello.carlos = 'X';
							return hello;
						}
					}
					addc = 0;
				}
			}
			else if (BIT.bcc[j1][i1] == 'O') {
				int addc1 = 1;
				if (j1 + addc1 < BIT.row) {
					while (j1 + addc1 <BIT.row && BIT.bcc[j1 + addc1][i1] == 'O') {
						addc1 += 1;
						if (addc1 == num) {
							struct curse hello = {};
							hello.row = j1 + addc1;
							hello.col = i1 - 1;
							hello.carlos = 'O';
							return hello;
						}
					}
					addc1 = 0;
				}
			}

		}

	}

	for (int i2 = 0; i2 < BIT.row; i2++) {
		for (int j2 = 0; j2 < BIT.col; j2++) {

			if (BIT.bcc[i2][j2] == 'X') {
				int a = 1;
				int b = 1;
				int count = 1;

				while (i2 + a <BIT.row && BIT.bcc[i2 + a][j2 + b] == 'X') {
					count += 1;
					a += 1;
					b += 1;
					if (count == num) {
						struct curse whatup = {};
						whatup.carlos = 'X';
						return whatup;
					}
				}
			}
			else if (BIT.bcc[i2][j2] == 'O') {
				int a = 1;
				int b = 1;
				int count = 1;

				while (i2 + a < BIT.row && BIT.bcc[i2 + a][j2 + b] == 'O') {
					count += 1;
					a += 1;
					b += 1;
					if (count == num) {
						struct curse whatup = {};
						whatup.carlos = 'O';
						return whatup;
					}
				}
				a = 0;
				b = 0;
			}
		}
	}

	for (int i2 = 0; i2 < BIT.row; i2++) {
		for (int j2 = 0; j2 < BIT.col; j2++) {

			if (BIT.bcc[i2][j2] == 'X') {
				int a = 1;
				int b = 1;
				int count = 1;

				while (i2 + a <BIT.row && BIT.bcc[i2 + a][j2 - b] == 'X') {
					count += 1;
					a += 1;
					b += 1;
					if (count == num) {
						struct curse whatup = {};
						whatup.carlos = 'X';
						return whatup;
					}
				}
			}
			else if (BIT.bcc[i2][j2] == 'O') {
				int a = 1;
				int b = 1;
				int count = 1;

				while (i2 + a < BIT.row && BIT.bcc[i2 + a][j2 - b] == 'O') {
					count += 1;
					a += 1;
					b += 1;
					if (count == num) {
						struct curse whatup = {};
						whatup.carlos = 'O';
						return whatup;
					}
				}
				a = 0;
				b = 0;
			}
		}
	}

	struct curse dummy;
	dummy.row = 1;

	return dummy;




}