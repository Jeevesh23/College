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

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
            cout << "__|▔▔";
        else
            cout << "▔▔|__";
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

int main() {
    int n;
    cout << "Enter the number of bits: ";
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr[i] = x;
    }

    const int bit_width = 5; // Width for each bit representation

    // Print the waveform
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0)
            cout << setw(bit_width) << "__|\u203E\u203E";
        else
            cout << setw(bit_width) << "\u203E|__";
    }
    cout << endl;

    return 0;
}

/*
Sample Input:
8
0 0 1 1 0 1 0 0
*/
