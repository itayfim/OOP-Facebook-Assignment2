using namespace std;
#include "Facebook.h"
#include "Exceptions.h"

Facebook::~Facebook()
{
	vector<User*>::iterator usersItr = users.begin();
	vector<User*>::iterator UsersEndItr = users.end();
	for (; usersItr != UsersEndItr; ++usersItr)
		delete* usersItr;
	vector<Page*>::iterator pagesItr = pages.begin();
	vector<Page*>::iterator PagesEndItr = pages.end();
	for (; pagesItr != PagesEndItr; ++pagesItr)
		delete* pagesItr;
}

void Facebook::addFriend(const User& user) noexcept(false)
{
	vector<User*>::iterator usersItr = users.begin();
	vector<User*>::iterator UsersEndItr = users.end();
	for (; usersItr != UsersEndItr; ++usersItr)
	{
		if ((*usersItr)->getName() == user.getName())
			throw UserOrPageExist(user.getName());
	}
	User* newUser = new User(user);
	users.push_back(newUser);
}

void Facebook::addPage(const Page& page) noexcept(false)
{
	vector<Page*>::iterator pagesItr = pages.begin();
	vector<Page*>::iterator PagesEndItr = pages.end();
	for (; pagesItr != PagesEndItr; ++pagesItr)
	{
		if ((*pagesItr)->getName() == page.getName())
			throw UserOrPageExist(page.getName());
	}
	Page* newPage = new Page(page);
	pages.push_back(newPage);
}

void Facebook::printUsers() const
{
	int i = 0;
	vector<User*>::const_iterator usersItr = users.begin();
	vector<User*>::const_iterator UsersEndItr = users.end();
	for (; usersItr != UsersEndItr; ++usersItr)
	{
		cout << ++i << ". " << (*usersItr)->getName() << endl;
		(*usersItr)->printStatusesOfUser();
	}
}

void Facebook::printPages() const
{
	int i = 0;
	vector<Page*>::const_iterator pagesItr = pages.begin();
	vector<Page*>::const_iterator PagesEndItr = pages.end();
	for (; pagesItr != PagesEndItr; ++pagesItr)
	{
		cout << ++i << ". " << (*pagesItr)->getName() << endl;
		(*pagesItr)->printStatusesOfPage();
	}
}

int Facebook::searchUserByName(string name) const noexcept(false)
{
	vector<User*>::const_iterator usersItr = users.begin();
	vector<User*>::const_iterator UsersEndItr = users.end();
	int count = 0;
	for (; usersItr != UsersEndItr; ++usersItr)
	{
		if ((*usersItr)->getName() == name)
			return count;
		count++;
	}
	throw UserOrPageNotExist(name);
}

int Facebook::searchPageByName(string name) const noexcept(false)
{
	int count = 0;
	vector<Page*>::const_iterator pagesItr = pages.begin();
	vector<Page*>::const_iterator PagesEndItr = pages.end();
	for (; pagesItr != PagesEndItr; ++pagesItr)
	{
		if ((*pagesItr)->getName() == name)
			return count;
		count++;
	}
	throw UserOrPageNotExist(name);
}

