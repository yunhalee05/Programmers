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


/*이런식으로도 가능하다

#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int len = brown/2 +2;

    //(x-2)(y-2) = yellow;
    x*y = brown+yellow를 yellow제거 식으로 해결
    x+y = brown/2 +2;가 된다.


    int y = len-3;
    int x= 3;//가로세로는 최소 3이상이여야 하므로

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