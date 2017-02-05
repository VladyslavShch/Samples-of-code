#ifndef _CONTROLLER_HPP_
#define _CONTROLLER_HPP_

#include <string>
#include <fstream>
#include <memory>
#include <unordered_map>
#include <iostream>

class Reader;
class Parameters;

class Controller
{
public:

	Controller(const std::string & _iniFile, const std::string & _templateFile);

	void readParams();

	void readTemplate();

	void createLog(const std::string & _log);
	
	void createReport();

	void addFuncParameter(const std::string & _paramName, std::string (*_func) ());

	~Controller();

private:

	std::unordered_map < std::string, std::unique_ptr < Parameters > > m_paramMap;

	std::unique_ptr<Reader> m_iniReader;
	
	std::unique_ptr<Reader> m_templateReader;

	std::ifstream m_iniStream;

	std::ifstream m_templateStream;

	std::ofstream m_logStream;

	std::string m_report;

};

#endif // _CONTROLLER_HPP_