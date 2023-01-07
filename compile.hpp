#pragma once

#include<string> // std::string
#include<iostream> // std::cout

#include"parse.hpp" // parse

auto run(std::string s)
{
	std::vector<std::string> result = parse(s);
	for (auto i : result)
	{
		std::cout << i;
	}
}