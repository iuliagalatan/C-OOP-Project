#include "Service.h"
#include "Repository.h"
/*
Adds a statue to the list of statues
params: PowerWordName
		Material
		Age
		CorporealForm
*/
void Service::AddStatueService(std::string PowerWordName, std::string Material, int Age, std::string CorporealForm)
{
	TElems Statue = TElems(PowerWordName, Material, Age, CorporealForm);
	if( this->repository.StaueIsInStatues(Statue)==-1)
		this->repository.addStatue(Statue);
}


/*
	Updates info from a statue in the list of statues
params: PowerWordName - existent powerwordname
		Material - new material 
		Age - new age
		CorporealForm - new form
*/
void Service::UpdateStatueService(std::string PowerWordName, std::string Material, int Age, std::string CorporealForm) 
{
	std::string emptystring = "";
	int age = 0;
	TElems Statue = TElems(PowerWordName, emptystring, age, emptystring);
	int position = this->repository.StaueIsInStatues(Statue);
	if (position != -1)
	{
		this->repository.updateStatue(position, PowerWordName, Material, Age, CorporealForm);
	}

}


/*
Deletes a statue after it s PowerWordName
*/
void Service::DeleteStatueService(std::string PowerWordName)
{
	std::string emptystring = "";
	int age = 0;
	TElems Statue = TElems(PowerWordName, emptystring, age, emptystring);
	this->repository.deleteStatue(Statue);
	
}

int Service::GetSize()
{

	return this->repository.GetSizeRepo();
}

TElems Service::GetElement(int position)
{
	return this->repository.GetElement(position);
}


DynamicVector<Statue> Service::GetElementsDynamicVector()
{
	return this->repository.GetElements();
}

int Service::SaveStatue(std::string powerWordName)
{
	Statue statue = this->repository.GetStatueAfterPowerWordName(powerWordName);
	if (this->repository.StaueinSaveList(statue))
		return 0;
	else
	{
		this->repository.addStatueinSaveList(statue);
		return 1;
	}
}

DynamicVector<TElems> Service::GetSavedElementsDynamicVector()
{
	return this->repository.GetSavedElements();
}

DynamicVector<TElems> Service::GetFilteredList(std::string material, int age)
{
	DynamicVector<TElems> WholeListofStatues = this->repository.GetElements();
	DynamicVector<TElems> FilteredListofStatues;
	for (int i = 0; i < WholeListofStatues.getSize(); ++i)
	{
		TElems statue = WholeListofStatues.get(i);
		if (statue.GetAge() < age && statue.GetMaterial() == material)
		{
			FilteredListofStatues.add(statue);
		}

	}
	return FilteredListofStatues;
}