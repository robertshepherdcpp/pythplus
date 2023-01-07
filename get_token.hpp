#pragma once

#include<string> // std::string

auto get_token(std::string& str)
{
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == ' ')
		{
			return str.substr(0, i);
		}
	}

	// there was nothing found, so just return str.

	return str;
}

auto get_token_index(std::string& str)
{
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == ' ')
		{
			return i;
		}
	}

	// there was nothing found, so just return str.size().

	return int(str.size());
}