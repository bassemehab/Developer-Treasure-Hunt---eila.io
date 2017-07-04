#include <bits/stdc++.h>

using namespace std;

pair<int, string> split(string element) {
    pair<int, string> new_element(0, "");
    for (char j : element) {
        if (j >= 'a' && j <= 'z') {
            new_element.second += j;
        } else {
            new_element.first *= 10;
            new_element.first += (j - '0');
        }
    }
    return new_element;
}

string merge(string A[], unsigned len_A, string B[], unsigned len_B) {
    vector<pair<int, string> > a, b;
    //These two loops are meant to convert the array into vector of pair splitting the string from the integer
    //O(N * length(string_i)**split func)
    for (int i = 0; i < len_A; ++i)
        a.push_back(split(A[i]));
    for (int i = 0; i < len_B; ++i)
        b.push_back(split(B[i]));
    //This is could be skipped if the two elements was already sorted O(N*LogN)
    sort(a.begin(), a.end()), sort(b.begin(), b.end());
    vector<pair<int, string> > merged;
    int index_a = 0, index_b = 0;
    string the_resultant_string = "";
    //This the merging loop that runs in O(N+M) where N is the length of A, M is the length of B
    for (int i = 0; i < (len_A) + (len_B); ++i)
        if (index_b == len_B || (index_a < len_A && a[index_a].first < b[index_b].first))
            merged.push_back(a[index_a++]), the_resultant_string += merged[i].second;
        else
            merged.push_back(b[index_b++]), the_resultant_string += merged[i].second;
    return the_resultant_string;
}

int main(void) {
    string A[] = {"88b", "20v", "11i", "83m", "29r", "82i", "40m", "8h"};
    string B[] = {"51e", "5s", "22e", "64t", "90e", "91r", "99s"};
    cout << merge(A, 8, B, 7);
}