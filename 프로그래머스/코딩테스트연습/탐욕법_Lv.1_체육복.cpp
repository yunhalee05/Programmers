#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    int tmp = lost.size();

    for (int j = 0; j < lost.size(); j++)//�������� ������ �������� ��� �ٸ�������� ������ �� ����
    {
        for (int i = 0; i < reserve.size(); i++)
        {
            if (reserve[i] == lost[j])
            {
                reserve[i] = -1;
                lost[j] = -1;
            }
        }
    }
    for (int j = 0; j < lost.size(); j++)
    {
        for (int i = 0; i < reserve.size(); i++)
        {
            if (reserve[i] != -1 && reserve[i] == (lost[j] - 1))//�ڱ⺸�� �� ������ ������ �ִ� ��� �޻���� ���� ����� ���� �� ��������. (�������ֱ�)
            {
                reserve[i] = -1;
                lost[j] = -1;
            }

            else if (reserve[i] != -1 && reserve[i] == (lost[j] + 1))
            {
                reserve[i] = -1;
                lost[j] = -1;
            }
        }
    }
    for (int i = 0; i < lost.size(); i++)
    {
        if (lost[i] != -1)
        {
            answer--;
        }
    }
    return answer + n;
}

/*
ó���� �ߴ� ���
#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    int tmp = lost.size();

    for (int j = 0; j < lost.size(); j++)
    {
        for (int i = 0; i < reserve.size(); i++)
        {
            if (reserve[i] != -1 && reserve[i] == (lost[j] - 1))
            {
                reserve[i] = -1;
                lost[j] = -1;
            }
            else if (reserve[i] != -1 && reserve[i] == lost[j])//�������� ����� ������ �ִ� ����� ���� ���
            {
                reserve[i] = -1;
                lost[j] = -1;
            }
            else if (reserve[i] != -1 && reserve[i] == (lost[j] + 1))
            {
                reserve[i] = -1;
                lost[j] = -1;
            }
        }
    }
    for (int i = 0; i < lost.size(); i++)
    {
        if (lost[i] != -1)
        {
            answer--;
        }
    }
    return answer + n;
}//12��° ���̽��� ������ �ȵȴ�.(�ڱⰡ ������ �ְ� �ڱⰡ �������� ��쿡�� ������ �� ���� ����!



//�̷��� ������� �� �����ϰԵ� �� �� �ִ�. 
#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> student(n, 0);
    for (int i = 0; i < lost.size(); i++)
    {
        student[lost[i]]--;
    }
    for (int i = 0; i < reserve.size(); i++)
    {
        student[reserve[i]]++;
    }
    for (int i = 0; i < n; i++)
    {
        if (student[i] == -1)
        {
            if (i != 0 && student[i - 1] == 1)
            {
                student[i] = student[i - 1] = 0;
            }
            else if (i != n - 1 && student[i + 1] == 1)
            {
                student[i] = student[i + 1] = 0;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (student[i] != -1)
            answer++;
    }
    return answer;
}//������ �ȵǾ����Ƿ� �ٽ� �����غ���
*/