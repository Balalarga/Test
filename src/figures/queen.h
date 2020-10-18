#pragma once

#include "figure.h"


class Queen : public Figure
{
public:
	Queen(FigureType t, Point cell);
	bool nextStepCheck(Point nextCell) override;
private:

};