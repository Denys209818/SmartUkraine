#pragma once
#include "libs.h"
#include "User.h"

class Firemen : public User
{
public:
	Firemen(string name, string surname, int age, string login, string password, string status);
};