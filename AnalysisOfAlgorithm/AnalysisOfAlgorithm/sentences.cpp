#include"sentences.h"
bool Sentences::isContains(string s) const
{
	return find(s) != -1;
}

int Sentences::find(string s) const
{
	size_t lenght = s.length();
	int i = 0;
	for (string var : wordList)
	{
		int count = 0;
		int lim;
		if (lenght >= var.length())
			lim = var.length();
		else
			lim = lenght;
			for (int i = 0; i < lim; i++)
			{
				if (tolower(s[i]) ==tolower( var[i]))
					count++;
			}
		
		if (count == lim)
			return i;
		i++;
	}
	return -1;
}

void Sentences::addWord(string w)
{

	if (w.length() == 0)
		return;
	if (w[w.length() - 1] == '.' || w[w.length() - 1] == '?' || w[w.length() - 1] == ',')
		w.resize(w.length() - 1);
	wordList.push_back(w);
	lenght++;
}
void Sentences::removeWord(int i)
{
	wordList.erase(wordList.begin() + i);
	lenght--;
}
int Sentences::_lenght()
{
	return lenght;
}

string Sentences::at(int i)
{	

	return wordList.at(i);
}

string Sentences::toString()
{
	string s = "";
	for (string a : wordList)
		s.append(a+" ");
	return s;
}
