#pragma once
#include "libs.h"
#include "User.h"
class Ambulance : public User
{
public:
	Ambulance(string name, string surname, int age, string login, string password, string status);
};
