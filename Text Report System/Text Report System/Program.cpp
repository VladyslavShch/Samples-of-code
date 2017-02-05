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
			throw std::logic_error("It should be name of programm and two (or no one) arguments in command line!");

		Controller c(
			  (argc == 3) ? argv[1] : "params.ini" 
			, (argc == 3) ? argv[2] : "report_template.txt"
		);

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