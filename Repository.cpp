#include "Repository.h"
#include "Domain.h"
#include <iostream>


void Repository::addStatue(TElems statue)
{
	if (StaueIsInStatues(statue)!= -1)
		return;
	statues.add(statue);
}


void Repository::updateStatue(int position, std::string PowerWordName, std::string newMaterial, int newAge, std::string newCorporealForm)
{
	TElems ourstatue = statues.get(position);
	TElems updated = TElems(PowerWordName, newMaterial, newAge, newCorporealForm);
	statues.setElement(position, updated);

}

void Repository::deleteStatue( TElems statue)
{
	int deleteposition = this->StaueIsInStatues(statue);
	if( deleteposition != -1)
		statues.deleteElement(deleteposition);
}




int Repository::StaueIsInStatues(TElems statue)
{
	for (int i = 0; i < statues.getSize(); i = i + 1)
	{
		TElems actualStatue = statues.get(i);
		if (actualStatue.GetPowerWordName() == statue.GetPowerWordName())
			return i;
	}
	return -1;
}


int Repository::GetSizeRepo()
{
	return this->statues.getSize();
}

TElems Repository::GetElement(int position)
{
	if (this->GetSizeRepo() > position)
	return this->statues.get(position);
}

DynamicVector<TElems> Repository::GetElements()
{
	return this->statues;
}


bool Repository::StaueinSaveList(TElems statue)
{
	for (int i = 0; i < this->savelist.getSize(); ++i)
		if (this->savelist.get(i).GetPowerWordName() == statue.GetPowerWordName())
			return true;
	return false;
}

//AICI ar trebui sa pun o preconditie sau sa returnez un fel de null stat
TElems Repository::GetStatueAfterPowerWordName(std::string PowerWordName)
{
	for (int i = 0; i < this->GetSizeRepo(); ++i)
	{
		TElems statue = this->GetElement(i);
		if (PowerWordName == statue.GetPowerWordName())
			return statue;
	}
}

void Repository::addStatueinSaveList(TElems statue) 
{
	this->savelist.add(statue);
}

DynamicVector<Statue> Repository::GetSavedElements()
{
	return this->savelist;
}