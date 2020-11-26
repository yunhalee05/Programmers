#include <string>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;


long long solution(int n, vector<int> times) {
    sort(times.begin(), times.end());
    int number = times.size();
    long long lt = 0;
    long long rt = (long long)times[number - 1] * n;
    long long answer = (long long)times[number - 1] * n;

    while (lt <= rt)
    {
        long long mid = (lt + rt) / 2;
        long long cnt = 0;
        for (int i = 0; i < number; i++)
        {
            cnt += mid / times[i];
        }
        if (cnt < n)
        {
            lt = mid + 1;
        }
        else
        {
            rt = mid - 1;

            if (answer > mid)
            {
                answer = mid;
            }
        }
    }

    return answer;
}