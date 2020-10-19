#include "bishop.h"

Bishop::Bishop(FigureType t, Point cell):
	Figure(t, cell)
{
}


bool Bishop::canGoTo(Point cell)
{
	return abs(cell.x - boardCell.x) == abs(cell.y - boardCell.y);
}

bool Bishop::canBeat(Point cell)
{
	return canGoTo(cell);
}
