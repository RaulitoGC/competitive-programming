#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'repeatedString' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. STRING s
 *  2. LONG_INTEGER n
 */

long repeatedString(string s, long n) {
    int size = s.size();
    long res = 0;
    for(int i = 0 ; i < size ; i++){
        if(s[i] == 'a'){
            res++;
        }
    }
    
    cout << size % n << endl; // 3
    cout << n % size << endl;// 1
    int rest = n % size;
    if(rest != 0){
        res *= (n/size);
        for(int i = 0 ; i < rest ; i++){
            if(s[i] == 'a'){
                res++;
            }
        }
    }else{
        res *= (n/size);
    }
    
    return res;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string n_temp;
    getline(cin, n_temp);

    long n = stol(ltrim(rtrim(n_temp)));

    long result = repeatedString(s, n);

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
