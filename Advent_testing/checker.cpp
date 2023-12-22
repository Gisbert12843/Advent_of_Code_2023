#include "checker.h"



int checker(std::string current_pump_status_string, std::string current_number_string, int current_collision_count) {


	//Wenn keine Zahlen übrig sind, haben wir das Ende der Möglichkeiten für diese Iteration erreicht. Wenn keine # vorhanden sind ist dies ein valider pfad sonst nicht.
	if (current_number_string.empty())
	{
		if (current_pump_status_string.find('#') == current_number_string.npos)
		{
			return 1;
		}
		else
			return 0;
	}
	else if (current_pump_status_string.empty())
	{
		if (current_number_string[0] - '0' == current_collision_count && current_number_string.size() == 1)
			return 1;
		return 0;
	}

	int possibilities = 0;

	////Check if current pattern and the corresponing numbers were already iterated and stored in the map 
	//if (pattern_map.contains(current_pump_status_string))
	//{
	//	if(std::get<0>(pattern_map[current_pump_status_string])==current_number_string)
	//		return std::get<1>(pattern_map[current_pump_status_string]);
	//}


	switch (current_pump_status_string[0])
	{
	case '.':
	{
		if (current_number_string[0] - '0' == current_collision_count)
		{
			possibilities += checker(current_pump_status_string.substr(1), current_number_string.substr(1), 0);
		}
		else possibilities += checker(current_pump_status_string.substr(1), current_number_string, 0);
	}
	break;
	case '#':
	{
		//collisions are still available
		if (current_number_string[0] - '0' > current_collision_count)
		{
			current_collision_count++;
			possibilities += checker(current_pump_status_string.substr(1), current_number_string, current_collision_count);
		}
		else
		{//no collisions available, invalid path
			return 0;
		}
	}
	break;

	case '?':
	{
		//as #
		std::string temp = current_pump_status_string;
		temp.at(0) = '#';
		possibilities += checker(temp, current_number_string, current_collision_count);

		//as .
		temp.at(0) = '.';
		possibilities += checker(temp, current_number_string, current_collision_count);
	}
	break;
	}
	return possibilities;
}