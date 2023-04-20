#ifndef __USER_H
#define __USER_H

#include "Header.h"
#include "Exceptions.h"

class Status;
class Page;

class User  // class of a friend in the Facebook system
{
private:
	std::string name;
	Date date_of_birth;
	std::vector<User*> friends;
	std::vector<Status*> my_statuses;
	std::vector<Page*> fan_pages;
	User(const User& other) = default;

public:
	User() = delete;
	User(const std::string& name, const Date& date_of_birth) : name(name) {
		if (date_of_birth.day > MAX_DAYS_IN_MONTH || date_of_birth.day < ONE ||
			date_of_birth.month > MAX_MONTHS_IN_YEAR || date_of_birth.month < ONE) //Check if the date input is correct
			throw DateException();
		this->date_of_birth = date_of_birth;
	}
	~User();
	void addFriend(User& new_friend) noexcept(false);
	void deleteFriend(User& old_friend);
	void addStatusForUser(Status& new_status);
	void addPage(Page& new_page);
	void deletePage(Page& old_page);
	const std::string& getName() const { return name; }
	const Date& getDateOfBirth() const { return date_of_birth; }
	void printFriends() const;
	void printStatusesOfUser() const;
	void printFriendsStatuses() const;
	void printFanPages() const;
	const int getNumOfFriends() const { return friends.size(); }

	bool operator>(const Page& page) const;
	bool operator<(const Page& page) const { return !(*this > page); }
	bool operator>(const User& user) const;
	bool operator<(const User& user) const { return !(*this > user); }
	const User& operator+=(User& user);

	friend class Facebook;
};

#endif