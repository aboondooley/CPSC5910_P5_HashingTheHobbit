//
// Created by Alie Boon-Dooley on 11/14/2020.
// For Seattle University, CPSC5005, P5.HashingTheHobbit
//

#include "WordCounter.h"
#include <string>

WordCounter::WordCounter(int capacity) {
    map = new LinkedList[capacity];
    uniqueWordCount = 0;
    totalWordCount = 0;
    this->capacity = capacity;
}

WordCounter::~WordCounter() {
    // deletes the array from The Heap
    delete[] map;
}

WordCounter::WordCounter(const WordCounter &other) {
    uniqueWordCount = other.uniqueWordCount;
    totalWordCount = other.totalWordCount;
    capacity = other.capacity;
    map = new LinkedList[capacity];

    // copy over all the contents
    for (int i = 0; i < capacity; i++) {
        map[i] = other.map[i];
    }
}

WordCounter &WordCounter::operator=(const WordCounter &rhs) {
    if (&rhs != this) {
        delete[] map;
        uniqueWordCount = rhs.uniqueWordCount;
        totalWordCount = rhs.totalWordCount;
        capacity = rhs.capacity;
        map = new LinkedList[capacity];
        for (int i = 0; i < capacity; i++) {
            map[i] = rhs.map[i];
        }
    }
    return *this;
}

int WordCounter::hash(std::string word) {
    std::hash<std::string> h;
    return h(word);
}

int WordCounter::getBucket(std::string word) const {
    return abs(hash(word)) % capacity; // always positive and no greater than
    // capacity
}

int WordCounter::addWord(std::string word) {
    int bucket = getBucket(word); // hash to get the correct bucket
    totalWordCount++;
    if (map[bucket].empty() || map[bucket].search(word) == "") {
        map[bucket].add(1, word);
        uniqueWordCount++; // only increment if it's a new word
        return map[bucket].getKey(word); // always 1
    }
    return map[bucket].incrementKey(word);
}

void WordCounter::removeWord(std::string word) {
    int bucket = getBucket(word); // hash to get the correct bucket
    if (!map[bucket].empty() && map[bucket].search(word) == word) {
        totalWordCount = totalWordCount - map[bucket].getKey(word);
        uniqueWordCount--;
        map[bucket].remove(word);
    }// do nothing if the word does not exist in HashMap
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
    return 1.0 * uniqueWordCount / capacity; // multiply by double to return a double
}

int WordCounter::getWordCount(std::string word) const {
    int bucket = getBucket(word);
    return map[bucket].getKey(word);
}










