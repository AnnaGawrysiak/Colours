#include "Test.h"
#include <iostream>
#include <vector>

Test::Test()
{
}

Test* Test::wsk = nullptr;

Test* Test::get_instance()
{
	if (!wsk)
		wsk = new Test();

	return wsk;
}

bool Test::Test1()
{
	Colour my_colour;
	my_colour.set_rgb_shade(129, 88, 47);
	my_colour.Convert_to_HSV();

	std::vector <double> expected_result;
	expected_result.push_back(30.0);
	expected_result.push_back(63.56589147286821);
	expected_result.push_back(50.588235294117645);

	std::vector <double> result = my_colour.get_hsv_shade();

	if (result == expected_result)
		return true;

	return false;
}

bool Test::Test2()
{
	Colour my_colour;
	my_colour.set_rgb_shade(31, 52, 29);
	my_colour.Convert_to_HSV();

	std::vector <double> expected_result;
	expected_result.push_back(114.78260869565217);
	expected_result.push_back(44.230769230769226);
	expected_result.push_back(20.392156862745097);

	std::vector <double> result = my_colour.get_hsv_shade();

	if (result == expected_result)
		return true;

	return false;
}

bool Test::Test3()
{
	Colour my_colour;
	my_colour.set_hsv_shade(30.0, 63.56589147286821, 50.588235294117645);
	my_colour.Convert_to_RGB();

	std::vector <double> expected_result;
	expected_result.push_back(129);
	expected_result.push_back(88);
	expected_result.push_back(47);

	std::vector <double> result = my_colour.get_rgb_shade();

	if (result == expected_result)
		return true;

	return false;
}

bool Test::Test4()
{
	Colour my_colour;
	my_colour.set_hsv_shade(114.78260869565217, 44.230769230769226, 20.392156862745097);
	my_colour.Convert_to_RGB();

	std::vector <double> expected_result;
	expected_result.push_back(31);
	expected_result.push_back(52);
	expected_result.push_back(29);

	std::vector <double> result = my_colour.get_rgb_shade();

	if (result == expected_result)
		return true;

	return false;
}


void Test::run()
{
	if (Test1())
		std::cout << "Test 1: Sukces! " << std::endl;
	else
		std::cout << "Test 1: Porazka " << std::endl;

	
	if (Test2())
		std::cout << "Test 2: Sukces! " << std::endl;
	else
		std::cout << "Test 2: Porazka " << std::endl;

	
	if (Test3())
		std::cout << "Test 3: Sukces! " << std::endl;
	else
		std::cout << "Test 3: Porazka " << std::endl;


	if (Test4())
		std::cout << "Test 4: Sukces! " << std::endl;
	else
		std::cout << "Test 4: Porazka " << std::endl;

}