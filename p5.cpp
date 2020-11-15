#include <iostream>
#include "WordCounter.h"
using namespace std;

int main() {

    WordCounter wc(100);
    cout << wc.addWord("hi") << endl;
    cout << wc.addWord("hi") << endl;


    return 0;
}
