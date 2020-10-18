#pragma once

#include "board.h"

class Game {
public:
	static Game& instance();

	void init();
	void destroy();


private:
	static Game* selfInstance;

	Game();
	spBoard board;

};