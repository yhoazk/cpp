#include <ncurses.h>
#include <string.h>


#include <array>
#include <cstdint>
#include <random>
#include <memory>
#include <iostream>

std::array<std::array<uint8_t, 30>, 30> screen;
std::array<std::array<uint8_t, 30>, 30> screen_a;
std::unique_ptr<std::array<std::array<uint8_t, 30>, 30>> screen_src;
std::unique_ptr<std::array<std::array<uint8_t, 30>, 30>> screen_dst;

bool swappy{true};
constexpr char alive{'o'};
constexpr char dead{' '};


void seed() {
    screen[3][12] = alive;
    screen[2][12] = alive;
    screen[1][12] = alive;
    screen[1][13] = alive;
    screen[1][14] = alive;
    screen[1][12] = alive;
    screen[11][22] = alive;
    screen[13][2] = alive;
    screen[23][42] = alive;
    screen[3][12] = alive;
}


void show(){
    for(size_t row=0; row < (*screen_src).size(); ++row) {
        auto& line = (*screen_src)[row];
        for(size_t col=0; col < line.size(); ++col) {
            mvaddch(row, col, (*screen_src)[row][col]);
        }
    }
    std::swap(screen_src, screen_dst);
}


void update(){
    char cell_state;
    size_t neigh{};

    for(size_t row=0; row < (*screen_src).size(); ++row) {
        auto& line = (*screen_src)[row];
        for(size_t col=0; col < line.size(); ++col) {
            if (row == 0) {
                if (col == 0) {
                    neigh = ((*screen_src)[row][col+1] == alive) + ((*screen_src)[row+1][col]== alive) + ((*screen_src)[row+1][col+1] == alive);
                } else if (col == line.size()) {
                    neigh = ((*screen_src)[row][col-1] == alive) + ((*screen_src)[row+1][col+1]== alive) + ((*screen_src)[row+1][col] == alive);
                } else {
                    neigh = ((*screen_src)[row][col-1] == alive) + ((*screen_src)[row][col+1] == alive);
                    neigh += ((*screen_src)[row+1][col-1] == alive) + ((*screen_src)[row+1][col]== alive) + ((*screen_src)[row+1][col+1] == alive);
                }
            } else if (row == (*screen_src).size()) {
                if (col == 0) {
                    neigh = ((*screen_src)[row][col+1] == alive) + ((*screen_src)[row-1][col]== alive) + ((*screen_src)[row-1][col+1] == alive);
                } else if (col == line.size()) {
                    neigh = ((*screen_src)[row][col-1] == alive) + ((*screen_src)[row-1][col]== alive) + ((*screen_src)[row-1][col-1] == alive);
                } else {
                    neigh = ((*screen_src)[row][col-1] == alive) + ((*screen_src)[row][col+1] == alive);
                    neigh += ((*screen_src)[row-1][col-1] == alive) + ((*screen_src)[row-1][col]== alive) + ((*screen_src)[row-1][col+1] == alive);
                }
            } else {
                    // check the 8 cases
                if (col == 0) {
                    neigh = ((*screen_src)[row-1][col] == alive) + ((*screen_src)[row-1][col+1]== alive);
                    neigh += ((*screen_src)[row][col+1] == alive);
                    neigh += ((*screen_src)[row+1][col] == alive) + ((*screen_src)[row+1][col+1]== alive);
                } else if (col == line.size()) {
                    neigh = ((*screen_src)[row-1][col] == alive) + ((*screen_src)[row-1][col-1]== alive);
                    neigh += ((*screen_src)[row][col-1] == alive);
                    neigh += ((*screen_src)[row+1][col] == alive) + ((*screen_src)[row+1][col-1]== alive);
                } else {
                    neigh = ((*screen_src)[row-1][col-1] == alive) + ((*screen_src)[row-+1][col]== alive) + ((*screen_src)[row-1][col+1] == alive);
                    neigh += ((*screen_src)[row][col-1] == alive) + ((*screen_src)[row][col+1] == alive);
                    neigh += ((*screen_src)[row+1][col-1] == alive) + ((*screen_src)[row+1][col]== alive) + ((*screen_src)[row+1][col+1] == alive);
                }
            }
            // update
            switch(neigh) {
                case 0:
                case 1:
                    cell_state = dead;
                    break;
                case 2:
                case 3:
                    cell_state = alive;
                    std::cerr<< "Alove" << std::endl;
                    break;
                default:
                    cell_state = dead;

            }
            (*screen_dst)[row][col] = cell_state;
        }
    }
    std::swap(screen_src, screen_dst);
}

int main() {
    for(auto& l : screen) {
        l.fill(dead);
    }
    for(auto& l : screen_a) {
        l.fill(dead);
    }
    seed();
    screen_src = std::make_unique<std::array<std::array<uint8_t, 30>, 30>>(screen);
    screen_dst = std::make_unique<std::array<std::array<uint8_t, 30>, 30>>(screen_a);
    initscr();
    while(true) {
        show();
        update();
        refresh();
        getch();
    }
    endwin();

    return 0;
}
