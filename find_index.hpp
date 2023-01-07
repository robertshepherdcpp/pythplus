#pragma once

template<char c>
auto find_index(std::string& s)
{
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == c)
		{
			// we return i.
			return i;
		}
	}
	// we haven't found it, retrun -1
	return -1;
}