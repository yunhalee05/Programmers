#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int x, y;
    int tmp = brown + yellow;


    for (int i = 3; i <= tmp - 3; i++)
    {
        if (tmp % i == 0)
        {
            x = i;
        }

        y = tmp / x;

        if ((x - 2) * (y - 2) == yellow)
        {
            answer.push_back(y);
            answer.push_back(x);
            break;
        }
    }

    return answer;
}


/*�̷������ε� �����ϴ�

#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int len = brown/2 +2;

    //(x-2)(y-2) = yellow;
    x*y = brown+yellow�� yellow���� ������ �ذ�
    x+y = brown/2 +2;�� �ȴ�.


    int y = len-3;
    int x= 3;//���μ��δ� �ּ� 3�̻��̿��� �ϹǷ�

    while(y>=x)
    {
        if(x*y ==brown+yellow)
        {
            answer.push_back(y);
            answer.push_back(x);
            break;
        }
        x++;
        y--;
    }


    return answer;
}*/