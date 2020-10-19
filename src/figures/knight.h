#pragma once

#include "figure.h"


class Knight : public Figure
{
public:
	Knight(FigureType t, Point cell);
	virtual bool canGoTo(Point cell) override;
	virtual bool canBeat(Point cell) override;

private:

};