#include "rook.h"

Rook::Rook(FigureType t, Point cell):
	Figure(t, cell)
{
}

bool Rook::nextStepCheck(Point nextCell)
{
	return (nextCell.x == boardCell.x && nextCell.y != boardCell.y) ||
		(nextCell.y == boardCell.y && nextCell.x != boardCell.x);
}