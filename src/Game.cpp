#include "Game.hpp"
//#include "Point.hpp"
//#include "Board.hpp"
//#include "Player.hpp"
//#include "Computer.hpp"

#include <fstream>
#include <string>
#include <iostream>
#include <map>

Game::Game():ifs{file_path}
{
  if (!ifs.is_open()) {
    std::cout << "cant open:" << file_path << '\n';
    throw("cant open %s", file_path);
  }
  std::string s1, s2;
  std::getline(ifs, s1);
  std::getline(ifs, s2);
  if (s1.find("Black") && s2.find("White")) {
    if (s1.find("computer")) {
    }
  } else if (s1.find("White") && s2.find("Black")) {
  }
};

Game::~Game()
{
  ifs.close();
};

void Game::init()
{
};

void Game::run()
{
};