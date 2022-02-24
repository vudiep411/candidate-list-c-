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

#include "InputHandler.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void displayMenu();
void processChoice(CandidateList& candidateList);

/*********************************************
* FUNCTION ADDED FOR SELECTION #6
*********************************************/
void colorSelection();

int main()
{
	CandidateList candidateList;

	readCandidateData(candidateList);
	displayMenu();
	processChoice(candidateList);

	cout  <<  endl;
	system("Pause");
	return 0;
}

void displayMenu()
{
	cout << "\n*** MAIN MENU ***\n";
	cout << "\nSelect one of the following:\n\n";
	cout << "    1: Print all candidates" << endl;
	cout << "    2: Print a candidate's kingdom votes" << endl;
	cout << "    3: Print a candidate's total votes" << endl;
	cout << "    4: Print winner" << endl;
	cout << "    5: Print final results" << endl;
	cout << "    6: Change text color" << endl;
	cout << "    7: To exit" << endl;
}

void colorSelection()
{
	cout << "Choose your text color, select one of the following:\n";
	cout << "    1: Blue" << endl;
	cout << "    2: Green" << endl;
	cout << "    3: Aqua" << endl;
	cout << "    4: Red" << endl;
	cout << "    5: Purple" << endl;
	cout << "    6: Yellow" << endl;
	cout << "    7: Gray" << endl;
	cout << "    8: Light Red" << endl;

	int choice;
	cout << "\nEnter your choice: ";
	cin >> choice;

	switch (choice)
	{
	case 1:
		system("Color 01");
		break;

	case 2:
		system("Color 02");
		break;

	case 3:
		system("Color 03");
		break;

	case 4:
		system("Color 04");
		break;

	case 5:
		system("Color 05");
		break;

	case 6:
		system("Color 06");
		break;

	case 7:
		system("Color 08");
		break;

	case 8:
		system("Color 0C");
		break;

	default:
		cout << "\n    => Sorry. That is not a selection." << endl;
	}
}

void processChoice(CandidateList& candidateList)
{
	int choice;
	cout << "\nEnter your choice: ";
	cin >> choice;

	while (choice != 7)
	{
		string fName, lName;
		int kingdom = 0,
			     id = 0;

		switch (choice)
		{
			// Print all candidates
		case 1:
			cout << endl;
			if (candidateList.isEmpty())
				cerr << "*** List is empty.\n";
			else
				candidateList.printAllCandidates();
			break;

			// Print a candidates's kingdom votes
		case 2:
			cout << endl;
			if (candidateList.isEmpty())
				cerr << "*** List is empty.\n";
			else
			{
				cout << "Enter candidate's ID number: ";
				cin >> id;
				cout << endl;
				if (candidateList.searchCandidate(id))
				{
					candidateList.printCandidateName(id);
					cout << endl;
					for (int i = 0; i < NUM_OF_KINGDOMS; ++i)
						candidateList.printKingdomVotes(id, i);
				}
			}
			break;

			// Print a candidate's total votes
		case 3:
			cout << endl; 
			if (candidateList.isEmpty())
				cerr << "*** List is empty.\n";
			else
			{
				cout << "Enter candidate's ID number: ";
				cin >> id;
				cout << endl;
				if (candidateList.searchCandidate(id))
				{
					candidateList.printCandidateName(id);
					cout << endl;
					candidateList.printCandidateTotalVotes(id);
				}
			}
			break;

				// Print winner
		case 4:
			cout << endl; 
			if (candidateList.isEmpty())
				cerr << "*** List is empty.\n";
			else
			{
				id = candidateList.getWinner();
				if (id != 0)
				{
					cout << "Election winner: ";
					candidateList.printCandidateName(id);
					cout << endl;
					candidateList.printCandidateTotalVotes(id);
				}
				else
				{
					cout << "\n    => There are no candidates." << endl;
				}
			}
			break;

			// Print final results
		case 5:
			cout << endl; 
			if (candidateList.isEmpty())
				cerr << "*** List is empty.\n";
			else
				candidateList.printFinalResults();
			break;

			//color selection
		case 6:
			colorSelection();
			break;

		default:
			cout << "\n    => Sorry. That is not a selection." << endl;
		}

		cout << endl;
		system("Pause");
		displayMenu();
		cout << "\nEnter your choice: ";
		cin >> choice;
	}

	if (choice == 7)
		cout << "\n*** Thank you and have a great day!" << endl;
}