#include <ncurses.h>			
#include <string.h> 
 
int main()
{
    const int SIZE = 10;

    char *string[SIZE];

    string[0] = "Test\0";
    string[1] = "These are times\0";
    string[2] = "That try Men's souls\0";

    char mesg[]="Enter a string: ";		
    char str[80];
    int row,col;
	int size = strlen(str);			
					 
    initscr();				
    getmaxyx(stdscr,row,col);		
    mvprintw(row/2,(col-strlen(mesg))/2,"%s",mesg);
                     		
    getstr(str);
    mvprintw(LINES - 3, 0, "You Entered: %s", str);

    char *quotePtr;
    for (int i = 0; i < SIZE; ++i)
    {
        for (quotePtr = string[i]; *quotePtr != '\0'; quotePtr++){
            //*quotePtr = tolower(*quotePtr);
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
