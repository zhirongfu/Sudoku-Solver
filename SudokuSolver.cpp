//Zhi Fu         4/30/23
#include "SudokuSolver.hpp"

SudokuSolver::SudokuSolver()//default constructor
{
    puzzle=new int*[9];
    for(int i=0;i<9;i++)
    {
        puzzle[i]=new int[9];
    }
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            puzzle[i][j]=0;
        }
    }
    solvable=false;
}
SudokuSolver::SudokuSolver(std::string input_file)//parametrized constructor
{
    puzzle=new int*[9];
    for(int i=0;i<9;i++)
    {
        puzzle[i]=new int[9];
    }
    std::ifstream file(input_file);

    //int puzzle1[9][9];
    std::string nums;
    int i=-1;
    while(std::getline(file,nums))
    {
        i++;
        int j=-1;
        std::stringstream ss(nums);
        while(getline(ss,nums,','))
        {
            j++;
            puzzle[i][j]=stoi(nums);
        }
    }

}
bool SudokuSolver::solve()//helper function to solve game
{
    Sudoku::Location location;
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(puzzle[i][j]==0)
            {
                location.row=i;
                location.col=j;
                for(int x=1;x<=9;x++)
                {
                    if(checkLegalValue(x,location))
                    {
                        puzzle[i][j]=x;
                        //display();
                        if(solve())
                        {
                            return true;
                        }
                        else
                        {
                            puzzle[i][j]=0;
                        }  
                    }
                }
                return false;
            }
        }
    }
    solvable=true;
    return true;
}
bool SudokuSolver::isPuzzleSolvable()//returns solvable private var
{
    return solvable;
}
void SudokuSolver::setSolvable()//sets solvable to true
{
    solvable=true;
}
int** SudokuSolver::getPuzzleNumbers()//returns the 2d array 
{
    return puzzle;
}
void SudokuSolver::setPuzzleNumbers(int** puzzle1)//sets the 2d array to param
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            puzzle[i][j]=puzzle1[i][j];
        }
    }
}
Sudoku::Location SudokuSolver::returnNextEmpty()//returns new index in the array that is empty
{
    Sudoku::Location location;
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(puzzle[i][j]==0)
            {
                location.row=i;
                location.col=j;
                return location;
            }
        }
    }
    location.row=-1;
    location.col=-1;
    return location;
}
bool SudokuSolver::checkLegalValue(int value,Sudoku::Location Location)//checks if a number can be placed at a location
{
    for(int i=0;i<9;i++)
    {
        if(value==puzzle[Location.row][i])
        {
            return false;
        }
        if(value==puzzle[i][Location.col])
        {
            return false;
        }
        if(value==puzzle[3*((Location.row)/3)+i/3][3*((Location.col)/3)+i%3])
        {
            return false;
        }
    }
    return true;
}
void SudokuSolver::display()//displays the sudoku board
{
  for(int i=0;i<9;i++)
    {
        if(i%3 ==0 && i>0)
        {
            std::cout<<"- - - - - - - - - - - -"<<std::endl;
        }
        for(int j=0;j<9;j++)
        {
            if(j%3==0 && j>0)
            {
                std::cout<<" | ";
            }
            if(puzzle[i][j]==0)
            {
                std::cout<<"X ";
            }
            else
            {
                std::cout<<puzzle[i][j]<<" ";
            }
        }
        std::cout<<std::endl;     
    }  
}