#pragma once
#include "libs.h"
#include "User.h"
class Police : public User
{
public:
	Police(string name, string surname, int age, string login, string password, string status);
};