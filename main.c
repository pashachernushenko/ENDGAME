#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>

char *choices[] = { 
			"START",
            "SETTINGS",
            "ABOUT US",
            "EXIT",
		  };

int n_choices = sizeof(choices) / sizeof(char *);
void print_menu(WINDOW *win, int highlight);

// void mx_start_menu_choice(int highlight) {
// 	if (highlight == 1)
// 		mx_start_game; // function that will start game
// 	else if (highlight == 2) // if you are at settings input something
// 	else if  (highlight == 3) // if you are at about us, there will be some information about us
// 	else (highlight == 4) // exit out of menu


// }

void print_menu(WINDOW *win, int highlight)
{
	int x;
    int y;
    int i;	
    
    x = 30;
	y = 13;

    wattron(win, COLOR_GREEN);
	box(win, 0, 0);
    wattroff(win, COLOR_GREEN);
	
    
    for(i = 0; i < n_choices; ++i) {	
        
        if(highlight == i + 1) { // this is used to highlight the present element
        	wattron(win, A_REVERSE); 
			mvwprintw(win, y, x, "%s", choices[i]);
			wattroff(win, A_REVERSE);
		}
		else
			mvwprintw(win, y, x, "%s", choices[i]);
		y += 5;
	}
	wrefresh(win);
}



int main(){	

int highlight = 1;
int choice = 0;
int c;

	initscr();
	clear();
	noecho();
    curs_set(0);
	
    int yMax;
    int xMax;
    getmaxyx(stdscr, yMax, xMax);

		
    WINDOW *win = newwin(yMax / 2, xMax / 2, yMax / 4, xMax / 4);
	keypad(win, TRUE);
    refresh();
   
    print_menu(win, highlight);
	
     while(1)
	{	c = wgetch(win);
		switch(c)
		{	case KEY_UP:
				if(highlight == 1)
					highlight = n_choices;
				else
					--highlight;
				break; 
			case KEY_DOWN:
				if(highlight == n_choices)
					highlight = 1;
				else 
					++highlight;
				break;
			 case 10: // ASCII ENTER
			//  	// mx_start_menu_choice(highlight);
			// 	// should be a function which starts the game will take highli
				break;
			default:
				
				refresh();
				break;
		}
		print_menu(win, highlight);
		if(choice != 0)	/* User did a choice come out of the infinite loop */
			break;
	}	
	
	clrtoeol();
	refresh();
	endwin();
	return 0;
}
