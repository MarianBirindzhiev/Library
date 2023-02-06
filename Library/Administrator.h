#pragma once
#include <chrono>
#include "User.h"

using namespace std::chrono;

class Administrator : public User
{
public:

	Administrator();

	Administrator(const Administrator& other);

	Administrator& operator=(const Administrator& other);

	~Administrator();

private:
	char* m_email;
	int m_libraryUniqueNumber;
};