#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include "board.h"

char meo(WINDOW* wow, int row, int col, struct board* BIT, WINDOW* win, int needed, FILE* fp, WINDOW* win2)
{
	int player = 0;
	int hmm = 0;
	mvwaddch(wow, 0, 0, 'X');
	wmove(wow, 0, 0);
	fprintf(fp, "X\n");
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			fprintf(fp, "%c", BIT->bcc[i][j]);
		}
		fprintf(fp, "\n");
	}
	fprintf(fp, "\n");
	fprintf(fp, "\n");
	while (true) {
		char input = wgetch(wow);
		if (input == 'a' || input == 'j') {
			hmm -= 1;
			if (hmm < 0) {
				mvwdelch(wow, 0, 0);
				hmm = col;
				hmm -= 1;
				if (player % 2 == 0) {
					mvwaddch(wow, 0, hmm, 'X');
					for (int i = 0; i < hmm; i++) {
						fprintf(fp, " ");
					}
					fprintf(fp, "X\n");
					for (int i = 0; i < row; i++) {
						for (int j = 0; j < col; j++) {
							fprintf(fp, "%c", BIT->bcc[i][j]);
						}
						fprintf(fp, "\n");
					}
					fprintf(fp, "\n");
					fprintf(fp, "\n");
				}
				else {
					mvwaddch(wow, 0, hmm, 'O');
					for (int i = 0; i < hmm; i++) {
						fprintf(fp, " ");
					}
					fprintf(fp, "O\n");
					for (int i = 0; i < row; i++) {
						for (int j = 0; j < col; j++) {
							fprintf(fp, "%c", BIT->bcc[i][j]);
						}
						fprintf(fp, "\n");
					}
					fprintf(fp, "\n");
					fprintf(fp, "\n");
				}
				wmove(wow, 0, hmm);
				refresh();
			}
			else {
				int j = hmm + 1;
				mvwdelch(wow, 0, j);
				if (player % 2 == 0) {
					mvwaddch(wow, 0, hmm, 'X');
					for (int i = 0; i < hmm; i++) {
						fprintf(fp, " ");
					}
					fprintf(fp, "X\n");
					for (int i = 0; i < row; i++) {
						for (int j = 0; j < col; j++) {
							fprintf(fp, "%c", BIT->bcc[i][j]);
						}
						fprintf(fp, "\n");
					}
					fprintf(fp, "\n");
					fprintf(fp, "\n");
				}
				else {
					mvwaddch(wow, 0, hmm, 'O');
					for (int i = 0; i < hmm; i++) {
						fprintf(fp, " ");
					}
					fprintf(fp, "O\n");
					for (int i = 0; i < row; i++) {
						for (int j = 0; j < col; j++) {
							fprintf(fp, "%c", BIT->bcc[i][j]);
						}
						fprintf(fp, "\n");
					}
					fprintf(fp, "\n");
					fprintf(fp, "\n");
				}
				wmove(wow, 0, hmm);
				refresh();
			}
		}
		else if (input == 's' || input == 'k') {
			hmm += 1;
			if (hmm > col - 1) {
				mvwdelch(wow, 0, col - 1);
				hmm = 0;
				if (player % 2 == 0) {
					mvwaddch(wow, 0, hmm, 'X');
					for (int i = 0; i < hmm; i++) {
						fprintf(fp, " ");
					}
					fprintf(fp, "X\n");
					for (int i = 0; i < row; i++) {
						for (int j = 0; j < col; j++) {
							fprintf(fp, "%c", BIT->bcc[i][j]);
						}
						fprintf(fp, "\n");
					}
					fprintf(fp, "\n");
					fprintf(fp, "\n");
				}
				else {
					mvwaddch(wow, 0, hmm, 'O');
					for (int i = 0; i < hmm; i++) {
						fprintf(fp, " ");
					}
					fprintf(fp, "O\n");
					for (int i = 0; i < row; i++) {
						for (int j = 0; j < col; j++) {
							fprintf(fp, "%c", BIT->bcc[i][j]);
						}
						fprintf(fp, "\n");
					}
					fprintf(fp, "\n");
					fprintf(fp, "\n");
				}
				wmove(wow, 0, hmm);
				refresh();

			}
			else {
				int j = hmm - 1;
				mvwdelch(wow, 0, j);
				if (player % 2 == 0) {
					mvwaddch(wow, 0, hmm, 'X');
					for (int i = 0; i < hmm; i++) {
						fprintf(fp, " ");
					}
					fprintf(fp, "X\n");
					for (int i = 0; i < row; i++) {
						for (int j = 0; j < col; j++) {
							fprintf(fp, "%c", BIT->bcc[i][j]);
						}
						fprintf(fp, "\n");
					}
					fprintf(fp, "\n");
					fprintf(fp, "\n");
				}
				else {
					mvwaddch(wow, 0, hmm, 'O');
					for (int i = 0; i < hmm; i++) {
						fprintf(fp, " ");
					}
					fprintf(fp, "O\n");
					for (int i = 0; i < row; i++) {
						for (int j = 0; j < col; j++) {
							fprintf(fp, "%c", BIT->bcc[i][j]);
						}
						fprintf(fp, "\n");
					}
					fprintf(fp, "\n");
					fprintf(fp, "\n");
				}
				wmove(wow, 0, hmm);
				refresh();
			}
		}
		else if (input == '\n' || input == ' ') {
			if (BIT->bcc[0][hmm] == 'X') {
				for (int i = 0; i < hmm; i++) {
					fprintf(fp, " ");
				}
				fprintf(fp, "O\n");
				for (int i = 0; i < row; i++) {
					for (int j = 0; j < col; j++) {
						fprintf(fp, "%c", BIT->bcc[i][j]);
					}
					fprintf(fp, "\n");
				}
				fprintf(fp, "\n");
				fprintf(fp, "\n");
			}
			else if (BIT->bcc[0][hmm] == 'O') {
				for (int i = 0; i < hmm; i++) {
					fprintf(fp, " ");
				}
				fprintf(fp, "X\n");
				for (int i = 0; i < row; i++) {
					for (int j = 0; j < col; j++) {
						fprintf(fp, "%c", BIT->bcc[i][j]);
					}
					fprintf(fp, "\n");
				}
				fprintf(fp, "\n");
				fprintf(fp, "\n");
			}
			for (int i = row - 1; i >= 0; i--) {
				if (BIT->bcc[i][hmm] == '*') {
					if (player % 2 == 0) {
						BIT->bcc[i][hmm] = 'X';
						mvwaddch(win, i, hmm, 'X');
						wrefresh(win);
						wmove(wow, 0, hmm);
						struct curse out = cal(*BIT, needed, wow);
						wmove(wow, 0, hmm);
						refresh();
						wrefresh(win);
						wrefresh(wow);


						if (out.carlos == 'X') {
							for (int i = 0; i < hmm; i++) {
								fprintf(fp, " ");
							}
							fprintf(fp, "X\n");
							for (int i = 0; i < row; i++) {
								for (int j = 0; j < col; j++) {
									fprintf(fp, "%c", BIT->bcc[i][j]);
								}
								fprintf(fp, "\n");
							}
							fprintf(fp, "Player 1 won!");
							wprintw(win2, "Player 1 won!");
							refresh();
							wrefresh(win2);
							wmove(win, out.row, out.col);
							return out.carlos;

						}

						else {

							int total = row * col;
							int tie = 0;
							for (int i = 0; i < row; i++) {
								for (int j = 0; j < col; j++) {
									if (BIT->bcc[i][j] != '*') {
										tie += 1;
									}
								}
							}
							if (tie == total) {
								wprintw(win2, "Tie Game");
								refresh();
								wrefresh(win2);
								for (int i = 0; i < hmm; i++) {
									fprintf(fp, " ");
								}
								fprintf(fp, "X\n");
								for (int i = 0; i < row; i++) {
									for (int j = 0; j < col; j++) {
										fprintf(fp, "%c", BIT->bcc[i][j]);
									}
									fprintf(fp, "\n");
								}
								fprintf(fp, "Tie Game");
								return 't';

							}


							for (int i = 0; i < hmm; i++) {
								fprintf(fp, " ");
							}
							fprintf(fp, "O\n");
							for (int i = 0; i < row; i++) {
								for (int j = 0; j < col; j++) {
									fprintf(fp, "%c", BIT->bcc[i][j]);
								}
								fprintf(fp, "\n");
							}
							fprintf(fp, "\n");
							fprintf(fp, "\n");
						}

					}
					else {
						BIT->bcc[i][hmm] = 'O';
						mvwaddch(win, i, hmm, 'O');
						wrefresh(win);
						struct curse out = cal(*BIT, needed, win);
						wmove(wow, 0, hmm);


						if (out.carlos == 'O') {
							for (int i = 0; i < hmm; i++) {
								fprintf(fp, " ");
							}
							fprintf(fp, "O\n");
							for (int i = 0; i < row; i++) {
								for (int j = 0; j < col; j++) {
									fprintf(fp, "%c", BIT->bcc[i][j]);
								}
								fprintf(fp, "\n");
							}
							fprintf(fp, "Player 2 won!");
							wprintw(win2, "Player 1 won!");
							refresh();
							wrefresh(win2);
							return out.carlos;
						}
						else {
							int total = row * col;
							int tie = 0;
							for (int i = 0; i < row; i++) {
								for (int j = 0; j < col; j++) {
									if (BIT->bcc[i][j] != '*') {
										tie += 1;
									}
								}
							}
							if (tie == total) {

								wprintw(win2, "Tie Game");
								refresh();
								wrefresh(win2);
								for (int i = 0; i < hmm; i++) {
									fprintf(fp, " ");
								}
								fprintf(fp, "O\n");
								for (int i = 0; i < row; i++) {
									for (int j = 0; j < col; j++) {
										fprintf(fp, "%c", BIT->bcc[i][j]);
									}
									fprintf(fp, "\n");
								}
								fprintf(fp, "Tie Game");
								return 't';
							}

							for (int i = 0; i < hmm; i++) {
								fprintf(fp, " ");
							}
							fprintf(fp, "X\n");
							for (int i = 0; i < row; i++) {
								for (int j = 0; j < col; j++) {
									fprintf(fp, "%c", BIT->bcc[i][j]);
								}
								fprintf(fp, "\n");
							}
							fprintf(fp, "\n");
							fprintf(fp, "\n");
						}

					}
					player += 1;
					mvwdelch(wow, 0, hmm);
					if (player % 2 == 0) {
						mvwaddch(wow, 0, hmm, 'X');
					}
					else {
						mvwaddch(wow, 0, hmm, 'O');
					}
					wrefresh(wow);
					wmove(wow, 0, hmm);
					refresh();
					break;
				}
			}
		}
		
		else {
			if (player % 2 == 0) {
				for (int i = 0; i < hmm; i++) {
					fprintf(fp, " ");
				}
				fprintf(fp, "X\n");
				for (int i = 0; i < row; i++) {
					for (int j = 0; j < col; j++) {
						fprintf(fp, "%c", BIT->bcc[i][j]);
					}
					fprintf(fp, "\n");
				}
				fprintf(fp, "\n");
				fprintf(fp, "\n");
			}
			else {
				for (int i = 0; i < hmm; i++) {
					fprintf(fp, " ");
				}
				fprintf(fp, "O\n");
				for (int i = 0; i < row; i++) {
					for (int j = 0; j < col; j++) {
						fprintf(fp, "%c", BIT->bcc[i][j]);
					}
					fprintf(fp, "\n");
				}
				fprintf(fp, "\n");
				fprintf(fp, "\n");
			}
		}	
	}
}


int main(int argc, const char* argv[])
{

	initscr();
	noecho();
	cbreak();
	int a = atoi(argv[1]);
	int b = atoi(argv[2]);
	int c = atoi(argv[3]);
	FILE*fp = fopen(argv[4], "w");
	WINDOW *win;
	WINDOW *win1;
	win1 = newwin(1, b, 0, 0);
	refresh();
	WINDOW *win2;
	win = newwin(a, b, 1, 0);
	refresh();
	for (int i = 0; i < a; i++) {
		for (int i1 = 0; i1 < b; i1++) {
			mvwaddch(win, i, i1, '*');
		}
	}
	wrefresh(win);
	win2 = newwin(1, 20, a + 1, 0);
	refresh();





	struct board BIT = {};
	BIT.row = a;
	BIT.col = b;
	BIT.bcc = (char**)malloc(BIT.row * sizeof(char*));
	for (int i = 0; i < BIT.row; i++) {
		BIT.bcc[i] = (char*)malloc(BIT.col * sizeof(char));
	}

	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			BIT.bcc[i][j] = '*';
		}
	}

	keypad(win1, true);
	meo(win1, a, b, &BIT, win, c, fp, win2);

	wrefresh(win1);
	wrefresh(win);
	/*
	box(win1, 0, 0);
	wrefresh(win1);
	box(win, 0, 0);
	wrefresh(win);
	box(win2, 0, 0);
	wrefresh(win2);
	*/
	endwin();

	return 0;
}