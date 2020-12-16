#include "Matrix_Types.h"
#include "Overloads.h"



int main() {
    Matrix one(3, 3, {{1, 2, 1}, {4 , 5 ,6}, {4, 8, 3}});
    Matrix two(3, 3, {{0, 1, 4}, {2 , 0 ,1}, {1,4,6}});
    Matrix three(5, 5, {{1, 5, 3, 6, 5},
                                                {5, 5, 3, 2, 6},
                                                {0, 1, 0, 9 ,4},
                                                {3, 5, 4, 7, 2},
                                                {0, 1, 9, 2, 6}});
    std::cout << one * (one.Inversed());
    std::cout << two.Inversed() * two;
    std::cout << three * three.Inversed();



   // std::cout << one.Inversed() * one;
   // std::cout << one * one.Inversed();

    /*
    one.WriteBinary(R"(C:\Users\danil\CLionProjects\HSE\HSE-CPP\Labs\LABA1\Matrix.bin)");
    two.ReadBinary(R"(C:\Users\danil\CLionProjects\HSE\HSE-CPP\Labs\LABA1\Matrix.bin)");
    std::cout << two;

    Identity_Matrix I(5);
    std::cout << I;*/

/*
    std::ofstream out;          // поток для записи
    out.open("D:\\hello.txt"); // окрываем файл для записи
    if (out.is_open())
    {
        out << one << std::endl;
    }
    else {
        throw std::runtime_error("File is not open");
    }

    std::ifstream in;
    in.open("D:\\hello.txt");
    if(in.is_open()) {
        in >> two;
    }
    else {
        throw std::runtime_error("File is not open");
    }

    std::cout << two;*/
    return 0;
}