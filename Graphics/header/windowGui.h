#ifndef __WINDOWGUI_H__
#define __WINDOWGUI_H__

#include "graphics.h"

class WindowGui : public Graphics
{
    public:
	WindowGui(std::vector<Graphics*>);
	virtual void draw();
	virtual void setMap(std::vector<std::string>);
    protected:
	std::vector<Graphics*> allWin;

};
#endif //__WINDOWGUI_H__
