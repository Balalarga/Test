#include "board.h"
#include "resourcemanager.h"
#include <iostream>
#include <fstream>
using namespace std;

Board::Board(int w, int h, Vector2 pos)
{
	setSize(w, h);
	setPosition(pos);

	background = new Sprite;
	background->setResAnim(ResourceManager::instance().getAnim("chess_board"));
	background->setSize(w, h);
	background->attachTo(this);
	background->addEventListener(TouchEvent::TOUCH_DOWN, CLOSURE(this, &Board::touched));
	background->setTouchChildrenEnabled(false);

	cellSize = {float(w/8), float(h/8)};
	initFigures();
}


void Board::resetFigures()
{
	figures.clear();
	initFigures();
}

bool Board::isPlayersFigure()
{
	return false;
}

void Board::touched(Event* event){
	std::cout << "Touch event\n";
	TouchEvent* tev = safeCast<TouchEvent*>(event);
	Point touchedCell = getCell(tev->localPosition);
	if (selectedFigure) {
		selectedFigure->setColor(Color(255, 255, 255));
		selectedFigure = nullptr;
	}
	for (auto& i : figures) {
		if (i.pos == touchedCell){
			selectedFigure = i.figure.get();
			selectedFigure->setColor(Color(0, 255, 0));
		}
	}
}

Vector2 Board::getCellPos(Point cell)
{
	return Vector2{ cell.x*cellSize.x, cell.y*cellSize.y };
}

Point Board::getCell(Vector2 pos)
{
	return Point(int(pos.x/cellSize.x),
		int(pos.y /cellSize.y));
}

void Board::initFigures()
{
	ifstream input("boardConfig.txt");
	if (!input){
		std::cout << "No such file\n";
		return;
	}
	string figureTag;

	int x, y;
	for(int k = 0; k < 32; k++){
		input >> x >> y;
		input >> figureTag;
		FigureType type = WHITE;
		if (figureTag[0] == 'b')
			type = BLACK;
		Point p = { x, y };
		auto f = initActor(new Figure(type),
			arg_pos = getCellPos(p),
			arg_attachTo = this,
			arg_resAnim = ResourceManager::instance().getAnim(figureTag),
			arg_size = cellSize
			);
		figures.push_back({ p,f });
	}
}

Board::~Board()
{
	for (auto& f : figures) {
		f.figure->detach();
	}
	figures.clear();
	background->detach();
	background = nullptr;
}