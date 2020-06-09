#include "../header/windowsGui.h"

WindowGui::WindowGui() : Graphics(){} 
{

}

WindowGui::WindowGui(Graphics* world, Graphics * action) : Graphics(){}
{
    worldWin = world;
    actionWin = action;
}

virtual void WindowGui::draw()
{
    int i = 0;
    for(i = 0; i< subWin.size();i++)
    {
        subWin[i].draw();
    }	
}
