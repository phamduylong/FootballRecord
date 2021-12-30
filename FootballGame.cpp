#include "FootballGame.h"
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

FootballGame::FootballGame(
	const char* home_team_name, const char* away_team_name, 
	int home_team_score, int away_team_score, 
	const char* match_location, int match_week) : 
	home_team(home_team_name), away_team(away_team_name),
	home_score(home_team_score), away_score(away_team_score), 
	location(match_location), week(match_week) {}


void FootballGame::read() {
	char garbage_collector{};
	std::cout << "Enter name of home team:\n";
	std::getline(std::cin, home_team);
	std::cout << "Enter name of away team:\n";
	std::getline(std::cin, away_team);
	std::cout << "Enter score of home team (Only numbers are accepted):\n";
	std::cin >> home_score;
	std::cout << "Enter score of away team (Only numbers are accepted):\n";
	std::cin >> away_score;
	garbage_collector = std::getchar();
	std::cout << "Enter location of the match:\n";
	std::getline(std::cin, location);
	std::cout << "Enter week of the match (Only numbers are accepted):\n";
	std::cin >> week;
	garbage_collector = std::getchar();
}

void FootballGame::print() const {
	std::cout << std::left << std::setw(COL_LEN) << home_team
		<< std::left << std::setw(COL_LEN) << home_score
		<< std::left << std::setw(COL_LEN) << away_score
		<< std::left << std::setw(COL_LEN) << away_team 
		<< std::left << std::setw(COL_LEN) << location 
		<< std::left << std::setw(COL_LEN) << week << '\n';
}

std::string FootballGame::getHomeTeam() const
{
	return home_team;
}

std::string FootballGame::getAwayTeam() const
{
	return away_team;
}

std::string FootballGame::getLocation() const
{
	return location; 
}
bool FootballGame::operator==(FootballGame cmp)
{
	return (home_team == cmp.home_team && away_team == cmp.away_team && 
		home_score == cmp.home_score && away_score == cmp.away_score && 
		location == cmp.location && week == cmp.week);
}
std::ostream& operator<<(std::ostream& os, const FootballGame& game)
{
	os << game.home_team + "," + game.away_team + ","
		+ std::to_string(game.home_score) + "," + std::to_string(game.away_score) + "," 
		+ game.location + "," + std::to_string(game.week) << '\n';
	return os;
}

std::istream& operator>>(std::istream& is, FootballGame& game)
{
	std::vector<int> comma_indexes;
	std::string line;
	std::getline(is, line);
	for (unsigned int i = 0; i < line.length(); ++i) {
		if (line[i] == ',') comma_indexes.push_back(i);
	}

	game.home_team = line.substr(0, comma_indexes[0]);
	game.away_team = line.substr(comma_indexes[0] + 1, comma_indexes[1] - comma_indexes[0] - 1);
	game.home_score = std::stoi(line.substr(comma_indexes[1] + 1, comma_indexes[2] - comma_indexes[1] - 1));
	game.away_score = std::stoi(line.substr(comma_indexes[2] + 1, comma_indexes[3] - comma_indexes[2] - 1));
	game.location = line.substr(comma_indexes[3] + 1, comma_indexes[4] - comma_indexes[3] - 1);
	game.week = std::stoi(line.substr(comma_indexes[4] + 1, line.length() - comma_indexes[4] - 1));
	return is;
}
