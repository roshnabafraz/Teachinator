#include <string>
#include <fstream>
#include <iostream>
#include <Windows.h>
#include <iomanip>

using namespace std;

struct Male_Teacher
{
	int Points = 0;
	string HairColor;
	string FacialHair;
	string Clothes;
	string Old;
};

struct Female_Teacher
{
	int Points = 0;
	string Abaya;
	string Glasses;
	string Old;
};

void Starting(HANDLE);
string CheckReplay(HANDLE, string Replay);

// Sending HANDLE in all Functions to use Modified Colours.

void Male(HANDLE h);
void GetMaleDataFromFile(HANDLE, struct Male_Teacher[]); // To get Data of all Male Teachers from a File and Store it in the Structure.
void Male_HairColor(struct Male_Teacher[]); // Asks Teacher's Hair Colour.
void Male_FacialHair(struct Male_Teacher[]); // Asks if  Teacher have Facial Hair.
void Male_Clothes(struct Male_Teacher[]); // Asks what type of Clothes Teacher Wears.
void Male_Old(struct Male_Teacher[]); // Asks if Teacher is Old or Young. 
void Output_Male(HANDLE h, struct Male_Teacher male[], int TotalMaleTeachers, int Male_Questions); // Shows Output of Male Teacher Guessed based on Answers.

void Female(HANDLE h);
void GetFemaleDataFromFile(HANDLE, struct Female_Teacher[]); //To get Data of all Female Teachers from a File and Store it in the Structure.
void Female_Abaya(HANDLE h, struct Female_Teacher[], int TotalFemaleTeachers); // Asks if Teacher wears Abaya.
void Female_Glasses(HANDLE h, struct Female_Teacher[], int TotalFemaleTeachers); // Ask if Teacher wears Glasses.
void Female_Old(HANDLE h, struct Female_Teacher[], int TotalFemaleTeachers); // Ask if Teacher is Old or Young.
void Output_Female(HANDLE h, struct Female_Teacher[], int TotalFemaleTeachers, int Female_Questions); // Shows Output of Female Teacher Guessed based on Answers.

int main()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	Male_Teacher male;
	Female_Teacher female;
	string Replay;

	do {
		system("CLS");
		Starting(h);
		Replay = CheckReplay(h, Replay);
	} while (Replay == "yes");
	SetConsoleTextAttribute(h, 3);
	cout << "\n \n \t \t Thanks for Playing :)" << "\n \n \n";
	SetConsoleTextAttribute(h, 15);

	return 0;
}

void GetMaleDataFromFile(HANDLE h, Male_Teacher male[])
{
	int ctrl = 0;
	int size = 2; //Male Teachers MT1

	fstream f;
	f.open("C:\\Teachinator\\MaleData.txt", ios::in);

	if (f.is_open())
	{
		while (!f.eof() && ctrl < size)
		{
			f >> male[ctrl].HairColor;
			f >> male[ctrl].FacialHair;
			f >> male[ctrl].Clothes;
			f >> male[ctrl].Old;
			ctrl++;
		}
	}

	else
	{
		SetConsoleTextAttribute(h, 4);
		cout << "Error: File is Missing from Disk.\n\n";
		SetConsoleTextAttribute(h, 15);
	}
}

void GetFemaleDataFromFile(HANDLE h, Female_Teacher female[])
{
	int ctrl = 0;
	int size = 3; //Female Teachers FT1

	fstream f;
	f.open("C:\\Teachinator\\FemaleData.txt", ios::in);

	if (f.is_open())
	{
		while (!f.eof() && ctrl < size)
		{
			f >> female[ctrl].Abaya;
			f >> female[ctrl].Glasses;
			f >> female[ctrl].Old;
			ctrl++;
		}
	}
	else
	{
		SetConsoleTextAttribute(h, 4);
		cout << "Error: File is Missing from Disk.\n\n";
		SetConsoleTextAttribute(h, 15);
	}
}

void Male_HairColor(HANDLE h, struct Male_Teacher male[], int TotalMaleTeachers)
{
	string HairColor;

	do
	{
		cout << "\t \t 2. Does the Teacher you're thinking of have ";
		SetConsoleTextAttribute(h, 10);
		cout << "Mixed(Black & White)";
		SetConsoleTextAttribute(h, 15);
		cout << " or ";
		SetConsoleTextAttribute(h, 10);
		cout << "Black";
		SetConsoleTextAttribute(h, 15);
		cout << " Hair ?" << endl << "\t \t ";
		cin >> HairColor;
		cout << endl;

		for (int ctrl = 0; ctrl < HairColor.length(); ctrl++)
		{
			HairColor[ctrl] = tolower(HairColor[ctrl]);
		}

		if (HairColor != "mixed" and HairColor != "black")
		{
			SetConsoleTextAttribute(h, 4);
			cout << "\t \t Reminder: You can only Reply in \"Mixed\" or \"Black\"" << endl << endl;
			SetConsoleTextAttribute(h, 15);
		}
	} while (HairColor != "mixed" and HairColor != "black");

	for (int ctrl = 0; ctrl < TotalMaleTeachers; ctrl++)
	{
		if (HairColor == male[ctrl].HairColor)
		{
			male[ctrl].Points++;
		}
	}
}

void Male_FacialHair(HANDLE h, struct Male_Teacher male[], int TotalMaleTeachers)
{
	string FacialHair;

	do {
		cout << "\t \t 3. Does the Teacher you're thinking of have ";
		SetConsoleTextAttribute(h, 10);
		cout << "Mustache";
		SetConsoleTextAttribute(h, 15);
		cout << " or ";
		SetConsoleTextAttribute(h, 10);
		cout << "Beard";
		SetConsoleTextAttribute(h, 15);
		cout << " ?" << endl << "\t \t ";
		cin >> FacialHair;
		cout << endl;

		for (int ctrl = 0; ctrl < FacialHair.length(); ctrl++)
		{
			FacialHair[ctrl] = tolower(FacialHair[ctrl]);
		}

		if (FacialHair != "mustache" and FacialHair != "beard")
		{
			SetConsoleTextAttribute(h, 4);
			cout << "\t \t Reminder: You can only Reply in \"Mustache\" or \"Beard\"" << endl << endl;
			SetConsoleTextAttribute(h, 15);
		}
	} while (FacialHair != "mustache" and FacialHair != "beard");

	for (int ctrl = 0; ctrl < TotalMaleTeachers; ctrl++)
	{
		if (FacialHair == male[ctrl].FacialHair)
		{
			male[ctrl].Points++;
		}
	}
}

void Male_Clothes(HANDLE h, struct Male_Teacher male[], int TotalMaleTeachers)
{
	string Clothes;
	string Temp;

	do {
		cout << "\t \t 4. Does the Teacher you're thinking of wears";
		SetConsoleTextAttribute(h, 10);
		cout << " Shalwar Kameez";
		SetConsoleTextAttribute(h, 15);
		cout << " or ";
		SetConsoleTextAttribute(h, 10);
		cout << "Pant Shirt";
		SetConsoleTextAttribute(h, 15);
		cout << " often ? " << endl << "\t \t ";
		cin >> Clothes >> Temp;
		cout << endl;

		for (int ctrl = 0; ctrl < Clothes.length(); ctrl++)
		{
			Clothes[ctrl] = tolower(Clothes[ctrl]);
		}

		if (Clothes != "shalwar" and Clothes != "pant")
		{
			SetConsoleTextAttribute(h, 4);
			cout << "\t \t Reminder: You can only Reply in \"Shalwar Kameez\" or \"Pant Shirt\"" << endl << endl;
			SetConsoleTextAttribute(h, 15);
		}
	} while (Clothes != "shalwar" and Clothes != "pant");

	for (int ctrl = 0; ctrl < TotalMaleTeachers; ctrl++)
	{
		if (Clothes == male[ctrl].Clothes)
		{
			male[ctrl].Points++;
		}
	}
}

void Male_Old(HANDLE h, struct Male_Teacher male[], int TotalMaleTeachers)
{
	string Old;

	do {
		cout << "\t \t 5. Is the Teacher you're thinking of Aged Above 35 Years?" << endl << "\t \t ";
		cin >> Old;
		cout << endl;

		for (int ctrl = 0; ctrl < Old.length(); ctrl++)
		{
			Old[ctrl] = tolower(Old[ctrl]);
		}

		if (Old != "yes" and Old != "no")
		{
			SetConsoleTextAttribute(h, 4);
			cout << "\t \t Reminder: You can only Reply in \"Yes\" or \"No\"" << endl << endl;
			SetConsoleTextAttribute(h, 15);
		}
	} while (Old != "yes" and Old != "no");

	for (int ctrl = 0; ctrl < TotalMaleTeachers; ctrl++)
	{
		if (Old == male[ctrl].Old)
		{
			male[ctrl].Points++;
		}
	}
}

void Male(HANDLE h)
{
	int const TotalMaleTeachers = 2; // Male Teachers MT2
	int Male_Questions = 4;
	Male_Teacher male[TotalMaleTeachers];

	GetMaleDataFromFile(h, male);
	Male_HairColor(h, male, TotalMaleTeachers);
	Male_FacialHair(h, male, TotalMaleTeachers);
	Male_Clothes(h, male, TotalMaleTeachers);
	Male_Old(h, male, TotalMaleTeachers);
	Output_Male(h, male, TotalMaleTeachers, Male_Questions);
}

void Female(HANDLE h)
{
	int const TotalFemaleTeachers = 3; // Female Teachers FT2
	int Female_Questions = 3;
	Female_Teacher female[TotalFemaleTeachers];

	GetFemaleDataFromFile(h, female);
	Female_Abaya(h, female, TotalFemaleTeachers);
	Female_Glasses(h, female, TotalFemaleTeachers);
	Female_Old(h, female, TotalFemaleTeachers);
	Output_Female(h, female, TotalFemaleTeachers, Female_Questions);
}

void Output_Female(HANDLE h, struct Female_Teacher female[], int TotalFemaleTeachers, int Female_Questions)
{
	int FemaleTeacherCheck;
	for (int check = 0; check < TotalFemaleTeachers; check++)
	{
		if (female[check].Points == Female_Questions)
		{
			FemaleTeacherCheck = check;
		}
	}

	switch (FemaleTeacherCheck)
	{
	case 0:
		cout << "\t \t You're Thinking of ";
		SetConsoleTextAttribute(h, 10);
		cout << "Ms. Batool Abbas!" << endl << endl;
		SetConsoleTextAttribute(h, 15);
		break;

	case 1:
		cout << "\t \t You're Thinking of ";
		SetConsoleTextAttribute(h, 10);
		cout << "Ms. Maria Tariq" << endl << endl;
		SetConsoleTextAttribute(h, 15);
		break;

	case 2:
		cout << "\t \t You're Thinking of ";
		SetConsoleTextAttribute(h, 10);
		cout << "Ms. Kiran Khalid" << endl << endl;
		SetConsoleTextAttribute(h, 15);
		break;

	default:
		SetConsoleTextAttribute(h, 4);
		cout << "\t \t I'm sorry, I didn't find anyone matching those requiements in BSCS(B).. Please try again!" << endl;
		SetConsoleTextAttribute(h, 15);
		break;
	}
}

void Starting(HANDLE h)
{
	SetConsoleTextAttribute(h, 4);
	cout << "\n \t \t REMINDER: This program determines what teacher you're thinking of by asking some Questions. " << endl;
	cout << "\t \t REMINDER: Use of capital and lowercase letters is allowed. " << endl;
	SetConsoleTextAttribute(h, 10);
	cout << "\t \t Think of a single Teacher from LGU BSCS-B.\n" << endl;
	SetConsoleTextAttribute(h, 15);

	string user;
	do {
		cout << "\t \t 1. Is the Teacher you're thinking of a ";
		SetConsoleTextAttribute(h, 10);
		cout << "Male";
		SetConsoleTextAttribute(h, 15);
		cout << " or ";
		SetConsoleTextAttribute(h, 10);
		cout << "Female";
		SetConsoleTextAttribute(h, 15);
		cout << " ? \t \t" << endl << "\t \t ";
		cin >> user;
		cout << endl;

		for (int ctrl = 0; ctrl < user.length(); ctrl++)
		{
			user[ctrl] = tolower(user[ctrl]);
		}

		if (user != "male" and user != "female")
		{
			SetConsoleTextAttribute(h, 4);
			cout << "\t \t Reminder: You can only Reply with \"Male\" or \"Female\"" << endl << endl;
			SetConsoleTextAttribute(h, 15);
		}
	} while (user != "male" and user != "female");

	if (user == "male")
	{
		Male(h);
	}
	else
	{
		Female(h);
	}
}

void Output_Male(HANDLE h, struct Male_Teacher male[], int TotalMaleTeachers, int Male_Questions)
{
	int MaleTeacherCheck;
	for (int check = 0; check < TotalMaleTeachers; check++)
	{
		if (male[check].Points == Male_Questions)
		{
			MaleTeacherCheck = check;
		}
	}

	switch (MaleTeacherCheck)
	{
	case 0:
		cout << "\t \t You're Thinking of ";
		SetConsoleTextAttribute(h, 10);
		cout << "Mr. Muhammad Arshad!" << endl << endl;
		SetConsoleTextAttribute(h, 15);
		break;

	case 1:
		cout << "\t \t You're Thinking of ";
		SetConsoleTextAttribute(h, 10);
		cout << "Mr. Hafiz Irfanullah!" << endl << endl;
		SetConsoleTextAttribute(h, 15);
		break;

	default:
		SetConsoleTextAttribute(h, 4);
		cout << "\t \t I'm sorry, I didn't find anyone matching those requiements in BSCS(B).. Please try again!" << endl;
		SetConsoleTextAttribute(h, 15);
		break;
	}
}

void Female_Abaya(HANDLE h, struct Female_Teacher female[], int TotalFemaleTeachers)
{
	string Abaya;

	do {
		cout << "\t \t 5. Is the Teacher you're thinking of wears Abaya?" << endl << "\t \t ";
		cin >> Abaya;
		cout << endl;

		for (int ctrl = 0; ctrl < Abaya.length(); ctrl++)
		{
			Abaya[ctrl] = tolower(Abaya[ctrl]);
		}

		if (Abaya != "yes" and Abaya != "no")
		{
			SetConsoleTextAttribute(h, 4);
			cout << "\t \t Reminder: You can only Reply in \"Yes\" or \"No\"" << endl << endl;
			SetConsoleTextAttribute(h, 15);
		}
	} while (Abaya != "yes" and Abaya != "no");

	for (int ctrl = 0; ctrl < TotalFemaleTeachers; ctrl++)
	{
		if (Abaya == female[ctrl].Abaya)
		{
			female[ctrl].Points++;
		}
	}
}

void Female_Glasses(HANDLE h, struct Female_Teacher female[], int TotalFemaleTeachers)
{
	string Glasses;

	do {
		cout << "\t \t 5. Is the Teacher you're thinking of wears Glasses?" << endl << "\t \t ";
		cin >> Glasses;
		cout << endl;

		for (int ctrl = 0; ctrl < Glasses.length(); ctrl++)
		{
			Glasses[ctrl] = tolower(Glasses[ctrl]);
		}

		if (Glasses != "yes" and Glasses != "no")
		{
			SetConsoleTextAttribute(h, 4);
			cout << "\t \t Reminder: You can only Reply in \"Yes\" or \"No\"" << endl << endl;
			SetConsoleTextAttribute(h, 15);
		}
	} while (Glasses != "yes" and Glasses != "no");

	for (int ctrl = 0; ctrl < TotalFemaleTeachers; ctrl++)
	{
		if (Glasses == female[ctrl].Glasses)
		{
			female[ctrl].Points++;
		}
	}
}

void Female_Old(HANDLE h, struct Female_Teacher female[], int TotalFemaleTeachers)
{
	string Old;

	do {
		cout << "\t \t 5. Is the person you're thinking of relatively Young?" << endl << "\t \t ";
		cin >> Old;
		cout << endl;

		for (int ctrl = 0; ctrl < Old.length(); ctrl++)
		{
			Old[ctrl] = tolower(Old[ctrl]);
		}

		if (Old != "yes" and Old != "no")
		{
			SetConsoleTextAttribute(h, 4);
			cout << "\t \t Reminder: You can only Reply in \"Yes\" or \"No\"" << endl << endl;
			SetConsoleTextAttribute(h, 15);
		}
	} while (Old != "yes" and Old != "no");

	for (int ctrl = 0; ctrl < TotalFemaleTeachers; ctrl++)
	{
		if (Old == female[ctrl].Old)
		{
			female[ctrl].Points++;
		}
	}
}

string CheckReplay(HANDLE h, string Replay)
{
	do {
		SetConsoleTextAttribute(h, 2);
		cout << endl << "\t \t Do you want to run the program again?" << endl << "\t \t ";
		SetConsoleTextAttribute(h, 15);
		cin >> Replay;

		for (int ctrl = 0; ctrl < Replay.length(); ctrl++)
		{
			Replay[ctrl] = tolower(Replay[ctrl]);
		}
		if (Replay != "yes" && Replay != "no")
		{
			SetConsoleTextAttribute(h, 4);
			cout << "\t \t You can only respond with \"Yes\" or \"No\"" << endl << endl;
			SetConsoleTextAttribute(h, 15);
		}
	} while (Replay != "yes" && Replay != "no");
	return Replay;
}