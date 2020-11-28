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
        if (ch[atoi(now.c_str())] == 0)//�̹� ���� ��찡 �ƴ� ��쿡�� ������ ����� �� ���տ� �����ش�.
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
        if (tmp == 1 || tmp == 0)continue;//1�̰ų� 0�̸� �Ҽ��� �ƴϸ� �������ְ� ���

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
//ó���� �ߴ� ��, ����
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

    return answer;//�������� �� ��츦 ��������� �Ѵ�.
}



//�ι�° �ߴ� ��
#include <string>
#include <vector>
#include <stdlib.h>
#include <iostream>

using namespace std;

vector<int> number;
vector<int> ch(10000000);

void Makenumber(string& numbers, int n, string now)//�̷����ϸ� ������ �������͸� ����Ǽ� �ȵȴ�.
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
        if (tmp == 1 || tmp == 0)continue;//�̷��� �������� ���� ������ ������θ� �߱� ������ ������ ������ �ʴ´�.

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