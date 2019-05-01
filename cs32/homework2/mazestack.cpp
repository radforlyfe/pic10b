//
//  Coord.cpp
//  homework2

#include<iostream>
#include<stack>

class Coord
{
public:
    Coord(int rr, int cc): m_r(rr), m_c(cc) {}
    int r() const { return m_r; }
    int c() const { return m_c; }
private:
    int m_r;
    int m_c;
};

// Return true if there is a path from (sr,sc) to (er,ec) through the maze;
// return false otherwise
bool pathExists(char maze[][10], int sr, int sc, int er, int ec)
{
    std::stack<Coord> coordStack;
    coordStack.push(Coord(sr,sc));
    maze[sr][sc] = '*';
    
    while(!coordStack.empty()){
        Coord current = coordStack.top();
        int r = current.r();
        int c = current.c();
        
        coordStack.pop();
        if(r == er && c == ec){                  // current = end coordinate
            return true;
        }
        if(maze[r+1][c] == '.'){                   // moving SOUTH
            coordStack.push( Coord(r+1,c) );
            maze[r+1][c] = '*';
        }
        if(maze[r][c-1] == '.'){                   // moving WEST
            coordStack.push( Coord(r,c-1) );
            maze[r][c-1] = '*';
        }
        if(maze[r-1][c] == '.'){                   // moving NORTH
            coordStack.push( Coord(r-1,c) );
            maze[r-1][c] = '*';
        }
        if(maze[r][c+1] == '.'){                   // moving EAST
            coordStack.push( Coord(r+1,c) );
            maze[r][c+1] = '*';
        }
    }
    return false;
}



int main()
{
    char maze[10][10] = {
        { 'X','X','X','X','X','X','X','X','X','X' },
        { 'X','.','.','.','.','X','.','.','.','X' },
        { 'X','.','X','X','.','X','X','X','.','X' },
        { 'X','X','X','.','.','.','.','X','.','X' },
        { 'X','.','X','X','X','.','X','X','X','X' },
        { 'X','.','X','.','.','.','X','.','.','X' },
        { 'X','.','.','.','X','.','X','.','.','X' },
        { 'X','X','X','X','X','.','X','.','X','X' },
        { 'X','.','.','.','.','.','.','.','.','X' },
        { 'X','X','X','X','X','X','X','X','X','X' }
    };
    
    if (pathExists(maze, 3,5, 8,8))
        std::cout << "Solvable!" << std::endl;
    else
        std::cout << "Out of luck!" << std::endl;
        //std::cout<< maze[][];
}