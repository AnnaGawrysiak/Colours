#pragma once
#include <vector>

class Colour
{
private:
    std::vector<double> rgb_shade;
    std::vector<double> hsv_shade;
public:
    Colour();
    void set_hsv_shade(double hue, double saturation, double value);
    void set_rgb_shade(double red, double green, double blue);
    std::vector<double> get_rgb_shade();
    std::vector<double> get_hsv_shade();
    void Convert_to_HSV();
    void print_hsv();
};

