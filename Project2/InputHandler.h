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

#include "CandidateList.h"

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

void createCandidateList(std::ifstream& infile, 
	CandidateList& candidateList)
{
	int id = 0;
	int allVotes[NUM_OF_KINGDOMS];
	std::string  fName, lName;

	infile >> id;

	while (id != -999)
	{
		CandidateType newCandidate;

		infile >> fName;
		infile >> lName;
		newCandidate.setCharacterInfo(fName, lName, id);

		for (int i = 0; i < NUM_OF_KINGDOMS; ++i)
		{
			infile >> allVotes[i];
			newCandidate.updateVotesByKingdom(i, allVotes[i]);
		}

		candidateList.addCandidate(newCandidate);

		infile >> id;
	}
}

void readCandidateData(CandidateList& candidateList)
{
	std::ifstream infile;

	infile.open("candidates_data.txt");

	if (!infile)
	{
		std::cerr << "Input file does not exist.\n";
		exit(1);
	}

	createCandidateList(infile, candidateList);

	infile.close();
}