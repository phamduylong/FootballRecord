#pragma once
#ifndef FOOTBALLGAME_H
#define FOOTBALLGAME_H
#endif

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
//length of report's columns
constexpr int COL_LEN = 20;
//class FootballGame declaration
class FootballGame {
	std::string home_team;
	std::string away_team;
	int home_score;
	int away_score;
	std::string location;
	int week;
public:
	//constructor
	FootballGame(const char* home_team_name = "", const char* away_team_name = "", 
				int home_team_score = 0, int away_team_score = 0, const char* match_location = "", int match_week = 0);
	//function to read data to class obj
	void read();
	//function to print an object in reports 
	void print() const;
	//getters
	std::string getHomeTeam() const;
	std::string getAwayTeam() const;
	std::string getLocation() const;
	//equal operator overloading
	bool operator == (FootballGame cmp);

	//stream operator overloading
	friend std::ostream& operator << (std::ostream& os, const FootballGame& game);
	friend std::istream& operator >> (std::istream& is, FootballGame& game);
};
