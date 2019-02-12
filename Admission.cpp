

/*Name : Hafiz Muneeb ur Rehman
Roll No. : BCSF15M030
Project: Admission System*/

#include"Admission.h"

/******************************************
		Implementation of Info class
******************************************/
Info::Info()
{
	cName = "";
	cFName = "";
	matricMarks = 0;
	interMarks = 0;
	CGPA = 0;
	testMarks = 0;
	hafizQuranMarks = 20;
	interviewMarks = 0;
}

/**********************************
Getter, setter of Info class
***********************************/

void Info::setCName(string s)	{ cName = s; }

void Info::setCFName(string s) { cFName = s; }

void Info::setMatricMarks(float m) { matricMarks = m; }

void Info::setInterMarks(float m) { interMarks = m; }

void Info::setCGPA(float m) { CGPA = m; }

void Info::setTestMarks(float m) { testMarks = m; }

void Info::setHafizQuranMarks(float m) { hafizQuranMarks = m; }

void Info::setInterviewMarks(float m) { interviewMarks = m; }

string Info::getCName() { return cName; }

string Info::getCFName() { return cFName; }

double Info::getMatricMarks() { return matricMarks; }

double Info::getInterMarks() { return interMarks; }

double Info::getCGPA() { return CGPA; }

double Info::getTestMarks() { return testMarks; }

double Info::getHafizQuranMarks() { return hafizQuranMarks; }

double Info::getInterviewMarks() { return interviewMarks; }

double Info::getMerit() { return merit; }

void Info::setIndex(int i) { index = i; }

int Info::getIndex() { return index; }

void Info::setMerit(float m) { merit = m; }

void Info::calcMerit(bool checkCase)
{
	/*
	formula for undergraduate
	merit=100*( marks earned(1/4 of matric+ FA/FSC + test + Hafiz e quran) ) / (  total marks(1/4 of matric + FA/Fsc + test ) )
	formula for graduation
	merit=100*( marks earned(1/4 of matric+ 1/5 of FA/FSc + BA/BSc + test + interview + Hafiz e quran) ) / (  total marks(1/4 of matric + 1/5 of FA/FSc + BA/BSc+ test + interview ) )
	total matric=1050
	total inter=1100
	total BA/BSc=4.0
	total test=60
	total interview=40
	*Hafiz e Quran = 20
	Total for undergraduate=1422.5
	Total for graduate=586.5
	*/
	if (checkCase)
	{
		merit = (100 * (((matricMarks / 4) + (interMarks / 5) + CGPA + testMarks + interviewMarks + hafizQuranMarks) / (586.5)));
		if (merit > 100)
			merit = 99.99;
	}
	else
	{
		merit = (100 * (((matricMarks / 4) + interMarks + testMarks + hafizQuranMarks) / (1422.5)));
		if (merit > 100)
			merit = 99.99;
	}
}
/*******************************************
setCursor function set/place cursor in
particular position
********************************************/
void setCursor(HANDLE screen, int row, int col)
{
	COORD position;
	position.X = col;
	position.Y = row;
	SetConsoleCursorPosition(screen, position);
}

/*****************************************
welcomeScreen function prints welcome 
messege
******************************************/
void welcomeScreen()
{
	system("color 2F");
	HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
	setCursor(screen, 3, 50);
	cout << "***********************************************";
	setCursor(screen, 4, 50);
	cout << "* Welcome to Admission System of Rise College *";
	setCursor(screen, 5, 50);
	cout << "***********************************************";
}

/***************************
drawBoundary draw  boundry
across admission form
****************************/
void  drawBoundary()
{
	HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
	setCursor(screen, 1, 2);
	for (int bound = 0; bound < 90; bound++)
		cout << char(220);
	setCursor(screen, 44, 2);
	for (int bound = 0; bound < 90; bound++)
		cout << char(220);
	setCursor(screen, 30, 2);
	for (int bound = 0; bound < 90; bound++)
		cout << char(220);
	for (int i = 2; i < 45; i++)
	{
		setCursor(screen, i, 2);
		cout << char(178);
	}
	for (int i = 2; i < 45; i++)

	{
		setCursor(screen, i, 91);
		cout << char(178);
	}
}

/*************************************************
if user want to enter more records of students
printForm function prints data entry form for user
**************************************************/

void printForm(int i, bool checkCase)
{
	HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
	system("CLS");
	drawBoundary();
	setCursor(screen, 3, 25);
	cout << "****************************************";
	setCursor(screen, 4, 25);
	cout << "*	    Data Entry Form # " << i + 1 << "	 *";
	setCursor(screen, 5, 25);
	cout << "****************************************";
	setCursor(screen, 6, 5);
	cout << "PERSONAL INFORMATION";
	setCursor(screen, 8, 10);
	cout << "Name*: ";
	setCursor(screen, 8, 47);
	cout << "Father Name*: ";
	setCursor(screen, 10, 5);
	cout << "ACADEMIC RECORDS";
	setCursor(screen, 12, 10);
	cout << "Matric Marks (1050): ";
	setCursor(screen, 13, 10);
	cout << "Intermediate Marks (1100): ";
	setCursor(screen, 14, 10);
	cout << "Test Marks (60): ";
	setCursor(screen, 15, 10);
	cout << "Hafiz (press y if yes otherwise press any key to continue): ";
	if (checkCase)
	{
		setCursor(screen, 16, 10);
		cout << "CGPA (4.0): ";
		setCursor(screen, 17, 10);
		cout << "Interview Marks (40): ";
	}
	setCursor(screen, 34, 10);
	cout << "Minimum Criteria : 50.00%";
	setCursor(screen, 35, 10);
	cout << "* Maximum length of Candidate name and his father name is 26 letters.";
}

/*******************************************
fillForm function gets data and store in a
file for futher processing
*******************************************/

void fillForm(int i, bool checkCase)
{
	HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
	ofstream write;
	if (checkCase)
	{
		write.open("Student Records MS.txt", ios::app);
		if (!write)
			cout << "Error opening file\n";
	}
	else
	{
		write.open("Student Records.txt", ios::app);
		if (!write)
			cout << "Error opening file\n";
	}
	char name[28], fName[28], hafiz;
	float matric, inter, BS, test, interview;
	setCursor(screen, 8, 17);
	cin.ignore();
	char terminate = 'a';
	bool flag = true;
	int position = 17, getc = 0;
	while (getc <= 25 && flag)
	{
		terminate = _getche();
		if (terminate == 10 || terminate == 13)
			flag = false;
		else if (terminate == 8)
		{
			--getc;
			--position;
			setCursor(screen, 8, position);
			cout << " ";
			setCursor(screen, 8, position);
		}
		else
		{
			name[getc] = terminate;
			++position;
			++getc;
		}
	}
	name[getc] = '\0';
	setCursor(screen, 8, 61);
	terminate = 'a';
	flag = true;
	position = 61;
	getc = 0;
	while (getc <= 25 && flag)
	{
		terminate = _getche();
		if (terminate == 10 || terminate == 13)
			flag = false;
		else if (terminate == 8)
		{
			--getc;
			--position;
			setCursor(screen, 8, position);
			cout << " ";
			setCursor(screen, 8, position);
		}
		else
		{
			fName[getc] = terminate;
			++position;
			++getc;
		}
	}
	fName[getc] = '\0';
	//academic records
	setCursor(screen, 12, 32);
	cin >> matric;
	while (matric > 1050 || matric < 0)
	{
		cin.clear();
		cin.ignore(100, '\n');
		setCursor(screen, 20, 10);
		cout << "Wrong input ! Enter again : ";
		Sleep(1000);
		setCursor(screen, 12, 32);
		for (int i = 0; i < 25; i++)
			cout << " ";
		setCursor(screen, 20, 10);
		for (int i = 0; i <= 30; i++)
			cout << " ";
		setCursor(screen, 12, 32);
		cin >> matric;
	}
	setCursor(screen, 13, 38);
	cin >> inter;
	while (inter > 1100 || inter < 0)
	{
		cin.clear();
		cin.ignore(100, '\n');
		setCursor(screen, 20, 10);
		cout << "Wrong input ! Enter again : ";
		Sleep(1000);
		setCursor(screen, 13, 38);
		for (int i = 0; i < 25; i++)
			cout << " ";
		setCursor(screen, 20, 10);
		for (int i = 0; i <= 30; i++)
			cout << " ";
		setCursor(screen, 13, 38);
		cin >> inter;
	}
	setCursor(screen, 14, 30);
	cin >> test;
	while (test > 60 || test < 0)
	{
		cin.clear();
		cin.ignore(100, '\n');
		setCursor(screen, 20, 10);
		cout << "Wrong input ! Enter again : ";
		Sleep(1000);
		setCursor(screen, 14, 30);
		for (int i = 0; i < 25; i++)
			cout << " ";
		setCursor(screen, 20, 10);
		for (int i = 0; i <= 30; i++)
			cout << " ";
		setCursor(screen, 14, 30);
		cin >> test;
	}
	setCursor(screen, 15, 70);
	hafiz = _getche();
	if (hafiz == 'y' || hafiz == 'Y')
		hafiz = 20;
	else
		hafiz = 0;
	if (checkCase)
	{
		setCursor(screen, 16, 32);
		cin >> BS;
		while (BS > 4.0 || BS < 2.0)
		{
			cin.clear();
			cin.ignore(100, '\n');
			setCursor(screen, 20, 10);
			cout << "Wrong input ! Enter again : ";
			Sleep(1000);
			setCursor(screen, 16, 32);
			for (int i = 0; i < 25; i++)
				cout << " ";
			setCursor(screen, 20, 10);
			for (int i = 0; i <= 30; i++)
				cout << " ";
			setCursor(screen, 16, 32);
			cin >> BS;
		}
		setCursor(screen, 17, 35);
		cin >> interview;
		while (interview > 40 || interview < 0)
		{
			cin.clear();
			cin.ignore(100, '\n');
			setCursor(screen, 20, 10);
			cout << "Wrong input ! Enter again : ";
			Sleep(1000);
			setCursor(screen, 17, 35);
			for (int i = 0; i < 25; i++)
				cout << " ";
			setCursor(screen, 20, 10);
			for (int i = 0; i <= 30; i++)
				cout << " ";
			setCursor(screen, 17, 35);
			cin >> interview;
		}
	}
	Info temp;
	temp.setMatricMarks(matric);
	temp.setInterMarks(inter);
	temp.setTestMarks(test);
	temp.setHafizQuranMarks(hafiz);
	if (checkCase)
	{
		temp.setCGPA(BS);
		temp.setInterviewMarks(interview);
	}
	temp.calcMerit(checkCase);
	if (checkCase)
	{
		setCursor(screen, 18, 10);
		cout << "Merit: " << temp.getMerit();
	}
	else
	{
		setCursor(screen, 16, 10);
		cout << "Merit: " << temp.getMerit();
	}
	if (temp.getMerit() > 50.00)
	{
		write << "\n" << i + 1 << " ";
		getc = 0;
		for (; name[getc] != '\0'; ++getc)
			write << name[getc];
		write << "@ ";
		getc = 0;
		for (; fName[getc] != '\0'; ++getc)
			write << fName[getc];
		write << "@ ";
		write << matric << " ";
		write << inter << " ";
		write << test << " ";
		write << hafiz << " ";
		if (checkCase)
		{
			write << BS << " ";
			write << interview << " ";
		}
		setCursor(screen, 21, 10);
		cout << "RECORD SAVED";
	}
	else
	{
		setCursor(screen, 19, 10);
		cout << "Merit below 50.00%";
		setCursor(screen, 20, 10);
		cout<<"He\\She is not Applicable";
		setCursor(screen, 21, 10);
		cout << "RECORD NOT SAVED";
	}
	cin.clear();
	cin.ignore(100, '\n');
	setCursor(screen, 20, 10);
}

/*****************************************
getData function extract students
information from file in array of objects
=> Candidate's Name
=> candidate's Father Name
=> Matric Marks Percentage
=> Intermediate Marks Percentage
=> Test Marks
=> Hafiz e Quran Marks
=> BS Marks
=> Interview Marks
=> Merit
=> Sr.no
******************************************/
void getData(Info *candidate, int total, bool checkCase)
{
	char cName[28], cFName[28];	
	float matricMarks, interMarks, CGPA,
		testMarks, hafizQuranMarks,
		interviewMarks;
	int index;
	ifstream read;
	if (checkCase)
	{
		read.open("Student Records MS.txt");
		if (!read)
			cout << "Error opening file...\n";
	}
	else
	{
		read.open("Student Records.txt");
		if (!read)
			cout << "Error opening file...\n";
	}
	int i = 0;
	while (!read.eof() && i < total)
	{
		read >> index;
		read.getline(cName, 28, '@');
		read.getline(cFName, 28, '@');
		read >> matricMarks;
		read >> interMarks;
		read >> testMarks;
		read >> hafizQuranMarks;
		if (checkCase)
		{
			read >> CGPA;
			read >> interviewMarks;
			candidate[i].setCGPA(CGPA);
			candidate[i].setInterviewMarks(interviewMarks);
		}
		candidate[i].setIndex(index);
		candidate[i].setCName(cName);
		candidate[i].setCFName(cFName);
		candidate[i].setMatricMarks(matricMarks);
		candidate[i].setInterMarks(interMarks);
		candidate[i].setTestMarks(testMarks);
		candidate[i].setHafizQuranMarks(hafizQuranMarks);
		i++;
	}
	read.close();
}

/*****************************************
showData function prints the student
records on console
******************************************/
void showData(Info *candidate, int total, bool checkCase)
{
	system("CLS");
	HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
	setCursor(screen, 2, 50);
	cout << "General Merit List";
	setCursor(screen, 6, 0);
	cout << "Sr.No";
	setCursor(screen, 6, 7);
	cout << "Candidate Name";
	setCursor(screen, 6, 40);
	cout << "Candidate's Father Name";
	setCursor(screen, 6, 80);
	cout << "Matric";
	setCursor(screen, 6, 90);
	cout << "Inter";
	setCursor(screen, 6, 100);
	cout << "Test";
	setCursor(screen, 6, 105);
	cout << "Hafiz";
	if (checkCase)
	{
		setCursor(screen, 6, 112);
		cout << "CGPA";
		setCursor(screen, 6, 119);
		cout << "Interview";
		setCursor(screen, 6, 130);
		cout << "Merit";
	}
	else
	{
		setCursor(screen,6, 112);
		cout << "Merit";
	}
	for (int i = 0; i < total; i++)
	{
		setCursor(screen, i + 9, 0);
		cout << candidate[i].getIndex();
		setCursor(screen, i + 9, 7);
		cout << candidate[i].getCName();
		setCursor(screen, i + 9, 40);
		cout << candidate[i].getCFName();
		setCursor(screen, i + 9, 80);
		cout << candidate[i].getMatricMarks();
		setCursor(screen, i + 9, 90);
		cout << candidate[i].getInterMarks();
		setCursor(screen, i + 9, 100);
		cout << candidate[i].getTestMarks();
		setCursor(screen, i + 9, 105);
		cout << candidate[i].getHafizQuranMarks();
		if (checkCase)
		{
			setCursor(screen, i + 9, 112);
			cout << candidate[i].getCGPA();
			setCursor(screen, i + 9, 122);
			cout << candidate[i].getInterviewMarks();
			setCursor(screen, i + 9, 130);
			cout << candidate[i].getMerit() << endl;
		}
		else
		{
			setCursor(screen, i + 9, 112);
			cout << candidate[i].getMerit() << endl;
		}
	}
}

/*****************************************
sortData function sort students record in
ascending order according to their merit
*****************************************/
void sortData(Info *candidate, int total)
{
	double max;
	int maxIndex;
	for (int index1 = 0; index1 < total; index1++)
	{
		max = candidate[index1].getMerit();
		maxIndex = index1;
		for (int i = index1; i < total; i++)
		{
			if (candidate[i].getMerit()>max)
			{
				max = candidate[i].getMerit();
				maxIndex = i;
			}
		}
		Info temp = candidate[index1];
		candidate[index1] = candidate[maxIndex];
		candidate[index1].setIndex(index1+1);
		candidate[maxIndex] = temp;
		candidate[maxIndex].setIndex(maxIndex+1);
	}
}

/************************************************
createList function creates merit lists and store
their records in file
it also store records of remaining students in
another file
=> 3 merit lists
=> 3 remaining students lists
************************************************/
void createList(Info *candidate, int total, int seats, int list,
				int &selected , int &displayRecords, bool checkCase)
{
	ofstream write, write1;
	int start, end;
	if (list == 1)
	{
		write.open("First List.txt");
		write1.open("Remaining Students 1.txt");
		start = 0; end = seats;
	}
	else if (list == 2)
	{
		write.open("Second List.txt");
		write1.open("Remaining Students 2.txt");
		start = 0;
		end = seats - selected;
	}
	else if (list == 3)
	{
		write.open("Third List.txt");
		write1.open("Remaining Students 3.txt");
		start = 0;
		end = seats - selected;
	}
	int index = 0;
	int j = displayRecords;
	for (int i = start; i < end; i++)
	{
		write << index + 1 << " ";
		write << candidate[j].getCName() << "@ ";
		write << candidate[j].getCFName() << "@ ";
		write << candidate[j].getMatricMarks() << " ";
		write << candidate[j].getInterMarks() << " ";
		write << candidate[j].getTestMarks() << " ";
		write << candidate[j].getHafizQuranMarks() << " ";
		if (checkCase)
		{
			write << candidate[j].getCGPA() << " ";
			write << candidate[j].getInterviewMarks() << " ";
		}
		write << candidate[j].getMerit() << endl;
		++index;
		++j;
	}
	write.close();
	for (int i = displayRecords; i < total; i++)
	{
		write1 << candidate[i].getIndex() << " ";
		write1 << candidate[i].getCName() << "@ ";
		write1 << candidate[i].getCFName() << "@ ";
		write1 << candidate[i].getMatricMarks() << " ";
		write1 << candidate[i].getInterMarks() << " ";
		write1 << candidate[i].getTestMarks() << " ";
		write1 << candidate[i].getHafizQuranMarks() << " ";
		if (checkCase)
		{
			write1 << candidate[i].getCGPA() << " ";
			write1 << candidate[i].getInterviewMarks() << " ";
		}
		write1 << candidate[i].getMerit() << endl;
	}
	write1.close();
}
/*******************************************
searchRecord search records by matching
index (sr.no) of records
********************************************/

void searchRecord(Info* candidate, int total, bool checkCase)
{
	HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
NEWRECORD:
	system("CLS");
	setCursor(screen, 10, 10);
	cout << "Enter Form Number:";
	int srNum = 0;
	setCursor(screen, 10, 30);
	cin >> srNum;
	while (srNum<0 || srNum>total)
	{
		cin.clear();
		cin.ignore(100, '\n');
		setCursor(screen, 10, 80);
		cout << "Wrong Form Number";
		setCursor(screen, 11, 10);
		cout << "Enter Again:";
		setCursor(screen, 11, 25);
		for (int i = 0; i < 20; i++)
			cout << " ";
		setCursor(screen, 11, 25);
		cin >> srNum;
	}
	bool found = true;
	for (int i = 0; i < total && found; i++)
	{
		if (srNum == candidate[i].getIndex())
			found = false;
	}
	if (!found)
	{
		system("CLS");
		setCursor(screen, 4, 10);
		cout << "****************************";
		setCursor(screen, 5, 10);
		cout << "*	Form No  " << candidate[srNum - 1].getIndex() << "\t    *";
		setCursor(screen, 6, 10);
		cout << "****************************";
		setCursor(screen, 14, 10);
		cout << "Name:";
		setCursor(screen, 14, 34);
		cout << candidate[srNum - 1].getCName();
		setCursor(screen, 15, 10);
		cout << "Father Name:";
		setCursor(screen, 15, 34);
		cout << candidate[srNum - 1].getCFName();
		setCursor(screen, 16, 10);
		cout << "Matric Marks:";
		setCursor(screen, 16, 35);
		cout << candidate[srNum - 1].getMatricMarks();
		setCursor(screen, 17, 10);
		cout << "Intermediate Marks:";
		setCursor(screen, 17, 35);
		cout << candidate[srNum - 1].getInterMarks();
		setCursor(screen, 18, 10);
		cout << "Test Marks:";
		setCursor(screen, 18, 35);
		cout << candidate[srNum - 1].getTestMarks();
		if (candidate[srNum - 1].getHafizQuranMarks() == 20)
		{
			setCursor(screen, 19, 10);
			cout << "Hafiz e Quran:";
			setCursor(screen, 19, 35);
			cout << "YES";
		}
		else
		{
			setCursor(screen, 19, 10);
			cout << "Hafiz e Quran:";
			setCursor(screen, 19, 35);
			cout << "NO";
		}
		if (checkCase)
		{
			setCursor(screen, 20, 10);
			cout << "CGPA:";
			setCursor(screen, 20, 35);
			cout << candidate[srNum - 1].getCGPA();
			setCursor(screen, 21, 10);
			cout << "Interview Marks:";
			setCursor(screen, 21, 35);
			cout << candidate[srNum - 1].getInterviewMarks();
		}
	}
	else
	{
		system("CLS");
		setCursor(screen, 15, 35);
		cout << "NOT FOUND...!!!";
	}
	setCursor(screen, 25, 10);
	cout << "Menu";
	setCursor(screen, 26, 10);
	cout << "1 => Search New Record";
	setCursor(screen, 27, 10);
	cout << "2 => Back Menu";
	setCursor(screen, 29, 10);
	cout << "Enter Your Option: ";
	int op = 0;
	setCursor(screen, 29, 30);
	cin >> op;
	while (op <= 0 || op >= 3)
	{
		cin.clear();
		cin.ignore(100, '\n');
		setCursor(screen, 29, 80);
		cout << "Wrong Input...!!!";
		setCursor(screen, 30, 10);
		cout << "Enter Again: ";
		setCursor(screen, 30, 25);
		for (int i = 0; i < 25; i++)
			cout << " ";
		setCursor(screen, 30, 25);
		cin >> op;
	}
	if (op == 1)
		goto NEWRECORD;
}


/********************************************
modifyRecord found object of that record by
index....if it is found it will allow to
rewrite data and create new file of same name
and store all records
********************************************/
void modifyRecord(Info *candidate, int total, bool checkCase)
{
ANOTHERRECORD:
	system("CLS");
	HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << "\n\n\n\t\t\tEnter Form Number: ";
	int formNum;
	cin >> formNum;
	while (cin.fail())
	{
		cout << "\n\n\t\t\tWrong Input...";
		cout << "\n\t\t\t\tEnter Again: ";
		cin.clear();
		cin.ignore(100, '\n');
		cin >> formNum;
	}
	if (formNum <= 0 || formNum>total)
	{
		cout << "\n\n\n\\t\t\t\t\t\tForm Number does not exist...!";
	}
	else
	{
		cout << "\n\n\n\t\t\tRecord Found";
		cout << "\n\t\t\tNow you can modify record...";
		Sleep(1000);
		system("CLS");
		--formNum;
		printForm(formNum, checkCase);
		char name[28], fName[28], hafiz;
		float matric, inter, BS, test, interview;
		setCursor(screen, 8, 17);
		cin.ignore();
		char terminate = 'a';
		bool flag = true;
		int position = 17;
		name[0] = ' ';
		int getc = 1;
		while (getc <= 25 && flag)
		{
			terminate = _getche();
			if (terminate == 10 || terminate == 13)
				flag = false;
			else if (terminate == 8)
			{
				--getc;
				--position;
				setCursor(screen, 8, position);
				cout << " ";
				setCursor(screen, 8, position);
			}
			else
			{
				name[getc] = terminate;
				++position;
				++getc;
			}
		}
		name[getc] = '\0';
		candidate[formNum].setCName(name);
		setCursor(screen, 8, 61);
		terminate = 'a';
		flag = true;
		position = 61;
		fName[0] = ' ';
		getc = 1;
		while (getc <= 25 && flag)
		{
			terminate = _getche();
			if (terminate == 10 || terminate == 13)
				flag = false;
			else if (terminate == 8)
			{
				--getc;
				--position;
				setCursor(screen, 8, position);
				cout << " ";
				setCursor(screen, 8, position);
			}
			else
			{
				fName[getc] = terminate;
				++position;
				++getc;
			}
		}
		fName[getc] = '\0';
		candidate[formNum].setCFName(fName);
		//academic records
		setCursor(screen, 12, 32);
		cin >> matric;
		while (matric > 1050 || matric < 0)
		{
			cin.clear();
			cin.ignore(100, '\n');
			setCursor(screen, 20, 10);
			cout << "Wrong input ! Enter again : ";
			Sleep(1000);
			setCursor(screen, 12, 32);
			for (int i = 0; i < 25; i++)
				cout << " ";
			setCursor(screen, 20, 10);
			for (int i = 0; i <= 30; i++)
				cout << " ";
			setCursor(screen, 12, 32);
			cin >> matric;
		}
		candidate[formNum].setMatricMarks(matric);
		setCursor(screen, 13, 38);
		cin >> inter;
		while (inter > 1100 || inter < 0)
		{
			cin.clear();
			cin.ignore(100, '\n');
			setCursor(screen, 20, 10);
			cout << "Wrong input ! Enter again : ";
			Sleep(1000);
			setCursor(screen, 13, 38);
			for (int i = 0; i < 25; i++)
				cout << " ";
			setCursor(screen, 20, 10);
			for (int i = 0; i <= 30; i++)
				cout << " ";
			setCursor(screen, 13, 38);
			cin >> inter;
		}
		candidate[formNum].setInterMarks(inter);
		setCursor(screen, 14, 30);
		cin >> test;
		while (test > 60 || test < 0)
		{
			cin.clear();
			cin.ignore(100, '\n');
			setCursor(screen, 20, 10);
			cout << "Wrong input ! Enter again : ";
			Sleep(1000);
			setCursor(screen, 14, 30);
			for (int i = 0; i < 25; i++)
				cout << " ";
			setCursor(screen, 20, 10);
			for (int i = 0; i <= 30; i++)
				cout << " ";
			setCursor(screen, 14, 30);
			cin >> test;
		}
		candidate[formNum].setTestMarks(test);
		setCursor(screen, 15, 70);
		hafiz = _getche();
		if (hafiz == 'y' || hafiz == 'Y')
			candidate[formNum].setHafizQuranMarks(20);
		else
			candidate[formNum].setHafizQuranMarks(0);
		if (checkCase)
		{
			setCursor(screen, 16, 32);
			cin >> BS;
			while (BS > 4.0 || BS < 2.0)
			{
				cin.clear();
				cin.ignore(100, '\n');
				setCursor(screen, 20, 10);
				cout << "Wrong input ! Enter again : ";
				Sleep(1000);
				setCursor(screen, 16, 32);
				for (int i = 0; i < 25; i++)
					cout << " ";
				setCursor(screen, 20, 10);
				for (int i = 0; i <= 30; i++)
					cout << " ";
				setCursor(screen, 16, 32);
				cin >> BS;
			}
			candidate[formNum].setCGPA(BS);
			setCursor(screen, 17, 35);
			cin >> interview;
			while (interview > 40 || interview < 0)
			{
				cin.clear();
				cin.ignore(100, '\n');
				setCursor(screen, 20, 10);
				cout << "Wrong input ! Enter again : ";
				Sleep(1000);
				setCursor(screen, 17, 35);
				for (int i = 0; i < 25; i++)
					cout << " ";
				setCursor(screen, 20, 10);
				for (int i = 0; i <= 30; i++)
					cout << " ";
				setCursor(screen, 17, 35);
				cin >> interview;
			}
			candidate[formNum].setInterviewMarks(interview);
		}
		setCursor(screen, 23, 25);
		cout << "Record Saved";
		cin.clear();
		cin.ignore(100, '\n');
		setCursor(screen, 20, 10);
		ofstream write;
		if (checkCase)
		{
			write.open("Student Records MS.txt");
			if (!write)
				cout << "Error opening file\n";
		}
		else
		{
			write.open("Student Records.txt");
			if (!write)
				cout << "Error opening file\n";
		}
		int i = 0, temp = total - 1;
		while (i < total)
		{
			write << candidate[i].getIndex() << " ";
			write << candidate[i].getCName() << "@";
			write << candidate[i].getCFName() << "@";
			write << candidate[i].getMatricMarks() << " ";
			write << candidate[i].getInterMarks() << " ";
			write << candidate[i].getTestMarks() << " ";
			write << candidate[i].getHafizQuranMarks() << " ";
			if (checkCase)
			{
				write << candidate[i].getCGPA() << " ";
				write << candidate[i].getInterviewMarks();
			}
			if (temp != i)
				write << endl;
			i++;
		}
		write.close();
	}
	setCursor(screen, 25, 10);
	cout << "Menu";
	setCursor(screen, 26, 10);
	cout << "1 => Modify Another Record";
	setCursor(screen, 27, 10);
	cout << "2 => Back Menu";
	setCursor(screen, 29, 10);
	cout << "Enter Your Option: ";
	int op = 0;
	setCursor(screen, 29, 30);
	cin >> op;
	while (op <= 0 || op >= 3)
	{
		cin.clear();
		cin.ignore(100, '\n');
		setCursor(screen, 29, 80);
		cout << "Wrong Input...!!!";
		setCursor(screen, 30, 10);
		cout << "Enter Again: ";
		setCursor(screen, 30, 25);
		for (int i = 0; i < 25; i++)
			cout << " ";
		setCursor(screen, 30, 25);
		cin >> op;
	}
	if (op == 1)
		goto ANOTHERRECORD;
}

/**********************************************
showList function prints merit lists on screen
=> 3 merit lists
**********************************************/
void showList(Info *candidate, int total, int seats,  int list,
			  int &selected, int &displayRecords, bool checkCase)
{
	cout << "\n\n\n\t\t\tPlease Wait...";
	Sleep(1000);
	system("CLS");
	int start, end;
	HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
	setCursor(screen, 2, 50);
	if (list == 1)
	{
		cout << "Fisrt Merit List";
		start = 0; end = seats;
	}
	else if (list == 2)
	{
		cout << "Second Merit List";
		start = 0;
		end = seats - selected;
	}
	else if (list == 3)
	{
		cout << "Third Merit List";
		start = 0;
		end = seats - selected;
	}
	setCursor(screen, 6, 0);
	cout << "Sr.No";
	setCursor(screen, 6, 7);
	cout << "Candidate Name";
	setCursor(screen, 6, 40);
	cout << "Candidate's Father Name";
	setCursor(screen, 6, 80);
	cout << "Matric";
	setCursor(screen, 6, 90);
	cout << "Inter";
	setCursor(screen, 6, 100);
	cout << "Test";
	setCursor(screen, 6, 105);
	cout << "Hafiz";
	if (checkCase)
	{
		setCursor(screen, 6, 112);
		cout << "CGPA";
		setCursor(screen, 6, 119);
		cout << "Interview";
		setCursor(screen, 6, 130);
		cout << "Merit";
	}
	else
	{
		setCursor(screen, 6, 112);
		cout << "Merit";
	}
	int index = 0;
	int j = displayRecords;
	for (int i = start; i < end; i++)
	{
		setCursor(screen, index + 9, 0);
		cout << index + 1;
		setCursor(screen, index + 9, 7);
		cout << candidate[j].getCName();
		setCursor(screen, index + 9, 40);
		cout << candidate[j].getCFName();
		setCursor(screen, index + 9, 80);
		cout << candidate[j].getMatricMarks();
		setCursor(screen, index + 9, 90);
		cout << candidate[j].getInterMarks();
		setCursor(screen, index + 9, 100);
		cout << candidate[j].getTestMarks();
		setCursor(screen, index + 9, 105);
		cout << candidate[j].getHafizQuranMarks();
		if (checkCase)
		{
			setCursor(screen, index + 9, 112);
			cout << candidate[j].getCGPA();
			setCursor(screen, index + 9, 122);
			cout << candidate[j].getInterviewMarks();
			setCursor(screen, index + 9, 130);
			cout << candidate[j].getMerit() << endl;
		}
		else
		{
			setCursor(screen, index + 9, 112);
			cout << candidate[j].getMerit() << endl;
		}
		++index;
		++j;
	}
}

/***************************************
feeSubmission function marked the 
submission status...yes or no
if yes then student get admission 
in university
***************************************/
void feeSubmission(Info *candidate, int total, int seats, int list,
	int &selected, int &displayRecords, bool checkCase)
{
	HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
	int start, end;
	ofstream write;
	if (list == 1)
	{
		write.open("Selected 1.txt");
		start = 0; end = seats;
	}
	else if (list == 2)
	{
		write.open("Selected 2.txt");
		start = 0;
		end = seats - selected;
	}
	else if (list == 3)
	{
		write.open("Selected 3.txt");
		start = 0;
		end = seats - selected;
	}
	cout << "\n\n\n\t\t\tStarting Fee Submission Process...";
	Sleep(1000);
	system("CLS");
	setCursor(screen, 3, 50);
	cout << "***********************************************";
	setCursor(screen, 4, 50);
	cout << "*		Fee Submission Process		*";
	setCursor(screen, 5, 50);
	cout << "***********************************************";
	char ch;
	setCursor(screen, 10, 10);
	cout << "If Applicants paid his dues press 'y' otherwise 'n'\n\n\n";
	int index = 0;
	int j = displayRecords;
	int move = 0;
	for (int i = start; i < end; i++)
	{
		setCursor(screen, 13+ move, 10);
		cout << index + 1 << ":";
		index++;
		setCursor(screen, 13+ move, 14);
		cout << candidate[j].getCName();
		setCursor(screen, 13+ move, 44);
		cout << candidate[j].getCFName();
		setCursor(screen, 15+ move, 15);
		cout << "paid:";
		setCursor(screen, 15 + move, 23);
		ch = _getche();
		while (!(ch == 'y' || ch == 'Y' || ch == 'n' || ch == 'N'))
		{
			setCursor(screen, 13 + move, 90);
			cout << "Wrong Input:-";
			setCursor(screen, 14 + move, 90);
			cout<<"you can only enter 'y' or 'n' for this process: ";
			setCursor(screen, 15 + move, 23);
			ch = _getche();
		}
		move += 4;
		if (ch == 'y' || ch == 'Y')
		{
			write << selected + 1 << " ";
			write << candidate[j].getCName() << "@ ";
			write << candidate[j].getCFName() << "@ ";
			write << candidate[j].getMatricMarks() << " ";
			write << candidate[j].getInterMarks() << " ";
			write << candidate[j].getTestMarks() << " ";
			write << candidate[j].getHafizQuranMarks() << " ";
			if (checkCase)
			{
				write << candidate[j].getCGPA() << " ";
				write << candidate[j].getInterviewMarks() << " ";
			}
			write << candidate[j].getMerit() << endl;
			++selected;
		}
		++j;
		++displayRecords;
	}
	write.close();
	cout << "\n\n\n\t\t\tPress Enter key to continue...";
	char key;
	key = _getch();
	while (key != 10 && key != 13)
	{
		cout << "\n\t\t\tYou Entered wrong key...";
		cout << "\n\t\t\tPress Enter key to continue...";
		key = _getch();
	}
}

/*********************************************
finalList function extracts data of admitted 
students form selected files and create a 
final list then show final list on screen
**********************************************/
void finalList(int selected, int s1, int s2, int s3,bool checkCase)
{
	char cName[28], cFName[28];
	float matricMarks, interMarks, CGPA,
		  testMarks, hafizQuranMarks,
		  interviewMarks, merit;
	int index;
	Info *sCandidate=new Info[selected];
	int counter;
	if (s1 > 0 && s2 > 0 && s3 > 0)
		counter = 3;
	else if (s1 > 0 && s2 > 0)
		counter = 2;
	else if (s1 > 0)
		counter = 1;
	else
	{
		cout << "There is no Final List.\n";
		counter = 0;
	}
	int i = 0;
	ifstream read;
	for (int index1 = 0; index1 < counter; index1++)
	{
		int check;
		if (index1 == 0)
		{
			read.open("Selected 1.txt");
			if (!read)
				cout << "Error opening Selected 1 File\n";
			check = s1;
		}
		if (index1 == 1)
		{
			read.open("Selected 2.txt");
			if (!read)
				cout << "Error opening Selected 2 File\n";
			check = s2;
		}
		if (index1 == 2)
		{
			read.open("Selected 3.txt");
			if (!read)
				cout << "Error opening Selected 3 File\n";
			check = s3;
		}
		while (!read.eof() && i < check)
		{
			read >> index;
			read.getline(cName, 28, '@');
			read.getline(cFName, 28, '@');
			read >> matricMarks;
			read >> interMarks;
			read >> testMarks;
			read >> hafizQuranMarks;
			if (checkCase)
			{
				read >> CGPA;
				read >> interviewMarks;
				sCandidate[i].setCGPA(CGPA);
				sCandidate[i].setInterviewMarks(interviewMarks);
			}
			read >> merit;
			sCandidate[i].setIndex(index);
			sCandidate[i].setCName(cName);
			sCandidate[i].setCFName(cFName);
			sCandidate[i].setMatricMarks(matricMarks);
			sCandidate[i].setInterMarks(interMarks);
			sCandidate[i].setTestMarks(testMarks);
			sCandidate[i].setHafizQuranMarks(hafizQuranMarks);
			sCandidate[i].setMerit(merit);
			i++;
		}
		read.close();
	}
	ofstream write("Final List of Admitted Students.txt");
	for (int i = 0; i < selected; i++)
	{
		write << i + 1 << " ";
		write << sCandidate[i].getCName() << "@ ";
		write << sCandidate[i].getCFName() << "@ ";
		write << sCandidate[i].getMatricMarks() << " ";
		write << sCandidate[i].getInterMarks() << " ";
		write << sCandidate[i].getTestMarks() << " ";
		write << sCandidate[i].getHafizQuranMarks() << " ";
		if (checkCase)
		{
			write << sCandidate[i].getCGPA() << " ";
			write << sCandidate[i].getInterviewMarks() << " ";
		}
		write << sCandidate[i].getMerit() << endl;
	}
	write.close();
	system("CLS");
	HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
	setCursor(screen, 2, 50);
	cout << "Final List of Admitted Students";
	setCursor(screen, 6, 0);
	cout << "Sr.No";
	setCursor(screen, 6, 7);
	cout << "Candidate Name";
	setCursor(screen, 6, 40);
	cout << "Candidate's Father Name";
	setCursor(screen, 6, 80);
	cout << "Matric";
	setCursor(screen, 6, 90);
	cout << "Inter";
	setCursor(screen, 6, 100);
	cout << "Test";
	setCursor(screen, 6, 105);
	cout << "Hafiz";
	if (checkCase)
	{
		setCursor(screen, 6, 112);
		cout << "CGPA";
		setCursor(screen, 6, 119);
		cout << "Interview";
		setCursor(screen, 6, 130);
		cout << "Merit";
	}
	else
	{
		setCursor(screen, 6, 112);
		cout << "Merit";
	}
	for (int i = 0; i < selected; i++)
	{
		setCursor(screen, i + 9, 0);
		cout << sCandidate[i].getIndex();
		setCursor(screen, i + 9, 7);
		cout << sCandidate[i].getCName();
		setCursor(screen, i + 9, 40);
		cout << sCandidate[i].getCFName();
		setCursor(screen, i + 9, 80);
		cout << sCandidate[i].getMatricMarks();
		setCursor(screen, i + 9, 90);
		cout << sCandidate[i].getInterMarks();
		setCursor(screen, i + 9, 100);
		cout << sCandidate[i].getTestMarks();
		setCursor(screen, i + 9, 105);
		cout << sCandidate[i].getHafizQuranMarks();
		if (checkCase)
		{
			setCursor(screen, i + 9, 112);
			cout << sCandidate[i].getCGPA();
			setCursor(screen, i + 9, 122);
			cout << sCandidate[i].getInterviewMarks();
			setCursor(screen, i + 9, 130);
			cout << sCandidate[i].getMerit() << endl;
		}
		else
		{
			setCursor(screen, i + 9, 112);
			cout << sCandidate[i].getMerit() << endl;
		}
	}
	cout << "\n\n\n\t\t\tPress Enter key to continue...";
	char key;
	key = _getch();
	while (key != 10 && key != 13)
	{
		cout << "\n\t\t\tYou Entered wrong key...";
		cout << "\n\t\t\tPress Enter key to continue...";
		key = _getch();
	}
}

/*********************************
Count total records of applicants
*Each line has one record.
Total lines=Total records
*********************************/
int countRecords(bool checkCase)
{
	string s;
	int lines = 0;
	ifstream write;
	if (checkCase)
		write.open("Student Records MS.txt");
	else
		write.open("Student Records.txt");
	while (!write.eof())
	{
		getline(write, s);
		++lines;
	}
	write.close();
	return lines;
}

/*************************************************
checkStatus prints
*Total seats
*Total number of applicants
*Total number of selected candidate
*************************************************/
void checkStatus(int seats, int total,int selected)
{
	cout << "\n\n\t\t\tTotal Seats: " << seats << endl;
	cout << "\t\t\tTotal Applicants: " << total << endl;
	cout << "\t\t\tTotal Number of Selected Students: " << selected << endl;
}

/**************************************************
backCheck validate whether user enter b or not
***************************************************/
void backCheck()
{
	char ch;
	cout << "\n\n\n\t\t\tPress b to access back menu: ";
	ch = _getch();
	while (ch != 'b' && ch != 'B')
	{
		cout << "\n\n\n\t\t\tWrong Input...!!!";
		cout << "\n\n\n\t\t\tPress b to access back menu: ";
		ch = _getch();
	}
}

void mainMenu()
{
	HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
	setCursor(screen, 8, 10);
	cout << "Menu";
	setCursor(screen, 10, 10);
	cout << "1 => Undergraduate";
	setCursor(screen, 11, 10);
	cout << "2 => Graduate";
	setCursor(screen, 12, 10);
	cout << "3 => Exit";
	setCursor(screen, 14, 10);
}

void menu1()
{
	HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
	setCursor(screen, 8, 10);
	cout << "Menu";
	setCursor(screen, 10, 10);
	cout << "1 => Check Status*";
	setCursor(screen, 11, 10);
	cout << "2 => Enter New Records";
	setCursor(screen, 12, 10);
	cout << "3 => General List";
	setCursor(screen, 13, 10);
	cout << "4 => Search Record";
	setCursor(screen, 14, 10);
	cout << "5 => Modify Record";
	setCursor(screen, 15, 10);
	cout << "6 => First Merit List";
	setCursor(screen, 16, 10);
	cout << "7 => Back Menu";
	setCursor(screen, 35, 100);
	cout << "*Total Records, Applicants and Selected.";
	setCursor(screen, 20, 10);
}

void menu2()
{
	cout << "\n\n\n\t\t\t1 => Start Fee Submission Process: ";
	cout << "\n\t\t\t2 => Exit: ";
	cout << "\n\t\t\tEnter your option: ";
	int op;
	cin >> op;
	while (op < 1 || op > 2)
	{
		cin.clear();
		cin.ignore(100, '\n');
		cout << "\n\t\t\tWrong Input...Enter Again: ";
		cin >> op;
	}
	if (op == 2)
	{
		cout << "\n\n\n\t\t\tGood Bye...!";
		Sleep(3000);
		exit(0);
	}
}

void menu3(int check,int seats,int total,int selected)
{
	HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
BACK:
	system("CLS");
	setCursor(screen, 9, 10);
	cout << "MENU";
	setCursor(screen, 11, 10);
	cout << "1 => Check Status";
	setCursor(screen, 12, 10);
	if (check == 2)
		cout << "2 => Second Merit List";
	else if (check == 3)
		cout << "2 => Third Merit List";
	setCursor(screen, 14, 10);
	cout << "Enter your option: ";
	setCursor(screen, 14, 32);
	int op = 0;
	cin >> op;
	while (op < 1 || op > 2)
	{
		cin.clear();
		cin.ignore(100, '\n');
		setCursor(screen, 14, 50);
		cout << "Wrong Input...Enter Again: ";
		setCursor(screen, 14, 32);
		for (int sp = 0; sp < 10; sp++)
			cout << " ";
		setCursor(screen, 14, 32);
		cin >> op;
	}
	if (op == 1)
	{
		system("CLS");
		checkStatus(seats, total, selected);
		backCheck();
		goto BACK;
	}
}
