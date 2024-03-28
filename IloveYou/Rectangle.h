#ifndef RECTANDLE_H
#define RECTANGLE_H

#include <iostream>
#include <string>

using namespace std;

class Rectangle
{
private:
	int column;
	int row;
public:
	Rectangle();
	~Rectangle();
	Rectangle(int c, int r);
	void ChangeRectangle(int c, int r);
	int GetColumn();
	int GetRow();
};



#endif