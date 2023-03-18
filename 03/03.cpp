// 03.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <math.h>
#include <functional>
#include <vector>
#include <algorithm>

constexpr const double PI = 3.141592653589793;

void FooSin(int angle)
{
    std::cout << " sin: " << sin((angle * PI) / 180.0) << '\t';
};

void FooCos(int angle)
{
    std::cout << " cos: " << cos((angle * PI) / 180.0) << '\t';
};

void FooTan(int angle)
{
    std::cout << "tan: " << tan((angle * PI) / 180.0) << '\t';
};

int main()
{
    setlocale(LC_ALL, "ru");  
    std::srand(std::time(nullptr));

    std::vector<int> vectorOfAngles{ 0, 30, 60, 90/*, 120, 150, 180, 210, 240, 270, 300, 330, 360*/ };

    std::cout << "vectorOfAngles: ";
    std::for_each(vectorOfAngles.begin(), vectorOfAngles.end(), [&vectorOfAngles](const int& n) { std::cout << n << '\t'; });

    int angleInDegrees = vectorOfAngles[std::rand() % vectorOfAngles.size()];

    std::cout << std::endl << "========================================" << std::endl;

    std::vector<std::function<void(int)>> vectorOfFoo;

    vectorOfFoo.push_back(FooSin);
    vectorOfFoo.push_back(FooCos);
    vectorOfFoo.push_back(FooTan);

    for (const auto& angle : vectorOfAngles)
    {
        std::cout << angle << ":\t";
        for (const auto& function : vectorOfFoo)
            function(angle);
        std::cout << std::endl;
    };
    
    std::cout << "\n\nHello World!\n";
}