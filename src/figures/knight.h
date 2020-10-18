#pragma once

#include "figure.h"


class Knight : public Figure
{
public:
	Knight(FigureType t, Point cell);
	bool nextStepCheck(Point nextCell) override;

private:

};