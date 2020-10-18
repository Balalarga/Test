#include "figure.h"


Figure::Figure(FigureType t, Point cell):
	type(t),
	boardCell(cell)
{
}

FigureType Figure::getType() const
{
	return type;
}

Point Figure::getCell()
{
	return boardCell;
}

void Figure::setCell(Point newCell)
{
	boardCell = newCell;
}

Figure::~Figure()
{
}
