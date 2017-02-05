#ifndef _PARAMETERS_HPP_
#define _PARAMETERS_HPP_

#include <string>

class Parameters
{

protected:

	Parameters() = default;

public:

	Parameters(const Parameters & _p) = delete;

	Parameters & operator= (const Parameters & _p) = delete;

	virtual bool check() = 0;

	virtual const std::string & getParameter() const = 0;

	virtual ~Parameters() = default;

};

#endif // _PARAMETERS_HPP_
