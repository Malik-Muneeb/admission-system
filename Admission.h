
/*Name : Hafiz Muneeb ur Rehman
Roll No. : BCSF15M030
Project: Admission System*/


#ifndef ADMISSION_H
#define ADMISSION_H
#include<iostream>
#include<windows.h>    //(column : 119, rows : 27 ......on small screen)
#include<fstream>
#include<string>
#include<conio.h>
#include<iomanip>
using namespace std;

/**********************************************
Info class store students records
**********************************************/

class Info
{
	int index;  //form Number
	string cName, cFName;		//candidate name, father name
	double matricMarks, interMarks, CGPA,
		testMarks, hafizQuranMarks, interviewMarks, merit;
public:
	Info();
	void setCName(string s);
	void setCFName(string s);

	void setMatricMarks(float m);
	void setInterMarks(float m);
	void setCGPA(float m);
	void setTestMarks(float m);
	void setHafizQuranMarks(float m);
	void setInterviewMarks(float m);
	void setIndex(int i);
	void setMerit(float m);
	int getIndex();
	string getCName();
	string getCFName();
	double getMatricMarks();
	double getInterMarks();
	double getCGPA();
	double getTestMarks();
	double getHafizQuranMarks();
	double getInterviewMarks();
	double getMerit();
	void calcMerit(bool case2);
	//Info operator=(const Info &);
};

void setCursor(HANDLE , int, int);
void welcomeScreen();
void checkStatus(int, int,int);
int countRecords(bool);
void backCheck();
void mainMenu();
void menu1();
void menu2();
void menu3(int, int, int, int);
void getData(Info*, int, bool);
void showData(Info*,int,bool);
void sortData(Info*, int);
void createList(Info*, int,int,int,int&,int&,bool);
void showList(Info*,int,int,int,int&,int&,bool);
void feeSubmission(Info*,int,int,int,int&,int&,bool);
void finalList(int,int,int,int,bool);
void printForm(int, bool);
void fillForm(int , bool);
void searchRecord(Info*, int,bool);
void modifyRecord(Info*,int, bool );
void drawBoundary();
#endif
