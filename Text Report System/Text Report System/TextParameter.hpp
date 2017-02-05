#ifndef _TEXTPARAMETER_HPP_
#define _TEXTPARAMETER_HPP_

#include "Parameters.hpp"

class TextParameter
	: public Parameters
{

public:

	TextParameter(std::string & _text);

	virtual bool check() override;

	virtual const std::string & getParameter() const override;

private:

	const std::string m_text;

};

inline
const std::string & TextParameter::getParameter() const
{
	return m_text;
}

inline
bool TextParameter::check()
{
	return true;
}

#endif // _TEXTPARAMETER_HPP_
