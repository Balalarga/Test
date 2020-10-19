#pragma once

#include "figure.h"

DECLARE_SMART(King, spKing);

class King : public Figure
{
public:
	King(FigureType t, Point cell);
	virtual bool canGoTo(Point cell) override;
	virtual bool canBeat(Point cell) override;

private:

};