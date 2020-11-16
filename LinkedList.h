//
// Created by Alie on 11/14/2020.
//

#ifndef LAB5_LISTTEMPLATE_LINKEDLIST_H
#define LAB5_LISTTEMPLATE_LINKEDLIST_H

#include <string>
#include <iostream>

// Dictionary of int: string functionality in a linked list implementation.
class LinkedList {
private:
    struct ListElem;  // forward declare this struct

public:
    LinkedList() {
        head = nullptr;
    }

    ~LinkedList() {
        clear();
    }

    LinkedList(const LinkedList &other) {
        head = copy(other.head);
    }

    LinkedList &operator=(const LinkedList &rhs) {
        if (&rhs != this) {
            clear();
            head = copy(rhs.head);
        }
        return *this;
    }

    void add(int key, std::string payload) {  // lightning fast!!
        if (payload == "")
            throw std::invalid_argument("Cannot have a payload of empty string "
                                        "(means "
                                        "not found when returned from search)");
        head = new ListElem(key, payload, head);
    }

    void remove(std::string p) { // not so fast -- linear search
        if (head == nullptr)
            return;

        // special case if found at head of list
        if (head->payload == p) {
            ListElem *toDelete = head;
            head = head->next;
            delete toDelete;
            return;
        }

        // normal case is to find later down the list
        ListElem *prior = head;
        for (ListElem *cur = head->next; cur != nullptr; cur = cur->next) {
            if (cur->payload == p) {
                prior->next = cur->next;
                delete cur;
                return;
            }
            prior = prior->next;
        }
    }

    int getKey(std::string p){
        for (ListElem *cur = head; cur != nullptr; cur = cur->next) {
            if (cur->payload == p) {
                return cur->key;
            }
        }
        return 0; // -1 means not found
    }

    int setKey(std::string p, int v) {
        for (ListElem *cur = head; cur != nullptr; cur = cur->next) {
            if (cur->payload == p) {
                cur->key = v;
                return cur->key;
            }
        }
        return -1; // -1 means not found
    }

    std::string search(std::string p) const { // not so fast -- linear search
        for (ListElem *cur = head; cur != nullptr; cur = cur->next) {
            if (cur->payload == p)
                return cur->payload;
        }
        return ""; // Empty string means not found
    }

    bool empty() const {
        if (head == nullptr) {
            return true;
        }
        return false;
    }

private:
    struct ListElem {
        int key;
        std::string payload;
        ListElem *next;

        // convenience ctor
        ListElem(int k, std::string p, ListElem *n) {
            key = k;
            payload = p;
            next = n;
        }
    };

    ListElem *head;

    void clear() {
        while (head != nullptr) {
            ListElem *toDelete = head;
            head = head->next;
            delete toDelete;
        }
    }

    static ListElem *copy(ListElem *headToCopy) {
        ListElem anchor(0, "", nullptr), *source, *tail;
        tail = &anchor;
        for (source = headToCopy; source != nullptr; source = source->next) {
            tail->next = new ListElem(source->key, source->payload, nullptr);
            tail = tail->next;
        }
        return anchor.next;
    }

};


#endif //LAB5_LISTTEMPLATE_LINKEDLIST_H
