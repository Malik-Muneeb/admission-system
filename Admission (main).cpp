
/*Project: Admission System*/

#include"Admission.h"
int total = 60;
const int seats = 30;
static int selected = 0;			//keep record of no. of selected students


int main()
{
	MAINMENU:
	system("CLS");
	welcomeScreen();
	mainMenu();
	HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << "Enter your choice: ";
	cin.clear();
	int op;
	cin >> op;
	while (op < 1 || op > 3)
	{
		cin.clear();
		cin.ignore(100, '\n');
		cout << "\t  Wrong input...Enter Again: ";
		cin >> op;
	}
	switch (op)
	{
		bool checkCase;
		case 1:
		{	
			checkCase = false;
			MENU1:
			system("CLS");
			menu1();
			int op = 0;
			cout << "Enter your option: ";
			cin >> op;
			while (op < 1 || op > 7)
			{
				cin.clear();
				cin.ignore(100, '\n');
				cout << "\t  Wrong input...Enter Again: ";
				cin >> op;
			}
			switch (op)
			{
			case 1:
			{
				system("CLS");
				total = countRecords(checkCase);  //count total records
				checkStatus(seats, total,selected);
				backCheck();
				goto MENU1;
			}
			break;
			case 2:
			{
				total = countRecords(checkCase);
				system("CLS");
				cout << "\n\n\n\t\t\tHow many records you want to enter: ";
				int num = 0;
				cin >> num;
				while (cin.fail())
				{
					cin.clear();
					cin.ignore(100, '\n');
					cout << "\t\t\tWrong Input...Enter Again: ";
					cin >> num;
				}
				for (int i = 0; i < num; i++)
				{
					printForm(total + i, checkCase);
					fillForm(total + i, checkCase);
				}
				total += num;
				char ch;
				setCursor(screen, 26, 10);
				cout << "Press b to access back menu: ";
				ch = _getch();
				while (ch != 'b' && ch != 'B')
				{
					setCursor(screen, 27, 10);
					cout << "Wrong Input...!!!";
					setCursor(screen, 28, 10);
					cout << "Press b to access back menu: ";
					ch = _getch();
				}
				goto MENU1;
			}
			break;
			case 3:
			{
				total = countRecords(checkCase);
				system("CLS");
				cout << "\n\n\n\t\tLoading Records of total Applicants....";
				Sleep(1000);
				Info *candidate = new Info[total];
				getData(candidate, total, checkCase);
				for (int i = 0; i < total; i++)
					candidate[i].calcMerit(checkCase);
				sortData(candidate, total);
				showData(candidate, total, checkCase);
				delete[] candidate;
				backCheck();
				goto MENU1;
			}
			break;
			case 4:
			{
				total = countRecords(checkCase);
				Info *candidate = new Info[total];
				getData(candidate, total, checkCase);
				searchRecord(candidate, total,checkCase);
				delete[] candidate;
				goto MENU1;
			}
			break;
			case 5:
			{
				total = countRecords(checkCase);
				Info *candidate = new Info[total];
				getData(candidate, total, checkCase);
				modifyRecord(candidate, total, checkCase);
				delete[] candidate;
				goto MENU1;
			}
			break;
			case 6:
				break;
			case 7:
				goto MAINMENU;
			break;
			}
			total = countRecords(checkCase);
			Info *candidate = new Info[total];
			getData(candidate, total, checkCase);
			for (int i = 0; i < total; i++)
				candidate[i].calcMerit(checkCase); 
			static int displayRecords = 0;		//keep record no. of students whose data displayed on screen
			int s1 = 0, s2 = 0, s3 = 0;			//s1= selected students of first list, s2= ... of second list , s3= ... third list
			sortData(candidate, total);
			createList(candidate, total, seats, 1, selected, displayRecords, checkCase);
			showList(candidate, total, seats, 1, selected, displayRecords, checkCase);
			menu2();
			feeSubmission(candidate, total, seats, 1, selected, displayRecords,checkCase);
			s1 = selected;
			if (seats - selected > 0)
			{
				menu3(2, seats, total, selected);
				createList(candidate, total, seats, 2, selected, displayRecords, checkCase);
				showList(candidate, total, seats, 2, selected, displayRecords, checkCase);
				menu2();
				feeSubmission(candidate, total, seats, 2, selected, displayRecords, checkCase);
				s2 = selected;
			}
			if (seats - selected > 0)
			{
				menu3(3,seats, total, selected);
				createList(candidate, total, seats, 3, selected, displayRecords, checkCase);
				showList(candidate, total, seats, 3, selected, displayRecords, checkCase);
				menu2();
				feeSubmission(candidate, total, seats, 3, selected, displayRecords, checkCase);
				s3 = selected;
			}
			finalList(selected, s1, s2, s3, checkCase);
			delete[] candidate;
			system("CLS");
			cout << "\n\n\n\t\t\tPress Enter key to Exit...";
			char key;
			key = _getch();
			while (key != 10 && key != 13)
			{
				cout << "\n\t\t\tYou Entered wrong key...";
				cout << "\n\t\t\tPress Enter key to Exit...";
				key = _getch();
			}
			cout << "\n\n\n\t\t\tGOOD BYE...!!!";
			Sleep(1000);
			exit(0);
		}
		break;
		case 2:
		{
			checkCase = true;
			CASE2MENU1:
			system("CLS");
			menu1();
			int op;
			cout << "Enter your option: ";
			cin >> op;
			while (op < 1 || op > 7)
			{
				cin.clear();
				cin.ignore(100, '\n');
				cout << "\t  Wrong input...Enter Again: ";
				cin >> op;
			}
			switch (op)
			{
			case 1:
			{
				system("CLS");
				total = countRecords(checkCase);  //count total records
				checkStatus(seats, total, selected);
				backCheck();
				goto CASE2MENU1;
			}
			break;
			case 2:
			{
				total = countRecords(checkCase);
				system("CLS");
				cout << "\n\n\n\t\t\tHow many records you want to enter: ";
				int num = 0;
				cin >> num;
				while (cin.fail())
				{
					cin.clear();
					cin.ignore(100, '\n');
					cout << "\t\t\tWrong Input...Enter Again: ";
					cin >> num;
				}
				for (int i = 0; i < num; i++)
				{
					printForm(total + i, checkCase);
					fillForm(total + i, checkCase);
				}
				total += num;
				char ch;
				setCursor(screen, 26, 10);
				cout << "Press b to access back menu: ";
				ch = _getch();
				while (ch != 'b' && ch != 'B')
				{
					setCursor(screen, 27, 10);
					cout << "Wrong Input...!!!";
					setCursor(screen, 28, 10);
					cout << "Press b to access back menu: ";
					ch = _getch();
				}
				goto CASE2MENU1;
			}
			break;
			case 3:
			{
				total = countRecords(checkCase);
				system("CLS");
				cout << "\n\n\n\t\tLoading Records of total Applicants....";
				Sleep(1000);
				Info *candidate = new Info[total];
				getData(candidate, total, checkCase);
				for (int i = 0; i < total; i++)
					candidate[i].calcMerit(checkCase);
				sortData(candidate, total);
				showData(candidate, total, checkCase);
				delete[] candidate;
				backCheck();
				goto CASE2MENU1;
			}
			break;
			case 4:
			{
				total = countRecords(checkCase);
				Info *candidate = new Info[total];
				getData(candidate, total, checkCase);
				searchRecord(candidate, total, checkCase);
				delete[] candidate;
				goto CASE2MENU1;
			}
			break;
			case 5:
			{
				total = countRecords(checkCase);
				Info *candidate = new Info[total];
				getData(candidate, total, checkCase);
				modifyRecord(candidate, total, checkCase);
				delete[] candidate;
				goto CASE2MENU1;
			}
			break;
			case 6:
				break;
			case 7:
				goto MAINMENU;
				break;
			}
			total = countRecords(checkCase);
			Info *candidate = new Info [total];
			getData(candidate, total, checkCase);
			for (int i = 0; i < total; i++)
				candidate[i].calcMerit(checkCase);
			static int displayRecords = 0;
			int s1 = 0, s2 = 0, s3 = 0;
			sortData(candidate, total);
			createList(candidate, total, seats, 1, selected, displayRecords, checkCase);
			showList(candidate, total, seats, 1, selected, displayRecords, checkCase);
			menu2();
			feeSubmission(candidate, total, seats, 1, selected, displayRecords, checkCase);
			s1 = selected;
			if (seats - selected > 0)
			{
				menu3(2, seats, total, selected);
				createList(candidate, total, seats, 2, selected, displayRecords, checkCase);
				showList(candidate, total, seats, 2, selected, displayRecords, checkCase);
				menu2();
				feeSubmission(candidate, total, seats, 2, selected, displayRecords, checkCase);
				s2 = selected;
			}
			if (seats - selected > 0)
			{
				menu3(3, seats, total, selected);
				createList(candidate, total, seats, 3, selected, displayRecords, checkCase);
				showList(candidate, total, seats, 3, selected, displayRecords, checkCase);
				menu2();
				feeSubmission(candidate, total, seats, 3, selected, displayRecords, checkCase);
				s3 = selected;
			}
			finalList(selected, s1, s2, s3, checkCase);
			delete[] candidate;
			system("CLS");
			cout << "\n\n\n\t\t\tPress Enter key to Exit...";
			char key;
			key = _getch();
			while (key != 10 && key != 13)
			{
				cout << "\n\t\t\tYou Entered wrong key...";
				cout << "\n\t\t\tPress Enter key to Exit...";
				key = _getch();
			}
			cout << "\n\n\n\t\t\tGOOD BYE...!!!";
			Sleep(1000);
			exit(0);
		}
		break;
		case 3:
		{
			cout << "\n\n\n\t\t\tGOOD BYE...!!!";
			Sleep(1000);
			exit(0);
		}
		break;
	}
	cout << "\n\n";
	system("pause");
	return 0;
}
