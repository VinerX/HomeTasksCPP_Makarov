#include <iostream>
#include <random>
#include "windows.h"
#include <ctime>




double* createArray(double* ptrArr, int sizeOfArr)
{
    ptrArr = new double[sizeOfArr];
    return ptrArr;
}
void initArray(double* ptrArr, int sizeOfArr)
{
    for (int i = 0; i < sizeOfArr; i++)
    {
        ptrArr[i] = i;
    }
}
void printArray(double* ptrArr, int sizeOfArr)
{
    for (int i = 0; i < sizeOfArr; i++)
    {
        std::cout << ptrArr[i] << "  ";
    }
    std::cout << std::endl;
}
void freeMemory(double* ptrArr)
{
    delete[] ptrArr;
    ptrArr = 0;

    
}


// Task 2

void task2() {

    bool flag = true;
    do {
        int arraySize;
        std::cout << "Введите размер массива: ";
        std::cin >> arraySize;

        double* ptrArray = nullptr;
        ptrArray = createArray(ptrArray, arraySize);
        initArray(ptrArray, arraySize);
        printArray(ptrArray, arraySize);
        freeMemory(ptrArray);

        std::cout << "Продолжить что-угодно, закончить 0: ";
        int a;
        std::cin >> a;
        (a == 0) ? flag = false : flag = true;

    } while (flag);
    
}

int random(int start, int end) {
    return (rand() % (end - start + 1) + start);
}

double** createArray2D(double** ptrArray, int Columns, int Rows) {
    ptrArray = new double*[Rows];
    for (int i = 0; i < Rows; i++) {
        ptrArray[i] = new double[Columns];
    }
    return ptrArray;
}
void fillArray2D(double** ptrArray, int Columns, int Rows) {
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Columns; j++) {
            ptrArray[i][j] = random(10, 50);
        }

    }
}
void printArray2D(double** ptrArray, int Columns, int Rows) {
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Columns; j++) {
            std::cout<<ptrArray[i][j]<<" ";
        }
        std::cout << std::endl;
    }
}
void freeMemory2D(double** ptrArray, int Columns, int Rows) {
    for (int i = 0; i < Rows; i++) {
        delete[] ptrArray[i];
    }
    delete[] ptrArray;
    
}

void task4() {
    srand(time(0));
    bool flag = true;
    do {
        int arrayColumns;
        int arrayRows;
        std::cout << "Введите кол-во стобцов массива: ";
        std::cin >> arrayColumns;
        std::cout << "Введите кол-во строк массива: ";
        std::cin >> arrayRows;


        double** ptrArray = nullptr;
        ptrArray = createArray2D(ptrArray, arrayColumns, arrayRows);
        fillArray2D(ptrArray, arrayColumns, arrayRows);
        printArray2D(ptrArray, arrayColumns, arrayRows);
        freeMemory2D(ptrArray, arrayColumns, arrayRows);

        std::cout << "Продолжить что-угодно, закончить 0: ";
        int a;
        std::cin >> a;
        (a == 0) ? flag = false : flag = true;

    } while (flag);

}



int main()
{
    setlocale(LC_ALL, "Russian");
    task2();
    task4();

}
