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

    ifstream fin("data.txt");
    string word;
    vector<string> words;
    while (fin >> word)
        words.push_back(word);
    fin.close();

    cout << "Data loaded: " << words.size() << " items\n";

  // --- RACE 1:
    auto start = high_resolution_clock::now();
    for (auto &w : words) vec.push_back(w);
    auto end = high_resolution_clock::now();
    auto vecRead = duration_cast<microseconds>(end - start).count();

    start = high_resolution_clock::now();
    for (auto &w : words) lst.push_back(w);
    end = high_resolution_clock::now();
    auto listRead = duration_cast<microseconds>(end - start).count();

    start = high_resolution_clock::now();
    for (auto &w : words) st.insert(w);
    end = high_resolution_clock::now();
    auto setRead = duration_cast<microseconds>(end - start).count();
    
    // --- RACE 2:
    start = high_resolution_clock::now();
    sort(vec.begin(), vec.end());
    end = high_resolution_clock::now();
    auto vecSort = duration_cast<microseconds>(end - start).count();

    start = high_resolution_clock::now();
    lst.sort();
    end = high_resolution_clock::now();
    auto listSort = duration_cast<microseconds>(end - start).count();

    long setSort = -1;

    // --- RACE 3:
    string test = "TESTCODE";
    start = high_resolution_clock::now();
    vec.insert(vec.begin() + vec.size()/2, test);
    end = high_resolution_clock::now();
    auto vecInsert = duration_cast<microseconds>(end - start).count();

    start = high_resolution_clock::now();
    auto it = lst.begin();
    advance(it, lst.size()/2);
    lst.insert(it, test);
    end = high_resolution_clock::now();
    auto listInsert = duration_cast<microseconds>(end - start).count();

    start = high_resolution_clock::now();
    st.insert(test);
    end = high_resolution_clock::now();
    auto setInsert = duration_cast<microseconds>(end - start).count();
    
    // --- RACE 4:

    
    return 0;
}

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/