#include <ncurses.h>			
#include <string.h> 
#define SIZE 10
#define LENGTH 180
int main()
{
    char string[SIZE][LENGTH] = {"Test\0","These are times\0","That try Men's souls\0"};

    char mesg[]="Enter a string: ";		
    char str[80];
    int row,col;
	int size = strlen(str);			
					 
    initscr();				
    getmaxyx(stdscr,row,col);		
    mvprintw(row/2,(col-strlen(mesg))/2,"%s",mesg);
                     		
    getstr(str);
    mvprintw(LINES - 3, 0, "You Entered: %s", str);

    for (int i = 0; i < SIZE; ++i)
    {
        for (int n = 0; n < LENGTH; ++n)
        {
            if (string[i][n] == str[0])
            {
                
            }
        }
    }

    if (string[0] == string[0])
    {
        mvprintw(LINES - 2, 0, "You Entered: %s", "Match");
    }
    else
    {
        mvprintw(LINES - 2, 0, "You Entered: %s", "No Match");
    }

    getch();
    endwin();
    return 0;
}
