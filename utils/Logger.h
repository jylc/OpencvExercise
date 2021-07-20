#pragma once
#ifndef LOG_H_
#define LOG_H_

#include <iostream>
#include <string>

class Logger
{
public:
	static void logger(const std::string& info)
	{
#ifdef OUTPUT_LOG_
		std::cout << "log: " << info;
#endif
	}

	static void logger(const char* info)
	{
		std::string str(info);
		logger(str);
	}
};


#endif // !LOG_H_
