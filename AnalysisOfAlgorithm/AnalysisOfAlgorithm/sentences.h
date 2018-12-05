#pragma once
#include<string>
#include<vector>
using std::string;
using std::vector;

class Sentences
{
	int lenght = 0;
	vector<string> wordList;

public:

	bool isContains(string)const;
	int find(string)const;
	void addWord(string);
	void removeWord(int s);
	int _lenght();
	string at(int);
	string toString();
};