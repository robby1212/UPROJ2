#include <stdio.h>
#include <ncurses.h> 

int main()
{
	
	// start/setup nCurses
	initscr();
	//start_color();
	raw(); 
	keypad(stdscr, TRUE);
	noecho();

	char * filename = "fileA.txt";
	wattron(stdscr,A_REVERSE);
	printw("Group 1\t\tFILE: %s\n", filename);
	wattroff(stdscr,A_REVERSE);

	int ch;

	int w, h, // the width and height of the window
	    x, y; // the x,y coordinates of the cursor
	int scroll = 0;
	
	bool active = true;
	bool edit_mode = false;
	
	// Set width and height to window size
	getmaxyx(stdscr, h,w);	
	x = 0;
	y = 2;

	
        mvprintw(h/2,w/3, " Welcome to Group 1 Text Editor! ");
	refresh();
		
	while (active)
	{
		ch = getch(); // gets the users key

		switch(ch)
		{	
		case KEY_LEFT: 
			if (x > 1)
				x --;
			break;
		case KEY_RIGHT:
			if (x < w-1)
				x ++; 
			break;
		case KEY_UP:
			if (y > 1)
				y --;
			else if (scroll > 0)
				scroll --;
			break;
		case KEY_DOWN: 
			if (y < h-2)
				y ++;
			else
				scroll ++;
			break;
		default: 
			active = false; 
			break;
		}
		clear_window();
		                wattron(stdscr,A_REVERSE);
                mvprintw(h-1,1,edit_mode ? "Line %d,%d) \t-EDIT MODE-":"Line %d,%d \t-TYPE MODE-", y + scroll,x);
                wattroff(stdscr,A_REVERSE);
	
		wmove(stdscr,y,x);


		refresh();
	}

	mvprintw(h/2,w/3,"PROGRAM WILL NOW TERMINATE");
	mvprintw(h/2+1,w/3,"Goodbye!");
	getch();
	
	endwin();
	
	return 0;
}

void clear_window()
{
	int width, height;
	getmaxyx(stdscr,height,width);

	for(int i = 1; i < height-1; i++)
	for(int j = 1; j < width; j++)
	{	
		//attron(COLOR_CYAN);
		if (j==1)
			mvprintw(i,j,"~");
		else
			mvprintw(i,j," ");
		//attroff(COLOR_CYAN);
	}

}



