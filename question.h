#ifndef QUESTION_H
#define QUESTION_H

#include <string>
#include <vector>
#include <fstream>
#include <stdio.h>
#include <windows.h>
#include <cstdlib>


//POLYMORPHISM virtual void show(); !!!!!!

int qID = 0;
int eID = 0;
int mID = 0;
int xID = 0;


class Question
{
public:
	int id{};
	std::string q{};
	std::string answers[4]{};
	std::string level{};
	int correct{};
	Question();
	Question(std::string quest, std::string ans[4], int cor);
	~Question();
	virtual void read();
	void show(int id, int color);
	bool check(char ans, Question c);
	bool operator==(const Question& question);
};

class Easy : public Question
{
	int eID{};
public:
	Easy();
	Easy(std::string quest, std::string ans[4], int cor);
	~Easy();
	virtual void read() override;
};

class Medium : public Question
{
	int mID{};
public:
	Medium();
	Medium(std::string quest, std::string ans[4], int cor);
	~Medium();
	virtual void read() override;
};

class Expert : public Question
{
	int xID{};
public:
	Expert();
	Expert(std::string quest, std::string ans[4], int cor);
	~Expert();
	virtual void read() override;
};

Question* q;
std::vector<Question> questions;

#endif
