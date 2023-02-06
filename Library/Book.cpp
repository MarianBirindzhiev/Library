#include "Book.h"


Book::Book(const char* author, const char* headline, const char* publishingHouse, const char* genre,
			const char* summary, const year& year, const char* keyWords, double raiting,
				int uniqueLibraryNumber, const char* ISBN)
{
	initAuthor(author);
	initHeadline(headline);
	initPublishingHouse(publishingHouse);
	initGenre(genre);
	initSummary(summary);
	m_year = year;
	initKeyWords(keyWords);
	m_raiting = raiting;
	m_uniqueLibraryNumber = uniqueLibraryNumber;
	initISBN(ISBN);
}


Book::Book(const Book& other)
{
	deepCopy(other);
}


Book& Book::operator=(const Book& other)
{
	if (this != &other)
	{
		clear();
		deepCopy(other);
	}
}


Book::~Book()
{
	clear();
}

/// 
/// Private functions
///
///

void Book::clear()
{
	delete[] m_author;
	delete[] m_headline;
	delete[] m_publishingHouse;
	delete[] m_genre;
	delete[] m_summary;
	delete[] m_keyWords;
	m_raiting = 0.0;
	m_uniqueLibraryNumber = 0;
	delete[] m_ISBN;
}


void Book::deepCopy(const Book& other)
{
	initAuthor(other.m_author);
	initHeadline(other.m_headline);
	initPublishingHouse(other.m_publishingHouse);
	initGenre(other.m_genre);
	initSummary(other.m_summary);
	m_year = other.m_year;
	initKeyWords(other.m_keyWords);
	m_raiting = other.m_raiting;
	m_uniqueLibraryNumber = other.m_uniqueLibraryNumber;
	initISBN(other.m_ISBN);
}


void Book::initAuthor(const char* author)
{
	m_author = new char[std::strlen(author) + 1];
	strcpy_s(m_author, std::strlen(author) + 1, author);
}


void Book::initHeadline(const char* headline)
{
	m_headline = new char[std::strlen(headline) + 1];
	strcpy_s(m_headline, std::strlen(headline) + 1, headline);
}


void Book::initPublishingHouse(const char* publishingHouse)
{
	m_publishingHouse = new char[std::strlen(publishingHouse) + 1];
	strcpy_s(m_publishingHouse, std::strlen(publishingHouse) + 1, publishingHouse);
}


void Book::initGenre(const char* genre)
{
	m_genre = new char[std::strlen(genre) + 1];
	strcpy_s(m_genre, std::strlen(genre) + 1, genre);
}


void Book::initSummary(const char* summary)
{
	m_summary = new char[std::strlen(summary) + 1];
	strcpy_s(m_summary, std::strlen(summary) + 1, summary);
}


void Book::initKeyWords(const char* keyWords)
{
	m_keyWords = new char[std::strlen(keyWords) + 1];
	strcpy_s(m_keyWords, std::strlen(keyWords) + 1, keyWords);
}


void Book::initISBN(const char* ISBN)
{
	m_ISBN = new char[std::strlen(ISBN) + 1];
	strcpy_s(m_ISBN, std::strlen(ISBN) + 1, ISBN);
}

