#include "Domain.h"
#include <iostream>
#include <string>

Statue::Statue(std::string const powerWordName, std::string const material, int const age, std::string const corporealForm)
{
	this->age = age;
	this->corporealForm = corporealForm;
	this->material = material;
	this->powerWordName = powerWordName;

}

Statue::Statue()
{
	this->age = 0;
	this->corporealForm = "";
	this->material = "";
	this->powerWordName = "";

}

std::string Statue::ToString()
{
	return this->powerWordName + " material:" + this->material + " age: "+ std::to_string(this->age)+" corporealform:"  + " " + this->corporealForm;
}