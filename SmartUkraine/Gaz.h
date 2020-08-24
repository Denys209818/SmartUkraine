#pragma once
#include "libs.h"
#include "User.h"

class Gaz : public User
{
public:
	Gaz(string name, string surname, int age, string login, string password, string status);
};
