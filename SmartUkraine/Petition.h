#pragma once
#include "libs.h"

class Petition
{
public:
	vector<int> numbers;
	string title;
	string text;

	Petition(string title, string text, vector<int> v);
};
