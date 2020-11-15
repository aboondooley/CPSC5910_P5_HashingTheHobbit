//
// Created by Alie on 11/14/2020.
//

#include "WordCounter.h"
#include "LinkedList.h"
#include <math.h>
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

int WordCounter::addWord(const std::string word) {
    int bucket = getBucket(word);
    totalWordCount++;
    if (map[bucket].empty() || map[bucket].search(word) == "") {
        if (map[bucket].empty()) {spacesUsed++;}
        map[bucket].add(1, word);
        uniqueWordCount++;
        return map[bucket].getKey(word); // always 1
    }

    return map[bucket].incrementKey(word);
    /*
    for (Node *cur = map[bucket].head; cur != nullptr; cur = cur->next) {
        if (cur->word == word) {
            return ++cur->count;
        }
    }
    LinkedList l;
    l.add(word);
    map[bucket].head = l.head;
    uniqueWordCount++;
    //cout << map[bucket].head->word << endl; // TODO remove
    //cout << map[bucket].head->count << endl; // TODO remove
     return map[bucket].head->count; // always 1
     */
}








