#pragma once
#include <iostream>

class Statue
{
private:
	std::string powerWordName;
	std::string material;
	int age;
	std::string corporealForm;

public:

	Statue();
	Statue(std::string const powerWordName, std::string const material, int const age, std::string const corporealForm);

	//Getters
	std::string GetPowerWordName() const { return powerWordName; }
	std::string GetMaterial() const { return material; }
	int GetAge() const { return age; }
	std::string GetCorporealForm() const { return corporealForm; }


	//Setters
	void setPowerWordName(std::string newname) { powerWordName = newname; }
	void setMaterial(std::string newmaterial) { material = newmaterial; }
	void setAge(int newage) { age = newage; }
	void setCorporealForm(std::string newcorporealform) { corporealForm = newcorporealform; }


	std::string ToString();

};

