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
			if (s[i + 3] == '[')
			{
				// reason that we are doing this is because, if we have a list, we want to handle it seperatly.
				return false;
			}
			else
			{
				return true;
			}
		}
		else
		{
			return false;
		}
	}
	return false;
}