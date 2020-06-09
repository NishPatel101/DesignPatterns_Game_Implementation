#include <fstream>
#include <ncurses.h>
#include <string>
#include <vector>
#include <unistd.h>


std::vector<std::string>map(100);
std::vector<std::string>logo(100);
std::vector<std::string> loadFile(std::string);

void printWorld(WINDOW*);
void printAction(WINDOW*);
void printLogo(WINDOW*);
void printChat(WINDOW*);

int main(int argc, char**argv) 
{
  initscr();
  start_color();
  init_pair(1,COLOR_BLACK,COLOR_RED);
  init_pair(2,COLOR_GREEN,COLOR_BLACK);
  noecho();
  cbreak();

  int yMax,xMax;
  getmaxyx(stdscr,yMax,xMax);

  map = loadFile("map1.txt");
  logo = loadFile("logo1.txt");
  int logoHeight = logo.size() + 1;
  int logStartYpos = logo.size() + yMax/2 + 1;



  WINDOW * leftWin = newwin(yMax/2,(xMax/2),logoHeight + 1,0);
  WINDOW * rightWin = newwin(yMax/2,(xMax/2),logoHeight + 1,(xMax/2)+1);
  WINDOW * chatWin = newwin(yMax - logStartYpos, xMax,logStartYpos,0);
  WINDOW * logoWin = newwin(logoHeight, xMax/3, 0,xMax/3);


  box(leftWin,0,0);
  box(rightWin,0,0);
  box(chatWin,0,0);
  //box(logoWin,0,0);
  //wbkgd(leftWin, COLOR_PAIR(1));

  refresh();
  wrefresh(leftWin);
  wrefresh(rightWin);
  wrefresh(chatWin);
  wrefresh(logoWin);
 
  
  printWorld(leftWin);
  printAction(rightWin);
  wattron(logoWin,COLOR_PAIR(2));
  printLogo(logoWin);
  printChat(chatWin);

  refresh();
  sleep(4);
  int c = getch();
  endwin();

  return 0;
}
void setup()
{


}
std::vector<std::string> loadFile(std::string file)
{	
    std::string line;
        std::ifstream readFile(file);
	std::vector<std::string>temp;
	while(std::getline(readFile,line))
	{
           temp.push_back(line);
	}
    return temp;
}


void printLogo(WINDOW *win)
{
    int row, col;
    char * c;
    
    for(row = 0; row < logo.size(); row++)
    {
	for(col = 0; col < logo[row].size(); col++)
	{
	    c = &logo[row].at(col);
            mvwprintw(win, row + 1, col + 1, "%c", *c);
	}
    }
    wrefresh(win);  
}

void printWorld(WINDOW * win)
{ 
    int row, col;
    char * c;
    int winX,winY;
    getyx(win,winY,winX);

    for(row = 0; row < 30; row++)
    {
	for(col = 0; col < 60; col++)
	{
	    c = &map[row].at(col);
            mvwprintw(win, row + 1, col + 30, "%c", *c);
	}
    }
    wrefresh(win);  
}

void printAction(WINDOW* win)
{
    mvwprintw(win,1,1,"%s","I'm Mr. Meeseeks, look at me!");
    wrefresh(win);
}

void printChat(WINDOW* win)
{
    mvwprintw(win, 10, 50, "%s", " DEBUG LOG CHAT AREA");
    wrefresh(win);
}
