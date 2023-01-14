#pragma once

#include<string> // std::string

#include"find_index.hpp"
#include"get_token.hpp"

// At the end of the for loop it will have to have # END_OF_FOR_LOOP
auto is_for_loop(std::string& s)
{
	if (find_index<' '>(s) != -1)
	{
		// there is white space, from 0 to ' ' must be the keyword `for`
		if (find_index<' '>(s) > 2 && s.substr(0, find_index<' '>(s)) == "for")
		{
			// yes we have a for loop, we think. now we check if the next bit is in:
			if (s.size() > 5 && (s.substr(find_index<' '>(s), find_index<' '>(s) + 2) == "in" || get_token_amount(s, 3) == "in" || true))
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		return false;
	}
}