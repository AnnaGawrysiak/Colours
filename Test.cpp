#include "Test.h"
#include <iostream>
#include <vector>
#include "Convert_to_RGB.h"
#include "Convert_to_HSV.h"
#include "RGB.h"
#include "HSV.h"

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
	HSV result = Colour_Converter::Convert_to_HSV(129, 88, 47);
	HSV expected_result(30.0, 63.56589147286821, 50.588235294117645);

	if (result == expected_result)
		return true;

	return false;
}

bool Test::Test2()
{
	HSV result = Colour_Converter::Convert_to_HSV(31, 52, 29);
	HSV expected_result(114.78260869565217, 44.230769230769226, 20.392156862745097);

	if (result == expected_result)
		return true;

	return false;
}

bool Test::Test3()
{
	RGB result = Colour_Converter::Convert_to_RGB(30.0, 63.56589147286821, 50.588235294117645);
	RGB expected_result(129, 88, 47);

	if (result == expected_result)
		return true;

	return false;
}

bool Test::Test4()
{
	RGB result = Colour_Converter::Convert_to_RGB(114.78260869565217, 44.230769230769226, 20.392156862745097);
	RGB expected_result(31, 52, 29);

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