#pragma once
#include "libs.h"
#include "_Form.h"

class User
{
private:
	vector<_Form*> forms;
protected:
	int id_;
	string name;
	string surname;
	int age;
	string password;
	string login;
	string status;
public:
	static int id;
	static bool valid;
	User(string name, string surname, int age, string login, string password, string status);

	int& GetAge();

	string& GetName();

	string& GetSurname();

	string& GetPassword();

	string& GetLogin();

	string& GetStatus();

	int GetId();

	virtual void CheckList();

};