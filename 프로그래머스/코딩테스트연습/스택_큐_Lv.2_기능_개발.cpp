#include <string>
#include <vector>
#include <stack>
#include<cmath>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    stack<int> s;

    for (int i = progresses.size() - 1; i >= 0; i--)
    {
        int num = (100 - progresses[i]) / speeds[i];
        if ((100 - progresses[i]) % speeds[i] != 0) num++;
        s.push(num);
    }
    int count = 1;
    int m = s.top();
    s.pop();
    while (!s.empty())
    {

        if (s.top() > m)
        {
            answer.push_back(count);
            count = 1;
            m = s.top();
            s.pop();
        }
        else
        {
            count++;
            s.pop();
        }

    }

    answer.push_back(count);

    return answer;
}




/*첫번째 답 : 부분실패
#include <string>
#include <vector>
#include <stack>
#include<cmath>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    stack<int> s;

    for (int i = progresses.size() - 1; i >= 0; i--)
    {
        int num = (100 - progresses[i]) / speeds[i];
        if ((100 - progresses[i]) % speeds[i] != 0) num++;
        s.push(num);
    }

    while (!s.empty())
    {
        int count = 0;
        int m = s.top();
        s.pop();
        count++;
        while (!s.empty() && s.top() < m)
        {
            count++;
            s.pop();
        }
        answer.push_back(count);
    }
    return answer;
}
*/
