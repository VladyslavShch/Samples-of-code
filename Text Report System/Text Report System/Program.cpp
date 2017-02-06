#include "Controller.hpp"
#include <string>
#include <iostream>
#include <sstream>
#include <ctime>

std::string date()
{

	std::ostringstream ost;

	time_t currentTime = time(nullptr);

	tm currentTM;
	gmtime_s(&currentTM ,&currentTime);

	ost << currentTM.tm_mday
		<< "." << currentTM.tm_mon + 1 
		<< "." << currentTM.tm_year + 1900;

	return ost.str();

}

void main(int argc, char* argv[])
{

	try
	{

		if (!(argc == 3 || argc == 1))
			throw std::logic_error("It should be three arguments in command line:\n [name_of_program] [ini_file] [template_of_report]");

		Controller c( argv[1], argv[2] );

		c.addFuncParameter("current_date", date);

		c.createReport();

	}
	catch (std::exception& _e)
	{
		std::cout << _e.what() << std::endl;
	}
	catch (...)
	{
		std::cout << "Unknown exeption." << std::endl;
	}
	
}