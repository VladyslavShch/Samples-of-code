#ifndef _FUNCPARAMETER_HPP_
#define _FUNCPARAMETER_HPP_

#include "Parameters.hpp"


class FuncParameter
	: public Parameters
{

public:

	FuncParameter(std::string (*_func) ());

	virtual bool check() override;

	virtual const std::string & getParameter() const override;

private:

	const std::string m_text;

};

inline
const std::string & FuncParameter::getParameter() const
{
	return m_text;
}

inline
bool FuncParameter::check()
{
	return false;
}

#endif // _FUNCPARAMETER_HPP_