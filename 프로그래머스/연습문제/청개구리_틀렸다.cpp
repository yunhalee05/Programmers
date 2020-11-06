#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main()
{
	string word;
	int ans[1001];
	getline(cin, word);


	for (int i = 0; word[i] != '\0'; i++)
	{
		int num = word[i];

		if (word[i] == ' ')
		{
			ans[i] = 32;
		}

		else if (65 <= num && num <= 77)
		{
			int tmp = num + (27 - 2 * (num - 64));
			ans[i] = tmp;
		}
		else if (78 <= num && num <= 90)
		{
			int tmp = num - (2 * (num - 77));
			ans[i] = tmp;
		}
		else if (97 <= num && num <= 109)
		{
			int tmp = num + (27 - 2 * (num - 96));
			ans[i] = tmp;
		}
		else if (110 <= num && num <= 122)
		{
			int tmp = num - (2 * (num - 109));
			ans[i] = tmp;
		}
		else
		{
			ans[i] = (int)word[i];
		}


	}

	for (int i = 0; i < word.length(); i++)
	{
		cout << char(ans[i]);
	}

	return 0;
}