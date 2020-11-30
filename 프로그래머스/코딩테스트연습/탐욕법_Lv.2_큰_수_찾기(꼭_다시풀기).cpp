#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int len = number.length() - k;
    int idx = -1;
    int j = 0;
    for (int i = 0; i < len; i++)
    {
        char max = '0';
        for (int j = idx + 1; j <= i + k; j++)
        {
            if (max < number[j])
            {
                max = number[j];
                idx = j;
            }
        }
        answer += max;
    }
    

    return answer;
}


