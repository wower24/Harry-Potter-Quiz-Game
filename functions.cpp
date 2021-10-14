#include "functions.h"

void noRepeats(int s) //s is the size of an array equal to how many questions are about to be displayed
{
	bool ir;
	con = new int[s];
	int i = 0;
	while (i < s) //the goal here is to have s different questions (with different IDs)
	{
		ir = false;
		int x = std::rand() % questions.size();
		if (i == 0)
		{
			con[i] = x;
			i++;
		}
		else
		{
			for (int j = 0; j < i; j++)
			{
				if (x == con[j])
				{
					ir = true;
					break;
				}
			}
			if (!ir)
			{
				con[i] = x;
				i++;
			}
		}
	}
	//throw 17.5;
}

void play(int p)
{
	char answer;
	noRepeats(p * 10);
	for (int k = 0; k < p * 10; k++)
	{
		int col=11;
		int pID = 0;
		Question task = questions[con[k]];
		if (p == 2)
		{
			pID = k % 2;
			if (k % 2 == 0)
				col = 2;
			else
				col = 5;
		}
		task.show(con[k], col);
		std::cin >> answer;
		if (q->check(answer, task))
		{
			std::cout << "Congrats " << players[pID].name << "!\nThat's a good answer, you get a point!\n\n";
			players[pID].score++;
		}
		else
		{
			std::cout << "Sorry, the correct answer was: " << task.answers[task.correct] << " :(\nNo points this time!\n\n";
		}
	}
}