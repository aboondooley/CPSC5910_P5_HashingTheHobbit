//
// Created by Alie on 11/14/2020.
//

#ifndef P5_HASHINGTHEHOBBIT_LINKEDLIST_H
#define P5_HASHINGTHEHOBBIT_LINKEDLIST_H
#include <string>


template <typename T>
class LinkedList {


private:
    struct Node {
        std::string word;
        int count;
        Node *next;
    };

    int s = 0; // size



public:
    LinkedList();
    ~LinkedList();
    LinkedList(const LinkedList<T> &other) {

    }
    LinkedList<T> &operator=(const LinkedList<T> &rhs) {

    }

    Node *head;

    void addNode(Node *toAdd) {

    }

    Node *deleteNode(Node *toDelete) {

    }

    static Node *nextNode(Node *current) {
        return current->next;
    }

    static std::string getWord(Node *toGet) {
        return toGet->word;
    }

    static int getCount(Node *toGet) {
        return toGet->count;
    }

    int size() {
        return size;
    }
}


#endif //P5_HASHINGTHEHOBBIT_LINKEDLIST_H
