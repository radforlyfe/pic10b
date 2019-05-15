//
//  MagicSquare.h
//  assignment6

#ifndef MagicSquare_H
#define MagicSquare_H
#include<vector>
#include<iostream>
#include<sstream>
#include<unordered_set>
#include<string>

std::istream& operator>>(std::istream& in, std::vector<std::vector<int>>& square);
std::ostream& operator<<(std::ostream& out, const std::vector<std::vector<int>>& square);

class MagicSquare{
public:
    MagicSquare(const std::vector<std::vector<int>>& vec);
    void solveSquare(size_t index);
    int getnum(size_t index) const;
    void setnum(size_t index, int value);
    int getcount() const;
    void settaken();
    void setI();
    
private:
    bool empty(size_t row, size_t col) const;
    bool taken(int i) const;
    bool checkRow() const;
    bool checkValid() const;
    std::vector<std::vector<int>> data_;
    std::unordered_set<int> taken_;
    std::vector<size_t> I;
    int count_solutions = 0;
};

#endif /* MagicSquare_h */

// what are the private members?
// which functions are private?
// which functions are const& ?

