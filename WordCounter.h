//
// Created by Alie on 11/14/2020.
//

#ifndef P5_HASHINGTHEHOBBIT_WORDCOUNTER_H
#define P5_HASHINGTHEHOBBIT_WORDCOUNTER_H

#include <string>


class WordCounter {
public:
    // BIG 4
    explicit WordCounter(int capacity);
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

    struct Node {
        int count;
        std::string word;
        Node *next, *last; // doubly-linked node!

        // Convenience constructor
        Node(int c, std::string w, Node *n, Node *l) {
            count = c;
            word = w;
            next = n;
            last = l;
        }
    };

    struct LinkedList {
        Node *head = nullptr;

        void add(std::string word) { // add to the front
            *head = Node(1, word, head, nullptr);
            if (head->next != nullptr) {
                head->next->last = head;
            }
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

private:




    static int hash(std::string word);
    int getBucket(std::string word) const;

    int capacity;
    int uniqueWordCount;
    int totalWordCount;
    LinkedList *map;





};


#endif //P5_HASHINGTHEHOBBIT_WORDCOUNTER_H
