//
// Created by Alie on 11/14/2020.
//

#ifndef P5_HASHINGTHEHOBBIT_WORDCOUNTER_H
#define P5_HASHINGTHEHOBBIT_WORDCOUNTER_H

#include "LinkedList.h"
#include <string>


class WordCounter {
public:
    // BIG 4
    explicit WordCounter(int capacity);
    ~WordCounter();
    WordCounter(const WordCounter &other);
    WordCounter &operator=(const WordCounter &rhs);

    int addWord(std::string word);
    void removeWord(std::string word);
    int getWordCount(std::string word) const;
    double getLoadFactor() const;
    int getUniqueWordCount() const;
    int getTotalWordCount() const;
    bool empty() const;


private:
    static int hash(std::string word);
    int getBucket(std::string word) const;

    int capacity;
    int uniqueWordCount;
    int totalWordCount;
    int spacesUsed;
    LinkedList *map;





};


#endif //P5_HASHINGTHEHOBBIT_WORDCOUNTER_H
