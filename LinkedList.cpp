//
// Created by Alie Boon-Dooley on 11/14/2020.
// For Seattle University, CPSC5005, P5.HashingTheHobbit
//

#include "LinkedList.h"

LinkedList::LinkedList() {
    head = nullptr;
}

LinkedList::~LinkedList() {
    // the LinkedList dtor deletes the Nodes for the
    // WordCounter, so all WordCounter needs to delete is the array
    clear();
}

LinkedList::LinkedList(const LinkedList &other) {
    head = copy(other.head);
}


LinkedList &LinkedList::operator=(const LinkedList &rhs) {
    if (&rhs != this) {
        clear();
        head = copy(rhs.head);
    }
    return *this;
}

void LinkedList::add(int key, std::string payload) {  // lightning fast!!
    if (payload == "")
        throw std::invalid_argument("Cannot have a payload of empty string "
                                    "(means "
                                    "not found when returned from search)");
    head = new ListElem(key, payload, head);
}

void LinkedList::remove(std::string p) { // not so fast -- linear search
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

int LinkedList::getKey(std::string p) {
    for (ListElem *cur = head; cur != nullptr; cur = cur->next) {
        if (cur->payload == p) {
            return cur->key;
        }
    }
    return 0; // -1 means not found
}

int LinkedList::incrementKey(std::string p) {
    for (ListElem *cur = head; cur != nullptr; cur = cur->next) {
        if (cur->payload == p) {
            cur->key++;
            return cur->key;
        }
    }
    return -1; // -1 means not found
}

std::string LinkedList::search(std::string p) const { // not so fast -- linear search
    for (ListElem *cur = head; cur != nullptr; cur = cur->next) {
        if (cur->payload == p)
            return cur->payload;
    }
    return ""; // Empty string means not found
}

bool LinkedList::empty() const {
    if (head == nullptr) {
        return true;
    }
    return false;
}

void LinkedList::clear() {
    int c = 0;
    while (head != nullptr) {
        ListElem *toDelete = head;
        head = head->next;
        delete toDelete;
    }
}

LinkedList::ListElem *LinkedList::copy(LinkedList::ListElem *headToCopy) {
    ListElem anchor(0, "", nullptr), *source, *tail;
    tail = &anchor;
    for (source = headToCopy; source != nullptr; source = source->next) {
        tail->next = new ListElem(source->key, source->payload, nullptr);
        tail = tail->next;
    }
    return anchor.next;
}

