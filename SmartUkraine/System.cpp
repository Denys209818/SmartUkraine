#include "libs.h"
#include "System.h"

void System::Start()
{
	ifstream file("baza.bin");
	char arr[255];
	while (!file.eof())
	{
		file.getline(arr, 255);
		char name[255];
		strcpy_s(name, strlen(arr) + 1, arr);

		int k = 0;
		for (int i = 0; i < strlen(arr) + 1; i++)
		{
			if (name[i] == '.')
			{
				name[i] = '\0';
				k = i;
				break;
			}
		}
		char surname[255];
		int l = 0;
		for (int i = k + 1; i < strlen(arr) + 1; i++)
		{
			if (arr[i] == ',')
			{
				k = i;
				surname[l] = '\0';
				break;
			}
			surname[l] = arr[i];
			l++;
		}

		char age[255];

		l = 0;
		for (int i = 0; i < strlen(arr) + 1; i++)
		{
			if (arr[i] == ',')
			{
				int u = i + 1;
				while (arr[u] != '~')
				{
					age[l] = arr[u];
					u++;
					l++;
				}
				age[l] = '\0';
				break;
			}
		}
		int age_ = atoi(age);
		char password[255];
		l = 0;
		for (int i = 0; i < strlen(arr) + 1; i++)
		{
			if (arr[i] == '~')
			{
				int p = i + 1;
				while (arr[p] != '&')
				{
					password[l] = arr[p];
					p++;
					l++;
				}
				password[l] = '\0';
				break;
			}
		}
		l = 0;
		char login[255];
		for (int i = 0; i < strlen(arr) + 1; i++)
		{
			if (arr[i] == '&')
			{
				int u = i + 1;
				while (arr[u] != '^')
				{
					login[l] = arr[u];
					u++;
					l++;
				}
				login[l] = '\0';
				break;
			}
		}
		l = 0;
		char status[255];

		for (int i = 0; i < strlen(arr) + 1; i++)
		{
			if (arr[i] == '^')
			{
				int u = i + 1;
				while (arr[u] != '\0')
				{
					status[l] = arr[u];
					u++;
					l++;
				}
				status[l] = '\0';
				break;
			}
		}

		if (status[0] == 'p') {  m.emplace(User::id++, new People(name, surname, age_, login, password, "p")); }//Людина
		else if (status[0] == 'r') m.emplace(User::id++, new Police(name, surname, age_, login, password, "r"));// Поліція
		else if (status[0] == 'l') m.emplace(User::id++, new Ambulance(name, surname, age_, login, password, "l"));// Лікар
		else if (status[0] == 'k') m.emplace(User::id++, new Firemen(name, surname, age_, login, password, "k"));// Пожежник
		else if (status[0] == 'g') m.emplace(User::id++, new Gaz(name, surname, age_, login, password, "g"));// Газовик
	}

	file.close();
}

void System::Show()
{
	for (int i = 0; i < m.size(); i++)
	{
		cout << m[i]->GetAge() << endl;
		cout << m[i]->GetName() << endl;
		cout << m[i]->GetSurname() << endl;
		cout << m[i]->GetPassword() << endl;
		cout << m[i]->GetLogin() << endl;
	}
}

void System::End()
{
	ofstream file("baza.bin", ios_base::trunc);
	for (int i = 0; i < m.size(); i++)
	{
		if (i + 1 == m.size()) { file << m[i]->GetName() << "." << m[i]->GetSurname() << "," << m[i]->GetAge() << "~" << m[i]->GetPassword() << "&" << m[i]->GetLogin() << "^" << m[i]->GetStatus(); }
		else { file << m[i]->GetName() << "." << m[i]->GetSurname() << "," << m[i]->GetAge() << "~" << m[i]->GetPassword() << "&" << m[i]->GetLogin() << "^" << m[i]->GetStatus() << "\n"; }
	}

	file.close();
}

void System::AddUser(User* u)
{
	this->m.emplace(User::id++, u);
}

int System::GetSize() 
{
	return this->m.size();
}

User* System::operator [] (int a)
{
	return this->m[a];
}