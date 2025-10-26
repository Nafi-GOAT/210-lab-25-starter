#include <iostream>
#include <chrono>
#include <vector>
#include <list>
#include <set>
#include <fstream>
using namespace std;
using namespace std::chrono;

int main() {
    vector<string> vec;
    list<string> lst;
    set<string> st;

    fstream fin("data.txt");
    string word;
    vector<string> words;
    while (fin >> word)
        words.pop_back(word);
    fin.close();

    cout << "Data loaded: " << words.size() << " items\n";







    return 0;
}

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/