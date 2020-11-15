//
// Created by Alie on 11/14/2020.
//

#include "WordCounter.h"

WordCounter::WordCounter(int capacity) {
    map = new LinkedList[capacity];
    uniqueWordCount = 0;
    totalWordCount = 0;
    this->capacity = capacity;

}

WordCounter::~WordCounter() {
    delete[] map;
}

WordCounter::WordCounter(const WordCounter &other) {
    uniqueWordCount = other.uniqueWordCount;
    totalWordCount = other.totalWordCount;
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
        capacity = rhs.capacity;
        map = new LinkedList[capacity];
        for (int i = 0; i < capacity; i++) {
            map[i] = rhs.map[i];
        }
    }
    return *this;
}




