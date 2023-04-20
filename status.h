#ifndef __STATUS_H
#define __STATUS_H

#include "Header.h"

struct Text
{
	std::string content;
	std::string date_of_release;
};

class Status
{
private:
	Text text_status;
	Status(const Status& other) = default;
public:
	Status(const std::string& content)
	{
		text_status.content = content;
		time_t now = time(0);
		text_status.date_of_release = ctime(&now); // Put in the release date the time now
	}
	void printStatus() const;
	bool operator==(const Status& status) { return text_status.content == status.text_status.content; }
	bool operator!=(const Status& status) { return !(*this == status); }

	friend class User;
	friend class Page;
};

#endif