#pragma once

#include "figure.h"


class Bishop : public Figure
{
public:
	Bishop(FigureType t, Point cell);
	virtual bool canGoTo(Point cell) override;
	virtual bool canBeat(Point cell) override;
};