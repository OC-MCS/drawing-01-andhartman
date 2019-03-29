#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
using namespace std;
using namespace sf;

enum ShapeEnum { CIRCLE, SQUARE };

class SettingsMgr 
{
private:
	Color curColor;
	ShapeEnum curShape;
	struct SettingsData 
	{
		unsigned int colorNum;
		int shape;
	};
public:
	SettingsMgr(Color startingColor = Color::Blue, ShapeEnum startingShape = CIRCLE) 
	{
		curColor = startingColor;
		curShape = startingShape;
	}

	Color getCurColor() 
	{
		return curColor;
	}

	void setCurColor(Color color) 
	{
		curColor = color;
	}

	ShapeEnum getCurShape() 
	{
		return curShape;
	}

	void setCurShape(ShapeEnum shape) 
	{
		curShape = shape;
	}

	unsigned int getColorInt() 
	{ 
		return curColor.toInteger(); 
	}

	void load(fstream &binFile) 
	{
		SettingsData temp;
		if (binFile.is_open()) 
		{
			binFile.read(reinterpret_cast<char*>(&temp), sizeof(temp));

			curColor = Color(temp.colorNum);
			curShape = (ShapeEnum)temp.shape;
		}
		else 
			cout << "Couldn't find file to open for SettingsMgr.\n";
	}

	void save(fstream &binFile) 
	{
		SettingsData temp = { getColorInt(), getCurShape() };
		binFile.write(reinterpret_cast<char*>(&temp), sizeof(temp));
	}
};
