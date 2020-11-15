//
// Created by Alie on 11/14/2020.
//

#ifndef P5_HASHINGTHEHOBBIT_WORDCOUNTER_H
#define P5_HASHINGTHEHOBBIT_WORDCOUNTER_H

#include <string>


class WordCounter {
public:
    // BIG 4
    WordCounter(int capacity);
    ~WordCounter();
    WordCounter(const WordCounter &other);
    WordCounter &operator=(const WordCounter &rhs);

    int addWord(const std::string word);
    void removeWord(const std::string word);
    int getWordCount(const std::string word) const;
    double getLoadFactor() const;
    int getUniqueWordCount() const;
    int getTotalWordCount() const;
    bool empty() const;

private:
    struct Node {
        std::string word;
        int count;
        Node *next, *last; // doubly-linked node!
    };

    struct LinkedList {
        Node *head = nullptr;

        void add(Node *toAdd) { // add to the front
            toAdd->next = head;
            head->last = toAdd;
            head = toAdd;
            toAdd->last = nullptr;
        }

        void remove(Node *toRemove) {
            if (head == toRemove) {
                head = toRemove->next;
            }
            toRemove->last->next = toRemove->next;
            toRemove->next->last = toRemove->last;
        }

        static Node *next(Node *current) {
            return current->next;
        }
    };

    static int hasher(std::string word);

    int capacity;
    int uniqueWordCount;
    int totalWordCount;
    LinkedList *map;





};


#endif //P5_HASHINGTHEHOBBIT_WORDCOUNTER_H
