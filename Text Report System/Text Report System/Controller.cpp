#include "Controller.hpp"
#include "ParamReader.hpp"
#include "TemplateReader.hpp"
#include "FuncParameter.hpp"

Controller::Controller(const std::string & _iniFile, const std::string & _templateFile)
{
	m_iniStream.open(_iniFile);
	m_templateStream.open(_templateFile);
	m_iniReader = std::make_unique<ParamReader>(m_iniStream, m_paramMap);
	m_templateReader = std::make_unique<TemplateReader>(m_templateStream, m_report, m_paramMap);
	m_logStream.open("report.log");
}

void Controller::readParams()
{
	m_iniReader->read();
}

void Controller::readTemplate()
{
	m_templateReader->read();
}

void Controller::createLog(const std::string & _log)
{
	m_logStream << _log << std::endl;
}

void Controller::createReport()
{
	try
	{
		readParams();
		readTemplate();
	}
	catch (const std::exception& _e)
	{
		std::string log = _e.what();
		createLog(log);
		return;
	}

	std::ofstream out;

	out.open("report.txt");

	out << m_report;

	out.close();

	createLog("Report was created successfully!");

}

void Controller::addFuncParameter(const std::string & _paramName, std::string (*_func)())
{
	if (!m_paramMap.count(_paramName))
	{
		m_paramMap[_paramName] = std::move(std::make_unique<FuncParameter>(_func));
	}
	else
	{
		createLog("You try to rewrite functional parameter!");
	}
}

Controller::~Controller()
{
	m_iniStream.close();
	m_templateStream.close();
	m_logStream.close();
}
