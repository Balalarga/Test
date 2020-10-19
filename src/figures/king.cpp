#include "king.h"

King::King(FigureType t, Point cell) :
	Figure(t, cell)
{
}


bool King::canGoTo(Point cell)
{
	return abs(cell.x - boardCell.x) == 1 ||
		abs(cell.y - boardCell.y) == 1;
}

bool King::canBeat(Point cell)
{
	return canGoTo(cell);
}