#include "Matrix_Types.h"
#include "Overloads.h"



int main() {
    Matrix one;
    Matrix two;

    std::cin >> one;
    one.WriteBinary(R"(C:\Users\danil\CLionProjects\HSE\HSE-CPP\Labs\LABA1\Matrix.bin)");
    two.ReadBinary(R"(C:\Users\danil\CLionProjects\HSE\HSE-CPP\Labs\LABA1\Matrix.bin)");
    std::cout << two;

    Identity_Matrix I(5);
    std::cout << I;

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