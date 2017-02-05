#ifndef _TEMPLATEREADER_HPP_
#define _TEMPLATEREADER_HPP_

#include "Reader.hpp"
#include <istream>
#include <memory>

class TemplateReader
	: public Reader
{
public:

	TemplateReader(std::istream & _in, std::string & _report, ParamMap & _paramMap);

private:

	virtual void readFromFile() override;

	virtual void processData() override;

	virtual void cleanTempData() override;

	std::istream & m_in;

	std::string & m_report;

	ParamMap & m_paramMap;

};

#endif // _TEMPLATEREADER_HPP_