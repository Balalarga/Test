#pragma once

#include "figure.h"

DECLARE_SMART(King, spKing);

class King : public Figure
{
public:
	King(FigureType t, Point cell);
	bool nextStepCheck(Point nextCell) override;

private:

};