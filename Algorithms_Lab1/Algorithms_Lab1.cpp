#include <iostream>
#include <conio.h>
#include <string>
#include <fstream>
#include <string.h>
using namespace std;

//минимальная длинна слова
const int MINLENGHTWORD = 2;

class Reader
{
public:
	string GetFilenameFromUser();
	void InputFromFile(string filename);
	bool WhetherCharacterPunctuationMark();
	void ThereIsNoWordHyphenationError();
	void ShowHyphenationOptions();
	bool StringContainsNumbers();
	Reader();
	~Reader();

private:
	char simbol_;
	//символ слова которй будет
	//конкатенироваться с пустой строкой для получаения слова
	string word;
	//длина слова
	int word_lenght;
	//проверка закончилось ли слово
	bool word_ends;
};

string Reader::GetFilenameFromUser()
{
	cout << "Введите название файла: ";
	string filename;
	cin >> filename;
	return filename;
}

void Reader::InputFromFile(string filename)
{
	ifstream file(filename);
	// пока не является заком припинания 
	// или пробелом 
	// или числом
	// вводим слово
	for (file >> word; !file.eof(); file >> word)
	{
		cout << word << endl;
	}
}

bool Reader::WhetherCharacterPunctuationMark()
{
	char dictionary[] ={ '.',
	  ',',
	  ';',
	  ':',
	  '.',
	  '!',
	  '?',
	};
	for (int i = 0; i < 8; i++)
	{
		if (simbol_ == dictionary[i])
		{
			return true;
		}
	}
}

void Reader::ThereIsNoWordHyphenationError()
{
	cout << "Слово " 
		<< word << "не иммеет вариантов переноса!"
			<< endl;
}

void Reader::ShowHyphenationOptions()
{
	if (word_lenght < MINLENGHTWORD) { ThereIsNoWordHyphenationError(); return; }
	else
	{
		char* word_c = new char[word_lenght];
		strcpy(word_c, word.c_str());
		int j = 0;
		int j_temp;
		cout << "Варианты переноса:\n";
		for (int i = 0; i < word_lenght; i++)
		{
			cout << i + 1 << ") ";
			cout << word_c[j];
			j++;
			j_temp = j;
			while (j < word_lenght)
			{
				cout << word_c[j];
				j++;
			}
			j = j_temp;
		}
		delete[] word_c;
	}
}

bool Reader::StringContainsNumbers()
{
	for (int i = 0; i < 8; i++)
	{
		if (simbol_ < 57 && simbol_ > 48)
		{
			return true;
		}
	}
}

Reader::Reader()
{
	simbol_ = '.';
	word = "";
	word_lenght = 0;
}

Reader::~Reader()
{
}

int main()
{
	system("chcp 1251");
	system("cls");
	class Reader Reader;
	Reader.InputFromFile(Reader.GetFilenameFromUser());
	return 0;
}