#pragma once

#include<string> // std::string

#include"get_token.hpp"
#include"find_index.hpp"

auto is_input(std::string& s)
{
	if (s[get_token_index(s) + 1] == '=')
	{
		// we have an equals sign, it is a good start.
		if (find_index<'('>(s) != -1)
		{
			// there is a function call somewhere.
			if (s.substr(get_token_index(s) + 3, find_index<'('>(s)) == "input")
			{
				// we will return true.
				return true;
			}
		}
	}
	return false;
}