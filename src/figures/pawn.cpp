#include "pawn.h"

Pawn::Pawn(FigureType t, Point cell) :
	Figure(t, cell)
{
}

bool Pawn::nextStepCheck(Point nextCell)
{
	if (type == WHITE) {
		if (boardCell.y == 1)
			return nextCell.y <= 3;
		else
			return nextCell.y - boardCell.y == 1;
	}
	return false;
}
