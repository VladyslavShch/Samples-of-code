#include "ParamReader.hpp"
#include "TextParameter.hpp"

ParamReader::ParamReader(std::istream & _in, ParamMap& _pParamMap)
	: m_in(_in)
	, m_pParamMap(_pParamMap)
{
}

void ParamReader::readFromFile()
{
	while (m_in.good() && !m_in.eof())
	{

		std::string tmp, param, value;

		std::getline(m_in, tmp);

		size_t i = tmp.find('=');

		if (
			i != std::string::npos 
			&& i > 0 
			&& i < tmp.size() - 1
			)
		{
			m_stringMap[tmp.substr(0, i)] = tmp.substr(i + 1, tmp.length());
		}
		else
			throw std::logic_error("Bad string in ini-file!");
		
	}

}

void ParamReader::processData()
{
	for (auto _it : m_stringMap)
	{
		if (!m_pParamMap.count(_it.first))
		{
			m_pParamMap[_it.first] = std::move(std::make_unique<TextParameter>(_it.second));
		}
		else if (!m_pParamMap.at(_it.first)->check())
		{
			throw std::logic_error("Functional parameter in ini-file!");
		}
	}
}

void ParamReader::cleanTempData()
{
	m_stringMap.clear();
}
