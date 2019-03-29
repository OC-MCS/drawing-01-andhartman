#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;
#include "ShapeMgr.h"

class DrawingUI {
private:
public:
	DrawingUI(Vector2f p) {}

	void draw(RenderWindow& win, ShapeMgr* mgr) 
	{
		for (int i = 0; i != mgr->getShapes().size(); i++)
			mgr->getShapes()[i]->draw(win);
	}

	bool isMouseInCanvas(Vector2f mousePos) 
	{
		bool inCanvas = false;
		if (mousePos.x > 191 && mousePos.y < 464)
			inCanvas = true;
		return inCanvas;
	}

};