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


    // printing all the highs
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 1)
            cout << " high ";
        else
            cout << "    ";
    }
    cout << endl;


    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
            cout << "____";
        else
            cout << "▔▔▔▔";
        if (i != n - 1)
            cout << "|";
    }
    cout << endl;

    // printing all the lows
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
            cout << "  low ";
        else
            cout << "    ";
    }
    cout << endl;
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

    // Calculate the width for each bit representation
    const int bit_width = 5; // Adjust width for symmetry

    // Printing all the highs
    for (int i = 0; i < n; i++) {
        if (arr[i] == 1)
            cout << setw(bit_width) << "high";
        else
            cout << setw(bit_width) << " ";
    }
    cout << endl;

    // Print the waveform
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0)
            cout << string(bit_width, '_');
        else
            cout << string(bit_width, '\u203E');
        
        // Print the transition only if it's not the last bit
        if (i != n - 1) {
            if (arr[i] != arr[i + 1])
                cout << "|";
            else
                cout << " ";
        }
    }
    cout << endl;

    // Printing all the lows
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0)
            cout << setw(bit_width) << "low";
        else
            cout << setw(bit_width) << " ";
    }
    cout << endl;

    return 0;
}

/*
Sample Input:
8
0 0 1 1 0 1 0 0
*/