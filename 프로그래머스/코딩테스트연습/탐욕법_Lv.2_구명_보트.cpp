#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    sort(people.rbegin(), people.rend());//������������ �����ϰ� 
    int answer = 0;//���� ���ſ� ����� ������ ����� ���ļ� ���ѵǴ� ���Կ� �����ϴ��� ���� ���̴�. (�ȵȴٸ� ���� ���ſ� ��� 1�� �¿��� �Ѵ�. )
    int i = 0;
    int j = people.size() - 1;//�ִ� �θ� �¿�� �ִ� �ּ� ���� ���϶�� �Ͽ���. (�������� �ƴϱ� ������ weight�� ���� �����Ͽ� ��������� �߰��� �ʿ䰡 ����)

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