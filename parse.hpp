#pragma once

#include<string> // std::string
#include<vector> // std::vector

#include"is_var.hpp"
#include"find_index.hpp"
#include"is_comment.hpp"
#include"is_function_call.hpp"

auto parse(std::string& s) // takes line by line
    -> std::vector<std::string>
{
	std::vector<std::string> result{};
	if (is_var(s))
	{
		std::string name{};
		std::string value{};
		std::string type{"auto"};
		auto index_space = find_index<' '>(s);
		if (index_space != -1)
		{
			name = s.substr(0, index_space);
			// now we get the rest of the python variable
			value = s.substr(index_space + 2, s.size());
			if (value[1] == '"')
			{
				type = "std::string";
			}
			result.push_back((type + " " + name + " =" + value + ";"));
		}
		else
		{
			// element was not, found, but that is impossible, because `is_var` returned true.
		}
		return result;
	}
	if (is_comment(s))
	{
		result.push_back("//" + s.substr(1, s.size()));
		return result;
	}
	if (is_function_call(s))
	{
		// we have a function_call.
		auto index_of_open_bracket = find_index<'('>(s);
		std::string function_name = s.substr(0, index_of_open_bracket);
		if (function_name == "print")
		{
			// with c++23
			function_name = "std::print";
		}
		auto index_of_close_bracket = find_index<')'>(s);
		std::string function_parameters = s.substr(index_of_open_bracket, index_of_close_bracket);
		result.push_back(function_name + function_parameters + ";");
		return result;
	}
}