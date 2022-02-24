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

#ifndef CANDIDATETYPE_H
#define CANDIDATETYPE_H

#include "CharacterType.h"

const int NUM_OF_KINGDOMS = 7;	// this is the capacity of the array
const std::string KINGDOMS[] = {
	"The North",
	"The Vale",
	"The Stormlands",
	"The Reach",
	"The Westerlands",
	"The Iron Islands",
	"Dorne" 
};

class CandidateType	: public CharacterType
{
public:
	// Default constructor
	CandidateType();
	// Copy constructor
	CandidateType(const CandidateType& otherCandidate);

	// Copy assignment operator
	CandidateType& operator=(const CandidateType& rhs);

	// updateVotesByKingdom
	void updateVotesByKingdom(int index, int newVote);

	// getTotalVotes
	int getTotalVotes() const;
	// getVotesByKingdom
	int getVotesByKingdom(int index) const;

	// printCandidateInfo
	void printCandidateInfo() const;
	// printCandidateTotalVotes
	void printCandidateTotalVotes() const;

	//overloaded operator==
	bool operator==(int id) const;

	// Destructor
	~CandidateType();

private:
	int totalVotes;
	int numOfKingdoms;
	int *kingdomVotes;
};

#endif
