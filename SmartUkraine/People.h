#pragma once
#include "libs.h"
#include "Petition.h"
#include "User.h"
class People : public User
{
	vector<Petition*> v;
public:
	People(string name, string surname, int age, string login, string password, string status);

	void ShowPetition();

	void SafeFile();

	void ReadPetitions();

	void MakePetition();

	People* GetPeople();

	void _AddForm();

	vector<Petition*> &GetV();

	void CheckList()override;

};
