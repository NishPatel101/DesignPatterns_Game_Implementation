#ifndef __WORLDGUI_H__
#define __WORLDGUI_H__
#include "graphics.h"

class WorldGui : public Graphics
{
    public:
        WorldGui(int winY, int winX, int startPosY, int startPosX, std::vector<std::string>) : Graphics();
	virtual void draw();
	void setMap(std::vector<std::string>);
    private:
	WINDOW* win;
	std::vector<std::string>map;
};
#endif //__WORLDGUI_H__
