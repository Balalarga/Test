#include "knight.h"

Knight::Knight(FigureType t, Point cell) :
	Figure(t, cell)
{
}

bool Knight::nextStepCheck(Point nextCell)
{
	return false;
}
