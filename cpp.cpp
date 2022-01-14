////////////////////////////////////////////////////////////
// Pascal's Triangle
////////////////////////////////////////////////////////////

#include <iostream>
#include <iomanip>

void Combine(int**& out, int row, int col) {
    int mid = col / 2;

    for(int i = 0; i < row; ++i) {
        for(int j = 0; j < col; ++j) {
            out[i][j] = 0;
            out[0][mid] = 1;
        }
    }

    for(int i = 1; i < row; ++i) {
        for(int j = 1; j < col - 1; ++j) {
            out[i][j] = out[i-1][j-1] + out[i-1][j+1];
        }
    }
}

void Print(int** out, int row, int col) {
    std::cout << "\n\n";

    for(int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            if(out[i][j] == 0) std::cout << "   ";
            else std::cout << std::setw(4) << std::right << out[i][j];
        }
        std::cout << '\n';
    }

    std::cout << "\n\n";
}

int main(void) {
    int** out, rows, columns;
    rows = 9; // Modify this
    columns = 2 * rows + 1;
 
    out = new int*[rows];

    for(int i = 0; i < rows; ++i) {
        out[i] = new int[columns];
    }
 
    Combine(out, rows, columns);
 
    Print(out, rows, columns);

    delete out;
}

