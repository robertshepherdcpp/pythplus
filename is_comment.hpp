#pragma once

#include<string> // std::string

auto is_comment(std::string& s)
{
	if (s[0] == '#')
	{
		return true;
	}
	else
	{
		return false;
	}
}