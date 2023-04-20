#include "page.h"
#include "status.h"
using namespace std;

Page::~Page()
{
	vector<Status*>::iterator itr = page_statuses.begin();
	vector<Status*>::iterator endItr = page_statuses.end();
	for (; itr != endItr; ++itr)
		delete* itr;
}

void Page::addFollower(User& new_follower)
{
	bool founded = false;
	vector<User*>::iterator itr = followers.begin();
	vector<User*>::iterator endItr = followers.end();
	for (; itr != endItr && !founded; ++itr) // Check if the new follower is already following the fan page
	{
		if ((*itr)->getName() == new_follower.getName())
			founded = true;
	}
	if (!founded) // The new follower isn't in the list of followers
	{
		followers.push_back(&new_follower);
		new_follower.addPage(*this); // Mutual action, the new follower will add the fan page to his list of pages
	}
}

void Page::deleteFollower(User& old_follower)
{
	vector<User*>::iterator itr = followers.begin();
	vector<User*>::iterator endItr = followers.end();
	for (; itr != endItr; ++itr) // Check if the new follower is in the list of followers
	{
		if ((*itr)->getName() == old_follower.getName())
		{
			followers.erase(itr);
			old_follower.deletePage(*this); // Mutual action, the old follower delete the fan page from his list of pages
			break;
		}		
	}
}

void Page::addStatusForPage(Status& new_status)
{
	Status* newStatus = new Status(new_status);
	page_statuses.push_back(newStatus);
}

void Page::printFollowers() const
{
	int i = 0;
	vector<User*>::const_iterator itr = followers.begin();
	vector<User*>::const_iterator endItr = followers.end();
	for (; itr != endItr; ++itr)
		cout << ++i << ". " << (*itr)->getName() << endl;
}

void Page::printStatusesOfPage() const
{
	int i = 0;
	vector<Status*>::const_iterator itr = page_statuses.begin();
	vector<Status*>::const_iterator endItr = page_statuses.end();
	if (page_statuses.size() != 0)
		cout << "" << name << "'s statuses:" << endl;
	for (; itr != endItr; ++itr)
	{
		cout << ++i << ". ";
		(*itr)->printStatus();
	}
}

const Page& Page::operator+=(User& follower)
{
	addFollower(follower);
	return *this;
}

bool Page::operator>(const Page& other) const
{
	return (this->followers.size() > other.followers.size()); 
}

bool Page::operator>(const User& user)
{
	return (this->followers.size() > user.getNumOfFriends());
}