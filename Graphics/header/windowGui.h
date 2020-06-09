#ifndef __WINDOWGUI_H__
#define __WINDOWGUI_H__

#include "graphics.h"

class WindowGui : public Graphics
{
    public:
	WindowGui(Graphics*, Graphics*);
	virtual void draw();
    protected:
	Graphics * worldWin;
	Graphics * actionWin;

};
#endif //__WINDOWGUI_H__
