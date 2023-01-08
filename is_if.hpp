#pragma once

#include<string>

auto is_if(std::string& s) -> bool
{
	if (s[0] == 'i' && s[1] == 'f')
	{
		return true;
	}
	else
	{
		return false;
	}
}