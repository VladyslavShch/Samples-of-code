#include "TemplateReader.hpp"
#include "Parameters.hpp"
#include <string>

TemplateReader::TemplateReader(std::istream & _in, std::string & _report, ParamMap & _paramMap)
	: m_in(_in)
	, m_report(_report)
	, m_paramMap(_paramMap)
{
}

void TemplateReader::readFromFile()
{

	std::string tmp;
	
	while (m_in.good() && !m_in.eof())
	{
		std::getline(m_in, tmp);

		m_report.append((!m_report.empty()) ? "\n" + tmp : tmp);

	}
}

void TemplateReader::processData()
{

	std::string tmp;
	size_t i1, i2;

	while ( ( i1 = m_report.find('{') ) != std::string::npos)
	{

		i2 = m_report.find('}');

		if (
			i2 == std::string::npos
			|| i2 <= i1
			)
			throw std::logic_error("Bad template file!");
		else
		{
			i2 -= (i1 + 1);
		}

		tmp = m_report.substr(i1 + 1, i2);

		i2 = m_report.find('}') - i1 + 1;

		if (tmp.front() == '*')
		{
			tmp.erase(tmp.begin());
			if (!m_paramMap.count(tmp))
				throw std::logic_error("There are no such parameter in list!");
			m_report.replace(i1, i2, m_paramMap.at(tmp)->getParameter());
		}
		else
		{
			if (m_paramMap.count(tmp))
				m_report.replace(i1, i2, m_paramMap.at(tmp)->getParameter());
			else
				m_report.replace(i1, i2, "");
		}

	}
}

void TemplateReader::cleanTempData()
{
	return;
}
