#pragma once
#include <chrono>

using namespace std::chrono;

struct Article
{
	char* headline;
	char* author;
	char* keyWords;

	Article(const char* headline = "", const char* author = "", const char* keyWords = "");

	~Article();

private:

	void clear();

	void initHeadline(const char* headline);

	void initAuthor(const char* author);

	void initKeyWords(const char* keyWords);
};

class PrintedEdition
{
public:

	PrintedEdition(const char* headline = "", const char* publishingHouse = "", const char* genre = "", const char* summary = "",
					const year_month& year = year_month(), int number = 0, const char* keyWords = "", double raiting = 0.0, int uniqueLibraryNumber = 0, 
					const char* ISSN = "", const char* articleHeadline="", const char* articleAuthor="", const char* articleKeyWords="");

	PrintedEdition(const PrintedEdition& other);

	PrintedEdition& operator=(const PrintedEdition& other);

	~PrintedEdition();

private:
	char* m_headline;
	char* m_publishingHouse;
	char* m_genre;
	char* m_summary;
	year_month m_year_month;
	int m_number;
	char* m_keyWords;
	double m_raiting;
	int m_uniqueLibraryNumber;
	char* m_ISSN;
	Article m_article;


	void clear();

	void deepCopy(const PrintedEdition& other);

	void initHeadline(const char* headline);

	void initPublishingHouse(const char* publishingHouse);

	void initGenre(const char* genre);

	void initSummary(const char* summary);

	void initKeyWords(const char* keyWords);

	void initISSN(const char* ISSN);

	void initArticle(const char* headline, const char* author, const char* keyWords);

};