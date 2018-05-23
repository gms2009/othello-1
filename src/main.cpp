#include <iostream>
#include <utility>
#include <vector>

#include "Board.hpp"
#include "Player.hpp"
#include "Computer.hpp"

using Point = std::pair<int,int>;
int main()
{
  Board board;

  Player player(board,Board_env::black);
  Computer com(board,Board_env::white);

  bool path_find = true;
  for(int i = 0;i < 60;++i, path_find = true){

    std::vector<Point> pos = board.put_able_spot(Board_env::black);
    if (pos.size() == 0) {
      std::cout << "you are path\n";
    } else {
      path_find = false;
      board.print_board();
      for (auto& e : pos) std::cout << "x is " << e.first << "y is " << e.second << '\n';
      player.define_spot();
    }
    board.print_board();

    pos = board.put_able_spot(Board_env::white);
    if(pos.size() == 0)
    {
      std::cout << "you are path\n";continue;
    } else {
      path_find = false;
      for (auto& e : pos) std::cout << "x is " << e.first << "y is " << e.second << '\n';
      com.define_spot();
      std::cout << "result is \n";
    }
    if(path_find == true)break;
  }
  Board_env winner =  board.define_winner();
  if (winner == Board_env::black)std::cout << "winner is black\n";
  else if (winner == Board_env::white)std::cout << "winner is white\n";
  else std::cout << "draw\n";
}