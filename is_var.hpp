#pragma once

#include<string> // std::string

#include"get_token.hpp"

auto is_var(std::string& s)
{
	int i = get_token_index(s);
	// so if the next token is '=', we have a variable
	if (i < s.size())
	{
		if (s[i + 1] == '=')
		{
			// we have a variable.
			return true;
		}
		else
		{
			return false;
		}
	}
	return false;
}