
#include "view_ascii.h"
#include "ansi_sequence.h"

#include <iostream>

using namespace view;
using namespace p4;
using namespace std;
using namespace ansi;

View_ASCII::View_ASCII(const Board& board) : board(board), current_player("", color_e::red) {}

void View_ASCII::display(bool clear)
{
    if(clear)
        std::system("clear");

    const auto& b = board.get_grid();

    for(int y = 0; y < Board::N_ROW; ++y)
    {
        for(int x = 0; x < Board::N_COLUMN; ++x)
        {
            cout << cell_to_print(b[x][y]);
        }
        cout << '\n';
    }
    cout << "0123456\n";

    cout << "history:";
    for(auto h : history)
    {
        if(h)
            cout << (int) h.value();
        else
            cout << '-';
        cout << ",";
    }
    cout << '\n';

    if(current_player.get_color() == color_e::red)
        cout << sgr::style::bold << sgr::fg::red, sgr::bg::blue;
    else
        cout << sgr::style::bold << sgr::fg::yellow, sgr::bg::blue;

    for(const auto& msg : msgs)
        cout << msg << '\n';

    //    cout << csi(sgr::reset) << flush;
    cout << sgr::style::reset << flush;
    msgs.clear();
}

void View_ASCII::message(const std::string& msg) { msgs.push_back(msg); }

string View_ASCII::cell_to_print(const Cell& cell) const
{
    if(cell.is_empty())
    {
        return "\033[4;44m \033[0m";
        //        return csi(sgr::underline, sgr::b_blue) + " " + csi(sgr::reset);
    }
    else
    {
        if(cell.get_color() == color_e::red)
        {
            return "\033[1;31;44mO\033[0m";
            //            return csi(sgr::bold, sgr::f_red, sgr::b_blue) + "0" + csi(sgr::reset);
        }
        else
        {
            return "\033[1;33;44mO\033[0m";
            //            return csi(sgr::bold, sgr::f_yellow, sgr::b_blue) + "0" + csi(sgr::reset);
        }
    }
    return "E";
}
