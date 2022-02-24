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

#ifndef CANDIDATELIST_H
#define CANDIDATELIST_H

#include "CandidateType.h"

#include <iostream>
#include <string>
#include <iomanip>
#include <list>

class CandidateList
{
public:
	// Default constructor
	CandidateList();

	// addCandidate
	void addCandidate(const CandidateType& candidate);

	// getWinner
	int getWinner() const;

	// isEmpty
	bool isEmpty() const;
	// searchCandidate
	bool searchCandidate(int id) const;

	// printCandidateName
	void printCandidateName(int id) const;
	// printAllCandidates
	void printAllCandidates() const;
	// printKingdomVotes
	void printKingdomVotes(int id, int index) const;
	// printCandidateTotalVotes
	void printCandidateTotalVotes(int id) const;
	// printFinalResults
	void printFinalResults() const;

	// Destructor
	~CandidateList();

private:
	// searchCandidate
	bool searchCandidate(int id,
		std::list<CandidateType>::const_iterator& it) const;

	// printHeader
	void printHeader() const;
	// printCandidate
	void printCandidate(std::list<CandidateType>::const_iterator it, 
		int rank) const;

	std::list<CandidateType> candidates;
};

#endif
