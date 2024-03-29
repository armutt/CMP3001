#include<iostream>
#include<Windows.h>
#include<fstream>
#include<conio.h>
#include"sentences.h"
#include<ctime>

using namespace std;

void errorbox(string s);
vector<Sentences*>ss;
vector<Sentences*>questions;
vector<string> commonwords= { "how","what","who","why","where","many","much","where","are","do","time","color" };

void setSentences() 
{

	fstream input("the_truman_show_script.txt");
	if (input.is_open())
	{

		ss.push_back(new Sentences);
		while (!input.eof()) 
		{
			string w;
			input >> w;
			
				if (w.length() > 2||isdigit(w[0]))
					ss.at(ss.size() - 1)->addWord(w);
			if (w.length()>0)
				if (w[w.length() - 1] == '.' || w[w.length() - 1] == '?')
				{
					if (ss.at(ss.size() - 1)->_lenght() < 4)
						ss.pop_back();
					ss.push_back(new Sentences);
				}
		}
		input.close();
		return;
	}
	else 
	{
		errorbox("the_truman_show_script.txt couldn't open");
		return ;
	}
}
Sentences answer(Sentences);
void setQuestions()
{
	fstream input("questions.txt");
	if (input.is_open())
	{
		questions.push_back(new Sentences);
		while (!input.eof())
		{
			string s;
			input >> s;
			if(s.length()>2||isdigit(s[0]))
			questions.at(questions.size() - 1)->addWord(s);
			if (s[s.length() - 1] == '?')
				questions.push_back(new Sentences);
		}
		input.close();
		return;
	}
	else
	{
		errorbox("question.txt couldn't open");
		return;
	}
}

int main() 
{
	clock_t c = clock();
	setSentences();
	setQuestions();

	for (Sentences* s : questions)
	{
		for (size_t i = 0; i < commonwords.size(); i++)
		{
			int a=s->find(commonwords[i]);
			if (a != -1)
				s->removeWord(a);
		}
		
	}
	for (int i = 0; i < 8; i++) {
		Sentences a = answer(*questions.at(i));
		cout << a.toString()<<endl;
	}
	cout << (clock()-c)/1000.0<<"sec"<<endl;
	return 0;
}

Sentences answer(Sentences question) {
	vector<Sentences> temp;
	for (Sentences* s: ss) {
		if(s->_lenght()>=question._lenght())
		temp.push_back(*s);
	}
	for (size_t i = 0; i < question._lenght(); i++)
	{
		int j = 0;
		while (j<temp.size())
		{
			int find = temp.at(j).find(question.at(i));
			if (find == -1)
				temp.erase(temp.begin() + j);
			else
			{
				temp.at(j).removeWord(find);
				j++;
			}
		}

	}
	if (temp.at(0).isContains("the"))
		temp.at(0).removeWord(temp.at(0).find("the"));
	return temp.at(0);
}

void errorbox(string s = "ERROR!!") {

	MessageBoxA(NULL, s.c_str(), NULL, MB_OK | MB_ICONSTOP);
}