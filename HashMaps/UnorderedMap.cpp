#include<iostream>
#include<unordered_map>
using namespace std;

// in the case of unordered maps, the key-value pair that is stored is in 
// random order rather than being in some ordered way

int main(){
    
    // creation
    unordered_map<string, int> m;

    // insertion:

        // method-1: by making a pair first and then pushing it in the map
        pair<string, int> p1 = make_pair("Kartik", 1);
        m.insert(p1);

        // method-2: by making a pair first and then pushing it in the map
        pair<string, int> p2("Radhika", 2);
        m.insert(p2);

        // method-3: by making a pair first and then pushing it in the map
        m["Nawed"] = 3;
        m["Prashast"] = 4;
        m["Himanshu"] = 5;
        m["Priyal"] = 6;
        m["Divya"] = 7;

    // searching:

    cout << m["Nawed"] << endl;
    cout << m.at("Radhika") << endl;
    cout << m.at("Kartik") << endl;

    // size:
    cout << m.size() << endl;

    // isPresent:
    cout << m.count("Kartik") << endl;

    // erase:
    m.erase("Nawed");
    cout << m.count("Nawed") << endl;
    cout << m.size() << endl;

    // ways of traversing through an unordered_map
    unordered_map<string, int> :: iterator it = m.begin();

    while(it != m.end()){
        cout << (*it).first << " = " << (*it).second*10 << endl;
        it++;
    }

    return 0;
}   