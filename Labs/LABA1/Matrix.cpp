#include "Matrix.h"

#include <utility>
#include "Overloads.h"
#include <cmath>

Matrix::Matrix() {
        num_rows_ = 0;
        num_columns_ = 0;
}

Matrix::Matrix(int num_rows, int num_columns) {
    Reset(num_rows, num_columns);
}

void Matrix::Reset(int num_rows, int num_columns) {
    if (num_rows < 0) {
        throw std::out_of_range("num_rows must be >= 0");
    }
    if (num_columns < 0) {
        throw std::out_of_range("num_columns must be >= 0");
    }
    if (num_rows == 0 or num_columns == 0) {
        num_rows = num_columns = 0;
    }

    num_rows_ = num_rows;
    num_columns_ = num_columns;
    elements_.assign(num_rows, std::vector<double>(num_columns));
}

double& Matrix::At(int row, int column) {
    return elements_.at(row).at(column);
}

double Matrix::At(int row, int column) const {
    return elements_.at(row).at(column);
}

int Matrix::GetNumRows() const {
    return num_rows_;
}

int Matrix::GetNumColumns() const {
    return num_columns_;
}

void Matrix::Swap(int i, int j) {
    std::swap(elements_[i], elements_[j]);
}

double Matrix::Trace() {
    if (num_rows_ != num_columns_) {
        throw std::invalid_argument("The trace can only be calculated for a square matrix");
    }

    double ans = 0;
    for (int i = 0; i < num_rows_; i++) {
        ans += elements_[i][i];
    }

    return ans;
}

Matrix Matrix::Transposed() const {
    Matrix transposed(num_columns_, num_rows_);
    for (int i = 0; i < num_rows_; i++) {
        for (int j = 0; j < num_columns_; j++) {
            transposed.At(j, i) = elements_[i][j];
        }
    }
    return transposed;
}

void Matrix::Transpose() {
    *this = this->Transposed();
}

double Matrix::FrobeniusNorm() const {
    std::cout << *this * this->Transposed();
    return sqrt(((*this) * this->Transposed()).Trace());
}

int Matrix::Rank() const{
    const double EPS = 1E-9;
    Matrix a = *this;
    int rank = std::max(a.GetNumRows(), a.GetNumColumns());
    std::vector<bool> line_used (a.GetNumRows());
    for (int i = 0; i < a.GetNumColumns(); ++i) {
        int j;
        for (j = 0; j < a.GetNumRows(); ++j)
            if (!line_used[j] && (std::abs(a.At(j,i)) > EPS))
                break;
        if (j == a.GetNumRows())
            --rank;
        else {
            line_used[j] = true;
            for (int p = i+1; p < a.GetNumColumns(); ++p)
                a.At(j, p) /= a.At(j, i);
            for (int k = 0; k < a.GetNumRows(); ++k)
                if (k != j && (std::abs(a.At(k, i)) > EPS))
                    for (int p = i + 1; p < a.GetNumColumns(); ++p)
                        a.At(k, p) -= a.At(j, p) * a.At(k, i);
        }
    }
    return rank;
}

double Matrix::Det() const{
    Matrix m = *this;
    if (m.GetNumColumns() != m.GetNumRows()) {
        throw std::invalid_argument("The determinant can only be calculated for a square matrix");
    }
    const double EPS = 1E-9;
    double det = 1;
    int n = m.GetNumRows();
    for (int i = 0; i < n; ++i) {
        int k = i;
        for (int j = i + 1; j < n; ++j) {
            if (std::abs(m.At(j, i)) > std::abs(m.At(k, i)))
                k = j;
        }
        if (std::abs(m.At(k, i)) < EPS) {
            det = 0;
            break;
        }
        m.Swap(i, k);
        if (i != k) {
            det = -det;
        }
        det *= m.At(i, i);
        for (int j = i + 1; j < n; ++j) {
            m.At(i, j) /= m.At(i, i);
        }
        for (int j = 0; j < n; ++j) {
            if ((j != i) && (std::abs(m.At(j, i)) > EPS)) {
                for (int k = i + 1; k < n; ++k) {
                    m.At(j, k) -= m.At(i, k) * m.At(j, i);
                }
            }
        }
    }
    return det;
}

void Matrix::Inverse() {
    *this = this->Inversed();
}


Matrix Matrix::Inversed() const {
    Matrix copy = *this;

    if (num_rows_ != num_columns_) {
        throw std::invalid_argument("The inversed matrix can only be calculated for a square matrix");
    }

    if (copy.Det() == 0) {
        throw std::invalid_argument("For a degenerate matrix, it is impossible to find the inversed matrix");
    }

    double tmp;
    int line = 0, c = 0;

    Matrix inv(num_rows_, num_columns_);
    for (int i = 0; i < num_rows_; i++)
        inv.At(i, i) = 1;

    for (int i = 0; i < num_rows_ - 1; i++) {
        c = i;
        line = -1;
        while ((line == -1) and (c < num_columns_)) {
            if (copy.At(c, i) != 0)
                line = c;
            c++;
        }

        if (line != i) {
            for (int j = 0; j < num_columns_; j++) {
                std::swap(copy.At(i, j), copy.At(line, j));
                std::swap(inv.At(i, j), inv.At(line, j));
            }
        }
    }

    for (int i = 0; i < num_rows_; i++) {
        for (int j = 0; j < num_rows_; j++) {
            if ((copy.At(i, i) != 0) and (i != j)) {
                tmp = copy.At(j, i) / copy.At(i, i);
                if (tmp != 0) {
                    for (int k = 0; k < num_columns_; k++) {
                        copy.At(j, k) -= copy.At(i, k) * tmp;
                        inv.At(j, k) -= inv.At(i, k) * tmp;
                    }
                }
            }
        }
    }

    return inv;
}


std::vector<double>& Matrix::AtRow(int i){
    return elements_.at(i);
}

Matrix::Matrix(int num_rows, int num_columns, std::vector<std::vector<double>> vec) : num_rows_(num_rows),
num_columns_(num_columns), elements_(std::move(vec)) {}


double ScalarProduct(const Matrix& lhs, const Matrix& rhs){
    if ((lhs.GetNumRows() != 1) or (rhs.GetNumRows() != 1)) {
        throw std::runtime_error("Vector is a matrix with 1 row and some columns");
    }
    if (lhs.GetNumColumns() != rhs.GetNumColumns()) {
        throw std::runtime_error("Dimensions of this two vectors are different");
    }

    double ans = 0;
    for (int i = 0; i < lhs.GetNumColumns(); ++i) {
        ans += lhs.At(0, i) * rhs.At(0, i);
    }
    return ans;
}

double Matrix::EuclideanNorm() const {
    if (this->GetNumRows() !=1)  {
        throw std::runtime_error("Vector is a matrix with 1 row and some columns");
    }
    return std::sqrt(ScalarProduct(*this, *this));
}

double Matrix::MaxNorm() const {
    if (this->GetNumRows() !=1)  {
        throw std::runtime_error("Vector is a matrix with 1 row and some columns");
    }
    double max = elements_[0][1];
    for (auto elem : elements_[0]) {
        if (elem > max)
            max = elem;
    }
    return max;
}

double Angle(const Matrix& lhs, const Matrix& rhs) {
    double cos = ScalarProduct(lhs, rhs);
    cos /= lhs.EuclideanNorm();
    cos /= rhs.EuclideanNorm();
    return std::acos(cos);
}