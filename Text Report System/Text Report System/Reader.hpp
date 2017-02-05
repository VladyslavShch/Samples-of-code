#ifndef _READER_HPP_
#define _READER_HPP_

#include <memory>
#include <unordered_map>

#include "Parameters.hpp"

class Reader
{
public:

	typedef std::unordered_map<std::string, std::unique_ptr < Parameters > > ParamMap;

	void read();

	virtual ~Reader() = default;

protected:

	Reader() = default;

private:

	virtual void readFromFile() = 0;

	virtual void processData() = 0;

	virtual void cleanTempData() = 0;


};

#endif // _READER_HPP_
