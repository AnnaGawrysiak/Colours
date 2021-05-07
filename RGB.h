#pragma once
#include <vector>
#include <iostream>

class RGB
{
public:
	double red;
	double green;
	double blue;
public:
	RGB();
	RGB(double red_, double green_, double blue_);
	friend std::ostream& operator <<(std::ostream& sream, const RGB& shade);
	bool operator==(const RGB& rhs);
};

