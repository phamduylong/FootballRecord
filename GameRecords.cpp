#include "GameRecords.h"

void GameRecords::init() {
	char conf{'n'};
	std::cout << "You are about to delete all the games in the record book! Do you want to continue?(y/n)\n";
	std::cin >> conf;
	if (!std::cin || (conf != 'y' && conf != 'n')) throw std::runtime_error("Please enter either y or n!");
	if (conf == 'y') {
		db.clear();
		writeToDatabase();
		std::cout << "Database cleared!\n";
	}
	else if (conf == 'n') {
		std::cout << "OK :)\n";
	}
}

void GameRecords::printAllGames() {
	readFromDatabase();
	if (db.empty()) {
		std::cout << "No games available in record book :( Please add some games and try again\n";
	}
	else {
		std::sort(db.begin(), db.end(),
			[](const FootballGame& fg1, const FootballGame& fg2) {
				return fg1.getLocation() < fg2.getLocation();
			}
		);
		std::cout << std::left << std::setw(COL_LEN) << "Home team"
			<< std::left << std::setw(COL_LEN) << "Home score"
			<< std::left << std::setw(COL_LEN) << "Away score"
			<< std::left << std::setw(COL_LEN) << "Away team"
			<< std::left << std::setw(COL_LEN) << "Location"
			<< std::left << std::setw(COL_LEN) << "Week" << '\n';
		for (auto const& it : db) {
			it.print();
		}
	}
}

void GameRecords::addGame() {
	readFromDatabase();
	FootballGame fg{};
	std::cout << "Enter details of the game:\n";
	fg.read();
	db.push_back(fg);
	writeToDatabase();
	std::cout << "Game added to record book!" << '\n';
}


void GameRecords::deleteGame() {
	readFromDatabase();
	FootballGame fg{};
	std::cout << "Enter details of the game. ";
	fg.read();
	auto it = std::find(db.begin(), db.end(), fg);
	if (it == db.end()) {
		std::cout << "Cannot find the game!\n";
	}
	else {
		db.erase(it);
		writeToDatabase();
		std::cout << "Game deleted from the record book!" << '\n';
	}

}

void GameRecords::modifyGame() {
	readFromDatabase();
	FootballGame query{};
	query.read();
	std::vector<FootballGame>::iterator it = std::find(db.begin(), db.end(), query);
	if (it != db.end()) {
		std::cout << "Game found! Please enter details of the new game:\n";
		(*it).read();
		std::cout << "Game modified!\n";
	}
	else {
		std::cout << "Game not found! Please try again!\n";
	}
	writeToDatabase();
}

void GameRecords::printByTeam() {
	readFromDatabase();
	std::sort(db.begin(), db.end(),
		[](const FootballGame& fg1, const FootballGame& fg2) {
			return fg1.getLocation() < fg2.getLocation();
		}
	);
	std::string team{};
	std::cout << "Enter name of the team:\n";
	std::getline(std::cin, team);
	std::cout << std::left << std::setw(COL_LEN) << "Home team"
		<< std::left << std::setw(COL_LEN) << "Home score"
		<< std::left << std::setw(COL_LEN) << "Away score"
		<< std::left << std::setw(COL_LEN) << "Away team"
		<< std::left << std::setw(COL_LEN) << "Location"
		<< std::left << std::setw(COL_LEN) << "Week" << '\n';
	for (auto const& i : db) {
		if (i.getHomeTeam() == team || i.getAwayTeam() == team) {
			i.print();
		}
	}

}

void GameRecords::printByLocation() {
	readFromDatabase();
	std::sort(db.begin(), db.end(),
		[](const FootballGame& fg1, const FootballGame& fg2) {
			return fg1.getHomeTeam() < fg2.getHomeTeam();
		}
	);
	std::string location{};
	std::cout << "Enter location:\n";
	std::getline(std::cin, location);
	std::cout << std::left << std::setw(COL_LEN) << "Home team"
		<< std::left << std::setw(COL_LEN) << "Home score"
		<< std::left << std::setw(COL_LEN) << "Away score"
		<< std::left << std::setw(COL_LEN) << "Away team"
		<< std::left << std::setw(COL_LEN) << "Location"
		<< std::left << std::setw(COL_LEN) << "Week" << '\n';
	for (auto const& i : db) {
		if (i.getLocation() == location) {
			i.print();
		}
	}
}

void GameRecords::writeToFile() {

	std::string filename{};
	std::cout << "Enter filename:\n";
	std::getline(std::cin, filename);
	std::ofstream customofile(filename);
	if (!customofile.is_open()) {
		std::cout << "Unable to open file! Please try again!\n";
		return;
	}
	customofile << "Home team,Away team,Home score,Away score,Location,Week\n";
	for (const auto& it : db) {
		customofile << it;
	}
	std::cout << "Data written to file " + filename + "\n";
	customofile.close();

}

void GameRecords::readFromFile() {

	std::string filename{};
	std::cout << "Enter filename:\nNOTE: File must be in csv format for the program to be able to read correctly\n";
	std::getline(std::cin, filename);
	std::ifstream customifile(filename);
	if (!customifile.is_open()) {
		std::cout << "Unable to open file! Please try again!\n";
		return;
	}
	db.clear();
	std::string tmp;
	while (std::getline(customifile, tmp)) {
		std::stringstream sstmp(tmp);
		FootballGame fg_tmp{};
		sstmp >> fg_tmp;
		db.push_back(fg_tmp);
	}
	writeToDatabase();
	std::cout << "Data read from file " << filename << "\n";
	customifile.close();

}

void GameRecords::writeToDatabase() {
	std::ofstream ofile("records.txt");
	if (!ofile.is_open()) throw(std::runtime_error("Unable to open database."));
	for (const auto &it : db) {
		ofile << it;
	}
	ofile.close();
}

void GameRecords::readFromDatabase() {
	db.clear();
	std::ifstream ifile("records.txt");
	if (!ifile.is_open()) throw(std::runtime_error("Unable to open database."));
	std::string tmp;
	while (std::getline(ifile, tmp)) {
		std::stringstream sstmp(tmp);
		FootballGame fg_tmp{};
		sstmp >> fg_tmp;
		db.push_back(fg_tmp);
	}
	ifile.close();
}

int GameRecords::takeInput() const {
	int choice{ 0 };
	std::cout << "1. Initialize database\n2. Save records to file\n3. Read records from a file\n4. Add a match\n"
		"5. Modify an existing match\n6. Delete a match\n7. Print report of a team's results\n8. Print report of matches played at a specific location\n"
		"9. Print all existing matches\n10. Exit program\n";
	std::cin >> choice;
	char garbage_collector = std::getchar();
	if (!std::cin) {
		throw(std::runtime_error("Input isn't a number. Please try again!"));
	}
	return choice;
}

void GameRecords::run() {
	readFromDatabase();
	bool cont = true;
	while (cont) {
		try {
			int choice = takeInput();
			switch (choice) {
			case INIT:
				init();
				break;
			case SAVETOFILE:
				writeToFile();
				break;
			case READFROMFILE:
				readFromFile();
				break;
			case ADDMATCH:
				addGame();
				break;
			case MODMATCH:
				modifyGame();
				break;
			case DELETEMATCH:
				deleteGame();
				break;
			case PRINTREPTEAM:
				printByTeam();
				break;
			case PRINTREPLOC:
				printByLocation();
				break;
			case PRINTREPDEF:
				printAllGames();
				break;
			case EXIT:
				cont = false;
				std::cout << "Program exited!\n";
				break;
			default:
				std::cout << "Please enter a number in the menu!\n";
				break;
			}
		}
		catch (std::exception& e) {
			std::cout << "Error occured: " << e.what() << '\n';
			cont = false;
			std::cout << "Program terminated due to error!";
		}

	}

}
