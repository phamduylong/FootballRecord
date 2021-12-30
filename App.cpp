#include "FootballGame.h"
#include "GameRecords.h"
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

int main(int argc, char* argv[]) {

	GameRecords* recordbook = new GameRecords;
	recordbook->run();
	delete recordbook;



	return 0;
}