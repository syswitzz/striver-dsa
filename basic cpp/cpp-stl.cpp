#include<bits/stdc++.h>
using namespace std;


// array, pairs, vectors
// iterators
// lists, deque, stacks, queue, priority queue
// sets, multiset, unordered_set
// map, multimap, unordered map



// ARRAYS
void arrays() {
    // arrays are stored in consecutive order in the cpu but we are not sure of position of first array because it can be anything
    int array1[3] = {9, 8, 3};

    // operations on arrays
    array1[2] -= 3;
    cout << array1 [2];

    // 2D arrays
    int array1[3][2];
}


// PAIRS
void pairs() {
    pair<int, int> pair1 = {2, 4};    // this is a pair
    pair<int, int> pair2[3] = {{9,8}, {4,0}, {3, 8}};     // array of pairs
}


// VECTORS - same as arrays except its dynamic so you can add or remove values from it
void vectors() {
    vector<int> v1;               // v1 = {}
    vector<pair<int, int>> v2;    // v2 = {{}}
    vector<int> v3(3, 69);        // v3 = {69, 69, 69}
    vector<int> v4(2);            // v4 = {0, 0}
    vector<int> v5(v3);           // v5 = v2

    v2.push_back({2,4});     // v2 = {{2,4}}
    v2.emplace_back(1,5);    // v2 = {{2,4}, {1,5}}

    cout << v2[0].first << endl;       // '2' from  {{2,4}, {1,5}}
    cout << v2.back().first;           // '2' from  {{2,4}, {1,5}}
}


// ITERATORS
void iterators() {
    vector<int> v1 = {8, 4, 0, 2, 3};   // this is a simple vector
    vector<int>::iterator it;           // this is an iterator instance 'it'

    // vector.begin()
    it = v1.begin();     // now 'it' points to the memory location of '8' in 'v1'
    it = it +2;
    cout << *(it) << endl;       // prints "0" from {8, 4, 0, 2, 3}

    // vector.end()
    it = v1.end();       // now 'it-1' (VVIP) points to the memory location of '3'
    it--;
    cout << *(it) << endl;               // prints "3" from {8, 4, 0, 2, 3}

    // vector.rbegin()  -- points to 3 from v1 and goes in reverse order
    // vector.rend()   -- points to _ before 8 from v1

    for(vector<int>::iterator it = v1.begin(); it!=v1.end(); it++){
        cout << *(it);  //84023
    }
    // (IMP) auto is used when you dont know the datatype so c++ auto detects it itself. eg; auto i= 1; so auto here will be integer
    for(auto it=v1.begin(); it!=v1.end(); it++) {
        cout << *(it);  //84023
    }
    for(auto it : v1){
        cout << it;     //84023
    }
}


// OPERATIONS ON VECTOR
void vector_ops(){
    vector<int> v = {3, 5, 2, 6, 5, 2};
    vector<int> v2 = {100, 10, 843};

    // ERASING
    v.erase(v.begin()+1);     // erases 5 from {3, 5, 2, 6, 5, 2}  ->  {3, 2, 6, 5, 2}
    v.erase(v.begin(), v.begin()+2);   // erases (3, 2) from {3, 2, 6, 5, 2}  ->  {6, 5, 2}

    // INSERTING
    v.insert(v.begin(), 67);    // {67, 6, 5, 2}
    v.insert(v.end(), 2, 8);    // {67, 6, 5, 2, 8, 8}

    // FUNCTIONS
    v.pop_back();   // {67, 6, 5, 2, 8}
    v.size();       // 5
    v.empty();      // false
    v.swap(v2);   // swaps v with v2
    v.clear();    // {}

    // COPY v1 in v
    v2.insert(v.end(), v2.begin(), v2.end());
}


// LISTS
void lists(){
    list<int> ls;
    ls.emplace_back(5);   // {5}
    ls.push_back(7);      // {5, 7}

    // cant do this in vectors
    ls.push_front(0);     // {0, 5, 7}
    ls.emplace_front(2);  // {2, 0, 5, 7}
    ls.sort();            // {0, 2, 5, 7}
    ls.reverse();         // {7, 5, 2, 0}

    for(auto it = ls.begin(); it!=ls.end(); it++) {
        cout << *(it);
    }

    // rest is pretty much same as in vector
    // begin, end, rbegin, rend, clear, insert, size, swap
}


// DEQUE
void deques(){
    deque<int> dq;
    dq.push_back(1); // {1}
    dq.emplace_back(2); // {1,2}
    dq.push_front(4); // {4,1,2}
    dq.emplace_front(3); //{3,4,1,2}

    dq.pop_back(); // {3, 4, 1}
    dq.pop_front(); // {4,1}

    dq.back();
    dq.front();

    // rest functions same as vector
    // begin, end, rbegin, rend, clear, insert, size, swap
}


// STACK  (O) = 1
// LIFO - last in first out
void stacks(){
    // push, pop, top - mostly used
    stack<int> sk;

    sk.push(6);    // {6}
    sk.push(9);    // {9, 6}
    sk.push(3);    // {3, 9, 6}

    cout << sk.top();    // 3

    sk.pop();      // {3, 9}

    cout << sk.size();   // 2 
    cout << sk.empty();  // 0 i.e, False
}


// QUEUE  (O) = 1
// FIFO - first in first out
void queues() {
    queue<int> q;

    q.push(1);      // {1}
    q.push(2);      // {1,2}
    q.emplace(4);   //{1,2,4}

    q.back() += 5;   //{1,2,9}

    cout << q.back();   // prints 9
    cout << q. front(); // prints 1

    q.pop(); // {2, 9}

    // size swap empty same as stack
}


// PRIORITY_QUEUE
// largest integer// maximum number// lexicographically largest string stays at top
void pqs(){
    // MAX HEAP
    priority_queue<int> pq;
    pq.push(5); // {5}
    pq.push(2); // {5,2}
    pq.push(8); // {8,5,2}
    pq.emplace(10); // {10, 8, 5,2}

    pq.pop(); // {8,5,2}

    cout << pq.top(); // prints 8


    // MIN HEAP
    priority_queue<int, vector<int>, greater<int>> pqmin;
    pqmin.push(5); // {5}
    pqmin.push(2); // {2,5}
    pqmin.push(8);//{2,5,8}
    pqmin.emplace(10); // {2, 5, 8, 10}

    cout << pqmin.top(); // prints 2

    // size swap empty function same as others
}


// SET  |  log(N)
// sorted and unique
void sets(){
    set<int> st;
    st.emplace(3);    // {3}
    st.insert(1);     // {1, 3}
    st.insert(2);     // {1, 2, 3}
    st.insert(3);     // {1, 2, 3}
    st.insert(5);     // {1, 2, 3, 5}

    auto it = st.find(6);   // returns iterator at st.end()
    auto it = st.find(3);   // returns iterator at '3'

    st.erase(3);      // {1, 2, 3}
    st.erase(it);     // {1, 2}       // st.erase(from iterator, to iterator)

    int cnt = st.count(2);   // either returns 1 or 0

    it = st.upper_bound(2);   // TO DO
    it = st.lower_bound(3);   // TO DO
}


// MULTISET  |  log(N)
// sorted but not unique
void multisets(){
    multiset<int> mst;

    mst.insert(1);   // {1}
    mst.insert(4);   // {1, 4}
    mst.emplace(4);   // {1, 4, 4}
    
    mst.count(4);    // 2
    mst.erase(4);    // {1}

    // if you say erase element it erases all its duplicates, but if you mst.erase(iterator) then it only erases that specifc element
    mst.erase(mst.find(1)); 
    mst.erase(mst.begin(), mst.end());
}


// UNORDERED SET  |  O(1)  |  O(N)  - worst Case Rarely Happen
// unique but not sorted
void unordered_set(){
    // everyhing is same except lower bound and upper bound does not workl
}


// MAPS  |  log(N)
// Sorted and Unique
void maps(){
    // Keys are unique, Values can be duplicate
    // Keys are stores in sorted order

    map<int, int> mpp;    
    map<int, pair<int, int>> mp2;
    map<pair<int, int>, int> mp3;

    mpp[1] = 78;          // {{1, 78}}
    mpp.emplace(5, 8);     // {{1, 78}, {5,8}}
    mpp.insert({3, 10});    // {{1, 78}, {5,8}. {3, 10}}
    mp3.insert({{3, 5}, 90});  // {{{3, 5}, 90}}

    for(auto it : mp3) {
        cout << it.first.first << it.second << endl;
    }

    auto it = mpp.find(3);    // gives iterator at key 3

    // if we find something thats not in the map it gives mpp.end()
    // lower bound, upper bound, erase, size, swap, empty, are same as above
}


// MULTIMAP  |  O(1) but rarely O(N)
// Sorted and Duplicate
void multimaps(){
    // mpp[key] cannot be used
}



// UNORDERED MAP  |  O(1) but rarely O(N)
// Randomised and Unique
void unordered_maps(){
    // in (unordered_map) key cannot be pair or vector 
    // but in (map) it can be any data type
}


// custom comparator for sorting a pair in a order or its second element but if second element is same then in order of first element
bool comparator(pair<int, int> p1, pair<int, int> p2){
    if(p1.second<p2.second) return true;
    if(p1.second>p2.second) return false;

    if(p1.first<p2.first) return true;
    else return false;
}

// ALGORITHMS
void algorithms(){
     pair<int, int> pr[3] = {{7,1}, {4, 0}, {2, 0}};

    // SORTING   // O(nlogn) in all cases
    //sort(a, a+n)
    //sort(v.begin(), v.end())

    // SORTING USING A COMPARATOR
    //sort(a, a+n, greater<int>)
    sort(pr, pr+3, comparator);   // {{2, 0}, {4, 0}, {7,1}}

    // FUNCTIONS
    int i = 6;
    cout<< __builtin_popcount(i);   // number of set bits, like 6 is 110 in binary so it returns 2

    long long j = 68323846;
    cout << __builtin_popcountll(j);   // number of set bits

    //int maxi = *(max_element(a, a+n);)

    // PERMUTATIONS
    string s = "123";     // it is very important for string to be in sorted order to print all permutations

    do {
        cout << s << endl;
    } while (next_permutation(s.begin(), s.end()));
}
