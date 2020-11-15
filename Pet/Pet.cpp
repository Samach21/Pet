#include<stdio.h>

struct Person
{
	int n;
	int score;
};

void whowin(Person*, int*);

int main()
{
	Person person;
	int a[5][4];
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (scanf_s("%d", &a[i][j]) != 1)
			{
				printf("ERROR");
				return 1;
			}
			else if (a[i][j] < 1 || a[i][j] > 5)
			{
				printf("ERROR");
				return 1;
			}
		}
	}
	whowin(&person, &a[0][0]);
	printf("%d %d", person.n, person.score);
	return 0;
}

void whowin(Person* p, int* x)
{
	p->score = 0;
	p->n = 0;
	int preScore;
	int preN = 1;
	for (int i = 0; i < 5; i++, preN++)
	{
		preScore = 0;
		for (int j = 0; j < 4; j++, x++)
		{
			preScore = preScore + *x;
		}
		if (preScore == p->score)
		{
			printf("%d,", p->n);
			p->n = preN;
		}
		else if (preScore > p->score)
		{
			p->score = preScore;
			p->n = preN;
		}
	}
}
