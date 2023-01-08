#pragma once

#include<string> // std::string
#include<vector> // std::vector

#include"is_var.hpp"
#include"find_index.hpp"
#include"is_comment.hpp"
#include"is_function_call.hpp"
#include"is_list.hpp"
#include"is_input.hpp"
#include"is_if.hpp"
#include"is_func.hpp"

auto parse(std::string& s) // takes line by line
    -> std::vector<std::string>
{
	std::vector<std::string> result{};
	if (is_input(s))
	{
		// notice ]need to parse before `is_var`.
		// first of all, lets get the variable name:
		std::string name = s.substr(0, get_token_index(s));
		std::string parameters = s.substr(get_token_index(s) + 9, s.size() - 1);
		result.push_back("std::cout " + parameters + ";\n");
		result.push_back("std::any " + name + " = 0;\n");
		result.push_back("std::cin >> name;\n");
		return result;
	}
	if (is_if(s))
	{
		// we have got an if that looks like this:
		// if(condition):
		// ...
		// elif(condition):
		// ...
		// else:
		// ...

		// first just the easy bit:
		result.push_back("if(" + s.substr(4, s.size() - 2) + "{\n");

		return result;
	}
	if (is_func(s))
	{
		std::string func_name{s.substr(3, find_index<'('>(s) - 3)};
		// check if it is a function taking no arguements.
		if (s[find_index<'('>(s) + 1] == ')')
		{
			// A function taking no arguaments.
			result.push_back("auto" + func_name + "() {");
			return result;
		}
	}
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
	if (is_list(s))
	{
		// we have a list so we need to use std::vector.
		std::string type = "std::vector";
		std::string name = get_token(s);
		if ((s[get_token_index(s) + 3] == '[') && (s[get_token_index(s) + 4] == ']'))
		{
			// we just have a default initialized list, so lets do that:
			result.push_back(type + " " + name + "{};");
			return result;
		}
		else
		{
			// otherwise we have an initialized list.
			std::string initializers{};
		}
	}
}