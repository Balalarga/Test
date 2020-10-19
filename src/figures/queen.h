#pragma once

#include "figure.h"


class Queen : public Figure
{
public:
	Queen(FigureType t, Point cell);
	virtual bool canGoTo(Point cell) override;
	virtual bool canBeat(Point cell) override;
private:

};