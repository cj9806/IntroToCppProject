#include <cstdlib>
#include <iostream>
#include <ctime>
#include <string>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::fstream;
using std::ifstream;
using std::ios;

//make a text file
void makeTextFile() {
	string choice;
	cout << "Please provide a filename to save your data into:" << endl;
	cin >> choice;
	choice = choice + ".txt";
	fstream towrite;
	towrite.open(choice, ios::out);
	if (towrite.is_open())
	{
		cout << "What is your Name" << endl;
		string name;
		cin >> name;

		cout << "How old are you" << endl;
		string age;
		cin >> age;
		cout << "What is your favorite colour" << endl;
		string colour;
		cin >> colour;
		cout << "Please solve this equation: 2+2" << endl;
		string math;
		cin >> math;
		if (math == "4")
		{
			math = "can do math";
		}
		else math = "can't do math";
		std::fstream out(choice);
		out <<"Name: "<< name << endl;
		out <<"Age: "<< age << endl;
		out <<"Favorite colour: "<< colour << endl;
		out <<"Can they do math: "<< math << endl;
	}
	else
	{
		cout << "An unexpected error has occured\n program will now terminate" << endl;
	}
	towrite.close();
}

void digitalPrinter()
{
	string line;
	cout << "Please give the name of the text file you would like to read" << endl;
	string toread;
	cin >> toread;
	toread = toread + ".txt";
	ifstream file_(toread);
	if (file_.is_open())
	{
		while (getline(file_, line))
		{
			cout << line << "\n";
		}
		file_.close();
	}
	else cout << "file not Found" << endl;
}
int main()
{
	string choice;
	bool running = true;
	while (running)
	{
		cout << "please select 1 or 2\n1)Read an Exsisting text file.\n2)Write a baisic biography about yourself" << endl;
		cin >> choice;
		if (choice == "1")
		{
			running = false;
			digitalPrinter();
		}
		else if (choice == "2")
		{
			running = false;
			makeTextFile();
		}
		else {
			cout << "I do not understand\n" << endl;
		}
	}
	
	return 0;
}
