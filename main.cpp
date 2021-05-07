#include <iostream>
#include "Test.h"
#include "Convert_to_RGB.h"
#include "Convert_to_HSV.h"
#include "RGB.h"
#include "HSV.h"

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

                RGB rgb_shade = Colour_Converter::Convert_to_RGB(hue, saturation, value);

                std::cout << " RGB equivalent: " << rgb_shade << std::endl;
            
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

                HSV my_hsv = Colour_Converter::Convert_to_HSV(red, green, blue);

                std::cout << " HSV equivalent: " << my_hsv << std::endl;
                
                break;
            }

            case 3:
            {
                return 0;
            }

        }
            
    }


    return 0;
}

