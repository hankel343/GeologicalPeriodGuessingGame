#include <iostream>
#include <ctime>
#include <string>

using namespace std;

enum Period { NEOGENE, PALEOGENE, CRETACEOUS, JURASSIC, TRIASSIC, PERMIAN, CARBONIFEROUS, DEVONIAN, SILURIAN, ORDOVICIAN, CAMBRIAN, PRECAMBRIAN };

int GenerateNum();
//Post: Computer has generated a random number from the set {23, 65, 136, 192, 225, 280, 345, 395, 435, 500, 570, 570, 4500}

void ToUpper(string& answer);
//Pre:User has entered a valid string
//Post: Function returns the user's input in all caps

Period IntToEnum(int randomNum);
//Pre: The computer has generated a random number and passed it as an argument to the function
//Post: Function returns a enumerator of type Period

string EnumToString(Period period);
//Pre: Function is passed a enumerator of type Period
//Post: Function returns a string that corresponds to the input enumerator.

int main()
{
	string answer;

	do
	{
		bool Loop = true;
		int randomNum = GenerateNum();
		string period = EnumToString(IntToEnum(randomNum));

		cout << "\n\nThe computer has generated a random number that is the starting date of a geological period.\n";
		cout << "Do you know what the name of this starting period is?\n";
		cout << "Period starting date: " << randomNum << endl;
		cout << "Enter your answer: ";
		cin >> answer;

		ToUpper(answer);

		while (Loop)
		{
			if (answer == period)
			{
				cout << "You're right!\n";
				cout << randomNum << " marks the beginning of the " << EnumToString(IntToEnum(randomNum)) << " period.";

				Loop = false;
			}
			else
			{
				cout << "Nope - try again: ";
				cin >> answer;
				ToUpper(answer);
			}
		}
		cout << "\n\nWould you like to try again? [Y/N]\n";
		cout << "Answer: ";
		cin >> answer;
	} while (toupper(answer.at(0) != 'N'));

	cout << "\n\nGo study...\n";

	return 0;
}

int GenerateNum()
{
	int numbers[] = { 23, 65, 136, 192, 225, 280, 345, 395, 435, 500, 570, 4500 };
	int length = sizeof(numbers) / sizeof(int);
	srand(time(0));
	int randomNumber = numbers[rand() % length];

	return randomNumber;
}

void ToUpper(string& answer)
{
	for (int i = 0; i <= (answer.length() - 1); i++)
	{
		answer[i] = toupper(answer[i]);
	}
}

Period IntToEnum(int randomNum)
{

	switch (randomNum)
	{
	case 23:
		return NEOGENE;

	case 65:
		return PALEOGENE;

	case 136:
		return CRETACEOUS;

	case 192:
		return JURASSIC;

	case 225:
		return TRIASSIC;

	case 280:
		return PERMIAN;

	case 345:
		return CARBONIFEROUS;

	case 395:
		return DEVONIAN;

	case 435:
		return SILURIAN;

	case 500:
		return ORDOVICIAN;

	case 570:
		return CAMBRIAN;

	case 4500:
		return PRECAMBRIAN;

	default:
		return PRECAMBRIAN;
	}
}

string EnumToString(Period period)
{
	switch (period)
	{
	case NEOGENE:
		return "NEOGENE";

	case PALEOGENE:
		return "PALEOGENE";

	case CRETACEOUS:
		return "CRETACEOUS";

	case JURASSIC:
		return "JURASSIC";

	case TRIASSIC:
		return "TRIASSIC";

	case PERMIAN:
		return "PERMIAN";

	case CARBONIFEROUS:
		return "CARBONIFEROUS";

	case DEVONIAN:
		return "DEVONIAN";

	case SILURIAN:
		return "SILURIAN";

	case ORDOVICIAN:
		return "ORDOVICIAN";

	case CAMBRIAN:
		return "CAMBRIAN";

	case PRECAMBRIAN:
		return "PRECAMBRIAN";
	}
}