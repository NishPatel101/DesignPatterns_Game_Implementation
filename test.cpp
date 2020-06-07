#include <fstream>
#include <ncurses.h>

using namespace std;

int main () 
{
  initscr();
  noecho();
  cbreak();
  //
  int yMax,xMax;
  getmaxyx(stdscr,yMax, xMax);
  
  //
  
  //
  string line;
  ifstream myfile ("map1.txt");
  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
      printw(line);
    }
    myfile.close();
  }

  else cout << "Unable to open file";

//
endwin();

  return 0;
}
