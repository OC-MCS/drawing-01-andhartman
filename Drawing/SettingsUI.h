#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;
#include "SettingsMgr.h"

class SettingsUI 
{
private:
	const int RADIUS = 10, LENGTH = RADIUS * 2;

	Font font;
	CircleShape blueBtn;
	Color blueBtnColor;
	CircleShape redBtn;
	Color redBtnColor;
	CircleShape greenBtn;
	Color greenBtnColor;
	CircleShape circleBtn;
	Color circleBtnColor;
	RectangleShape squareBtn;
	Color squareBtnColor;
	RectangleShape vertGuideline;
	RectangleShape horzGuideline;
	Color curColor;
	ShapeEnum curShape;

public:
	SettingsUI(SettingsMgr *mgr) 
	{
		applySettings(mgr);
	}

	void applySettings(SettingsMgr *mgr) 
	{
		blueBtnColor = Color::Transparent;
		redBtnColor = Color::Transparent;
		greenBtnColor = Color::Transparent;

		circleBtnColor = Color::Transparent;
		squareBtnColor = Color::Transparent;

		curColor = mgr->getCurColor();
		if (curColor == Color::Blue)
			blueBtnColor = curColor;
		if (curColor == Color::Red)
			redBtnColor = curColor;
		if (curColor == Color::Green)
			greenBtnColor = curColor;
		curShape = mgr->getCurShape();
		if (curShape == CIRCLE)
			circleBtnColor = Color::White;
		if (curShape == SQUARE) 
			squareBtnColor = Color::White;
	}

	void handleMouseUp(Vector2f mouse, SettingsMgr *mgr) 
	{
		if (blueBtn.getGlobalBounds().contains(mouse)) 
		{
			blueBtnColor = Color::Blue;
			redBtnColor = Color::Transparent;
			greenBtnColor = Color::Transparent;

			mgr->setCurColor(Color::Blue);
		}
		if (redBtn.getGlobalBounds().contains(mouse)) 
		{
			blueBtnColor = Color::Transparent;
			redBtnColor = Color::Red;
			greenBtnColor = Color::Transparent;

			mgr->setCurColor(Color::Red);
		}
		if (greenBtn.getGlobalBounds().contains(mouse)) 
		{
			blueBtnColor = Color::Transparent;
			redBtnColor = Color::Transparent;
			greenBtnColor = Color::Green;

			mgr->setCurColor(Color::Green);
		}

		if (circleBtn.getGlobalBounds().contains(mouse)) 
		{
			circleBtnColor = Color::White;
			squareBtnColor = Color::Transparent;

			mgr->setCurShape(CIRCLE);
		}
		if (squareBtn.getGlobalBounds().contains(mouse)) 
		{
			circleBtnColor = Color::Transparent;
			squareBtnColor = Color::White;

			mgr->setCurShape(SQUARE);
		}
	}

	void draw(RenderWindow& win) {
		if (!font.loadFromFile("C:\\Windows\\Fonts\\arial.ttf"))
			die("couldn't load font");

		Text title("Drawing Color", font, 20);
		title.setPosition(23, 40);
		win.draw(title);

		blueBtn.setPosition(Vector2f(75, 100));
		blueBtn.setRadius(static_cast<float>(RADIUS));
		blueBtn.setOutlineThickness(2);
		blueBtn.setOutlineColor(Color::Blue);
		blueBtn.setFillColor(blueBtnColor);
		win.draw(blueBtn);

		redBtn.setPosition(Vector2f(75, 150));
		redBtn.setRadius(static_cast<float>(RADIUS));
		redBtn.setOutlineThickness(2);
		redBtn.setOutlineColor(Color::Red);
		redBtn.setFillColor(redBtnColor);
		win.draw(redBtn);

		greenBtn.setPosition(Vector2f(75, 200));
		greenBtn.setRadius(static_cast<float>(RADIUS));
		greenBtn.setOutlineThickness(2);
		greenBtn.setOutlineColor(Color::Green);
		greenBtn.setFillColor(greenBtnColor);
		win.draw(greenBtn);

		Text shapeText("Drawing Shape", font, 20);
		shapeText.setPosition(20, 275);
		win.draw(shapeText);

		circleBtn.setPosition(Vector2f(75, 335));
		circleBtn.setRadius(static_cast<float>(RADIUS));
		circleBtn.setOutlineThickness(2);
		circleBtn.setOutlineColor(Color::White);
		circleBtn.setFillColor(circleBtnColor);
		win.draw(circleBtn);

		squareBtn.setPosition(Vector2f(75, 385));
		squareBtn.setOutlineColor(Color::White);
		squareBtn.setOutlineThickness(2);
		squareBtn.setSize(Vector2f(static_cast<float>(LENGTH), static_cast<float>(LENGTH)));
		squareBtn.setFillColor(squareBtnColor);
		win.draw(squareBtn);

		vertGuideline.setPosition(Vector2f(180, 0));
		vertGuideline.setOutlineColor(Color::White);
		vertGuideline.setSize(Vector2f(1, 475));
		vertGuideline.setFillColor(Color::White);
		win.draw(vertGuideline);

		horzGuideline.setPosition(Vector2f(0, 475));
		horzGuideline.setOutlineColor(Color::White);
		horzGuideline.setSize(Vector2f(800, 1));
		horzGuideline.setFillColor(Color::White);
		win.draw(horzGuideline);
	}

	void die(string msg) 
	{
		cout << msg << endl;
		exit(-1);
	}
};