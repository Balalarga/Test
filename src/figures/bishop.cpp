#include "bishop.h"

Bishop::Bishop(FigureType t, Point cell):
	Figure(t, cell)
{
}

bool Bishop::nextStepCheck(Point nextCell)
{
	return abs(nextCell.x-boardCell.x) == abs(nextCell.y-boardCell.y);
}
