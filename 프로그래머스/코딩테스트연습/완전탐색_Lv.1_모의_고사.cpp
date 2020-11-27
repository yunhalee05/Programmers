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

    /*
    1. 여기서 max를 일일이 따로 지정해주지 않고,[algorithm]을 include하고 for 문을 다 돌고나서
    int max = *max_element(cnt.begin(), cnt.end());
    를 사용해주면 훨씬 간결하게 할 수 있다. 


    2. 또 %를 이용해서 일일이 써주지 말고 바로 
    answer[i]==One[i/One.size()]이런식으로 넣어줘서 더 간결하게 할 수도 있다. 

   */
    for (int i = 0; i < 3; i++)
    {
        if (cnt[i] == max)
        {
            answer.push_back(i + 1);
        }
    }

    return answer;
}