/*
	PhoKimChi
	Nguyen, Frank (TTh 6:30)
	Song, Jung Hoon (TTh 6:30)
	Diep, Vu (TTh 6:30)
	Vuong, Anh (TTh 6:30)
	Zhao, Xiangjun (TTh 6:30)

	May 16, 2020

	CS A250
	Project 2
*/

#include "CharacterType.h"

using namespace std;

// Implement all functions in the SAME order
// as listed in the interface file.
CharacterType::CharacterType() : id(0) {}

CharacterType::CharacterType(const std::string& newFirstName,
	const std::string& newLastName, int newID)
	: firstName(newFirstName), lastName(newLastName), id(newID) {}

void CharacterType::setCharacterInfo(const std::string& newFirstName,
	const std::string& newLastName, int newID)
{
	firstName = newFirstName;
	lastName = newLastName;
	id = newID;
}

string CharacterType::getFirstName() const { return firstName; }

string CharacterType::getLastName() const { return lastName; }

int CharacterType::getID() const { return id; }

void CharacterType::printName() const
{
	cout << lastName << ", " << firstName;
}

void CharacterType::printCharacterInfo() const
{
	printID();
	cout << " " << firstName << " " << lastName;
}

void CharacterType::printID() const
{
	cout << "ID# " << id;
}

CharacterType::~CharacterType() {}