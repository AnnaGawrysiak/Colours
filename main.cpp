#include <iostream>
#include "Colour.h"
#include "Test.h"

int main()
{
    Test* testowa = Test::get_instance();
    testowa->run();
    int choice = 0;

    while (choice != 3)
    {
        std::cout << "What would you like to do? Press 1 if you wish to convert a colour to RGB. Press 2 if you want to convert to HSV. Press 3 to quit. " << std::endl;
        std::cin >> choice;

        switch (choice)
        {
            case 1:
            {
                double hue = 0;
                double saturation = 0;
                double value = 0;

                std::cout << "Enter HSV values. " << std::endl;
                std::cout << "Hue: ";
                std::cin >> hue;
                std::cout << "Saturation: ";
                std::cin >> saturation;
                std::cout << "Value: ";
                std::cin >> value;
                std::cout << " ." << std::endl;

                Colour my_colour;
                my_colour.set_hsv_shade(hue, saturation, value);
                my_colour.Convert_to_RGB();

                std::cout << " RGB equivalent: " << std::endl;
                my_colour.print_rgb();
                break;
            }

            case 2:
            {
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

                std::cout << " HSV equivalent: " << std::endl;
                my_colour.print_hsv();
                break;
            }

            case 3:
            {
                return 0;
            }

        }
            
    }

    Colour my_colour;
    my_colour.set_hsv_shade(30.0, 63.56589147286821, 50.588235294117645);
    my_colour.Convert_to_RGB();

    std::cout << " RGB equivalent: " << std::endl;
    my_colour.print_rgb();

    return 0;
}

