#include <fstream>
#include <ncurses.h>
#include <string>
#include <vector>
#include <unistd.h>
std::vector<std::string>map(100);
std::vector<std::string> loadMap();
void printArea();

int main(int argc, char**argv) 
{
  initscr();
  //printw("hello world");
  refresh();
  noecho();
  cbreak();
  //
  int yMax,xMax;
  getmaxyx(stdscr,yMax, xMax);
  WINDOW * game = newwin(6,xMax,yMax,5);
  refresh();
  wrefresh(game);
  //
  map = loadMap();
  //
  //for(int i = 0; i < map.size();i++)
  //{
  //    printw("%s\n", map[i].c_str());
  //}
  printArea();

  refresh();
  sleep(4);
  int c = getch();
  printw("%c",c);
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

void printArea()
{
  for(int i = 0; i < 20; i++)
  {
      printw("%s\n", map[i].c_str());
      refresh();
  }
  
}
