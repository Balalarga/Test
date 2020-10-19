#include "rook.h"

Rook::Rook(FigureType t, Point cell):
	Figure(t, cell)
{
}

bool Rook::canGoTo(Point cell)
{
	return (cell.x == boardCell.x && cell.y != boardCell.y) ||
		(cell.y == boardCell.y && cell.x != boardCell.x);;
}

bool Rook::canBeat(Point cell)
{
	return canGoTo(cell);
}
