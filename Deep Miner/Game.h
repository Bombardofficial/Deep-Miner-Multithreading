#pragma once
#include <chrono>
#include <thread>
#include <mutex>
#include "Computerplayer.h"
class Game
{
public:
	void start_game();
	void createFirst(Player* first);
	void createSecond(Player* second);
	void createThird(Player* third);
	void createFourth(Player* fourth);
	void createFifth(Player* fifth);

	void randFirst(Player* first);
	void randSecond(Player* second);
	void randThird(Player* third);
	void randFourth(Player* fourth);
	void randFifth(Player* fifth);


	std::thread createFirstThread(Player* first) {
		return std::thread([=] { createFirst(first); });
	}
	std::thread createSecondThread(Player* second) {
		return std::thread([=] { createSecond(second); });
	}
	std::thread createThirdThread(Player* third) {
		return std::thread([=] { createThird(third); });
	}
	std::thread createFourthThread(Player* fourth) {
		return std::thread([=] { createFourth(fourth); });
	}
	std::thread createFifthThread(Player* fifth) {
		return std::thread([=] { createFifth(fifth); });
	}


	std::thread randFirstThread(Player* first) {
		return std::thread([=] { randFirst(first); });
	}
	std::thread randSecondThread(Player* second) {
		return std::thread([=] { randSecond(second); });
	}
	std::thread randThirdThread(Player* third) {
		return std::thread([=] { randThird(third); });
	}
	std::thread randFourthThread(Player* fourth) {
		return std::thread([=] { randFourth(fourth); });
	}
	std::thread randFifthThread(Player* fifth) {
		return std::thread([=] { randFifth(fifth); });
	}

};


