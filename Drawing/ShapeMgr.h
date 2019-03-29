#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <fstream>
#include <string>
#include "Shape.h"
using namespace std;
using namespace sf;

class ShapeMgr 
{
private:
	vector<DrawingShape *> shapes;
public:
	~ShapeMgr() 
	{
		for (DrawingShape * i : shapes)
			delete[] i;
		shapes.clear();
	}

	void addShape(Vector2f pos, ShapeEnum whichShape, Color color) 
	{
		DrawingShape * temp;
		if (whichShape == CIRCLE)
			temp = new Circle(pos, whichShape, color);
		if (whichShape == SQUARE)
			temp = new Square(pos, whichShape, color);
		shapes.push_back(temp);
	}

	vector<DrawingShape *> getShapes() { return shapes; }

	void load(fstream &binFile) 
	{
		ShapeData temp;
		if (binFile.is_open())
		{
			while (binFile.read(reinterpret_cast<char*>(&temp), sizeof(temp)))
				addShape(Vector2f(static_cast<float>(temp.xpos), static_cast<float>(temp.ypos)), (ShapeEnum)temp.objShape, Color(temp.colorNum));
		}
		else
			cout << "Couldn't find file to open for SettingsMgr.\n";
	}

	void save(fstream &binFile) 
	{
		ShapeData temp;

		for (int i = 0; i != shapes.size(); i++) 
		{
			temp = shapes[i]->getShapeData();
			binFile.write(reinterpret_cast<char*>(&temp), sizeof(temp));
		}
	}

};
