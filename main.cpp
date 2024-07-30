//Zhi Fu         4/30/23
#include "SudokuSolver.hpp"
int main()
{
SudokuSolver solve1("puzzle1.csv");
solve1.display();
std::cout<<std::endl<<std::endl;
solve1.solve();
solve1.display();


//Sudoku::Location location;
//location.row=3;
//location.col=1;
//location=solve1.returnNextEmpty();
//std::cout<<location.row<<" "<<location.col;
//std::cout<<std::endl<<std::endl;
//std::cout<<solve1.isPuzzleSolvable();
//std::cout<<solve1.checkLegalValue(3,location);
//solve1.solve();
//solve1.display();
}

