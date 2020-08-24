#include "libs.h"
#include "People.h"


People::People(string name, string surname, int age, string login, string password, string status) : User(name, surname, age, login, password, status)
{
	
}

void People::ShowPetition()
{
	if (this->v.size() > 0) 
	{
	while (true)
	{
		
		bool gr = false;
		int ch = 1;
		int counter = 0;

		int l = 3, s = 0;
		do
		{
			l = 3;
			system("cls");
			if (v.size() - s < 3)
			{
				l = v.size() - s;
			}

			SetPos(45, 0);
			SetConsoleOutputCP(1251);
			cout << "<<< Назад || Вперед >>>" << endl;
			SetConsoleOutputCP(866);

			for (int i = 0; i < l; i++)
			{
				if (counter == i) SetCol(4);
				for (int i = 0; i < 118; i++) cout << "=";
				cout << "\n";
				for (int i = 0; i < 50; i++) cout << " ";
				cout << v[i + s]->title << endl;

				for (int k = 0; k < v[i + s]->text.size() / 2; k++)
				{
					cout << v[i + s]->text[k];
				}
				cout << "..." << endl;
				for (int i = 0; i < 118; i++) cout << "=";
				cout << "\n";
				SetCol(7);
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
				case 77: {s + 3 < this->v.size() ? s += 3 : s = s; counter = 0; break; }
				}
			}
			}


		} while (ch != 13);

		system("cls");
		cout << v[counter + s]->title << ",";
		SetPos(0, 2);

		for (int i = 0; i < v[counter + s]->text.size(); i++)
		{
			if (i % 50 == 0) { cout << endl; }
			cout << v[counter + s]->text[i];
		}
		int ch_ = 1;
		int counter_ = 1;
		while (true)
		{
			do
			{
				for (int i = 0; i < this->v[counter + s]->numbers.size(); i++)
				{
					if (this->v[counter + s]->numbers[i] == this->id_) { SetCol(4); gr = true; }
					
				}
				
				
				if (counter_ == 1) SetCol(12);
				SetPos(2, 20);
				cout << "@@@@@@@@@@@@";
				SetPos(2, 21);
				cout << "@          @";
				SetPos(2, 22);
				cout << "@   LIKE   @";
				SetPos(2, 23);
				cout << "@          @";
				SetPos(2, 24);
				cout << "@@@@@@@@@@@@";
				SetCol(7);
				if (counter_ == 2) SetCol(12);
				SetPos(18, 20);
				cout << "@@@@@@@@@@@@";
				SetPos(18, 21);
				cout << "@          @";
				SetPos(18, 22);
				cout << "@   BACK   @";
				SetPos(18, 23);
				cout << "@          @";
				SetPos(18, 24);
				cout << "@@@@@@@@@@@@";
				SetCol(7);

				if (counter_ == 3) SetCol(12);
				SetPos(18 * 2, 20);
				cout << "@@@@@@@@@@@@";
				SetPos(18 * 2, 21);
				cout << "@          @";
				SetPos(18 * 2, 22);
				cout << "@   MENU   @";
				SetPos(18 * 2, 23);
				cout << "@          @";
				SetPos(18 * 2, 24);
				cout << "@@@@@@@@@@@@";
				SetCol(7);
				ch_ = _getch();
				switch (ch_)
				{
				case 224:
				{
					switch (_getch())
					{
					case 77: counter_ < 3 ? counter_++ : counter_ = 1; break;
					case 75: counter_ > 1 ? counter_-- : counter_ = 3; break;
					}
				}
				}
			} while (ch_ != 13);

			if (counter_ == 1)
			{
				if (gr)
				{
					gr = false;
					for (int i = 0; i < this->v[counter + s]->numbers.size(); i++)
					{
						if (this->v[counter + s]->numbers[i] == this->id_)
						{
							for (int j = i; j < this->v[counter + s]->numbers.size() - 1; i++)
							{
								int temp = this->v[counter + s]->numbers[j];
								this->v[counter + s]->numbers[j] = this->v[counter + s]->numbers[j + 1];
								this->v[counter + s]->numbers[j + 1] = temp;
							}
							this->v[counter + s]->numbers.pop_back();
							break;
						}
					}
				}
				else
				{
					bool f = true;
					for (int i = 0; i < this->v[counter + s]->numbers.size(); i++)
					{
						if (this->v[counter + s]->numbers[i] == this->id_)
						{
							f = false;
						}
					}
					if (f)
					{
						v[counter + s]->numbers.push_back(this->id_);
					}
					gr = true;
				}
				this->SafeFile();
			}
			else if (counter_ == 2)
			{
				break;
			}
			else if (counter_ == 3)
			{
				return;
			}
		}
	}
	}
	else 
{
return;
}
}

void People::SafeFile()
{
	ofstream file("petitions.txt", ios::trunc);
	for (int i = 0; i < this->v.size(); i++)
	{
		if (i != 0) file << "\n";
		file << this->v[i]->title << "~" << this->v[i]->text << "&";
		for (int j = 0; j < this->v[i]->numbers.size(); j++)
		{
			file << this->v[i]->numbers[j] << "_";
		}
	}
	file.close();
}

void People::ReadPetitions()
{
	ifstream file("petitions.txt");
	char buffer[255];
	char title[255];
	char text[255];

	system("cls");

	while (!file.eof())
	{
		file.getline(buffer, 255);
		if (buffer[0] != '\0')
		{
			int k = 0;
			for (int i = 0; i < strlen(buffer); i++)
			{

				if (buffer[i] == '~')
				{
					title[i] = '\0';
					k = i + 1;
					break;
				}
				title[i] = buffer[i];
			}
			int i = 0;
			while (buffer[k] != '&')
			{
				text[i] = buffer[k];
				i++;
				k++;
			}
			text[i] = '\0';
			k++;
			vector<int> v_;

			while (buffer[k] != '\0' && buffer[k] != '\0')
			{
			char number[10];
			int i = 0;
				while (buffer[k] != '_' && buffer[k] != '\0') 
				{
				
				number[i] = buffer[k];
				k++;
				i++;
				}
				number[i] = '\0';
				v_.push_back(atoi(number));
				k++;
			}


			Petition* p = new Petition(title, text, v_);


			this->v.push_back(p);
		}
	}
	
	file.close();
}

void People::MakePetition()
{
	//SetCol(35);
	int k = 1;
	int p = 0;
	char title[255];
	char* text = new char[10000];


	system("cls");
	//SetCol(36);
	SetPos(27, 0);
	for (int i = 0; i < 60; i++) cout << "@";
	SetPos(27, 1);
	cout << "@";
	SetPos(86, 1);
	cout << "@";
	SetPos(27, 2);
	cout << "@";
	SetPos(86, 2);
	cout << "@";
	SetPos(86, 3);
	cout << "@";
	SetPos(27, 4);
	cout << "@";
	SetPos(86, 4);
	cout << "@";
	SetPos(27, 5);
	cout << "@";
	SetPos(86, 5);
	cout << "@";
	SetPos(27, 6);
	for (int i = 0; i < 60; i++) cout << "@";
	SetPos(27, 3);
	SetConsoleOutputCP(1251);
	cout << "@ Ведiть заголовок - ";
	SetConsoleOutputCP(866);
	int s = 0;
	while (true)
	{
		title[s] = _getch();


		SetPos(27, 3);
		SetConsoleOutputCP(1251);
		cout << "@ Ведiть заголовок - ";
		SetConsoleOutputCP(866);


		if (title[s] == (int)13)
		{
			title[s] = '\0';
			break;
		}
		
		if (title[s] == (char)63) title[s] = 'i';

		if (title[s] == (int)8)
		{
			for (int k = 0; k < s - 1; k++)
			{
				cout << title[k];
			}
			cout << " ";
			s--;
		}
		else
		{
			s++;
			for (int k = 0; k < s; k++)
			{
				cout << title[k];
			}
		}
	}
	//SetCol(7);
	system("cls");
	int i = 0;
	//SetCol(36);
	cout << endl;
	for (int i = 0; i < 50; i++) cout << " ";
	SetConsoleOutputCP(1251);
	cout << "Введiть текст статтi";
	SetConsoleOutputCP(866);
	for (int i = 35; i < 85; i++)
	{
		SetPos(i, 0);
		cout << "@";
	}

	for (int i = 0; i < 20; i++)
	{
		SetPos(34, i);
		cout << "@";
	}

	for (int i = 0; i < 20; i++)
	{
		SetPos(86, i);
		cout << "@";
	}

	for (int i = 35; i < 85; i++)
	{
		SetPos(i, 19);
		cout << "@";
	}
	do
	{
		//SetCol(36);
		text[i] = _getch();

		if ((int)text[i] == 13)
		{
			text[i] = '\0';
			break;
		}
		text[i + 1] = '\0';
		if (text[i] == (char)8)
		{
			text[i - 1] = ' ';
			i--;
		}
		else
		{
			i++;
		}
		for (int i = 35; i < 85; i++)
		{
			SetPos(i, 0);
			cout << "@";
		}
		cout << endl;
		for (int i = 0; i < 50; i++) cout << " ";
		SetConsoleOutputCP(1251);
		cout << "Введiть текст статтi";
		SetConsoleOutputCP(866);


		//SetCol(36);
		for (int i = 0; i < 35; i++) cout << " ";
		for (int i = 0; i < strlen(text); i++)
		{
			if (i % 50 == 0)
			{
				cout << endl;
				for (int i = 0; i < 35; i++) cout << " ";
				k++;
			}
			
			if (text[i] == (char)63) text[i] = 'i';
			

			
			cout << text[i];
		}
		//cout << text;

		for (int i = 0; i < 20; i++)
		{
			SetPos(34, i);
			cout << "@";
		}

		for (int i = 0; i < 20; i++)
		{
			SetPos(86, i);
			cout << "@";
		}

		for (int i = 35; i < 85; i++)
		{
			SetPos(i, 19);
			cout << "@";
		}

		//SetCol(35);
	} while (true);
	system("cls");
	SetPos(50, 8);
	ofstream file("petitions.txt", ios_base::app);
	char* c = strstr(text, "   ");
	if (c != nullptr)
	{
		c = '\0';
	}

	for (int i = 0; i < strlen(text); i++) 
	{
		if (text[i] == (char)63) text[i] = 'i';
	}

	for (int i = 0; i < strlen(title); i++)
	{
		if (title[i] == (char)63) title[i] = 'i';
	}

	file << "\n" << title << "~" << text << "&";
	file.close();
	SetConsoleOutputCP(1251);
	cout << "Петицiю опублiковано!" << endl;
	_getch();
	SetConsoleOutputCP(866);


	SetCol(7);


}

People* People::GetPeople()
{
	return this;
}

void People::_AddForm()
{
	SetConsoleOutputCP(1251);
	char title[255];
	char text[10000];
	system("cls");
	int s = 0;
	cout << "Ведiть проблему (пожежа, хворба i т.д) - ";
	SetConsoleOutputCP(866);
	while (true)
	{
		title[s] = _getch();


		SetPos(0, 0);
		SetConsoleOutputCP(1251);
		cout << "Ведiть проблему (пожежа, хворба i т.д) - ";
		SetConsoleOutputCP(866);

		if (title[s] == (int)13)
		{
			title[s] = '\0';
			break;
		}


		if (title[s] == (int)8)
		{
			for (int k = 0; k < s - 1; k++)
			{
				if (title[k] == (char)63) cout << "i";
				else cout << title[k];
			}
			cout << " ";
			s--;
		}
		else
		{
			s++;
			for (int k = 0; k < s; k++)
			{
				if (title[k] == (char)63) cout << "i";
				else cout << title[k];
			}
		}

	}

	SetPos(0, 3);
	SetConsoleOutputCP(1251);
	cout << "Ведiть опис проблеми (Детально про випадок, вказати адресу обовязково!) - ";
	SetConsoleOutputCP(866);
	int i = 0;
	while (true)
	{
		text[i] = _getch();

		SetPos(0, 3);
		SetConsoleOutputCP(1251);
		cout << "Ведiть опис проблеми (Детально про випадок, вказати адресу обовязково!) - ";
		SetConsoleOutputCP(866);
		if (text[i] == (int)13)
		{
			text[i] = '\0';
			break;
		}



		if (text[i] == (int)8)
		{
			for (int k = 0; k < i - 1; k++)
			{
				if (text[k] == '?') cout << "i";
				else cout << text[k];
			}
			cout << " ";
			i--;
		}
		else
		{
			i++;
			for (int k = 0; k < i; k++)
			{
				if (text[k] == '?') cout << "i";
				else cout << text[k];
			}
		}



		SetConsoleOutputCP(866);



	}

	for (int t = i; t > 0; t--)
	{
		if (text[t] != ' ')
		{
			break;
		}
		else
		{
			text[t] = '\0';
		}
	}

	for (int t = s; t > 0; t--)
	{
		if (title[t] != ' ')
		{
			break;
		}
		else
		{
			title[t] = '\0';
		}
	}

	ofstream file("baza_forms.txt", ios_base::app);
	for (int i = 0; i < strlen(text); i++)
	{
		if (text[i] == (char)63) text[i] = 'i';
	}

	for (int i = 0; i < strlen(title); i++)
	{
		if (title[i] == (char)63) title[i] = 'i';
	}
	
	file << "\n" << title << "~" << text << "&" << "active" << "_" << this->GetName() << this->GetSurname() << this->GetLogin();
	file.close();
	SetConsoleOutputCP(866);

}

vector<Petition*>& People::GetV()
{
	return this->v;
}

void People::CheckList()
{
	try
	{
		throw 1;
	}
	catch (int ex)
	{
		if (ex == 1) cout << "You can't this use!" << endl;
	}
}