#pragma once
#include <string>
#include <chrono>

using namespace std::chrono;


class Book
{
public:

	Book(const char* author = "", const char* headline = "", const char* publishingHouse = "", const char* genre = "",
			const char* summary = "", const year& year = year(), const char* keyWords = "", double raiting = 0.0,
				int uniqueLibraryNumber = 0, const char* ISBN = "");

	Book(const Book& other);

	Book& operator=(const Book& other);

	~Book();

private:

	char* m_author;
	char* m_headline;
	char* m_publishingHouse;
	char* m_genre;
	char* m_summary;
	year m_year;
	char* m_keyWords;
	double m_raiting;
	int m_uniqueLibraryNumber;
	char* m_ISBN;

	void clear();

	void deepCopy(const Book& other);

	void initAuthor(const char* author);

	void initHeadline(const char* headline);

	void initPublishingHouse(const char* publishingHouse);

	void initGenre(const char* genre);

	void initSummary(const char* summary);

	void initKeyWords(const char* keyWords);

	void initISBN(const char* ISBN);



};
