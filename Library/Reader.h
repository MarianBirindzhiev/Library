#pragma once
#include <chrono>
#include "User.h"

using namespace std::chrono;

struct booksTracker
{
	char* takenBook;
	year_month_day dayTaken;
	year_month_day dayReturned;
};


class Reader : public User
{
public:

	Reader();

	Reader(const Reader& other);

	Reader& operator=(const Reader& other);

	~Reader();


private:
	std::vector<booksTracker> m_takenBooks;
};