#pragma once
#include "Repository.h"
class Service
{
private:
	Repository& repository;

public:
	Service(Repository& repository) : repository{repository} { }
	void AddStatueService(std::string PowerWordName, std::string Material, int Age, std::string CorporealForm);
	void UpdateStatueService(std::string PowerWordName, std::string Material, int Age, std::string CorporealForm);
	void DeleteStatueService(std::string PowerWordName);
	int GetSize();
	TElems GetElement(int);
	DynamicVector<TElems> GetElementsDynamicVector();
	DynamicVector<TElems> GetSavedElementsDynamicVector();
	DynamicVector<TElems> GetFilteredList(std::string, int);
	int SaveStatue(std::string);
};

