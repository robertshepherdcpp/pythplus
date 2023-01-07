#pragma once

#include<string> // std::string

#include"find_index.hpp"

auto is_function_call(std::string& s)
{
	auto index_of_open_bracket = find_index<'('>(s);
	if (index_of_open_bracket != -1)
	{
		auto index_of_close_bracket = find_index<')'>(s);
		if (index_of_close_bracket != -1)
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
		// there is not bracket, so we have to return false.
		return false;
	}
}