#ifndef LABA1_OVERLOADS_H
#define LABA1_OVERLOADS_H

#include "Matrix.h"

bool operator==(const Matrix& one, const Matrix& two);
Matrix operator+(const Matrix& one, const Matrix& two);
Matrix operator-(const Matrix& one, const Matrix& two);
Matrix operator*(const Matrix& one, double alpha);
Matrix operator*(double alpha, const Matrix& one);
Matrix operator*(const Matrix& one, const Matrix& two);
Matrix operator%(const Matrix& one, const Matrix& two);
std::istream& operator>>(std::istream& in, Matrix& matrix);
std::ostream& operator<<(std::ostream& out, const Matrix& matrix);
std::ifstream& operator>>(std::ifstream& in, Matrix& matrix);
std::ofstream& operator<<(std::ofstream& out, const Matrix& matrix);

std::vector<double> operator/(std::vector<double>& vec, double alpha);
std::vector<double> operator*(double alpha, std::vector<double>& vec);
std::vector<double> operator-(std::vector<double> lhs, std::vector<double> rhs);

#endif //LABA1_OVERLOADS_H
