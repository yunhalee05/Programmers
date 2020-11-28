#include <string>
#include <vector>
#include <stdlib.h>
#include <iostream>

using namespace std;

vector<int> number;
vector<int> ch(10000000, 0);
vector<int> ch2(10000000, 0);

void Makenumber(string& numbers, int n, string now)
{

    if (n == numbers.length())
    {
        if (ch[atoi(now.c_str())] == 0)//이미 나온 경우가 아닐 경우에만 나오는 경우의 수 집합에 더해준다.
        {
            ch[atoi(now.c_str())]++;
            number.push_back(atoi(now.c_str()));
        }

        return;
    }
    else {
        for (int i = 0; i < numbers.size(); i++)
        {
            if (ch2[i] == 0)
            {
                ch2[i] = 1;
                Makenumber(numbers, n + 1, now + numbers[i]);
                ch2[i] = 0;
                Makenumber(numbers, n + 1, now);
            }
        }
    }
    return;
}
int solution(string numbers) {

    int answer = 0;
    Makenumber(numbers, 0, "");

    for (int i = 0; i < number.size(); i++)
    {

        bool flag = true;
        int tmp = number[i];
        if (tmp == 1 || tmp == 0)continue;//1이거나 0이면 소수가 아니면 제외해주고 계산

        for (int j = 2; j <= tmp / 2; j++)
        {
            if (tmp % j == 0)
            {
                flag = false;
                break;
            }
        }

        if (flag == true)
        {
            answer++;
        }
    }

    return answer;
}

/*
//처음에 했던 답, 실패
#include <string>
#include <vector>
#include <stdlib.h>
#include <iostream>

using namespace std;

vector<int> number;
vector<int> ch(10000000);

void Makenumber(string& numbers, int n, string now)
{
    if (n == numbers.length())
    {
        number.push_back(atoi(now.c_str()));
        ch[atoi(now.c_str())]++;
        return ;
    }
    else {
        Makenumber(numbers, n + 1, now);
        Makenumber(numbers, n + 1, now + numbers[n]);
    }
    return ;
}
int solution(string numbers) {

    int answer = 0;

    Makenumber(numbers, 0, "");

    for (int i = 0; i < number.size(); i++)
    {
        if (ch[number[i]] == 1)
        {
            bool flag = true;
            int tmp = number[i];

            for (int j = 2; j < (tmp / 2) + 1; j++)
            {
                if (tmp % j == 0)
                {
                    flag = false;
                    break;
                }
            }

            if (flag == true)
            {
                answer++;
            }
        }
    }

    return answer;//공집합이 될 경우를 제외해줘야 한다.
}



//두번째 했던 답
#include <string>
#include <vector>
#include <stdlib.h>
#include <iostream>

using namespace std;

vector<int> number;
vector<int> ch(10000000);

void Makenumber(string& numbers, int n, string now)//이렇게하면 순서가 맞춰진것만 실행되서 안된다.
{

    if (n == numbers.length())
    {
        if (ch[atoi(now.c_str())] == 0)
        {
            ch[atoi(now.c_str())]++;
            number.push_back(atoi(now.c_str()));
        }

        return;
    }
    else {
        Makenumber(numbers, n + 1, now);
        Makenumber(numbers, n + 1, now + numbers[n]);
    }
    return;
}
int solution(string numbers) {

    int answer = 0;
    Makenumber(numbers, 0, "");

    for (int i = 0; i < number.size(); i++)
    {

        bool flag = true;
        int tmp = number[i];
        if (tmp == 1 || tmp == 0)continue;//이렇게 해줬지만 앞의 정해진 순서대로만 했기 때문에 정답이 나오지 않는다.

        for (int j = 2; j <= tmp / 2; j++)
        {
            if (tmp % j == 0)
            {
                flag = false;
                break;
            }
        }

        if (flag == true)
        {
            answer++;
        }
    }

    return answer;
}
*/