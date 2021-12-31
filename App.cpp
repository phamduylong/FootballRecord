#include "FootballGame.h"
#include "GameRecords.h"
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

int main(int argc, char* argv[]) {
	//_CrtMemState s1;
	//_CrtMemCheckpoint(&s1);

	GameRecords* recordbook = new GameRecords;
	recordbook->run();
	delete recordbook;
	//_CrtMemState s2, s3;
	//_CrtMemCheckpoint(&s2);
	//if (_CrtMemDifference(&s3, &s1, &s2)) {
	//	std::cout << "Memory leaked\n";
	//	_CrtDumpMemoryLeaks();
	//	_CrtMemDumpStatistics(&s3);
	//}
	//else {
	//	std::cout << "No memory leaked\n";
	//}


	return 0;
}