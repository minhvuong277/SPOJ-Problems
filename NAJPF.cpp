#include <iostream>
#include <string>
#include <vector>

using namespace std;

int t;

void constructLps(string &pat, vector<int> &lps) {

    // len stores the length of longest prefix which is also a suffix for the previous index
    int len = 0;

    // lps[0] is always 0
    lps[0] = 0;

    int i = 1;
    while (i < pat.length()) {

        // If characters match, increment the size of lps
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        }

        // If there is a mismatch
        else {
            if (len != 0) {

                // Update len to the previous lps value
                len = lps[len - 1];
            }
            else {

                // If no matching prefix found, set lps[i] to 0
                lps[i] = 0;
                i++;
            }
        }
    }
}

vector<int> search(string &pat, string &s)
{
    int n = s.length();
    int m = pat.length();

    vector<int> lps(m);
    vector<int> res;

    constructLps(pat, lps);

    // i and j, for traversing the text and pattern
    int i = 0;
    int j = 0;

    while (i<n)
    {
        // If characters match, move both pointers forward
        if (s[i] == pat[j])
        {
            i++; j++;

            // If the entire pattern is matched, store the start index in result
            if (j == m)
            {
                res.push_back(i-j);
                j = lps[j-1]; // update pointer j
            }
        }
        else // If there is a mismatch
        {
            // Use lps value of previous index to avoid redundant comparisons
            if (j!=0)
                j = lps[j-1];
            else
                i++;
        }
    }

    return res;
}

void Example()
{
    // result is 0 9 12
    /*
    string txt = "aabaacaadaabaaba";
    string pat = "aaba";

    vector<int> res = search(pat, txt);
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    */
}

void Process()
{
    cin >> t;
    string txt, pat;

    // Traverse each line
    for (int i = 0; i < t; i++)
    {
        cin >> txt >> pat;

        vector<int> res = search(pat, txt);
        int res_size = res.size();
        if (res_size > 0)
        {
            cout << res_size << endl;
            for (int i = 0; i < res_size; i++)
                cout << res[i]+1 << " ";
            cout << endl;
        }
        else
        {
            cout << "Not Found" << endl;
        }
    }
}

int main()
{
    //Example();

    Process();

    return 0;
}
