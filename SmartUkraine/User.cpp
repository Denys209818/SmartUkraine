#include "libs.h"
#include "User.h"

User::User(string name, string surname, int age, string login, string password, string status)
{
	this->name = name;
	this->surname = surname;
	this->age = age;
	this->password = password;
	this->login = login;
	this->id_ = User::id;
	this->status = status;
}

int& User:: GetAge()
{
	return this->age; 
}

string& User:: GetName()
{
	return this->name; 
}

string& User::GetSurname()
{
	return this->surname; 
}

string& User::GetPassword()
{
	return this->password;
}

string& User::GetLogin()
{
	return this->login;
}

string& User::GetStatus()
{
	return this->status;
}

int User::GetId()
{
	return this->id_; 
}

void User::CheckList()
{
	char arr[10000];
	char title[255];
	char text[255];
	char status[255];
	char end[255];
	ifstream file("baza_forms.txt");
	
	while (!file.eof())
	{
		file.getline(arr, 10000);
		int k = 0;
		for (int i = 0; i < strlen(arr); i++)
		{
			if (arr[i] == '~')
			{
				k = i + 1;
				title[i] = '\0';
				break;
			}
			title[i] = arr[i];
		}

		int s = 0;
		for (int i = k; i < strlen(arr); i++)
		{
			if (arr[i] == '&')
			{
				k = i + 1;
				text[s] = '\0';
				break;
			}
			text[s] = arr[i];
			s++;
		}

		int l = 0;
		for (int i = k; i < strlen(arr); i++)
		{
			if (arr[i] == '_')
			{
				k = i + 1;
				status[l] = '\0';
				break;
			}
			status[l] = arr[i];
			l++;
		}
		l = 0;
		while (arr[k] != '\0')
		{
			end[l] = arr[k];
			k++;
			l++;
		}
		end[l] = '\0';
		string st = status;

		if (st == "active" || st == "process")
		{
		this->forms.push_back(new _Form(title, text, status, end));
		}
	}
	
	file.close();
	int counter = 0;
	int ch = 1, s = 0;
	int size = 0;
	while (true)
	{
		do
		{
		    size = 0;
			system("cls");
			int l = 3;
			for (int i = 0; i < this->forms.size(); i++) 
			{
				if (this->forms[i + s]->status == "active" || this->forms[i + s]->status == "process") 
				{
					size++;
				}
			}
			if (size - s < 3)
			{
				l = size - s;
			}
			SetPos(45, 0);
		
			SetConsoleOutputCP(1251);
			cout << "<<< Назад || Вперед >>>\n";
			SetConsoleOutputCP(866);
			
			for (int i = 0; i < l; i++)
			{
				if (this->forms[i + s]->status == "active" || this->forms[i + s]->status == "process")
				{
				if (this->forms[i + s]->status == "process") SetCol(14);

				for (int j = 0; j < 118; j++) cout << "#";
				cout << endl;
				SetCol(7);
				if (counter == i) SetCol(14);
				cout << this->forms[i + s]->title << endl << endl;
				cout << this->forms[i + s]->text << endl;
				SetCol(7);
				if (this->forms[i + s]->status == "process") SetCol(14);
				if (this->forms[i + s]->status == "closed") SetCol(12);
				for (int j = 0; j < 118; j++) cout << "#";
				cout << endl;
				SetCol(7);
				}


			}

			ch = _getch();

			switch (ch)
			{
			case 224:
			{
				switch (_getch())
				{
				case 80: counter < l - 1 ? counter++ : counter = 0; break;
				case 72: counter > 0 ? counter-- : counter = l - 1; break;
				case 75: { s > 0 ? s -= 3 : s = s; counter = 0; break; }
				case 77: { 3 + s < this->forms.size() ? s += 3 : s = s; counter = 0; break;	}
				}
			}
			}
		} while (ch != 13);


		if (size > 0) 
		{
		if (this->forms[counter + s]->status == "active")  this->forms[counter + s]->status = "process";
		else if (this->forms[counter + s]->status == "process") { this->forms[counter + s]->status = "closed"; counter--; }
		else if (this->forms[counter + s]->status == "closed") this->forms[counter + s]->status = "active";
		}

		ofstream file("baza_forms.txt", ios_base::trunc);

		for (int i = 0; i < size; i++)
		{
			if (this->forms[i]->status == "active" || this->forms[i]->status == "process") 
			{
			file << this->forms[i]->title << "~" << this->forms[i]->text << "&" << this->forms[i]->status << "_" << this->forms[i]->end;
			if(i + 1 != this->forms.size()) file << "\n";
			}
		}
		file.close();
	}

}