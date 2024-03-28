#include "Rectangle.h"

Rectangle::Rectangle()
{
	column = 0;
	row = 0;

}
Rectangle::~Rectangle()
{

}
Rectangle::Rectangle(int c, int r)
{
	column = c;
	row = r;
}
void Rectangle::ChangeRectangle(int c, int r)
{
	column = c;
	row = r;
}
int Rectangle::GetColumn()
{
	return column;
}
int Rectangle::GetRow()
{
	return row;
}