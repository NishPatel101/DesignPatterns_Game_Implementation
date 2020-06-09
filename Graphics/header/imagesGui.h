#ifndef __IMAGESGUI_H__
#define __IMAGESGUI_H__
#include "graphics.h"

class ImagesGui : public Graphics
{
    public:
        ImagesGui(int winY, int winX, int startPosY, int startPosX, std::vector<std::string>);
	virtual void draw();
	void setMap(std::vector<std::string>);
    private:
	WINDOW* win;
	std::vector<std::string>map;
};
#endif //__IMAGESGUI_H__
