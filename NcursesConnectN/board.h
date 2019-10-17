#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

struct board {
	int row;
	int col; 
	char **bcc;
};
struct curse {
	int row;
	int col;
	char carlos;
};
struct curse cal(struct board BIT, int num,WINDOW* wow);