#include "../header/windowGui.h"

WindowGui::WindowGui(std::vector<Graphics*> windowCollect)
{
    allWin = windowCollect;
}

void WindowGui::draw()
{
    int i;
    for(i = 0; i < allWin.size();i++)
    {
	    allWin[i]->draw();
    }
}

void WindowGui::setMap(std::vector<std::string>)
{

}
