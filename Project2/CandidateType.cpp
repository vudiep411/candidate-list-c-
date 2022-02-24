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

#include "CandidateType.h"

using namespace std;

// Implement all functions in the SAME order
// as listed in the interface file.
CandidateType::CandidateType() 
{
	totalVotes = 0;
	numOfKingdoms = NUM_OF_KINGDOMS;
	kingdomVotes = new int[numOfKingdoms] {0};
}

CandidateType::CandidateType(const CandidateType& otherCandidate)
	: CharacterType(otherCandidate.getFirstName(),
		otherCandidate.getLastName(), otherCandidate.getID())
{
	totalVotes = otherCandidate.totalVotes;
	numOfKingdoms = otherCandidate.numOfKingdoms;
	kingdomVotes = new int[otherCandidate.numOfKingdoms];

	for (int i = 0; i < numOfKingdoms; i++)
		kingdomVotes[i] = otherCandidate.kingdomVotes[i];
}

CandidateType& CandidateType::operator=(const CandidateType& rhs)
{
	if (&rhs != this)
	{
		setCharacterInfo(rhs.getFirstName(),
			rhs.getLastName(), rhs.getID());

		if (numOfKingdoms != rhs.numOfKingdoms)
		{
			delete[] kingdomVotes;
			kingdomVotes = new int[rhs.numOfKingdoms];
			numOfKingdoms = rhs.numOfKingdoms;
		}

		for (int i = 0; i < numOfKingdoms; i++)
			kingdomVotes[i] = rhs.kingdomVotes[i];

		totalVotes = rhs.totalVotes;
	}
	else
		cerr << "Attempted assignment to itself." << endl;

	return *this;
}

void CandidateType::updateVotesByKingdom(int index, int newVote)
{
	kingdomVotes[index] += newVote;
	totalVotes += newVote;
}

int CandidateType::getTotalVotes() const { return totalVotes; }

int CandidateType::getVotesByKingdom(int index) const
{
	return kingdomVotes[index]; 
}

void CandidateType::printCandidateInfo() const
{
	printID();
	cout << " - ";
	printName();
}

void CandidateType::printCandidateTotalVotes() const
{
	printName();
	cout << "\n=> Total Votes (all kingdoms): " << totalVotes;
}

bool CandidateType::operator==(int id) const
{
	return (this->getID() == id);
}

CandidateType::~CandidateType() 
{
	delete[] kingdomVotes;
	kingdomVotes = nullptr;
}