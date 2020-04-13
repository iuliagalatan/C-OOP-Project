#include "UI.h"
#include <iostream>
#include <string>


// command line parammeters
enum Params {
	firstparammeter,
	secondparammeter,
	thirdparammeter,
	fourthparammeter
};

void UI::start_program()
{
	char command[100];
	int returnValue;
	std::string powerwordname;
	std::string material;
	int age;
	std::string corporealform;
	
	while (true)
	{
		std::cout << "enter command..";
		ParseCommand();
	}
}

void UI::ParseCommand()
{
	char* pointerToLine;
	char lineRead[1000];
	std::cin.getline(lineRead, 1000);

	if (strcmp(lineRead, "exit") == 0)
	{
		std::cout << "exit application\n";
		exit(0);
	}

	int number = 0;
	int parameters = 0;
	pointerToLine = strtok(lineRead, " ");

	if (pointerToLine == nullptr)
	{
		std::cout << "wrong command\n";
		return;
	}

	if ( strcmp(pointerToLine, "add") == 0)
	{
		AddStatueUI(pointerToLine);
		return;
	}

	if ( strcmp(pointerToLine, "update") == 0)
	{	
		UpdateStatueUI(pointerToLine);
		return;
	}

	if ( strcmp(pointerToLine, "delete") == 0)
	{		
		DeleteStatueUI(pointerToLine);
		return;
	}

	if (strcmp(pointerToLine, "list") == 0)
	{		
		ListUI(pointerToLine);
		return;
	}

	if ( strcmp(pointerToLine, "mode") == 0)
	{
		ModeChangeUI(pointerToLine);
		return;
	}

	if (strcmp(pointerToLine, "next") == 0)
	{
		NextStatueUI(pointerToLine);
		return;
	}

	if ( strcmp(pointerToLine, "save") == 0)
	{
		SaveStatueUI(pointerToLine);
		return;
	}

	if ( strcmp(pointerToLine, "mylist") == 0)
	{
		this->ListMyList();
		return;
	}

	// the command is ill formed
	std::cout << "wrong command\n";
}

void UI::NextStatueUI(char* pointerToLine)
{
	if (modeB)
	{
		this->Next(position);
		position += 1;
	}
}

void UI::ModeChangeUI(char* pointerToLine)
{
	pointerToLine = strtok(NULL, " ");
	if (pointerToLine != NULL)
		if (strcmp(pointerToLine, "A") == 0)
			modeA = true, modeB = false; // mode A -  magic spells on
		else
			if (strcmp(pointerToLine, "B") == 0)
				modeB = true,
				modeA = false; // mode B spells will work
}


void UI::SaveStatueUI(char* pointerToLine)
{ 
	if (modeB)
	{
		pointerToLine = strtok(NULL, " ");
		std::string powerWordName = pointerToLine;
		this->SaveStatue(powerWordName);
		std::cout << "Statue saved ";
	}
}

void UI::ListUI(char* pointerToLine)
{
	pointerToLine = strtok(NULL, ", ");
	if (pointerToLine == NULL)
		if (modeA == 1)
			this->ListAll();

	if (pointerToLine != NULL)
	{
		std::string material = pointerToLine;
		pointerToLine = strtok(NULL, ", ");
		int age = atoi(pointerToLine);

		this->filterAfterMaterialAndAge(material, age);
	}
}

void UI::AddStatueUI(char* pointerToLine)
{
	for (int i = 0; i < 4; ++i) // add needs to have 4 params
	{
		pointerToLine = strtok(NULL, ", ");
		if (pointerToLine != NULL)
		{
			GetParameters(i, pointerToLine);
		}
		else
		{
			std::cout << "not enough parammeters\n";
			return;
		}
	}

	if (modeA == 1)
		this->service.AddStatueService(powerwordname, material, age, corporealform);
}

void UI::UpdateStatueUI(char* pointerToLine)
{
	for (int i = 0; i < 4; ++i) //update needs to have 4 params
	{
		pointerToLine = strtok(NULL, ", ");
		if (pointerToLine != NULL)
		{
			GetParameters(i, pointerToLine);
		}
		else
		{
			std::cout << "not enough parammeters\n";
			return;				
		}
	}

	if (modeA == 1)
		this->service.UpdateStatueService(powerwordname, material, age, corporealform);
}

void UI::GetParameters(int i, char* pointerToLine)
{
	if (i == firstparammeter) // first param
		powerwordname = pointerToLine;
	if (i == secondparammeter) // second param
		material = pointerToLine;
	if (i == thirdparammeter) // third param
		age = atoi(pointerToLine);
	if (i == fourthparammeter) // forthparam
		corporealform = pointerToLine;
}


void UI::DeleteStatueUI(char* pointerToLine)
{
	for (int i = 0; i < 1; ++i) // delete needs to have 1 param
	{
		pointerToLine = strtok(NULL, " ");
		if (pointerToLine != NULL)
		{
			if (i == 0) // only one param
				powerwordname = pointerToLine;
		}
		else
		{
			std::cout << "not enough parammeters\n";
			return;
		}
	}
	
	if (modeA == 1) // if magicspell is 1, we can proceed.
		this->service.DeleteStatueService(powerwordname);	
}

void UI::ListAll()
{
	this->List(this->service.GetElementsDynamicVector());
}

void UI::List(DynamicVector<TElems> toprint)
{
	for (int i = 0; i < toprint.getSize(); ++i)
	{
		Statue statue = toprint.get(i);
		std::cout << statue.ToString() << '\n';
	}
}

void UI::Next(int position)
{
	if (position >= this->service.GetSize())
		std::cout << "NO";
	else
	{
		Statue nextstatue = this->service.GetElement(position);
		std::cout << nextstatue.ToString() << '\n';
	}
}

void UI::SaveStatue(std::string PowerWordName)
{
	this->service.SaveStatue(PowerWordName);
}

void UI::ListMyList()
{
	DynamicVector<TElems> toprint = this->service.GetSavedElementsDynamicVector();
	this->List(toprint);
}

void UI::filterAfterMaterialAndAge(std::string material, int age)
{
	DynamicVector<TElems> toprint = this->service.GetFilteredList(material, age);
	if (toprint.getSize() == 0)
		toprint = this->service.GetElementsDynamicVector();
	this->List(toprint);
}