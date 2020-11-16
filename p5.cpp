#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "WordCounter.h"
#include "English.h"
using namespace std;

void loadWords(string filename, ifstream &infile, WordCounter &w) {
    infile.open(filename);
    if (infile) {

    }
}
void tableStats(WordCounter &w) {
    // tableStats
    cout << "Word counter statistics: " << endl;
    cout << "\tunique: " << w.getUniqueWordCount() << endl;
    cout << "\ttotal:  " << w.getTotalWordCount() << endl;
    cout << "\tload:   " << setprecision(3) << fixed
         << w.getLoadFactor() << endl << endl;
}

void removeWords(WordCounter &w, vector<string> &toRemove) {
    for (int i = 0; i < toRemove.size(); i++) {
        w.removeWord(toRemove[i]);
    }
}

vector<string> wordAnalysis(WordCounter &w) {
    string allWords, one;
    vector<string> fromUser;
    cout << "Enter words (separated by space): ";
    getline(cin, allWords); // get multiple lines
    cout << "Analysis of words: " << endl;
    istringstream  buffer(allWords);
    while (buffer >> one) {
        cout << "\t" << one << ": " << w.getWordCount(one) << endl;
        fromUser.push_back(one);
    }
    return fromUser;
}

int main() {
/*
    WordCounter wc(100);
    cout << wc.empty() << endl;
    cout << wc.addWord("hi") << endl;
    cout << wc.addWord("hi") << endl;
    cout << wc.addWord("alie") << endl;
    cout << wc.addWord("hi") << endl;
    cout << wc.addWord("ben") << endl;
    cout << wc.getTotalWordCount() << endl;
    cout << wc.getUniqueWordCount() << endl;
    //cout << wc.getWordCount("hi") << endl;
    //cout << wc.getWordCount("alie") << endl;
    cout << wc.empty() << endl;
    // cout << wc.getLoadFactor() << endl;

    WordCounter second(wc);
    cout << second.getTotalWordCount() << endl;
    cout << second.getUniqueWordCount() << endl;
    cout << second.empty() << endl;
    second.removeWord("hi");
    cout << second.getTotalWordCount() << endl;
    cout << second.getUniqueWordCount() << endl;
    cout << wc.getTotalWordCount() << endl;
    cout << wc.getUniqueWordCount() << endl;
    wc.removeWord("alie");
    cout << wc.getUniqueWordCount() << endl;
    cout << wc.getTotalWordCount() << endl;

    cout << wc.getWordCount("hi") << endl;
    cout << wc.getWordCount("ben") << endl;
    cout << wc.getWordCount("alie") << endl;
    cout << second.getWordCount("hi") << endl;
    cout << second.getWordCount("ben") << endl;
    cout << second.getWordCount("alie") << endl;
*/
    ifstream infile;
    int capacity;
    cout << "Enter file: " << endl;
    string filename = "..\\files\\hobbit.txt";
    //cin >> filename;
    cout << "Enter capacity: " << endl;
    //cin >> capacity;
    capacity = 833;
    WordCounter w(capacity);

    // loadFile
    //TODO need to take care of "" as value
    //TODO need to take care of hyphenated word at end of line
    string line, word;
    infile.open(filename);
    if (infile) {
        while (getline(infile, line)) {
            istringstream buffer(line);
            while (buffer >> word) {
                w.addWord(English::cleanWord(word));
            }
        }
    }

    vector<string> commonWords = English::commonWords();
    removeWords(w, commonWords);
    tableStats(w);
    vector<string> toRemove = wordAnalysis(w);
    removeWords(w, toRemove);
    tableStats(w);

    return 0;
}
