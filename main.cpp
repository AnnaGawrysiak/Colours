#include <iostream>
#include "Colour.h"
#include "Test.h"

int main()
{
    Test* testowa = Test::get_instance();
    testowa->run();

    double red = 0;
    double green = 0;
    double blue = 0;
    
    std::cout << "Enter RGB values. " << std::endl;
    std::cout << "Red: ";
    std::cin >> red;
    std::cout << "Green: ";
    std::cin >> green;
    std::cout << "Blue: ";
    std::cin >> blue; 
    std::cout << " ." << std::endl;
    
    Colour my_colour;
    my_colour.set_rgb_shade(red, green, blue);
    my_colour.Convert_to_HSV();
    
    std::cout << " HSV equivalent: "<< std::endl;
    my_colour.print_hsv();

    return 0;
}

