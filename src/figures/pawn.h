#pragma once

#include "figure.h"


class Pawn : public Figure
{
public:
	Pawn(FigureType t, Point cell);
	virtual bool canGoTo(Point cell) override;
	virtual bool canBeat(Point cell) override;

private:

};