#pragma once

#include<string>

auto is_end_of_for_loop(std::string& s)
{
	if (s == "# END_OF_FOR_LOOP")
	{
		return true;
	}
}