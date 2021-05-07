#include "HSV.h"
#include <iostream>
#include <vector>

HSV::HSV()
{
	hue = -1;
	saturation = -1;
	value = -1;
}

HSV::HSV(double hue_, double saturation_, double value_)
{
	hue = hue_;
	saturation = saturation_;
	value = value_;
}

std::ostream& operator<<(std::ostream& os, const HSV& shade)
{
	os << " hue: " << shade.hue << ", saturation: " << shade.saturation << ", value: " << shade.value << std::endl;
	return os;
}

bool HSV::operator==(const HSV& rhs)
{
	if (hue == rhs.hue && saturation == rhs.saturation && value == rhs.value) 
		return true;

	return false;
}