#include "Matrix.h"

void Matrix::WriteBinary(const char* filename) const{
    FILE * ptrFile = fopen(filename , "wb");

    if (ptrFile == nullptr) {
        throw std::runtime_error("File is not open");
    }

    fwrite(&num_rows_, sizeof(int), 1, ptrFile);
    fwrite(&num_columns_, sizeof(int), 1, ptrFile);

    for (int i = 0; i < num_rows_; ++i) {
        for (int j = 0; j < num_columns_; ++j) {
            fwrite(&elements_[i][j], sizeof(double), 1, ptrFile);
        }
    }
    fclose (ptrFile);
}

void Matrix::ReadBinary(const char* filename) {
    FILE * ptrFile = fopen(filename , "rb");
    if (ptrFile == nullptr) {
        throw std::runtime_error("File is not open");
    }

    int i;
    int j;
    fread(&i, 1, sizeof(int), ptrFile);
    fread(&j, 1, sizeof(int), ptrFile);

    Reset(i, j);
    for (int m = 0; m < i; ++m) {
        for (int n = 0; n < j; ++n) {
            double tmp;
            fread(&tmp, sizeof(double), 1, ptrFile);
            elements_[m][n] = tmp;
        }
    }

    fclose (ptrFile);
}