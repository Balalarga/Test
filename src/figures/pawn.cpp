#include "pawn.h"

Pawn::Pawn(FigureType t, Point cell) :
	Figure(t, cell)
{
}


bool Pawn::canGoTo(Point cell)
{
	if (cell.x != boardCell.x)
		return false;

	if (type == BLACK)
	{
		if (boardCell.y == 1) {
			return cell.y - boardCell.y <= 2;
		}
		else
		{
			return cell.y - boardCell.y == 1;
		}
	}
	else {
		if (boardCell.y == 6) {
			return boardCell.y - cell.y <= 2;
		}
		else
		{
			return boardCell.y - cell.y == 1;
		}
	}
}

bool Pawn::canBeat(Point cell)
{
	if (type == BLACK)
		return cell.y - boardCell.y == 1 &&
			abs(boardCell.x - cell.x) == 1;
	else
		return boardCell.y - cell.y == 1 &&
			abs(boardCell.x - cell.x) == 1;
}