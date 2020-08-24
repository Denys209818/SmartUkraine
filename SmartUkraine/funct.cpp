#include "libs.h"
#include "User.h"
#include "Petition.h"
#include "People.h"
#include"Police.h"
#include "Ambulance.h"
#include "Gaz.h"
#include "Firemen.h"
#include "System.h"
void SetPos(int x, int y)
{
	COORD cPos;
	cPos.X = x;
	cPos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cPos);
}

void SetCol(int a)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), a);
}

int Autefication()
{
	SetConsoleOutputCP(1251);
	int ch = 1;
	int counter = 1;

	SetPos(0, 0);
	cout << "@@@@@@@@@@@@@@@@" << endl;
	SetPos(0, 1);
	cout << "@@@@@@@@@@@@" << endl;
	SetPos(0, 2);
	cout << "@@@@@@@@@@" << endl;
	SetPos(0, 3);
	cout << "@@@@@@@@" << endl;
	SetPos(0, 4);
	cout << "@@@@@" << endl;
	SetPos(0, 5);
	cout << "@@@" << endl;
	SetPos(0, 6);
	cout << "@" << endl;

	SetPos(0, 20);
	cout << "@" << endl;
	SetPos(0, 21);
	cout << "@@@@@" << endl;
	SetPos(0, 22);
	cout << "@@@@@@@@" << endl;
	SetPos(0, 23);
	cout << "@@@@@@@@@@" << endl;
	SetPos(0, 24);
	cout << "@@@@@@@@@@@@" << endl;
	SetPos(0, 25);
	cout << "@@@@@@@@@@@@@@@" << endl;
	SetPos(0, 26);
	cout << "@@@@@@@@@@@@@@@@@@" << endl;

	SetPos(100, 0);
	cout << "  @@@@@@@@@@@@@@@@" << endl;
	SetPos(100, 1);
	cout << "     @@@@@@@@@@@@@" << endl;
	SetPos(100, 2);
	cout << "        @@@@@@@@@@" << endl;
	SetPos(100, 3);
	cout << "          @@@@@@@@" << endl;
	SetPos(100, 4);
	cout << "            @@@@@@" << endl;
	SetPos(100, 5);
	cout << "               @@@" << endl;
	SetPos(100, 6);
	cout << "                 @" << endl;
	

	SetPos(98, 20);
	cout << "                   @" << endl;
	SetPos(98, 21);
	cout << "              @@@@@@" << endl;
	SetPos(98, 22);
	cout << "           @@@@@@@@@" << endl;
	SetPos(98, 23);
	cout << "         @@@@@@@@@@@" << endl;
	SetPos(98, 24);
	cout << "       @@@@@@@@@@@@@" << endl;
	SetPos(98, 25);
	cout << "   @@@@@@@@@@@@@@@@@" << endl;
	SetPos(98, 26);
	cout << "@@@@@@@@@@@@@@@@@@@@" << endl;

	SetCol(12);
	SetPos(50, 0);
	cout << " _______________" << endl;
	SetPos(50, 1);
	cout << "/ АВТОРИЗОВАННЯ \\" << endl;
	cout << endl;
	SetCol(7);

	while (ch != 13)
	{
		Sleep(20);
		if (counter == 1) SetCol(5);
		SetPos(40, 3);
		cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
		SetPos(40, 4);
		cout << "@ Вiйти як громадянин               @" << endl;
		SetPos(40, 5);
		cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n" << endl;
		SetCol(7);

		if (counter == 2) SetCol(5);
		SetPos(40, 7);
		cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
		SetPos(40, 8);
		cout << "@ Вiйти як полiцейський             @" << endl;
		SetPos(40, 9);
		cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n" << endl;
		SetCol(7);

		if (counter == 3) SetCol(5);
		SetPos(40, 11);
		cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
		SetPos(40, 12);
		cout << "@ Вiйти як лiкар                    @" << endl;
		SetPos(40, 13);
		cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n" << endl;
		SetCol(7);

		if (counter == 4) SetCol(5);
		SetPos(40, 15);
		cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
		SetPos(40, 16);
		cout << "@ Вiйти як пожежник                 @" << endl;
		SetPos(40, 17);
		cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n" << endl;
		SetCol(7);

		if (counter == 5) SetCol(5);
		SetPos(40, 19);
		cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
		SetPos(40, 20);
		cout << "@ Вiйти як працiвник газової служби @" << endl;
		SetPos(40, 21);
		cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n" << endl;
		SetCol(7);

		ch = _getch();

		switch (ch)
		{
		case 224:
		{
			switch (_getch())
			{
			case 80: {counter < 6 ? counter++ : counter = 1; break; }
			case 72: {counter > 1 ? counter-- : counter = 6; break; }
			}
		}
		}
	}
	SetConsoleOutputCP(866);
	return counter;
}

void AntiCursor() 
{
	CONSOLE_CURSOR_INFO curs = { 0 };
	curs.dwSize = sizeof(curs);
	curs.bVisible = FALSE;
	::SetConsoleCursorInfo(::GetStdHandle(STD_OUTPUT_HANDLE), &curs);
}



void  MenuPeople(People* p)
{
	while (true)
	{
		system("cls");
		SetCol(14);
		cout << "My Name:" << endl;
		cout << "--------------" << endl;
		cout << "| " << p->GetName();
		SetPos(13, 2);
		cout << "|\n";
		cout << "--------------" << endl;

		cout << endl;
		cout << "My Surname:" << endl;
		cout << "-------------------" << endl;
		cout << "| " << p->GetSurname();
		SetPos(18, 7);
		cout << "|\n";
		cout << "-------------------" << endl;

		cout << endl;
		cout << "Age:" << endl;
		cout << "------------------------" << endl;
		cout << "| " << p->GetAge();
		SetPos(23, 12);
		cout << "|\n";
		cout << "------------------------" << endl;

		cout << "\n" << endl;
		SetConsoleOutputCP(1251);
		cout << "-------------------" << endl;
		cout << "| Вйити жмiть esc |" << endl;
		cout << "-------------------" << endl;
		SetConsoleOutputCP(866);

		cout << "\n" << endl;
		cout << "--------------" << endl;
		cout << "|            |" << endl;
		cout << "--------------" << endl;
		SetCol(7);


		SetPos(45, 2);
		SetCol(2);
		cout << "@______________MENU_____________@" << endl;
		int counter = 1;
		int ch = 1;
		while (ch != 13)
		{
			if (ch == 27) return;
			if (counter == 1) SetCol(4);
			SetPos(45, 5);
			cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
			SetPos(45, 6);
			SetConsoleOutputCP(1251);
			cout << "@  Подати петицiю               @" << endl;
			SetConsoleOutputCP(866);
			SetPos(45, 7);
			cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
			SetCol(2);

			if (counter == 2) SetCol(4);
			SetPos(45, 9);
			cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
			SetPos(45, 10);
			SetConsoleOutputCP(1251);
			cout << "@  переглянути петицiї          @" << endl;
			SetConsoleOutputCP(866);
			SetPos(45, 11);
			cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
			SetCol(2);

			if (counter == 3) SetCol(4);
			SetPos(45, 13);
			cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
			SetPos(45, 14);
			SetConsoleOutputCP(1251);
			cout << "@  Подати заяву до спец. служб  @" << endl;
			SetConsoleOutputCP(866);
			SetPos(45, 15);
			cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
			SetCol(2);

			ch = _getch();
			switch (ch)
			{
			case 224:
			{
				switch (_getch())
				{
				case 80: counter < 3 ? counter++ : counter = 1; break;
				case 72: counter > 1 ? counter-- : counter = 3; break;
				}
			}
			}


		}
		SetCol(7);
		switch (counter)
		{
		case 1:
		{
			p->MakePetition();
			break;
		}
		case 2:
		{
			p->ReadPetitions();
			p->ShowPetition();
			break;
		}
		case 3:
		{
			p->_AddForm();
			break;
		}
		}

	}
}

void  MenuPolice(Police* p)
{
	p->CheckList();
}

void  MenuAmbulance(Ambulance* a)
{
	a->CheckList();
}

void  MenuFiremen(Firemen* f)
{
	f->CheckList();
}

void  MenuGaz(Gaz* g)
{
	g->CheckList();
}

void Reception(System& s, string a = "p")
{
	system("cls");
	SetPos(0, 1);
	int ch, counter = 1;
	do
	{
		SetConsoleOutputCP(1251);
		system("cls");
		if (counter == 1) SetCol(14);
		cout << "----------" << endl;
		cout << "|Вход    |" << endl;
		cout << "----------" << endl;
		SetCol(7);
		SetPos(0, 4);

		if (a == "p")
		{
			if (counter == 2) SetCol(14);
			cout << "-----------------" << endl;
			cout << "|Регистрация    |" << endl;
			cout << "-----------------" << endl;
			SetCol(7);
		}
		Sleep(50);
		switch (counter)
		{
		case 1:
		{
			SetPos(40, 10);
			cout << "-------------------------------------" << endl;
			SetPos(40, 11);
			cout << "|                                   |" << endl;
			SetPos(40, 12);
			cout << "|Enter login:                       |";
			SetPos(40, 13);
			cout << "|                                   |" << endl;
			SetPos(40, 14);
			cout << "|Enter password:                    |";
			SetPos(40, 15);
			cout << "|                                   |" << endl;
			SetPos(40, 16);
			cout << "-------------------------------------" << endl;
			break;
		}
		case 2:
		{
			if (a == "p")
			{
				SetPos(40, 10);
				cout << "-------------------------------------" << endl;
				SetPos(40, 11);
				cout << "|                                   |" << endl;
				SetPos(40, 12);
				cout << "|Enter login:                       |";
				SetPos(40, 13);
				cout << "|                                   |" << endl;
				SetPos(40, 14);
				cout << "|Enter password:                    |";
				SetPos(40, 15);
				cout << "|                                   |" << endl;
				SetPos(40, 16);
				cout << "|Enter name:                        |";
				SetPos(40, 17);
				cout << "|                                   |" << endl;
				SetPos(40, 18);
				cout << "|Enter surname:                     |";
				SetPos(40, 19);
				cout << "|                                   |" << endl;
				SetPos(40, 20);
				cout << "|Enter age:                         |";
				SetPos(40, 21);
				cout << "|                                   |" << endl;
				SetPos(40, 22);
				cout << "-------------------------------------" << endl;
				break;
			}
		}
		}

		ch = _getch();
		switch (ch)
		{
		case 224:
		{
			switch (_getch())
			{
			case 72: counter < 2 ? counter++ : counter = 1; break;
			case 80: counter > 1 ? counter-- : counter = 2; break;
			}
		}
		}

		SetConsoleOutputCP(866);
	} while (ch != 13);
	
	string name;
	string surname;
	string login;
	string password;
	int age;
	SetPos(0, 0);
	switch (counter)
	{
	case 1:
	{
		SetPos(40, 10);
		cout << "-------------------------------------" << endl;
		SetPos(40, 11);
		cout << "|                                   |" << endl;
		SetPos(40, 12);
		cout << "|Enter login:";
		cin >> login;
		SetPos(40, 13);
		cout << "|                                   |" << endl;
		SetPos(40, 14);
		cout << "|Enter password:";
		cin >> password;
		SetPos(40, 15);
		cout << "|                                   |" << endl;
		SetPos(40, 16);
		cout << "-------------------------------------" << endl;
		while (login[login.size() - 1] == ' ' || login[0] == ' ')
		{
			if (login[login.size() - 1] == ' ') login.pop_back();
			if (login[0] == ' ') login[0] = '\0';
		}

		while (password[password.size() - 1] == ' ' || password[0] == ' ')
		{
			if (password[password.size() - 1] == ' ') password.pop_back();
			if (password[0] == ' ') password[0] = '\0';
		}

		for (int i = 0; i < User::id; i++)
		{
			if (s[i]->GetLogin() == login && s[i]->GetPassword() == password && s[i]->GetStatus() == a)
			{
				User::valid = true;
				if (s[i]->GetStatus() == "p") MenuPeople((People*)s[i]);
				else if (s[i]->GetStatus() == "r") MenuPolice((Police*)s[i]);
				else if (s[i]->GetStatus() == "l") MenuAmbulance((Ambulance*)s[i]);
				else if (s[i]->GetStatus() == "k") MenuFiremen((Firemen*)s[i]);
				else if (s[i]->GetStatus() == "g") MenuGaz((Gaz*)s[i]);
				break;
			}
		}
		break;
	}
	case 2:
	{
		if (a == "p")
		{
			SetPos(40, 10);
			cout << "-------------------------------------" << endl;
			SetPos(40, 11);
			cout << "|                                   |" << endl;
			SetPos(40, 12);
			cout << "|Enter login:";
			cin >> login;
			SetPos(40, 13);
			cout << "|                                   |" << endl;
			SetPos(40, 14);
			cout << "|Enter password:";
			cin >> password;
			SetPos(40, 15);
			cout << "|                                   |" << endl;
			SetPos(40, 16);
			cout << "|                                   |" << endl;
			SetPos(40, 16);
			cout << "|Enter name:";
			cin >> name;
			SetPos(40, 17);
			cout << "|                                   |" << endl;
			SetPos(40, 18);
			cout << "|Enter surname:";
			cin >> surname;
			SetPos(40, 19);
			cout << "|                                   |" << endl;
			SetPos(40, 20);
			cout << "|Enter age:";
			cin >> age;
			SetPos(40, 21);
			cout << "|                                   |" << endl;
			SetPos(40, 22);
			cout << "-------------------------------------" << endl;

			bool checkbox = true;
			for (int i = 0; i < User::id; i++) 
			{
				if (s[i]->GetLogin() == login) checkbox = false;
			}

			if (checkbox) 
			{
			User* user = new People(name, surname, age, login, password, "p");
			s.AddUser(user);
			}
			else 
			{
				system("cls");
				SetPos(45,10);
				SetConsoleOutputCP(1251);
				cout << "Логiн уже використовується!" << endl;
				SetConsoleOutputCP(866);
				_getch();
			}
	

			break;
		}
	}
	}


}
