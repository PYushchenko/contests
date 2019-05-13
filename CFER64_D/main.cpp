#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;


long long submax(vector<long long> a, int start, int end, int x) {
        for (int i = start; i <= end; i++) a[i] *= x;

    long long max_so_far = 0, max_ending_here = 0;

    for (int i = 0; i < a.size(); i++) {
        max_ending_here += a[i];

        if (max_so_far < max_ending_here) {
            max_so_far = max_ending_here;
        }

        if (max_ending_here < 0) {
            max_ending_here = 0;
        }
    }
    return max_so_far;
}


long long submax2(vector<long long> a, int start, int end) {
    long long max_so_far = 0, max_ending_here = 0;

    for (int i = start; i <= end; i++) {
        max_ending_here += a[i];

        if (max_so_far < max_ending_here) {
            max_so_far = max_ending_here;
        }

        if (max_ending_here < 0) {
            max_ending_here = 0;
        }
    }
    return max_so_far;
}

int main() {
    int n, x;
    cin >> n >> x;

    vector<long long> a;

    for (int i = 0; i < n; i++) {
        long long tmp;
        cin >> tmp;
        a.push_back(tmp);
    }

    if (x == 0) {
        int max_so_far = INT_MIN, max_ending_here = 0,
                start =0, end = 0, s=0;

        for (int i=0; i< n; i++ )
        {
            max_ending_here += a[i];

            if (max_so_far < max_ending_here)
            {
                max_so_far = max_ending_here;
                start = s;
                end = i;
            }

            if (max_ending_here < 0)
            {
                max_ending_here = 0;
                s = i + 1;
            }
        }

        long long q1 = submax2(a, 0, start - 1);
        long long q2 = submax2(a, end + 1, n - 1);
        cout << max_so_far + max(q1, q2);
        return 0;
    }


    if (x > 0) {
        long long max_so_far = 0, max_ending_here = 0;
        for (int i = 0; i < n; i++) {
            max_ending_here += a[i];

            if (max_so_far < max_ending_here) {
                max_so_far = max_ending_here;
            }

            if (max_ending_here < 0) {
                max_ending_here = 0;
            }
        }

        cout << max_so_far * x;
        return 0;
    } else {
        long long min_so_far = INT_MAX, min_ending_here = 0,
                start = 0, end = 0, s = 0;
        long long max_so_far = submax(a, 0, 0, 1);

        for (int i = 0; i < n; i++) {
            min_ending_here += a[i];

            if (min_so_far > min_ending_here) {
                min_so_far = min_ending_here;
                start = s;
                end = i;
            } else if (min_so_far == min_ending_here) {
                if (min_so_far < 0 ) {
                    long long tmp = submax(a, s, i, x);
                    max_so_far = max(max_so_far, tmp);
                }
            }

            if (x == 0) {
                if (min_ending_here < 0 ) {
                    long long tmp = submax(a, s, i, x);
                    max_so_far = max(max_so_far, tmp);
                }
            }

            if (min_ending_here > 0) {
                min_ending_here = 0;
                s = i + 1;
            }
        }

        if (min_so_far < 0 ) {
            long long tmp = submax(a, start, end, x);
            max_so_far = max(max_so_far, tmp);
        }


        cout << max_so_far;
    }


    return 0;
}