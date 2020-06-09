#ifndef __GRAPHICS_H__
#define __GRAPHICS_H__

#include <ncurses.h>
#include <unistd.h>
#include <vector>
#include <string>

class Graphics
{
    public:
       	Graphics();
        virtual void draw() = 0;
    protected:
	int winX;
	int winY;
	int startPosX;
	int startPosY;

};
#endif //__GRAPHICS_H__
