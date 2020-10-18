#include "figure.h"



Figure::Figure(FigureType t):
	type(t)
{
}

FigureType Figure::getType() const
{
	return type;
}

