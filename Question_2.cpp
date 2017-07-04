#include <bits/stdc++.h>

using namespace std;

void print_most_five_words(string xx) {
    stringstream Input(xx);
    // I choosed the map datastructure because it hashes the strings for me and count their repeatitions
    // time for instertion and sorting O(N*logN)
    map<string, int> mem;
    string temp = "";
    while ((Input.rdbuf()->in_avail())) {
        Input >> temp;
        transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
        mem[temp]++;
    }
    // I choosed the priority_queue datastructure because it will sort the elements and gets me back the top X in O(1) each
    // time for instertion and sorting O(N*logN)
    priority_queue<int> sorted;
    for (auto x : mem)
        sorted.push(x.second);
    for (int i = 0; i < 5; ++i) {
        printf("%d\n", sorted.top());
        sorted.pop();
    }
}

int main(void) {
    string Input("Yo ho, yo ho, a pirate's life for me\n"
                         "We pillage, we plunder, we rifle, and loot\n"
                         "Drink up, me 'earties, yo ho\n"
                         "We kidnap and ravage and don't give a hoot\n"
                         "Drink up me 'earties, yo ho\n"
                         "\n"
                         "Yo ho, yo ho, a pirate's life for me\n"
                         "We extort, we pilfer, we filch, and sack\n"
                         "Drink up, me 'earties, yo ho\n"
                         "Maraud and embezzle, and even high-jack\n"
                         "Drink up, me 'earties, yo ho\n"
                         "\n"
                         "Yo ho, yo ho, a pirate's life for me\n"
                         "We kindle and char, inflame and ignite\n"
                         "Drink up, me 'earties, yo ho\n"
                         "We burn up the city, we're really a fright\n"
                         "Drink up, me 'earties, yo ho\n"
                         "\n"
                         "We're rascals, scoundrels, villans, and knaves\n"
                         "Drink up, me 'earties, yo ho\n"
                         "We're devils and black sheep, really bad eggs\n"
                         "Drink up, me 'earties, yo ho");
    print_most_five_words(Input);
}