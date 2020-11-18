//
// Created by Alie Boon-Dooley on 11/14/2020.
// For Seattle University, CPSC5005, P5.HashingTheHobbit
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "WordCounter.h"
#include "English.h"
using namespace std;

/**
 * Tests the WordCounter and LinkedList functionalities
 * Reads in a file with words, gives statistics about the words in the file and
 * asks the user to select words to analyze and deletes them after analysis
 * It also takes care of trailing hyphens
 * It uses the English Class to clean up the words before entering them into
 * the WordCounter
 */

/**
 * Takes care of the trialing hyphens which sometimes even when the word
 * is not split. It combines the two halves of the word if the hyphen is due
 * to end of line, and gets rid of the trailing hyphen otherwise
 * @param buffer istringstream object to separate the line into words
 * @param infile istream object to read from file
 * @param clean the cleaned word, ready to de-hyphenate
 * @return the cleaned and de-hyphenated word
 */
string deHyphen(istringstream &buffer, ifstream &infile, string clean) {
    string line, word;
    if (clean[clean.length() - 1] == '-') {
        // get rid of trialing hyphens
        clean = clean.substr(0, clean.length() - 1);
        // if end of line, combine with first word of next line
        if (buffer.eof()) {
            if (getline(infile, line)) {
                istringstream b(line);
                b >> word;
                buffer.operator=(
                        dynamic_cast<basic_istringstream<char> &&>(b));
                clean = clean + English::cleanWord(word);
            }
        }
    }
    return clean;
}


/**
 * Loads in a file of strings, cleans them, de-hyphenates them (if at end of
 * word) and adds them to the WordCounter
 * @param filename to read
 * @param infile ifstream object used to read from file
 * @param w WordCounter object to load words in to
 * */
void loadWords(string filename, ifstream &infile, WordCounter &w) {
    string line, word, clean;
    infile.open(filename);
    if (infile) {
        while (getline(infile, line)) {
            istringstream buffer(line);
            while (buffer >> word) {
                clean = English::cleanWord(word);
                if (clean != "") { // don't add if blank
                    if (clean[clean.length() - 1] == '-') {
                        // handle trailing hyphens
                        clean = deHyphen(buffer, infile, clean);
                    }
                    w.addWord(clean);
                }
            }
        }
    }
}


/**
 * Prints out the statistics for the file that was just loaded into the word
 * counter, including the total number of words, number of unique words, and
 * the load factor
 * @param w WordCounter object
 */
void tableStats(WordCounter &w) {
    // tableStats
    cout << "Word counter statistics: " << endl;
    cout << "\tunique: " << w.getUniqueWordCount() << endl;
    cout << "\ttotal:  " << w.getTotalWordCount() << endl;
    cout << "\tload:   " << setprecision(3) << fixed
         << w.getLoadFactor() << endl << endl;
}


/**
 * Removes a given vector of words from the WordCounter
 * @param w WordCounter object
 * @param toRemove vector of words to remove
 */
void removeWords(WordCounter &w, vector<string> &toRemove) {
    for (int i = 0; i < toRemove.size(); i++) {
        w.removeWord(toRemove[i]);
    }
}


/**
 * Prompts the user to input words they want to analyze
 * Then prints out how many times the words occur in the WordCounter object
 * @param w WordCounter object to analyze
 * @return a vector containing the analyzed words so they can be deleted
 */
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
    cout << endl;
    return fromUser;
}

/**
 * Main entrance to tests
 * @return 0
 */
int main() {

    ifstream infile;
    int capacity;
    string filename;
    cout << "Enter file: " << endl;
    cin >> filename;
    cout << "Enter capacity: " << endl;
    cin >> capacity;
    cin.ignore();
    WordCounter w(capacity);

    loadWords(filename, infile, w);
    vector<string> commonWords = English::commonWords();
    removeWords(w, commonWords);

    tableStats(w);
    vector<string> toRemove = wordAnalysis(w);
    removeWords(w, toRemove);
    tableStats(w);

    return 0;
}
