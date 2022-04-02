#include "question.h"

HANDLE hOut;

Question::Question()
{
	std::cout << "Loading Questions...\n";
}

Question::Question(std::string quest, std::string ans[], int cor)
{
	this->id = qID;
	qID++;
	this->q = quest;
	for (int i = 0; i < 4; i++)
		this->answers[i] = ans[i];
	this->correct = cor;

}

Question::~Question()
{
	//delete[] &questions;
}

void Question::read() //read all of the files for the random mode
{
	std::ifstream readAll;
	std::string fNames[3] = { "easy.txt", "medium.txt", "expert.txt" };
	std::string task, a[4];
	int cor;
	for (int i = 0; i < 3; i++)
	{
		readAll.open(fNames[i]);
		if (readAll.good())
		{
			while (!readAll.eof())
			{
				getline(readAll, task);
				for (int i = 0; i < 4; i++)
				{
					getline(readAll, a[i]);
					if (a[i][a[i].size() - 1] == '.')
						cor = i;
				}
			Question question(task, a, cor);
			questions.push_back(question);
			}
			
		}
		readAll.close();
	}
	std::cout << "Done!\n\n";
}

void Question::show(int id, int color)
{
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut, color);
	std::cout << questions[id].q << std::endl;
	for (int i = 0; i < 4; i++)
	{
		SetConsoleTextAttribute(hOut, 7); //7 is standard text color :)
		if (questions[id].correct == i)
		{
			for (int j = 0; j < (questions[id].answers[i].size() - 1); j++)
				std::cout << questions[id].answers[i][j];
			std::cout << std::endl;
		}
		else
			std::cout << questions[id].answers[i] << std::endl;
	}
}

bool Question::check(char ans, Question c)
{
	bool good = false;
	if (((int)ans - 49) == c.correct || ((int)ans - 65) == c.correct || ((int)ans - 97) == c.correct) //indexes in the answers array starts form 0! 
	{
		good = true;
		return good;
	}
	else
		return good;
}

bool Question::operator==(const Question& question)
{
	if (this->q == question.q && this->answers[this->correct] == question.answers[question.correct])
		return true;
	else
		return false;
}

Easy::Easy()
{
	std::cout << "Opening file easy.txt...\n";
}

Easy::Easy(std::string quest, std::string ans[], int cor)
{
	this->id = eID;
	eID++;
	this->q = quest;
	for (int i = 0; i < 4; i++)
		this->answers[i] = ans[i];
	this->correct = cor;
}

Easy::~Easy()
{

}

void Easy::read() //read the easy file for the easy mode
{
	std::ifstream readEasy;
	std::string task, a[4];
	int cor;
		readEasy.open("easy.txt");
		if (readEasy.good())
		{
			while (!readEasy.eof())
			{
				getline(readEasy, task);
				for (int i = 0; i < 4; i++)
				{
					getline(readEasy, a[i]);
					if (a[i][a[i].size() - 1] == '.')
						cor = i;
				}
				Question question(task, a, cor);
				questions.push_back(question);
			}

		}
		readEasy.close();
	std::cout << "Done!\n\n";
}

Medium::Medium()
{
	std::cout << "Opening file medium.txt...\n";
}

Medium::Medium(std::string quest, std::string ans[], int cor)
{
	this->id = mID;
	mID++;
	this->q = quest;
	for (int i = 0; i < 4; i++)
		this->answers[i] = ans[i];
	this->correct = cor;
}

Medium::~Medium()
{

}

void Medium::read() //read the meidum file for the medium mode
{
	std::ifstream readMedium;
	std::string task, a[4];
	int cor;
	readMedium.open("medium.txt");
	if (readMedium.good())
	{
		while (!readMedium.eof())
		{
			getline(readMedium, task);
			for (int i = 0; i < 4; i++)
			{
				getline(readMedium, a[i]);
				if (a[i][a[i].size() - 1] == '.')
					cor = i;
			}
			Question question(task, a, cor);
			questions.push_back(question);
		}

	}
	readMedium.close();
	std::cout << "Done!\n\n";
}

Expert::Expert()
{
	std::cout << "Opening file expert.txt...\n";
}

Expert::Expert(std::string quest, std::string ans[], int cor)
{
	this->id = xID;
	xID++;
	this->q = quest;
	for (int i = 0; i < 4; i++)
		this->answers[i] = ans[i];
	this->correct = cor;
}

Expert::~Expert()
{

}

void Expert::read() //read the expert file for the expert mode
{
	std::ifstream readExpert;
	std::string task, a[4];
	int cor;
	readExpert.open("expert.txt");
	if (readExpert.good())
	{
		while (!readExpert.eof())
		{
			getline(readExpert, task);
			for (int i = 0; i < 4; i++)
			{
				getline(readExpert, a[i]);
				if (a[i][a[i].size() - 1] == '.')
					cor = i;
			}
			Question question(task, a, cor);
			questions.push_back(question);
		}

	}
	readExpert.close();
	std::cout << "Done!\n\n";
}