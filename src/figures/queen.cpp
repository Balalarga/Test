#include "queen.h"

Queen::Queen(FigureType t, Point cell) :
	Figure(t, cell)
{
}

bool Queen::nextStepCheck(Point nextCell)
{
	return abs(nextCell.x - boardCell.x) == abs(nextCell.y - boardCell.y) ||
		(nextCell.x == boardCell.x && nextCell.y != boardCell.y) ||
		(nextCell.y == boardCell.y && nextCell.x != boardCell.x);
}
