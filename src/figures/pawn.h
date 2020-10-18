#pragma once

#include "figure.h"


class Pawn : public Figure
{
public:
	Pawn(FigureType t, Point cell);
	bool nextStepCheck(Point nextCell) override;

private:

};