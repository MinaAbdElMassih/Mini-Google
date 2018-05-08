#include <iostream> 
#include <string>
#include <fstream>
#include <string.h>
#include <dirent.h>
#include <iterator>
#include "Search.h"
using namespace std;

int main() {

	while (true)
	{
		cout << "Enter Word ?" << endl;
		string word;
		cin >> word; 
		system("cls");
		Search search(word);
	}


}
