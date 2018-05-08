#include <iostream> 
#include <string>
#include <vector>
#include <fstream>
#include <dirent.h>
#include <iterator>
using namespace std;
class Search
{
	int files = 0, counter = 0, repeat = 0, WordExist=0,FileCount=0;
	//WIN32_FIND_DATA find;
	DIR *dp;
	struct dirent *ep;
	string  strWords[1000],line, path = "C:\\Users\\lenovo\\Desktop\\ay7aga2\\Many\\", NewPath, search;

	vector<string> Filname;


 void Display(string);

 void Divide_To_Words(string line);

 void Count_Repetation(string word);

 void FirstThreeLines();

 void FileExist();

 void Choose();

 void Names();

 void OpenFile();

public:
	 Search();
     Search(std::string);
	~Search();
};

