#include <iostream>
#include <fstream>
using namespace std;
#include <SFML\Graphics.hpp>
#include "SettingsMgr.h"
#include "ShapeMgr.h"
#include "SettingsUI.h"
#include "DrawingUI.h"
using namespace sf;

int main() 
{
	const int WINDOW_WIDTH = 800;
	const int WINDOW_HEIGHT = 600;

	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Drawing");
	window.setFramerateLimit(120);

	fstream binFile;
	SettingsMgr settingsMgr(Color::Blue, ShapeEnum::CIRCLE);
	SettingsUI  settingsUI(&settingsMgr);
	ShapeMgr    shapeMgr;
	DrawingUI   drawingUI(Vector2f(200, 50));

	binFile.open("shapes.bin", ios::in | ios::binary);
	settingsMgr.load(binFile);
	settingsUI.applySettings(&settingsMgr);
	shapeMgr.load(binFile);
	binFile.close();

	while (window.isOpen()) 
	{
		Event event;
		while (window.pollEvent(event)) 
		{
			if (event.type == Event::Closed) 
			{
				window.close();

				binFile.open("shapes.bin", ios::out | ios::binary);
				settingsMgr.save(binFile);
				shapeMgr.save(binFile);
				binFile.close();
			}
			else if (event.type == Event::MouseButtonReleased) 
			{
				Vector2f mousePos = window.mapPixelToCoords(Mouse::getPosition(window));
				settingsUI.handleMouseUp(mousePos, &settingsMgr);
			}
			else if (event.type == Event::MouseMoved && Mouse::isButtonPressed(Mouse::Button::Left)) 
			{
				Vector2f mousePos = window.mapPixelToCoords(Mouse::getPosition(window));
				if (drawingUI.isMouseInCanvas(mousePos)) {
					shapeMgr.addShape(mousePos, settingsMgr.getCurShape(), settingsMgr.getCurColor());
				}
			}
		}
		window.clear();
		settingsUI.draw(window);
		drawingUI.draw(window, &shapeMgr);
		window.display();
	}

	return 0;
}