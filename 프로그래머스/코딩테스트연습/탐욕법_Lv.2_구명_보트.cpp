#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    sort(people.rbegin(), people.rend());//내림차순으로 정렬하고 
    int answer = 0;//가장 무거운 사람과 가벼운 사람을 합쳐서 제한되는 무게에 부합하는지 비교할 것이다. (안된다면 제일 무거운 사람 1명만 태워야 한다. )
    int i = 0;
    int j = people.size() - 1;//최대 두명만 태울수 있는 최소 값을 구하라고 하였다. (여러명이 아니기 때문에 weight를 따로 정의하여 여러사람을 추가할 필요가 없다)

    while (i <= j)
    {
        if (people[i] + people[j] <= limit)
        {
            j--;
        }
        i++;
        answer++;


    }
    return answer;
}