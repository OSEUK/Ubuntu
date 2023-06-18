#include <ncurses.h>
#include <string.h>

int main(void)
{
	initscr();
	cbreak();
	noecho();

	int x = 20; int y = 10;
	char str[] = {"class 1"};
	WINDOW *w1 = newwin(y, x, 0, 0);
	WINDOW *w2 = newwin(y, x, y/2, x/2);
	WINDOW *w3 = newwin(y, x, y, x);

	box(w1, 0, 0); box(w2, 0, 0); box(w3, 0, 0);
	mvwprintw(w3, y/2, x/2-strlen(str)/2, "%s", str);

	refresh();
	wrefresh(w1); wrefresh(w2); wrefresh(w3);

	getch();
	endwin();
	return 0;
}
