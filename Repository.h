#pragma once
#include <iostream>
#include  "Domain.h"
#include "DynamicVector.h"
typedef Statue TElems;



class Repository
{
private:
	DynamicVector<Statue> statues;
	DynamicVector<Statue> savelist;
public:

	Repository()
	{
		statues = DynamicVector<Statue>(10);
		savelist = DynamicVector<Statue>(10);
	}

	void addStatue(TElems statue);
	void updateStatue(int position, std::string PowerWordName, std::string newMaterial, int newAge, std::string newCorporealForm);
	void deleteStatue(TElems statue);
	int StaueIsInStatues(TElems statue);
	int GetSizeRepo();
	TElems GetElement(int );
	DynamicVector<Statue> GetElements();
	DynamicVector<Statue> GetSavedElements();
	bool StaueinSaveList(TElems);
	TElems GetStatueAfterPowerWordName(std::string);
	void addStatueinSaveList(TElems);
};

