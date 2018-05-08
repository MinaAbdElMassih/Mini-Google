#include "Search.h"
#include <iostream> 
#include <fstream>
#include <dirent.h>
#include <iterator>
using namespace std;

Search::Search()
{


}

Search::Search(string word)
{
	const char *dirname = "C:\\Users\\lenovo\\Desktop\\ay7aga2\\Many\\";
	dp = opendir(dirname);
	ep = readdir(dp);


	if (dp != NULL)
	{

		while (ep == readdir(dp))
		{

			int compare1 = strcmp(ep->d_name, ".");
			int compare2 = strcmp(ep->d_name, "..");


			if (compare1 == 0 || compare2 == 0)
				continue;


			NewPath = path + ep->d_name;
			//cout << NewPath << endl;
			ifstream take(NewPath);
				while (!take.eof())
			{
				WordExist = 0;
				while (getline(take, line))
				{
					//cout << line << endl;
					counter = 0;
					Divide_To_Words(line);
					Count_Repetation(word);

				}
				if (WordExist > 0)
					FileExist();
			}


			files++;
			if (files == 50)
				break;

		}

		if (repeat == 0) {
			cout << "Word Not Found " << endl << endl;
			cout << "Press any Key To Continue " << endl;
			char x;
			cin >> x;
			return;
		}


		Display(word);
		Choose();

	}
}

void Search::Choose() {
	int Go =1;

	cout << "The Word Was Found in " << FileCount << " Files" << endl << endl;
	while (true)
	{



		cout << "Would you like To :- " << endl << endl;

		cout << "  1 -> Show All File Names That Found In the Search" << endl << endl;

		cout << "  2 -> Display First three Lines of KEYWORD Files" << endl << endl;

		cout << "  3 -> Open Specific File" << endl << endl;

		cout << "  4 -> Another Search" << endl << endl;
		cin >> Go;
		if (Go == 1)
			Names();
		else if (Go == 2)
			FirstThreeLines();
		else if (Go == 3)
			OpenFile();
		else if (Go == 4)
			return;
		else
		{
			cout << "Wrong Choice " << endl;
			continue;
		}

	}
}

void Search::Divide_To_Words(string line) {


	for (int i = 0; i < line.length(); i++)
	{

		if (line[i] == ',' || line[i] == '"' || line[i] == ';' || line[i] == '،')continue;

		if (line[i] == ' ')
			counter++;

		else

			strWords[counter] = strWords[counter] + line[i];  

	}
}

void Search::Count_Repetation(string word) {

	for (size_t i = 0; i < counter; i++)
	{
		if (word == strWords[i])
		{
			WordExist++;
			repeat++;
		}

	}

	// erase th string
	for (size_t i = 0; i < counter; i++)
	{
		strWords[i].clear();
	}

}

void Search::FileExist() {

	FileCount++;
	string na = ep->d_name;
	Filname.push_back(na);


}

void Search::Display(string word) {

	cout << "The word '" << word << "' is Repeated " << repeat << " Times" << endl << endl;

}

void Search::FirstThreeLines() {

	for (size_t i = 0; i < Filname.size(); i++)
	{
		int Lines = 0;
		string Path2 = path + Filname[i], Store;

		ifstream input(Path2);
		cout << Filname[i] << endl;
		while (getline(input, Store))
		{
			cout << Store << endl;
			Lines++;
			if (Lines == 3)break;
		}

		cout << endl << endl << endl;
	}
}

void Search::OpenFile() {
	string Name, newpath, li;
	cout << "Type The file Name/Number" << endl;
	cin >> Name;
	if (Name.find(".txt") != string::npos)
		newpath = path + Name;
	else
		newpath = path + Name + ".txt";
	ifstream take(newpath);

	if (take.is_open())
	{
		while (getline(take, li))
		{
			cout << li << endl;
		}
	}
	else
	{
		cout << "The File Does Not Exist Please enter an Exist Name " << endl;
		OpenFile();
	}


}

void Search::Names() {

	for (size_t i = 0; i < Filname.size(); i++)
	{
		cout << Filname[i] << endl;

	}
}

Search::~Search()
{
}
