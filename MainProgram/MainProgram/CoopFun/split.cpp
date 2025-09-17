﻿#include "header_coop_fun.h"

std::vector <std::string> splitString(const std::string& str, const std::string& del) {
	std::string str_in = str;
	std::vector<std::string> result;

	while (true) {
		auto pos = str_in.find(del);
		result.push_back(str_in.substr(0, pos));
		str_in = str_in.substr(pos + 1);
		if (pos == std::string::npos) {
			break;
		}
	}
	return result;
}