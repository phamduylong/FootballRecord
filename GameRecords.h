#pragma once
#include <fstream>
#include <sstream>
#include <algorithm>
#include "FootballGame.h"
#ifndef GAMERECORDS_H
#define GAMERECORDS_H
#endif

class GameRecords {

	std::vector<FootballGame> db;

	enum { INIT = 1, SAVETOFILE, READFROMFILE, ADDMATCH, MODMATCH, DELETEMATCH, PRINTREPTEAM, PRINTREPLOC, PRINTREPDEF, EXIT };

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

public:

	void run();


};




