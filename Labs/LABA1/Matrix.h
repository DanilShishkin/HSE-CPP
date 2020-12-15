#ifndef LABA1_MATRIX_H
#define LABA1_MATRIX_H

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>
#include <cmath>

class Matrix {
protected:
    int num_rows_;
    int num_columns_;
    std::vector<std::vector<double>> elements_;

public:
    Matrix();
    Matrix(int num_rows, int num_columns);
    Matrix(int num_rows, int num_columns, std::vector<std::vector<double>> vec);
    void Reset(int num_rows, int num_columns);
    double& At(int row, int column);
    double At(int row, int column) const;
    int GetNumRows() const;
    int GetNumColumns() const;
    double Trace();
    void Transpose();
    Matrix Transposed() const;
    double FrobeniusNorm() const;
    void Swap(int i, int j);
    void Inverse();
    Matrix Inversed() const;
    int Rank() const;
    double Det() const;
    std::vector<double>& AtRow(int i);
    double EuclideanNorm() const;
    double MaxNorm() const;
    void WriteBinary(const char* filename) const;
    void ReadBinary(const char* filename);
};

double ScalarProduct(const Matrix& lhs, const Matrix& rhs);
double Angle(const Matrix& lhs, const Matrix& rhs);


#endif //LABA1_MATRIX_H
