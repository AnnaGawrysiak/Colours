#include "Colour.h"
#include <vector>
#include <iostream>
#include <algorithm> 

Colour::Colour()
{
	rgb_shade.reserve(3);
	hsv_shade.reserve(3);
}

void Colour::set_hsv_shade(double hue, double saturation, double value)
{
	if (hsv_shade.empty())
	{
		hsv_shade.push_back(hue);
		hsv_shade.push_back(saturation);
		hsv_shade.push_back(value);

	}
	else
	{
		hsv_shade.clear();
		hsv_shade.push_back(hue);
		hsv_shade.push_back(saturation);
		hsv_shade.push_back(value);
	}
	
}

void Colour::set_rgb_shade(double red, double green, double blue)
{
	if (rgb_shade.empty())
	{
		rgb_shade.push_back(red);
		rgb_shade.push_back(green);
		rgb_shade.push_back(blue);
	}
	else
	{
		rgb_shade.clear();
		rgb_shade.push_back(red);
		rgb_shade.push_back(green);
		rgb_shade.push_back(blue);
	}
}

std::vector<double> Colour::get_rgb_shade()
{
	return rgb_shade;
}
std::vector<double> Colour::get_hsv_shade()
{
	return hsv_shade;
}

void Colour::Convert_to_HSV()
{
	double red = rgb_shade.at(0);
	double green = rgb_shade.at(1);
	double blue = rgb_shade.at(2);

	double hue = -1; 
	double saturation = -1;
	double value = -1;

	/*
	The RGB model makes use of the fact that when we mix these three primary colors, we will be able to 
	achieve other colors. For that purpose, we represent these primary colors alone in three values 
	(red, green, blue) respectively. Based on this combination, we can define other colors by bringing 
	about the mix of the specified values. These individual values can range from 0, 255. 
	*/
	// R, G, B values are divided by 255 to change the range from 0..255 to 0..1
	red = red / 255.0;
	green = green / 255.0;
	blue = blue / 255.0;
	
	double max_rgb = std::max(red, std::max(green, blue));
	double min_rgb = std::min(red, std::min(green, blue));

	double difference = max_rgb - min_rgb;

	// Hue calculation
	// if cmax and cmin equal 0, then h = 0
	if (max_rgb == 0 && min_rgb == 0)
	{
		hue = 0;
	}
	else if (max_rgb == red)
	{
		hue = fmod(60 * ((green - blue) / difference) + 360, 360);
	}
	else if (max_rgb == green)
	{
		hue = fmod(60 * ((blue - red) / difference)+120, 360);
	}
	else if (max_rgb == blue)
	{
		hue = fmod(60 * ((red - green) / difference)+240, 360);
	}

	// Saturation computation :
	if (max_rgb == 0)
		saturation = 0;
	else
		saturation = (difference / max_rgb)*100;
	
	// Value computation
	value = max_rgb*100;

	set_hsv_shade(hue, saturation, value);
}

void Colour::print_hsv()
{
	std::cout << "Hue: " << hsv_shade.at(0) << ", saturation: " << hsv_shade.at(1) << ", value: " << hsv_shade.at(2) << std::endl;
	
}