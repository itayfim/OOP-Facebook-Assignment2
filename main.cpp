#include "Header.h"
#include "Facebook.h"
using namespace std;

const char* UNKNOWN_ERROR = "Unknown error has been occurred, please try again.\n"; 

void main()
{
	set_terminate(newTerminate); // implement of our terminate function
	Facebook system;
	initSystem(system); // Hard-coded entities creation
	int choice;
	cout << "Hello and welcome to Facebook!" << endl;
	do
	{
		try
		{
			printMenu();
			cin >> choice;
			cin.ignore();
			executeChoice(choice, system);
			cout << endl;
		}
		catch (UserOrPageExist& e)
		{
			cout << e.myWhat();
		}
		catch (UserOrPageNotExist& e)
		{
			cout << e.myWhat();
		}
		catch (LessThan2Users& e)
		{
			cout << e.what();
		}
		catch (ZeroUsers& e)
		{
			cout << e.what();
		}
		catch (ZeroPages& e)
		{
			cout << e.what();
		}
		catch (FacebookException& e)
		{
			cout << e.what();
		}
		catch (SelfFriend& e)
		{
			cout << e.what();
		}
		catch (DateException& e)
		{
			cout << e.what();
		}
		catch (UserException& e)
		{
			cout << e.what();
		}
		catch (invalid_argument& e)
		{
			cout << e.what();
		}
		catch (...)
		{
			cout << UNKNOWN_ERROR;
		}
	} while (choice != EXIT);
	cout << "Thanks and good bye!" << endl;
}