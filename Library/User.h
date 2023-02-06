#pragma once
#include <chrono>
using namespace std::chrono;

class User
{
protected:
	User();

	User(const User& other);

	User& operator=(const User& other);

	~User();


private:
	char* m_username;
	char* m_password;
	year_month_day m_year_month;
	year_month_day m_lastOnline;
};

