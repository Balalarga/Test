#pragma once

#include "figure.h"


class Rook : public Figure
{
public:
	Rook(FigureType t, Point cell);
	virtual bool canGoTo(Point cell) override;
	virtual bool canBeat(Point cell) override;
private:

};