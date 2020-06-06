#ifndef __WINDOWGUI_H__
#define __WINDOWGUI_H__
#include "Graphic.h"

class WindowGui : Graphic
{
    public:
        WindowGui()
	virtual void draw();
    protected:
	Graphics * components;
}
#endif __WINDOWGUI_H__
