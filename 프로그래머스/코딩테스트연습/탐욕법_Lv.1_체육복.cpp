#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    int tmp = lost.size();

    for (int j = 0; j < lost.size(); j++)//여유분이 있지만 도난당한 경우 다른사람한테 빌려줄 수 없음
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
            if (reserve[i] != -1 && reserve[i] == (lost[j] - 1))//자기보다 앞 순서에 여분이 있는 경우 뒷사람이 빌릴 경우의 수가 더 많아진다. (먼저해주기)
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
처음에 했던 방법
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
            else if (reserve[i] != -1 && reserve[i] == lost[j])//도난당한 사람과 여분이 있는 사람이 같을 경우
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
}//12번째 케이스만 실행이 안된다.(자기가 여분이 있고 자기가 도난당한 경우에는 빌려줄 수 없기 때문!



//이러한 방법으로 더 간단하게도 할 수 있다. 
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
}//실행이 안되었으므로 다시 공부해보기
*/