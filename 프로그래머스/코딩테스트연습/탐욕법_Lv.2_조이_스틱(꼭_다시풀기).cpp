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
        if (name[i] != 'A')//���Ʒ��� �����̴� ���(�� ���� �ٲܼ� �ִ� ���� ����)
        {
            (name[i] - 'A') > ('Z' + 1 - name[i]) ? answer += ('Z' + 1 - name[i]) : answer += (name[i] - 'A');
            tmp[i] = name[i];
        }

        if (name == tmp) break;

        else//�¿�� Ŀ���� �ű涧
        {
            int right = (i + 1) % name.length();
            int right_cnt = 1;
            while (name[right] == 'A' || tmp[right] == name[right])//���������� �ű涧
            {
                right_cnt++;
                right = (right + 1) % name.length();

            }
            int left = (i + name.length() - 1) % name.length();
            int left_cnt = 1;
            while (name[right] == 'A' || tmp[left] == name[left])//�������� �ű涧
            {
                left = (left + name.length() - 1) % name.length();
                left_cnt++;
            }
            if (left_cnt < right_cnt)//�ΰ��� ���� ���ؼ� �� ª�� ���� ���ϰ� i�� ���� ������ġ�� �ٲ��ش�. (�ݺ�)
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