#include "knight.h"

Knight::Knight(FigureType t, Point cell) :
	Figure(t, cell)
{
}

bool Knight::canGoTo(Point cell)
{
	return (abs(boardCell.x - cell.x) == 1 && abs(boardCell.y - cell.y) == 2) ||
		(abs(boardCell.x - cell.x) == 2 && abs(boardCell.y - cell.y) == 1);
}

bool Knight::canBeat(Point cell)
{
	return canGoTo(cell);
}
