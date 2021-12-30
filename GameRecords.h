#pragma once
#include <vector>
#include <string>
#include "FootballGame.h"
#ifndef GAMERECORDS_H
#define GAMERECORDS_H

class GameRecords {

	std::vector<FootballGame> db;

	const static enum { INIT = 1, SAVETOFILE, READFROMFILE, ADDMATCH, MODMATCH, DELETEMATCH, PRINTREPTEAM, PRINTREPLOC, PRINTREPDEF, EXIT };
public:
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


};


#endif

