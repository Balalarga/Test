#pragma once

#include <oxygine-framework.h>
using namespace oxygine;

DECLARE_SMART(Figure, spFigure);

enum FigureType {
	WHITE = 0, BLACK
};

class Figure: public Sprite
{
public:
	Figure(FigureType t);

private:
	FigureType type;
};

