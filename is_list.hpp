#pragma once

#include"get_token.hpp"

#include<string> // std::string

auto is_list(std::string& s)
{
	if (get_token_index(s) != -1)
	{
		// there is a space, so that is the name.
		if (s[get_token_index(s) + 1] == '=')
		{
			if (s[get_token_index(s) + 3] == '[')
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}