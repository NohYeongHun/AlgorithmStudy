#include <vector>
#include <numeric>
#include <algorithm>
#include <iostream>

/*
    함수포인터 예제
    bool (*comparisonFcn)(int, int)
    => bool 반환값을 가지고 (int, int)타입의 매개변수를 가지고 있는 함수의 포인터
    => 여기서는 ascending, descending에 대한 포인터를 가져온다.

    typedef를 활용하여 해당 포인터에 대한 타입을 정의할 수도 있다.
*/
typedef bool (*validateFcn)(int, int);

void selectionSort(int* array, int size, bool (*comparisonFcn)(int, int))
{
    for (int i = 0; i < size; ++i)
    {
        int smallestIndex = i;

        for (int j = i + 1; j < size; ++j)
        {
            if (comparisonFcn(array[smallestIndex], array[j])) // 비교 부분
                smallestIndex = j;
        }

        std::swap(array[smallestIndex], array[i]);
    }
}

void selectionSort2(int* array, int size, validateFcn vf)
{
    for (int i = 0; i < size; ++i)
    {
        int smallestIndex = i;

        for (int j = i + 1; j < size; ++j)
        {
            if (vf(array[smallestIndex], array[j])) // 비교 부분
                smallestIndex = j;
        }

        std::swap(array[smallestIndex], array[i]);
    }
}

bool ascending(int x, int y)
{
    return x > y; // 오름차순
}

bool descending(int x, int y)
{
    return x < y; // 내림차순
}

void printArray(int *array, int size)
{
    for (int index=0; index < size; ++index)
        std::cout << array[index] << " ";
    std::cout << '\n';
}

int main()
{
    int array[9] = { 3, 7, 9, 5, 6, 1, 8, 2, 4 };
    int array2[9] = { 3, 7, 9, 5, 6, 1, 8, 2, 4 };

    // 내린차순 선택정렬
    selectionSort(array, 9, descending);
    printArray(array, 9);

    // 오름차순 선택정렬
    selectionSort(array, 9, ascending);
    printArray(array, 9);
    
    cout << '\n';

    // 내림차순 선택정렬
    selectionSort2(array2, 9, descending);
    printArray(array2, 9);

    // 오름차순 선택정렬
    selectionSort2(array2, 9, ascending);
    printArray(array2, 9);

    return 0;
}
