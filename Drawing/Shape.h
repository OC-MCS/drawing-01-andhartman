#pragma once
#include <SFML/Graphics.hpp>
#include <string>
using namespace std;
using namespace sf;

struct ShapeData 
{
	int xpos, ypos, objShape;
	unsigned int colorNum;
};

class DrawingShape 
{
private:
	Vector2f pos;
	Color color;
	ShapeEnum shape;
public:
	DrawingShape(Vector2f p, ShapeEnum whichShape, Color whichColor) 
	{
		pos = p;
		color = whichColor;
		shape = whichShape;
	}

	virtual void draw(RenderWindow& win) = 0;

	ShapeData getShapeData() 
	{
		ShapeData temp = { static_cast<int>(pos.x), static_cast<int>(pos.y), shape, color.toInteger() };
		return temp;
	}
};

class Circle :public DrawingShape
{
private:
	CircleShape cir;
	const int RADIUS = 10;
public:
	Circle(Vector2f pos, ShapeEnum whichShape, Color whichColor) : DrawingShape(pos, whichShape, whichColor) 
	{
		cir.setPosition(Vector2f(pos.x - RADIUS, pos.y - RADIUS));
		cir.setRadius(static_cast<float>(RADIUS));
		cir.setOutlineThickness(2);
		cir.setOutlineColor(whichColor);
		cir.setFillColor(whichColor);
	}

	void draw(RenderWindow& win) { win.draw(cir); }
};

class Square :public DrawingShape 
{
private:
	RectangleShape sq;
	const int LENGTH = 20;
public:
	Square(Vector2f pos, ShapeEnum whichShape, Color whichColor) : DrawingShape(pos, whichShape, whichColor) 
	{
		sq.setPosition(Vector2f(pos.x - (LENGTH / 2), pos.y - (LENGTH / 2)));
		sq.setOutlineColor(whichColor);
		sq.setOutlineThickness(2);
		sq.setSize(Vector2f(static_cast<float>(LENGTH), static_cast<float>(LENGTH)));
		sq.setFillColor(whichColor);
	}

	void draw(RenderWindow& win) { win.draw(sq); }
};