//
// Created by Alie Boon-Dooley on 11/14/2020.
// For Seattle University, CPSC5005, P5.HashingTheHobbit
//

#ifndef LAB5_LISTTEMPLATE_LINKEDLIST_H
#define LAB5_LISTTEMPLATE_LINKEDLIST_H

#include <string>
#include <iostream>

/**
 * LinkedList Class: Dictionary implementation of a singly-linked LinkedList
 * which holds an int key and a string payload. Clients can add and remove
 * entries, as well as search for specific words and can get and increment
 * the key value. They can also check to see if the LinkedList is empty.
 * The LinkedList is constructed of ListElements called ListElems
 *
 */
// Dictionary of int: string functionality in a linked list implementation.
class LinkedList {
private:
    struct ListElem;  // forward declare this struct

public:
    /**
     * Constructor
     */
    LinkedList();

    /**
     * Destructor
     */
    ~LinkedList();

    /**
     * Copy constructor
     * @param other LinkedList to create deep copy of
     */
    LinkedList(const LinkedList &other);

    /**
     * Assignment operator overload
     * @param rhs LinkedList to create deep copy of
     * @return copy of the LinkedList
     */
    LinkedList &operator=(const LinkedList &rhs);

    /**
     * Adds a node to the front of the linked list
     * @param key the number of times that word has been added to the LinkedList
     * @param payload the word
     */
    void add(int key, std::string payload);

    /**
     * Removes a node from the LinkedList, based on the word
     * @param p the word to remove
     */
    void remove(std::string p);

    /**
     * Returns the number of times the given word has been added to the
     * LinkedList
     * @param p the word to look up
     * @return the number of entries associated with that word
     */
    int getKey(std::string p);

    /**
     * There needs to be a way to increase the count associated with a word
     * when the word is added another tine:
     * Increments the number of entries associated with the word by
     * @param p the word which has been added again
     * @return the new key associated with the word (one greater than before)
     */
    int incrementKey(std::string p);

    /**
     * Searches to see if the word exists in the linked list
     * @param p the word to find
     * @return if it exists, return the word, else return an empty string
     */
    std::string search(std::string p) const;

    /**
     * Checks to see if the LinkedList is empty
     * @return true if empty, false if not
     */
    bool empty() const;

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

    ListElem *head; // pointer to the head of the LinkedList

    /**
     * Used in the dtor and equals assignment over load, deletes each node in
     * the
     * LinkedList from The Heap because the LinkedList is dynamically allocated
     */
    void clear();

    /**
     * Used in the copy ctor and the equals assignment overload, copies over
     * one LinkedList contents to another, making a deep copy and allocating
     * on The Heap
     * @param headToCopy pointer to head of LinkedList to copy
     * @return myself, which now looks exactly liked the other LinkedList
     */
    static ListElem *copy(ListElem *headToCopy);

};




#endif //LAB5_LISTTEMPLATE_LINKEDLIST_H
