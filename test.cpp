#include <fstream>
#include <ncurses.h>
#include <string>
#include <vector>
#include <unistd.h>
std::vector<std::string>map(100);
std::vector<std::string> loadMap();
void printArea(WINDOW*);

int main(int argc, char**argv) 
{
  initscr();
  start_color();
  init_pair(1,COLOR_BLACK,COLOR_RED);
  //attron(COLOR_PAIR(1));
  //printw("hello world");
  //attroff(COLOR_PAIR(1));
  
  //refresh();

  noecho();
  cbreak();
  //
  int yMax,xMax;
  getmaxyx(stdscr,yMax, xMax);
  WINDOW * leftWin = newwin(yMax/2,(xMax/2)-2,0,0);
  WINDOW * rightWin = newwin(yMax/2,(xMax/2)-2,0,xMax/2);
  wbkgd(leftWin, COLOR_PAIR(1));
  //wbkgd(WindowName, COLOR_PAIR(1))
  refresh();
  wrefresh(leftWin);
  wrefresh(rightWin);
 
  map = loadMap();
 
  
  //wprintw(leftWin,"yMAX:%d",xMax);
  
  //wprintw(rightWin,"xMax:%d",yMax);
  //wrefresh(leftWin);
  //wrefresh(rightWin);
  printArea(leftWin);
  printArea(rightWin);

  refresh();
  sleep(4);
  int c = getch();
  //printw("%c",c);
  endwin();

  return 0;
}

std::vector<std::string> loadMap()
{	
    std::string line;
        std::ifstream file("map1.txt");
	std::vector<std::string>temp;
	while(std::getline(file,line))
	{
           temp.push_back(line);
	}
    return temp;
}

void printArea(WINDOW * win)
{ 
    int row, col;
    char * c;
    //mvwprintw(win,row+ 25,0,c);
    for(row = 0; row < 20; row++)
    {
	//wprintw(win, "%c", map[0].at(0));

	for(col = 0; col < 10; col++)
	{
	    &c = map[row].at(col);
            mvwprintw(win, row, col, "%c", *c);

	    /*if( == 0)
	    {
	     	  mvwprintw(win,row, col, " ");
	    }
	    else
	    {
		mvwprintw(win,row, col,"%s", c);    
                //wrefresh(win);
	    }*/
	}

    }
    wrefresh(win);  
}
