#include "FuncParameter.hpp"

FuncParameter::FuncParameter(std::string (*_func)())
	: m_text(_func())
{
}
