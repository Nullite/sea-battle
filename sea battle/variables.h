#pragma once
#include <string>
#include <vector>

static bool isGame = true;
static bool isUserPlay;
static bool partyOver = false;
static bool bot1Aiming;
static bool bot2Aiming;
static bool isSaved = false;
static bool userSaveGame = false;
static bool saveLoad = false;
static std::string verticalBattleship = "#\n\t\t#\n\t\t#\n\t\t#\n";
static std::string horizontalBattleship = "####\n";
static std::string verticalCruiser = "#\n\t\t#\n\t\t#\n";
static std::string horizontalCruiser = "###\n";
static std::string verticalDestroyer = "#\n\t\t#\n";
static std::string horizontalDestroyer = "##\n";
static std::string submarine = "#\n";
static std::string shipElement = { (char)178, (char)178 };
static std::string destroyedShipElement = { (char)176, (char)176 };
static std::string miss = { (char)126, (char)126 };
static std::string userBoard;
static std::string comp1Board;
static std::string comp2Board;
static std::vector <int> ships = { 0, 0, 0, 0 };
static std::vector <int> ship;
static std::vector<std::vector <int> > comp1Ships;
static std::vector<std::vector <int> > comp2Ships;
static std::vector<std::vector <int> > userShips;
static std::vector<char> players;
static std::string userEnemyBoard;
static std::string comp1EnemyBoard;
static std::string comp2EnemyBoard;
static std::string sight = "[]";
static std::vector<int> coordsFinishingForBot1 = {-1, 0, 0, 0};
static std::vector<int> coordsFinishingForBot2 = {-1, 0, 0, 0};
static std::string bot1name = "John";
static std::string bot2name = "Elizabeth";
static std::string userName;
static std::string whoseTurn;
static std::string whoseNext;