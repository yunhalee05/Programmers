#include <string>
#include <vector>

using namespace std;


int solution(string name) {
    int answer = 0;
    int Size = name.length();
    string tmp(Size, 'A');

    int i = 0;

    while (1)
    {
        if (name[i] != 'A')//위아래로 움직이는 경우(더 빨리 바꿀수 있는 수를 더함)
        {
            (name[i] - 'A') > ('Z' + 1 - name[i]) ? answer += ('Z' + 1 - name[i]) : answer += (name[i] - 'A');
            tmp[i] = name[i];
        }

        if (name == tmp) break;

        else//좌우로 커서를 옮길때
        {
            int right = (i + 1) % name.length();
            int right_cnt = 1;
            while (name[right] == 'A' || tmp[right] == name[right])//오른쪽으로 옮길때
            {
                right_cnt++;
                right = (right + 1) % name.length();

            }
            int left = (i + name.length() - 1) % name.length();
            int left_cnt = 1;
            while (name[right] == 'A' || tmp[left] == name[left])//왼쪽으로 옮길때
            {
                left = (left + name.length() - 1) % name.length();
                left_cnt++;
            }
            if (left_cnt < right_cnt)//두개의 수를 비교해서 더 짧은 것을 더하고 i의 값을 현재위치로 바꿔준다. (반복)
            {
                answer += left_cnt;
                i = left;
            }
            else
            {
                answer += right_cnt;
                i = right;
            }

        }

    }

    return answer;
}