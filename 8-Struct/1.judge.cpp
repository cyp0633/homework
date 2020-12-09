//评委打分
#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
	pair<int, string> student[1000];
	int n, i, j, temp, maxScore, minScore;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		maxScore = -2147483647;
		minScore = 2147483647;
		cin >> student[i].second;
		student[i].first = 0;
		for (j = 0; j < 7; j++)
		{
			scanf("%d", &temp);
			student[i].first += temp;
			if (temp > maxScore)
				maxScore = temp;
			if (temp < minScore)
				minScore = temp;
		}
		student[i].first -= maxScore + minScore;
	}
	sort(student, student + n);
	for (i = n - 1; i >= 0; i--)
	{
		cout << student[i].second << ' ' << student[i].first << '\n';
	}
	return 0;
}