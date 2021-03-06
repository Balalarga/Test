#pragma once

#include <oxygine-framework.h>
using namespace oxygine;

DECLARE_SMART(Figure, spFigure);

enum FigureType {
	WHITE, BLACK
};

class Figure: public Sprite
{
public:
	Figure(FigureType t, Point cell);
	FigureType getType() const;
	Point getCell();
	void setCell(Point newCell);

	virtual bool canGoTo(Point cell) = 0;
	virtual bool canBeat(Point cell) = 0;
	virtual ~Figure();

protected:
	FigureType type;
	Point boardCell;
};

