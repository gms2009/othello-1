#include "Computer.hpp"

#include <iostream>
#include <istream>
#include <utility>

#include "Board.hpp"

using Point = std::pair<int,int>;
/*
std::istream& operator>>(std::istream& is , Point& pos)
{
  std::cin >> pos.first >> pos.second;
  return is;
}
*/

Computer::Computer(class Board& board, const Board_env& com_color) :val(&board), computer_stone(com_color){
};
Computer::~Computer(){};

Board_env define_enemy_color(const Board_env& my_color)
{
  if(my_color == Board_env::black)return Board_env::white;
  return Board_env::black;
}

void Computer::define_spot()
{
  std::vector<Point> put_able = val->put_able_spot(computer_stone);
  int size = put_able.size();
  int best_put = 0;
  int count_enemy = -1000;
  Board_env enemy_stone = define_enemy_color(computer_stone);

  for (int i = 0;i < size;++i)
  {
    Board cp_board;
    cp_board.board = val->board;
    cp_board.put_stone(put_able[i] ,computer_stone);
    cp_board.print_board();
    std::vector<Point> pos = cp_board.put_able_spot(enemy_stone);
    for (auto& e : pos)
    {
      std::cout << "x is " << e.first << "y is " << e.second << '\n';
    }
    int cost = 0;
    if((cost = costmap[put_able[i].second][put_able[i].first] - 5 * pos.size()) > count_enemy)
    {
      count_enemy =cost;// costmap[put_able[i].second][put_able[i].first] - 10 * pos.size();
      std::cout <<"this cost is "<< cost << '\n';
      best_put = i;
    }
  }
  val->put_stone(put_able[best_put],computer_stone);
}
