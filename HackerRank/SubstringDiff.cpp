#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

int dirDiff(int k, string s1, string s2)
{
    int d = 0; //discrepancy counter
    int l = 0; //length
    int t = s1.size();
    
    //comparison loop moving s1
    for (int i = 0; i < t; i++)
    {
        d = 0; //reset
        if (l > t - i) break;
        
        //start and end indices of current substring
        int start = i;
        int subSize = 0;

        //compare each index
        for (int j = 0; j < t-i; j++)
        {
            if (subSize > t - i) break;
            //add to discrepancy counter if not same char
            if (s1.at(i + j) != s2.at(j))
            {
                d++;
            }

            subSize++;

            //remove from start until discrepancies are satisfactory or end of string is reached
            while (d > k && start < t)
            {        
                if (s1.at(start) != s2.at(start - i)) d--;
                start++;
                subSize--;
            }


            //replace l if new length is greater
            if (subSize > l) l = subSize;
        }
    }
    return l;
}

int substringDiff(int k, string s1, string s2)
{
    return max(dirDiff(k, s1, s2), dirDiff(k, s2, s1));
}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string kS1S2_temp;
        getline(cin, kS1S2_temp);

        vector<string> kS1S2 = split_string(kS1S2_temp);

        int k = stoi(kS1S2[0]);

        string s1 = kS1S2[1];

        string s2 = kS1S2[2];

        int result = substringDiff(k, s1, s2);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
