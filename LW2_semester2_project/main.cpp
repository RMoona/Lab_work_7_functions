#include <iostream>
#include <string>
#include <cctype>

using namespace std;

void uppercaseLowercaseConverter(char* s);
void uppercaseLowercaseConverter(string& s);

int main()
{
	int studentCode = 83859;
	int taskVarCount = 25;

	cout << "Task number: " << studentCode % taskVarCount << endl;
	cout << "-------------------------------------------------------" << endl;

	const int rows = 2;
	const int columns = 3;
	const int maxLength = 101;

	char* cStringArr[rows][columns];
	cout << "Enter array elements, each element up to " << maxLength - 1 << " characters:" << endl;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			cStringArr[i][j] = new char[maxLength];
			cin.getline(cStringArr[i][j], maxLength);
		}
	}

	string stringArrCopy[rows][columns];
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			stringArrCopy[i][j] = cStringArr[i][j];
		}
	}

	cout << "\nConverted C-strings:" << endl;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			if (cStringArr[i][j][0] != '\0')
			{
				if (isalpha(cStringArr[i][j][0]))
				{
					uppercaseLowercaseConverter(cStringArr[i][j]);
					cout << cStringArr[i][j] << "\t";
				}
			}
		}
		cout << endl;
	}

	cout << "\nConverted C++ strings:" << endl;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			uppercaseLowercaseConverter(stringArrCopy[i][j]);
			cout << stringArrCopy[i][j] << "\t";
		}
		cout << endl;
	}


	return 0;
}

void uppercaseLowercaseConverter(char* s)
{
	if (islower(*s))
	{
		*s = toupper(*s);
	}

	for (int i = 1; s[i] != '\0'; i++)
	{
		if (isupper(s[i]))
		{
			s[i] = tolower(s[i]);
		}
	}
}

void uppercaseLowercaseConverter(string& s)
{
	if (islower(s[0]))
	{
		s[0] = toupper(s[0]);
	}

	for (size_t i = 1; i < s.length(); i++)
	{
		if (isupper(s[i]))
		{
			s[i] = tolower(s[i]);
		}
	}
}