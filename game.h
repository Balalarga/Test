#pragma once

#include "board.h"

class Game {
public:
	static Game& instance();

	void preinit();
	void init();
	void destroy();
	void update();
	void flush();


private:
	static Game* selfInstance;

	Game();
	spBoard board;

};