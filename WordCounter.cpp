//
// Created by Alie on 11/14/2020.
//

#include "WordCounter.h"
#include <iostream> // TODO remove
using namespace std;

WordCounter::WordCounter(int capacity) {
    map = new LinkedList[capacity];
    uniqueWordCount = 0;
    totalWordCount = 0;
    spacesUsed = 0;
    this->capacity = capacity;
}

WordCounter::~WordCounter() {
    delete[] map;
}

WordCounter::WordCounter(const WordCounter &other) {
    uniqueWordCount = other.uniqueWordCount;
    totalWordCount = other.totalWordCount;
    spacesUsed = other.spacesUsed;
    capacity = other.capacity;
    map = new LinkedList[capacity];
    for (int i = 0; i < capacity; i++) {
        map[i] = other.map[i];
    }
}

WordCounter &WordCounter::operator=(const WordCounter &rhs) {
    if (&rhs != this) {
        delete[] map;
        uniqueWordCount = rhs.uniqueWordCount;
        totalWordCount = rhs.totalWordCount;
        spacesUsed = rhs.spacesUsed;
        capacity = rhs.capacity;
        map = new LinkedList[capacity];
        for (int i = 0; i < capacity; i++) {
            map[i] = rhs.map[i];
        }
    }
    return *this;
}

int WordCounter::hash(std::string word) {
    std::hash<string> h;
    return h(word);
}

int WordCounter::getBucket(std::string word) const {
    return abs(hash(word)) % capacity;
}

int WordCounter::addWord(std::string word) {
    int bucket = getBucket(word);
    totalWordCount++;
    if (map[bucket].empty() || map[bucket].search(word) == "") {
        if (map[bucket].empty()) {spacesUsed++;}
        map[bucket].add(1, word);
        uniqueWordCount++;
        return map[bucket].getKey(word); // always 1
    }
    return map[bucket].setKey(word, map[bucket].getKey(word) + 1);
}

void WordCounter::removeWord(std::string word) {
    int bucket = getBucket(word);
    if (!map[bucket].empty() && map[bucket].search(word) == word) {
        totalWordCount = totalWordCount - map[bucket].getKey(word);
        uniqueWordCount--;
        map[bucket].remove(word);
        if (map[bucket].empty()) {spacesUsed--;}
    }
}

int WordCounter::getUniqueWordCount() const {
    return uniqueWordCount;
}

int WordCounter::getTotalWordCount() const {
    return totalWordCount;
}

bool WordCounter::empty() const {
    return totalWordCount == 0;
}

double WordCounter::getLoadFactor() const {
    return 1.0 * spacesUsed / capacity; // multiply by double to return a double
}

int WordCounter::getWordCount(std::string word) const {
    int bucket = getBucket(word);
    return map[bucket].getKey(word);
}










