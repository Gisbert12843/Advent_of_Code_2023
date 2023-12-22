#include "checker.h"


int main()
{
	std::vector<std::tuple<std::string, std::string>> input_vector = {};
	std::string current = "";

	int line = 0;
	while (std::getline(std::cin, current))
	{
		if (current.empty())
			break;

		int mode = 0;
		std::string first = "", second = "";

		for (auto it : current)
		{
			if (it == ' ')
			{
				mode = 1;
				continue;
			}
			else if (it == ',')
				continue;

			if (mode == 0)
			{
				first.push_back(it);
			}
			else
				second.push_back(it);
		}
		input_vector.push_back(std::make_tuple(first, second));
		line++;
	}


	int sum = 0;

	for (auto it : input_vector)
	{
		std::string first = std::get<0>(it), second = std::get<1>(it);
		sum += checker(first, second);
	}
	std::cout << sum;
}

