#pragma once
#ifndef FOOTBALLGAME_H
#define FOOTBALLGAME_H
#endif

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

class FootballGame {
	std::string home_team;
	std::string away_team;
	int home_score;
	int away_score;
	std::string location;
	int week;
public:
	FootballGame(const char* home_team_name = "", const char* away_team_name = "", 
				int home_team_score = 0, int away_team_score = 0, const char* match_location = "", int match_week = 0);
	void read();
	void print() const;
	std::string getHomeTeam() const;
	std::string getAwayTeam() const;
	std::string getLocation() const;
	bool operator == (FootballGame cmp);
	friend std::ostream& operator << (std::ostream& os, const FootballGame& game);
	friend std::istream& operator >> (std::istream& is, FootballGame& game);
};
