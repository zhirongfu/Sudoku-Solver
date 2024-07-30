//Zhi Fu             4/30/23
#ifndef SUDOKU_SOLVER_HPP_
#define SUDOKU_SOLVER_HPP_
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

namespace Sudoku
{ 
  struct Location
  {
    int row;
    int col;
  };
}

class SudokuSolver
{
public:
//Add your public members here
SudokuSolver();//default constructor
SudokuSolver(std::string input_file);//parametrized constructor
bool solve();//helper function to solve game
bool isPuzzleSolvable();//returns solvable private var
void setSolvable();//sets solvable to true
int** getPuzzleNumbers();//returns the 2d array 
void setPuzzleNumbers(int** puzzle1);//sets the 2d array to param
Sudoku::Location returnNextEmpty();//returns new index in the array that is empty
bool checkLegalValue(int value, Sudoku::Location Location);//checks if a number can be placed at a location
void display();//displays the sudoku board



private:
int ** puzzle;//2d array taht stores the puzzle
bool solvable=false;//solvablae variable defaulted false





};

#endif
