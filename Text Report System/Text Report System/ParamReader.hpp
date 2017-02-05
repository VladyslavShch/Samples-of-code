#ifndef _PARAMREADER_HPP_
#define _PARAMREADER_HPP_

#include "Reader.hpp"
#include <istream>

class ParamReader
	: public Reader
{
public:

	ParamReader(std::istream& _in, ParamMap & _pParamMap);

private:

	virtual void readFromFile() override;

	virtual void processData() override;

	virtual void cleanTempData() override;
	
	std::istream & m_in;

	ParamMap & m_pParamMap;

	std::unordered_map<std::string, std::string> m_stringMap;

};

#endif // _PARAMREADER_HPP_