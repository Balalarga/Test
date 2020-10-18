#include "king.h"

King::King(FigureType t, Point cell) :
	Figure(t, cell)
{
}

bool King::nextStepCheck(Point nextCell)
{

	return abs(nextCell.x - boardCell.x) == 1 ||
		abs(nextCell.y - boardCell.y) == 1;
}
