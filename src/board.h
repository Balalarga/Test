#pragma once
#include <vector>
#include <oxygine-framework.h>
using namespace oxygine;
using namespace std;

#include "figure.h"

DECLARE_SMART(Board, spBoard);


struct Item {
	Point pos;
	spFigure figure;
};

class Board: public Actor
{
public:
	Board(int w, int h, Vector2 pos);
	~Board();
	void update(const UpdateState& us);
	void resetFigures();
	void setPair(Figure fig, Point pos);
	//bool isAnyFigures();

private:
	vector<Item> figures;
	spSprite background;

	void touched(Event * event);
};

