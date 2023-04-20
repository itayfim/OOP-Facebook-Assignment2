#include "status.h"
#include "ctime"
using namespace std;

void Status::printStatus() const
{
	cout << text_status.content << endl;
	cout << "Status creation date: " << text_status.date_of_release << endl;
}
