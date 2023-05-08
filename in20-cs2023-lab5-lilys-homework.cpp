#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'lilysHomework' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

// This Function swaps two integers given as input
void swap(int* a, int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}


int lilysHomework(vector<int> arr) {
    vector<int> arr2, arr_asc, arr_dsc;
    arr2 = arr;
    arr_asc = arr;
    arr_dsc = arr;
    
    sort(arr_asc.begin(), arr_asc.end());
    sort(arr_dsc.begin(), arr_dsc.end(), greater<int>());
    int n = arr.size();
    int left_swaps = 0, right_swaps = 0;
    
    int i = 0;
    while(1)
    {
        if(arr[i] != arr_asc[i])
        {
            
            auto ind_arr = find(arr.begin(), arr.end(), arr_asc[i]);
            if(ind_arr != arr.end())
            {
                int indx = ind_arr - arr.begin();
                swap(&arr[i], &arr[indx]);
                left_swaps++;
                continue;
            }       
        }
        if(i == n-1){
                break;
        }
        i++;
    
    }
    i = 0;
    while(1)
    {
        if(arr2[i] != arr_dsc[i])
        {
            
            auto ind_arr = find(arr2.begin(), arr2.end(), arr_dsc[i]);
            if(ind_arr != arr2.end())
            {
                int indx = ind_arr - arr2.begin();
                swap(&arr2[i], &arr2[indx]);
                right_swaps++;
                continue;
            }       
        }
        if(i == n-1){
                break;
        }
        i++;
    
    }

    return min(left_swaps, right_swaps);
        
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int result = lilysHomework(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
