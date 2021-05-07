#include "Convert_to_HSV.h"
#include <vector>
#include <iostream>

HSV Colour_Converter::Convert_to_HSV(double red, double green, double blue)
{

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
	
	double max_rgb = red > green ? (red > blue ? red : blue) : (green > blue ? green : blue);
	double min_rgb = red < green ? (red < blue ? red : blue) : (green < blue ? green : blue);

	double difference = max_rgb - min_rgb;

	// Hue calculation
	// if cmax and cmin equal 0, then h = 0
	HSV hsv_shade;

	if (max_rgb == 0 && min_rgb == 0)
	{
		hsv_shade.hue = 0;
	}
	else if (max_rgb == red)
	{
		hsv_shade.hue = fmod(60 * ((green - blue) / difference) + 360, 360);
	}
	else if (max_rgb == green)
	{
		hsv_shade.hue = fmod(60 * ((blue - red) / difference) + 120, 360);
	}
	else if (max_rgb == blue)
	{
		hsv_shade.hue = fmod(60 * ((red - green) / difference) + 240, 360);
	}

	// Saturation computation :
	if (max_rgb == 0)
		hsv_shade.saturation = 0;
	else
		hsv_shade.saturation = (difference / max_rgb) * 100;

	// Value computation
	hsv_shade.value = max_rgb * 100;

	return hsv_shade;
}
