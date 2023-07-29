#include <iostream>

double askTowerHeight()
{
    std::cout << "Enter the height of the tower in meters: ";
    double height{};
    std::cin >> height;
    return height;
}

double distanceFallen(int seconds)
{
    constexpr double gravity_constant{9.8};
    return (gravity_constant * seconds * seconds) / 2.0;
}

void announceBallHeight(int initialHeight, int seconds)
{
    const double fallMeters{distanceFallen(seconds)};
    const double heightLeft = initialHeight - fallMeters;
    if (heightLeft > 0.0)
        std::cout << "At " << seconds << " seconds, the ball is at height: " << heightLeft << '\n';
    else
        std::cout << "At " << seconds << " seconds, the ball is on the ground." << '\n';
}

void announceBallDrop(int height)
{
    announceBallHeight(height, 0);
    announceBallHeight(height, 1);
    announceBallHeight(height, 2);
    announceBallHeight(height, 3);
    announceBallHeight(height, 4);
    announceBallHeight(height, 5);
}

int main()
{
    const double towerHeight{askTowerHeight()};
    announceBallDrop(towerHeight);

    return 0;
}
