#include "PublishingHouse.h"
#include <iostream>


Article::Article(const char* headline, const char* author , const char* keyWords)
{
	initHeadline(headline);
	initAuthor(author);
	initKeyWords(keyWords);
}

Article::~Article()
{
	clear();
}


void Article::clear()
{
	delete[] headline;
	delete[] author;
	delete[] keyWords;
}

/// 
/// PRIVATE FUNCTIONS
/// 
/// 

void Article::initHeadline(const char* headline)
{
	this->headline = new char[std::strlen(headline) + 1];
	strcpy_s(this->headline, std::strlen(headline) + 1, headline);
}


void Article::initAuthor(const char* author)
{
	this->author = new char[std::strlen(author) + 1];
	strcpy_s(this->author, std::strlen(author) + 1, author);
}


void Article::initKeyWords(const char* keyWords)
{
	this->keyWords = new char[std::strlen(keyWords) + 1];
	strcpy_s(this->keyWords, std::strlen(keyWords) + 1, keyWords);
}


/// 
/// PrintedEdition
///
///

PrintedEdition::PrintedEdition(const char* headline, const char* publishingHouse, const char* genre, const char* summary, 
								const year_month& year_month, int number,const char* keyWords, double raiting, int uniqueLibraryNumber,
								const char* ISSN, const char* articleHeadline,const char* articleAuthor,const char* articleKeyWords)
{
	initHeadline(headline);
	initPublishingHouse(publishingHouse);
	initGenre(genre);
	initSummary(summary);
	m_year_month = year_month;
	m_number = number;
	initKeyWords(keyWords);
	m_raiting = raiting;
	m_uniqueLibraryNumber = uniqueLibraryNumber;
	initISSN(ISSN);
	initArticle(articleHeadline, articleAuthor, articleKeyWords);

}


PrintedEdition::PrintedEdition(const PrintedEdition& other)
{
	deepCopy(other);
}


PrintedEdition& PrintedEdition::operator=(const PrintedEdition& other)
{
	if (this != &other)
	{
		clear();
		deepCopy(other);
	}
	return *this;
}


PrintedEdition::~PrintedEdition()
{
	clear();
}

/// 
/// PRIVATE FUNCTIONS
/// 
/// 

void PrintedEdition::clear()
{
	delete[] m_headline;
	delete[] m_publishingHouse;
	delete[] m_genre;
	delete[] m_summary;
	m_number = 0;
	delete[] m_keyWords;
	m_raiting = 0.0;
	m_uniqueLibraryNumber = 0;
	delete[] m_ISSN;
}


void PrintedEdition::deepCopy(const PrintedEdition& other)
{
	initHeadline(other.m_headline);
	initPublishingHouse(other.m_publishingHouse);
	initGenre(other.m_genre);
	initSummary(other.m_summary);
	m_year_month = other.m_year_month;
	m_number = other.m_number;
	initKeyWords(other.m_keyWords);
	m_raiting = other.m_raiting;
	m_uniqueLibraryNumber = other.m_uniqueLibraryNumber;
	initISSN(other.m_ISSN);
	initArticle(other.m_article.headline, other.m_article.author, other.m_article.keyWords);
}


void PrintedEdition::initHeadline(const char* headline)
{
	m_headline = new char[std::strlen(headline) + 1];
	strcpy_s(m_headline, std::strlen(headline) + 1, headline);
}


void PrintedEdition::initPublishingHouse(const char* publishingHouse)
{
	m_publishingHouse = new char[std::strlen(publishingHouse) + 1];
	strcpy_s(m_publishingHouse, std::strlen(publishingHouse) + 1, publishingHouse);
}


void PrintedEdition::initGenre(const char* genre)
{
	m_genre = new char[std::strlen(genre) + 1];
	strcpy_s(m_genre, std::strlen(genre) + 1, genre);
}


void PrintedEdition::initSummary(const char* summary)
{
	m_summary = new char[std::strlen(summary) + 1];
	strcpy_s(m_summary, std::strlen(summary) + 1, summary);
}


void PrintedEdition::initKeyWords(const char* keyWords)
{
	m_keyWords = new char[std::strlen(keyWords) + 1];
	strcpy_s(m_keyWords, std::strlen(keyWords) + 1, keyWords);
}


void PrintedEdition::initISSN(const char* ISSN)
{
	m_ISSN = new char[std::strlen(ISSN) + 1];
	strcpy_s(m_ISSN, std::strlen(ISSN) + 1, ISSN);
}


void PrintedEdition::initArticle(const char* headline, const char* author, const char* keyWords)
{
	m_article = Article(headline, author, keyWords);
}

