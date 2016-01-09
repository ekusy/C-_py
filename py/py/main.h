#pragma once
#include <Python.h>
#include <Windows.h>
#include <string>

#include <vector>
template <typename List>
void split(const std::string& s, const std::string& delim, List& result);

class main
{
public:
	main();
	~main();
};

