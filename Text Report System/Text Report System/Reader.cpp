#include "Reader.hpp"

void Reader::read()
{
	readFromFile();
	processData();
	cleanTempData();
}
