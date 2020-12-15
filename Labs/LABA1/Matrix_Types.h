#ifndef LABA1_MATRIX_TYPES_H
#define LABA1_MATRIX_TYPES_H
#include "Matrix.h"

class Identity_Matrix : public Matrix {
public:
    explicit Identity_Matrix(int num);
};

class Diagonal_Matrix : public Matrix {
public:
    Diagonal_Matrix(int num, std::vector<double> elements);
};

class Upper_Matrix : public Matrix {
public:
    Upper_Matrix(int num);
};

class Lower_Matrix : public Matrix {
public:
    Lower_Matrix(int num);
};

class Symmetrical_Matrix : public Matrix {
public:
    Symmetrical_Matrix(int num);
};

#endif //LABA1_MATRIX_TYPES_H
