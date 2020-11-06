#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    bool check[201] = { false, };
    int sum;
    for (int i = 0; i < numbers.size() - 1; i++)
    {
        for (int j = i + 1; j < numbers.size(); j++)
        {
            sum = numbers[i] + numbers[j];
            if (check[numbers[i] + numbers[j]] == false)
            {
                check[numbers[i] + numbers[j]] = true;
                answer.push_back(sum);
            }
        }

    }
    sort(answer.begin(), answer.end());

    return answer;
}