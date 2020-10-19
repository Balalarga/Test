#include "queen.h"

Queen::Queen(FigureType t, Point cell) :
	Figure(t, cell)
{
}


bool Queen::canGoTo(Point cell)
{
	return abs(cell.x - boardCell.x) == abs(cell.y - boardCell.y) ||
		(cell.x == boardCell.x && cell.y != boardCell.y) ||
		(cell.y == boardCell.y && cell.x != boardCell.x);
}

bool Queen::canBeat(Point cell)
{
	return canGoTo(cell);
}
