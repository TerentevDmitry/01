// Задача 1. Лямбда-функция
//

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    setlocale(LC_ALL, "ru");

    std::vector<int> myVector = { 4, 7, 9, 14, 12, 15 };
    //                            4,21,27, 14, 12, 45

    auto print = [](const int& n) { std::cout << n << '\t'; };

    std::cout << "before:\t";
    std::for_each(myVector.cbegin(), myVector.cend(), print);
    std::cout << '\n';

    std::for_each(myVector.begin(), myVector.end(), [&myVector](int& i)
        {
            if (i % 2 != 0)
            {
                (i) *= 3;
            }
        });
    
    std::cout << "after:\t";
    std::for_each(myVector.cbegin(), myVector.cend(), print);
    std::cout << '\n';

    std::cout << "\n\nHello World!\n";
}