#include "Matrix_Types.h"

Identity_Matrix::Identity_Matrix(int num){
    Reset(num, num);
    for (int i = 0; i < num; i++) {
        elements_[i][i] = 1;
    }
}

Diagonal_Matrix::Diagonal_Matrix(int num, std::vector<double> elements) {
    Reset(num, num);
    for (int i = 0; i < num; i++) {
        elements_[i][i] = elements[i];
    }
}

Lower_Matrix::Lower_Matrix(int num) {
    Reset(num, num);
    for (int i = 0; i < num; i++) {
        std::cout << "enter " << i + 1 << " elements" << std::endl << ">>> ";
        for (int j = 0; j < num; j++) {
            if(i >= j) {
                std::cin >> elements_[i][j];
            }
        }
    }
}

Upper_Matrix::Upper_Matrix(int num) {
    Reset(num, num);
    for (int i = 0; i < num; i++) {
        std::cout << "enter " << num - i << " elements" << std::endl << ">>> ";
        for (int j = 0; j < num; j++) {
            if(i <= j) {
                std::cin >> elements_[i][j];
            }
        }
    }
}

Symmetrical_Matrix::Symmetrical_Matrix(int num) {
    Reset(num, num);
    for (int i = 0; i < num; i++) {
        std::cout << "enter " << num - i << " elements" << std::endl << ">>> ";
        for (int j = 0; j < num; j++) {
            if(i <= j) {
                std::cin >> elements_[i][j];
                elements_[j][i] = elements_[i][j];
            }
        }
    }
}
