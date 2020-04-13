#pragma once
#include "Service.h"
#include <cstring>
#include <iostream>
class UI
{
private:
	Service& service;
	bool modeA = false;
	bool modeB = true;

	std::string powerwordname;
	std::string material;
	int age;
	std::string corporealform;
	int position = 0;

public:
	UI(Service& service): service{service} { }

	void start_program();
	void List(DynamicVector<TElems>);
	void ListAll();
	void Next(int);
	void SaveStatue(std::string);
	void filterAfterMaterialAndAge(std::string material, int age);
	void ListMyList();
	void ParseCommand();

	void AddStatueUI(char* pointerToLine);
	void UpdateStatueUI(char* pointerToLine);
	void GetParameters(int i, char* pointerToLine);
	void DeleteStatueUI(char* pointerToLine);
	void ModeChangeUI(char* pointerToLine);
	void NextStatueUI(char* pointerToLine);
	void FilterUI(char* pointerToLine);
	void ListUI(char* pointerToLine);
	void SaveStatueUI(char* pointerToLine);
};

