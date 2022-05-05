#pragma once
#include <chrono>
#include <thread>
#include <mutex>
#include "Computerplayer.h"
class Game
{
public:
	void start_game();
	std::thread createFirst(Player* first);
	std::thread createSecond(Player* second);
	std::thread createThird(Player* third);
	std::thread createFourth(Player* fourth);
	std::thread createFifth(Player* fifth);

	std::thread randFirst(Player* first);
	std::thread randSecond(Player* second);
	std::thread randThird(Player* third);
	std::thread randFourth(Player* fourth);
	std::thread randFifth(Player* fifth);
};


