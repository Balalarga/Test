#include "board.h"
#include "resourcemanager.h"
#include <iostream>
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
	Vector2 figSize = {float(w/8), float(h/8)};
	Point figPos = { 0, 0 };
	spFigure f1 = new Figure(WHITE);
	figures.push_back({ figPos, f1 });
	f1->setResAnim(ResourceManager::instance().getAnim("b_king"));
	f1->attachTo(this);
	f1->setPosition(figPos);
	f1->setSize(figSize);
}

void Board::update(const UpdateState& us) {

}

void Board::resetFigures()
{
	for (int i = 0; i < 2; i++) {
		FigureType type = FigureType(i);
		char resPrefix = type == WHITE ? 'w' : 'b';
		spFigure rook1 = new Figure(type);
		spFigure rook2 = new Figure(type);
		spFigure knight1 = new Figure(type);
		spFigure rook2 = new Figure(type);
		spFigure rook1 = new Figure(type);
		spFigure rook2 = new Figure(type);

	}
}

void Board::setPair(Figure fig, Point pos) {

}

void Board::touched(Event* event){
	cout << "Touch event\n";
	TouchEvent* tev = static_cast<TouchEvent*>(event);
	cout << tev->position.x << ", " << tev->position.x << endl;
}

Board::~Board()
{
	background->detach();
	background = nullptr;
}
