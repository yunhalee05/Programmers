#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string, int> m;
    for (int i = 0; i < completion.size(); i++)
    {
        string key = completion[i];
        m[key] += 1;
    }
    for (int i = 0; i < participant.size(); i++)
    {
        string key = participant[i];

        if (m[key] == 0)
        {
            answer = key;
            break;
        }
        else
        {
            m[key] -= 1;
        }
    }
    return answer;
}