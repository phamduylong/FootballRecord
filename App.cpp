#include "FootballGame.h"
#include "GameRecords.h"


int main(int argc, char* argv[]) {

	GameRecords* recordbook = new GameRecords;
	recordbook->run();
	delete recordbook;

	return 0;
}