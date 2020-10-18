#pragma once

#include "figure.h"


class Bishop : public Figure
{
public:
	Bishop(FigureType t, Point cell);
	bool nextStepCheck(Point nextCell) override;
};