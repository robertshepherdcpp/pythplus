#pragma once

#include<string> // std::string

#include"find_index.hpp"

auto is_func(std::string& s) -> bool
{
	if (find_index<' '>(s) != -1)
	{
		if (s.substr(0, find_index<' '>(s)) == "def")
		{
			// yes, it is a function.
			return true;
		}
	}
	return false;
}