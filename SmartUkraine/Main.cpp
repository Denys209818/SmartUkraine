#include "libs.h"
#include "_Form.h"
#include "User.h"
#include "Petition.h"
#include "People.h"
#include"Police.h"
#include "Ambulance.h"
#include "Gaz.h"
#include "Firemen.h"
#include "System.h"
int User::id = 0;
bool User::valid = false;

void  MenuPeople(People* p);



void  MenuPolice(Police* p);

void  MenuAmbulance(Ambulance* a);

void  MenuFiremen(Firemen* f);

void  MenuGaz(Gaz* g);

void Reception(System& s, string a = "p");


void main() 
{
	System s;
	bool checkbox = true;
	User::id = 0;
	s.Start();

	while (true) 
	{
	system("cls");
	AntiCursor();
	

	int a = Autefication();


	switch (a) 
	{
	    case 1: 
	    {
			Reception(s);
	    	break;
	    }
		case 2: 
		{
			Reception(s,"r");
			break;
		}
		case 3: 
		{
			Reception(s, "l");
			break;
		}
		case 4:
		{
			Reception(s, "k");
			break;
		}
		case 5:
		{
			Reception(s, "g");
			break;
		}
	}


	SetCol(7);

	s.End();
	}
	
	
	


	



}