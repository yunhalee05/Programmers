#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> One = { 1,2,3,4,5 };
    vector<int> Two = { 2,1,2,3,2,4,2,5 };
    vector<int> Three = { 3,3,1,1,2,2,4,4,5,5 };
    vector<int> cnt(3, 0);
    int max = -1;

    for (int i = 0; i < answers.size(); i++)
    {
        int tmp1 = i % One.size();
        int tmp2 = i % Two.size();
        int tmp3 = i % Three.size();

        if (answers[i] == One[tmp1])
        {
            cnt[0]++;
            if (max < cnt[0])
            {
                max = cnt[0];
            }
        }
        if (answers[i] == Two[tmp2])
        {
            cnt[1]++;
            if (max < cnt[1])
            {
                max = cnt[1];
            }
        }
        if (answers[i] == Three[tmp3])
        {
            cnt[2]++;
            if (max < cnt[2])
            {
                max = cnt[2];
            }
        }
    }
    for (int i = 0; i < 3; i++)
    {
        if (cnt[i] == max)
        {
            answer.push_back(i + 1);
        }
    }

    return answer;
}