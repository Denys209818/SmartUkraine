#pragma once
#include "libs.h"
#include "User.h"
#include "People.h"
#include "Police.h"
#include "Ambulance.h"
#include "Firemen.h"
#include "Gaz.h"

class System
{
	map<int, User*> m;
    
public:
	void Start();

	void Show();

	void End();

	void AddUser(User* u);

	int GetSize();

	User* operator [] (int a);
};
