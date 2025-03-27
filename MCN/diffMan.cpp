#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cout << "Enter the number of bits: ";
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr[i] = x;
    }

    int prev = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
            cout << "|__|▔▔";
        else
        {
            if (prev == -1)
                cout << "▔▔|__";
            else
            {
                if (prev == 1)
                    cout << "__|▔▔";
                else
                    cout << "▔▔|__";
            }
        }
        prev = arr[i];
    }
    cout << endl;

    return 0;
}

/*
8
0 0 1 1 0 1 0 0

*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cout << "Enter the number of bits: ";
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr[i] = x;
    }

    // Initial waveform printing for the first bit
    if (arr[0] == 0)
        cout << "|__|";
    else
        cout << "__|\u203E\u203E";

    // Print the rest of the waveform based on transitions
    for (int i = 1; i < n; i++)
    {
        if (arr[i] == 0)
        {
            if (arr[i - 1] == 1)
                cout << "|__|";
            else
                cout << "  __|";
        }
        else
        {
            if (arr[i - 1] == 0)
                cout << "\u203E\u203E|";
            else
                cout << "|__";
        }
    }
    cout << endl;

    return 0;
}

/*
Sample Input:
8
0 0 1 1 0 1 0 0
*/
