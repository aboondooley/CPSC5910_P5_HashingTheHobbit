#include <iostream>
#include "WordCounter.h"
using namespace std;

int main() {

    //WordCounter wc(100);
    //cout << wc.addWord("hi") << endl;
    //cout << wc.addWord("hi") << endl;
    WordCounter::LinkedList l;
    l.add("hi");
    cout << l.head->word << endl;
    cout << l.head->count << endl;
    l.add("hi");
    cout << l.head->word << endl;
    cout << l.head->count << endl;


    return 0;
}
