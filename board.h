#pragma once
#include <map>
#include <cmath>
#include <oxygine-framework.h>
using namespace oxygine;
using namespace std;

#include "figure.h"

struct Item {
	Point pos;
	spFigure figure;
};

DECLARE_SMART(Board, spBoard);

class Board: public Actor
{
public:
	Board(int w, int h, Vector2 pos);
	~Board();
	void resetFigures();
	bool isPlayersFigure();

private:
	vector<Item> figures;
	spSprite background;
	Vector2 cellSize;
	Figure* selectedFigure = nullptr;

	void touched(Event * event);
	Vector2 getCellPos(Point cell);
	Point getCell(Vector2 pos);
	void initFigures();
};