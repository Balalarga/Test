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
	Figure(FigureType t);
	FigureType getType() const;

private:
	FigureType type;
};

