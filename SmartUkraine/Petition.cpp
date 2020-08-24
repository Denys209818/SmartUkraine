#include "libs.h"
#include "Petition.h"

Petition::Petition(string title, string text, vector<int> v)
{
	this->text = text;
	this->title = title;
	this->numbers = v;
}