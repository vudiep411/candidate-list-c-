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
#include <list>
#include <algorithm>

using namespace std;

// Function declarations
// Same order as in class definition
CandidateList::CandidateList() {}

void CandidateList::addCandidate(const CandidateType& candidate)
{
	candidates.push_back(candidate);
}

int CandidateList::getWinner() const
{
	if (isEmpty())
	{
		cerr << "    => List is empty." << endl;
		return 0;
	}
	else
	{
		int highestVotes = 0;
		int id = 0;
		auto beg = candidates.begin();
		auto end = candidates.end();

		while (beg != end)
		{
			int totalVotes = beg->getTotalVotes();

			if (totalVotes > highestVotes)
			{
				highestVotes = totalVotes;
				id = beg->getID();
			}

			++beg;
		}

		return id;
	}
}

bool CandidateList::isEmpty() const { return candidates.empty(); }

bool CandidateList::searchCandidate(int id) const
{
	auto it = candidates.begin();
	return (searchCandidate(id, it));
}

void CandidateList::printCandidateName(int id) const
{
	auto it = candidates.begin();
	
	if (searchCandidate(id, it))
		it->printName();
}

void CandidateList::printAllCandidates() const
{
	if (isEmpty())
		cerr << "    => List is empty." << endl;
	else
	{
		auto beg = candidates.begin();
		auto end = candidates.end();

		while (beg != end)
		{
			beg->printCandidateInfo();
			cout << endl;
			++beg;
		}
	}
}

void CandidateList::printKingdomVotes(int id, int index) const
{
	auto it = candidates.begin();

	if (searchCandidate(id, it))
	{
		cout << setw(5) << "*" << setw(3)
			<< it->getVotesByKingdom(index)
			<< "( => )" << KINGDOMS[index] << endl;
	}
}

void CandidateList::printCandidateTotalVotes(int id) const
{
	auto it = candidates.begin();

	if (searchCandidate(id, it))
	{
		cout << "    => Total votes: " 
			<< it->getTotalVotes() << endl;
	}
}

void CandidateList::printHeader() const
{
	cout << string(12, '*') << " FINAL RESULTS "
		<< string(12, '*') << endl;
	cout << endl;

	cout << left << setw(15) << "LAST";
	cout << left << setw(10) << "FIRST";
	cout << left << setw(9) << "TOTAL";
	cout << left << setw(5) << "POS" << endl;
	cout << left << setw(15) << "NAME";
	cout << left << setw(10) << "NAME";
	cout << left << setw(9) << "VOTES";
	cout << right << setw(3) << "#" << endl;

	cout << string(39, '_') << endl;
	cout << endl;
}

void CandidateList::printFinalResults() const
{
	printHeader();

	auto beg = candidates.begin();
	auto end = candidates.end();
	auto winner = candidates.end();
	int highest = 0;
	int next = 0;
	int i = 0;
	int size = static_cast<int>(candidates.size());

	while (i < size)
	{
		beg = candidates.begin();

		while (beg != end)
		{
			int totalVote = beg->getTotalVotes();

			if (i == 0)
			{
				if (totalVote > highest)
				{
					highest = totalVote;
					next = highest;
					winner = beg;
				}

				++beg;
			}
			else
			{
				if (totalVote > next && totalVote < highest)
				{
					next = totalVote;
					winner = beg;
				}

				if (totalVote == highest - 1)
					beg = end;
				else
					++beg;
			}
		}

		++i;
		highest = next;
		next = 0;

		printCandidate(winner, i);
	}

	cout << string(39, '_') << endl;
}

void CandidateList::printCandidate
		(list<CandidateType>::const_iterator it, int rank) const
{
	cout << left << setw(15) << it->getLastName();
	cout << left << setw(10) << it->getFirstName();
	cout << setw(5) << right << it->getTotalVotes();
	cout << left << setw(7) << right << rank << endl;

	if (rank % 5 == 0)
		cout << string(39, '-') << endl;
}

CandidateList::~CandidateList() {}

bool CandidateList::searchCandidate(int id, 
				list<CandidateType>::const_iterator& it) const
{
	if (isEmpty())
		cerr << "    => List is empty." << endl;
	else
	{
		it = find(candidates.begin(), candidates.end(), id);
		
		if (it != candidates.end())
			return true;
		else
			cout << "    => ID not in the list." << endl;
	}

	return false;
}