#pragma once
#include <vector>
#include <iostream>

class HSV
{
public:
	double hue;
	double saturation;
	double value;
public:
	HSV();
	HSV(double hue_, double saturation_, double value_);
	friend std::ostream& operator<<(std::ostream& os, const HSV& shade);
	bool operator==(const HSV& rhs);
};