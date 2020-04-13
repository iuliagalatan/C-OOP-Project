#include "Tests.h"
#include <iostream>
#include "Service.h"
#include <assert.h>


void AddStatueService_ValidInput_AddedtoList()
{
	Repository repository = Repository();
	Service service = Service{ repository };
	std::string examplestring = "aaa";
	service.AddStatueService(examplestring, examplestring, 1, examplestring);
	assert(service.GetSize() == 1);

}
void AddStatue_ValidInput_AddedtoList()
{
	Repository repository = Repository();
	Service service = Service{ repository };
	std::string examplestring = "aaa";
	Statue statue = Statue(examplestring, examplestring, 1, examplestring);
	repository.addStatue(statue);
	
	assert(repository.GetSizeRepo() == 1);

}


void DeleteStatueService_ValidInput_RemovedfromList()
{
	Repository repository = Repository();
	Service service = Service{ repository };
	std::string examplestring = "aaa";
	service.AddStatueService(examplestring, examplestring, 1, examplestring);
	service.DeleteStatueService(examplestring);
	assert(service.GetSize() == 0);
}



void DeleteStatue_ValidInput_RemovedfromList()
{
	Repository repository = Repository();
	Service service = Service{ repository };
	std::string examplestring = "aaa";
	Statue statue = Statue(examplestring, examplestring, 1, examplestring);
	repository.addStatue(statue);
	repository.deleteStatue(statue);
	assert(repository.GetSizeRepo() == 0);
}


void UpdateStatueService_ValidInput_UpdatedinList()
{
	Repository repository = Repository();
	Service service = Service{ repository };
	std::string examplestring = "aaa";
	service.AddStatueService(examplestring, examplestring, 1, examplestring);
	service.UpdateStatueService("aaa", "bbb", 0, "sss");

	assert(service.GetElement(0).GetMaterial() == "bbb");
}


void UpdateStatue_ValidInput_UpdatedinList()
{
	Repository repository = Repository();
	Service service = Service{ repository };
	std::string examplestring = "aaa";
	Statue statue = Statue(examplestring, examplestring, 1, examplestring);
	repository.addStatue(statue);

	repository.updateStatue(0,"aaa", "bbb", 0, "sss");

	assert(repository.GetElement(0).GetMaterial()== "bbb");
}



void Start_tests()
{

	AddStatueService_ValidInput_AddedtoList();
	AddStatue_ValidInput_AddedtoList();
	UpdateStatueService_ValidInput_UpdatedinList();
	UpdateStatue_ValidInput_UpdatedinList();
	DeleteStatueService_ValidInput_RemovedfromList();
	DeleteStatue_ValidInput_RemovedfromList();
	StaueIsInStatues_ValidInput_Found();
	StaueIsInStatues_ValidInput_NotFound();
}


void StaueIsInStatues_ValidInput_Found()
{
	std::string examplestring = "aaa";
	Repository repository = Repository();
	Statue statue = Statue(examplestring, examplestring, 1, examplestring);
	repository.addStatue(statue);
	assert(repository.StaueIsInStatues(statue) == 0);

}

void StaueIsInStatues_ValidInput_NotFound()
{
	std::string examplestring = "aaa";
	Repository repository = Repository();
	Statue statue = Statue(examplestring, examplestring, 1, examplestring);
	repository.addStatue(statue);
	Statue statue2 = Statue("alabala", examplestring, 1, examplestring);
	assert(repository.StaueIsInStatues(statue) == 0);
}

void GetSize_ValidInput_ReturnedSize()
{
	Repository repository = Repository();
	Service service = Service{ repository };
	std::string examplestring = "aaa";
	service.AddStatueService(examplestring, examplestring, 1, examplestring);
	assert(service.GetSize() == 1);
}

void GetElement_ValidInput_ReturnedElement()
{
	Repository repository = Repository();
	Service service = Service{ repository };
	std::string examplestring = "aaa";
	Statue statue = Statue(examplestring, examplestring, 1, examplestring);
	
	service.AddStatueService(examplestring, examplestring, 1, examplestring);
	assert(service.GetElement(0).GetAge() == 1);

}
