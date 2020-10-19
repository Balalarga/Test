#include "board.h"
#include "figures\bishop.h"
#include "figures\king.h"
#include "figures\queen.h"
#include "figures\knight.h"
#include "figures\pawn.h"
#include "figures\rook.h"
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
		i->detach();
		i = 0;
	}
	figures.clear();
	initFigures();
}

bool Board::isPlayersFigure()
{
	bool findTypes[] = { false, false };
	for (auto& i : figures) {
		findTypes[i->getType()] = true;
		if (findTypes[0] && findTypes[1])
			return true;
	}
	return false;
}

void Board::touched(Event* event) {

	TouchEvent* tev = safeCast<TouchEvent*>(event);
	Point newCell = getCell(tev->localPosition);
	Vector2 newCellPos = getCellPos(newCell);
	spFigure touchedItem = getTouched(newCell);

	if (selectedItem) {
		selectedItem->setColor(Color(255, 255, 255));
		if (!touchedItem) {
			if (selectedItem->canGoTo(newCell)) {
				selectedItem->setCell(newCell);
				selectedItem->setPosition(newCellPos);
				selectedItem = nullptr;
			}
			else {
				selectedItem = nullptr;
			}
		}
		else {
			if (selectedItem->getType() == touchedItem->getType()) {
				selectedItem = touchedItem;
				selectedItem->setColor(Color(0, 200, 0));
			}
			else if (selectedItem->canBeat(newCell)) {
				int deleteIndex = 0;
				for (int i = 0; i < figures.size(); i++) {
					if (figures[i] == touchedItem) {
						figures[i]->detach();
						figures[i] = 0;
						deleteIndex = i;
						break;
					}
				}
				selectedItem->setCell(newCell);
				selectedItem->setPosition(newCellPos);
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
		selectedItem->setColor(Color(0, 200, 0));
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
		string figName = figureTag.substr(2);
		spFigure f;
		if (figName == "bishop") {
			f = new Bishop(type, p);
		}else if (figName == "king") {
			f = new King(type, p);
		}
		else if(figName == "pawn") {
			f = new Pawn(type, p);
		}
		else if(figName == "queen") {
			f = new Queen(type, p);
		}
		else if (figName == "knight") {
			f = new Knight(type, p);
		}
		else if (figName == "rook") {
			f = new Rook(type, p);
		}
		f->attachTo(this);
		f->setPosition(getCellPos(p));
		f->setResAnim(ResourceManager::instance().getAnim(figureTag));
		f->setSize(cellSize);

		figures.push_back(f);
	}
	input.close();
}

spFigure Board::getTouched(Point touchedCell)
{
	for (auto& i : figures) {
		if (i->getCell() == touchedCell)
			return i;
	}
	return nullptr;
}

void Board::free() {
	for (auto& f : figures) {
		f->detach();
		f = 0;
	}
	figures.clear();
	background->detach();
	background = nullptr;
}
