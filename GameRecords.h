#pragma once
#include <vector>
#include <string>
#include "FootballGame.h"
#ifndef GAMERECORDS_H
#define GAMERECORDS_H

namespace GameRecords {
	namespace Container {
		static std::vector<FootballGame> db;
	}
	enum {INIT = 1, SAVETOFILE, READFROMFILE, ADDMATCH, MODMATCH, PRINTREPTEAM, PRINTREPLOC, PRINTREPDEF, EXIT};

	void init();

	void printAllGames();

	void addGame();

	void deleteGame();

	void modifyGame();

	void printByTeam();

	void printByLocation();

	void writeToFile();

	void readFromFile();

	void writeToDatabase();

	void readFromDatabase();

	int takeInput();

	void run();
	

}


#endif

