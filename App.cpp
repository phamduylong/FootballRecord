#include "FootballGame.h"
#include "GameRecords.h"

constexpr int COL_LEN = 20;

int main(int argc, char* argv[]) {

	GameRecords* recordbook = new GameRecords;
	recordbook->run();
	delete recordbook;

	return 0;
}