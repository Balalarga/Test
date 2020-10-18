#pragma once

#include "figure.h"


class Rook : public Figure
{
public:
	Rook(FigureType t, Point cell);
	bool nextStepCheck(Point nextCell) override;
private:

};