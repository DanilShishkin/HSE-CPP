#include "Overloads.h"

bool operator==(const Matrix& one, const Matrix& two) {
    if (one.GetNumRows() != two.GetNumRows()) {
        return false;
    }

    if (one.GetNumColumns() != two.GetNumColumns()) {
        return false;
    }

    for (int row = 0; row < one.GetNumRows(); ++row) {
        for (int column = 0; column < one.GetNumColumns(); ++column) {
            if (one.At(row, column) != two.At(row, column)) {
                return false;
            }
        }
    }

    return true;
}

Matrix operator+(const Matrix& one, const Matrix& two) {
    if (one.GetNumRows() != two.GetNumRows()) {
        throw std::invalid_argument("Mismatched number of rows");
    }

    if (one.GetNumColumns() != two.GetNumColumns()) {
        throw std::invalid_argument("Mismatched number of columns");
    }

    Matrix result(one.GetNumRows(), one.GetNumColumns());
    for (int row = 0; row < result.GetNumRows(); ++row) {
        for (int column = 0; column < result.GetNumColumns(); ++column) {
            result.At(row, column) = one.At(row, column) + two.At(row, column);
        }
    }

    return result;
}

Matrix operator-(const Matrix& one, const Matrix& two) {
    if (one.GetNumRows() != two.GetNumRows()) {
        throw std::invalid_argument("Mismatched number of rows");
    }

    if (one.GetNumColumns() != two.GetNumColumns()) {
        throw std::invalid_argument("Mismatched number of columns");
    }

    Matrix result(one.GetNumRows(), one.GetNumColumns());
    for (int row = 0; row < result.GetNumRows(); ++row) {
        for (int column = 0; column < result.GetNumColumns(); ++column) {
            result.At(row, column) = one.At(row, column) - two.At(row, column);
        }
    }
    return result;
}

Matrix operator*(const Matrix& one, double alpha) {
    Matrix result(one.GetNumRows(), one.GetNumColumns());
    for (int row = 0; row < result.GetNumRows(); ++row) {
        for (int column = 0; column < result.GetNumColumns(); ++column) {
            result.At(row, column) = one.At(row, column) * alpha;
        }
    }

    return result;
}

Matrix operator*(double alpha, const Matrix& one) {
    return one * alpha;
}

std::vector<double> operator/(std::vector<double>& vec, double alpha) {
    for (auto& elem : vec) {
        elem /= alpha;
    }
    return vec;
}

std::ostream& operator<<(std::ostream& out, const std::vector<double>& vec) {
    out << "[";
    for (auto elem : vec) {
        out << elem;
    }
    out << "]";
    return out;
}

std::vector<double> operator-(std::vector<double> lhs, std::vector<double> rhs) {
    std::vector<double> ans;
    if (lhs.size() != rhs.size()) {
        throw std::runtime_error ("You can not to use operator - with vectors of different length");
    }
    int i = 0;
    for (int i = 0; i < lhs.size(); i++) {
        ans.push_back(lhs[i] - rhs[i]);
    }
    std::cout << ans;
    return ans;
}


// Multiplication of the Hadamard
Matrix operator%(const Matrix& one, const Matrix& two) {
    if (one.GetNumRows() != two.GetNumRows()) {
        throw std::invalid_argument("Mismatched number of rows");
    }

    if (one.GetNumColumns() != two.GetNumColumns()) {
        throw std::invalid_argument("Mismatched number of columns");
    }

    Matrix result(one.GetNumRows(), one.GetNumColumns());
    for (int row = 0; row < result.GetNumRows(); ++row) {
        for (int column = 0; column < result.GetNumColumns(); ++column) {
            result.At(row, column) = one.At(row, column) * two.At(row, column);
        }
    }

    return result;
}

Matrix operator*(const  Matrix& one, const Matrix& two) {
    if (one.GetNumColumns() != two.GetNumRows()) {
        throw std::invalid_argument("Mismatched number of rows in the second matrix");
    }

    Matrix result(one.GetNumRows(), two.GetNumColumns());

    for (int i = 0; i < one.GetNumRows(); i++)
        for (int j = 0; j < two.GetNumColumns(); j++)
            for (int k = 0; k < one.GetNumRows(); k++)
                result.At(i, j) += (one.At(i, k) * two.At(k, j));

    return result;
}

std::istream& operator>>(std::istream& in, Matrix& matrix) {
    int num_rows, num_columns;
    std::cout << "please enter the number of rows and columns \n>>>";
    in >> num_rows >> num_columns;

    matrix.Reset(num_rows, num_columns);
    for (int row = 0; row < num_rows; ++row) {
        for (int column = 0; column < num_columns; ++column) {
            in >> matrix.At(row, column);
        }
    }

    return in;
}

std::ostream& operator<<(std::ostream& out, const Matrix& matrix) {
    out << "Matrix [" << matrix.GetNumRows() << " * " << matrix.GetNumColumns() << "]" << std::endl;
    for (int row = 0; row < matrix.GetNumRows(); ++row) {
        for (int column = 0; column < matrix.GetNumColumns(); ++column) {
            if (column > 0) {
                out << " ";
            }
            out << matrix.At(row, column);
        }
        out << std::endl;
    }

    return out;
}

std::ifstream& operator>>(std::ifstream& in, Matrix& matrix) {
    int num_rows, num_columns;
    in >> num_rows >> num_columns;

    matrix.Reset(num_rows, num_columns);
    for (int row = 0; row < num_rows; ++row) {
        for (int column = 0; column < num_columns; ++column) {
            in >> matrix.At(row, column);
        }
    }

    return in;
}

std::ofstream& operator<<(std::ofstream& out, const Matrix& matrix) {
    out <<matrix.GetNumRows() << " " << matrix.GetNumColumns() << std::endl;
    for (int row = 0; row < matrix.GetNumRows(); ++row) {
        for (int column = 0; column < matrix.GetNumColumns(); ++column) {
            if (column > 0) {
                out << " ";
            }
            out << matrix.At(row, column);
        }
        out << std::endl;
    }

    return out;
}


std::vector<double> operator*(double alpha, std::vector<double> &vec) {
    for (auto& elem : vec) {
        elem *= alpha;
    }
    return vec;
}

