#include <functional>
#include "oxygine-framework.h"

#include "game.h"
#include "resourcemanager.h"

using namespace oxygine;

Game* Game::selfInstance = nullptr;

Game & Game::instance()
{
	if (!selfInstance)
		selfInstance = new Game();
	return *selfInstance;
}

Game::Game()
{

}

void Game::preinit()
{
}

void Game::init()
{
	ResourceManager::instance().load("resources.xml");
	auto windowSize = getStage()->getSize();

	int boardSize = windowSize.y;
	if (windowSize.x < windowSize.y)
		boardSize = windowSize.x;
	Vector2 boardPos;
	boardPos.x = (windowSize.x - boardSize) / 2;
	boardPos.y = (windowSize.y - boardSize) / 2;

	board = new Board(boardSize, boardSize, boardPos);
	board->attachTo(getStage());
}

void Game::destroy()
{
	ResourceManager::instance().free();
}

void Game::update()
{

}

void Game::flush()
{

}