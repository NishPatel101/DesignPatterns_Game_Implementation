#include "../header/windowGui.h"

WindowGui::WindowGui(Graphics* world, Graphics * action)
{
    worldWin = world;
    actionWin = action;
}

void WindowGui::draw()
{
    worldWin->draw();
    actionWin->draw();
}
