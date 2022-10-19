
#include <bits/stdc++.h>

using namespace std;

int main()

{

ios_base::sync_with_stdio(false);

cin.tie(NULL);

long long int n;

cin >> n;

long long int arr[n];

for (long long int i = 0; i < n; i++)

    cin >> arr[i];

long long int c = 0;

for (long long int i = 0; i < n - 1; i++)

{

    if (arr[i + 1] < arr[i])

    {

        c += arr[i] - arr[i + 1];

        arr[i + 1] = arr[i];

    }

}

cout << c;

return 0;
}
