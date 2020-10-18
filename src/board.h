#pragma once
#include <map>
#include <cmath>
#include <oxygine-framework.h>
using namespace oxygine;
using namespace std;

#include "figures/figure.h"

DECLARE_SMART(Board, spBoard);

class Board: public Actor
{
public:
	Board(int w, int h, Vector2 pos);
	void free();
	void resetFigures();
	bool isPlayersFigure();

private:
	vector<spFigure> figures;
	spSprite background;
	Vector2 cellSize;
	spFigure selectedItem = nullptr;

	void initFigures();

	void touched(Event* event);
	Vector2 getCellPos(Point cell);
	Point getCell(Vector2 pos);
	spFigure getTouched(Point touchedCell);
};