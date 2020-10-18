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

	cellSize = { float(w / 8), float(h / 8) };
	initFigures();
	addEventListener(TouchEvent::TOUCH_DOWN, CLOSURE(this, &Board::touched));
	setTouchChildrenEnabled(false);
}


void Board::resetFigures()
{
	for (auto& i : figures) {
		i.figure->detach();
		i.figure = 0;
	}
	figures.clear();
	initFigures();
}

bool Board::isPlayersFigure()
{
	bool findTypes[] = { false, false };
	for (auto& i : figures) {
		findTypes[i.figure->getType()] = true;
		if (findTypes[0] && findTypes[1])
			return true;
	}
	return false;
}

void Board::touched(Event* event) {

	TouchEvent* tev = safeCast<TouchEvent*>(event);
	Item* touchedItem = getTouched(getCell(tev->localPosition));

	if (selectedItem) {
		selectedItem->figure->setColor(Color(255, 255, 255));
		if (!touchedItem)
			selectedItem = nullptr;
		else {
			if (selectedItem->figure->getType() == touchedItem->figure->getType()) {
				selectedItem = touchedItem;
				selectedItem->figure->setColor(Color(0, 200, 0));
			}
			else {
				Point newCellPos = touchedItem->pos;
				Vector2 newRawPos = touchedItem->figure->getPosition();
				int deleteIndex = 0;
				for (int i = 0; i < figures.size(); i++) {
					if (&figures[i] == touchedItem) {
						figures[i].figure->detach();
						figures[i].figure = 0;
						deleteIndex = i;
						break;
					}
				}
				selectedItem->pos = newCellPos;
				selectedItem->figure->setPosition(newRawPos);
				selectedItem = nullptr;
				figures.erase(figures.begin() + deleteIndex);
				if (!isPlayersFigure()) {
					resetFigures();
				}
			}
		}
	}
	else if(touchedItem){
		selectedItem = touchedItem;
		selectedItem->figure->setColor(Color(0, 200, 0));
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
	for (int k = 0; k < 32; k++) {
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
		figures.push_back({ p, f });
	}
	input.close();
}

Item* Board::getTouched(Point touchedCell)
{
	for (auto& i : figures) {
		if (i.pos == touchedCell)
			return &i;
	}
	return nullptr;
}

void Board::free() {
	for (auto& f : figures) {
		f.figure->detach();
		f.figure = 0;
	}
	figures.clear();
	background->detach();
	background = nullptr;
}
