#pragma once

#include "board.h"

class Game {
public:
	static Game& instance();

	void init();
	void destroy();
	void resetFigures();
	bool isPlayersFigure();


private:
	static Game* selfInstance;

	Game();
	spBoard board;
	vector<spFigure> figures;
	Vector2 cellSize;
	spFigure selectedItem = nullptr;
	
	void initFigures();
	Vector2 getCellPos(Point cell);
	Point getCell(Vector2 pos);
	spFigure getTouched(Point touchedCell);
	void touched(Event* event);
};