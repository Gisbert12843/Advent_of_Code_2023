#pragma once
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <utility>


inline std::unordered_map<std::string, std::tuple<std::string, int>> pattern_map = {};

int checker(std::string current_pump_status_string, std::string current_number_string, int current_collision_count = 0);