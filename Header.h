#ifndef __HEADER_H
#define __HEADER_H

#include <iostream>
#include <vector>
#include <string>
#pragma warning(disable: 4996)

#define ONE 1
#define TWO 2
#define THREE 3
#define FOUR 4
#define FIVE 5
#define SIX 6
#define SEVEN 7
#define EIGHT 8
#define NINE 9
#define TEN 10
#define ELEVEN 11
#define TWELVE 12
#define MAX_NAME_LEN 100
#define MAX_STATUS_LEN 1000
#define INVALID -1
#define VALID 0
#define EXIT 12
#define MAX_MONTHS_IN_YEAR 12
#define MAX_DAYS_IN_MONTH 31

struct Date {
	int day, month, year;
};

#include "user.h"
#include "page.h"
#include "Facebook.h"
#include "status.h"
#include "functions.h"

#endif // !__HEADER_H

