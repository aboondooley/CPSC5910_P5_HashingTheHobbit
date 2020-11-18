//
// Created by Alie Boon-Dooley on 11/14/2020.
// For Seattle University, CPSC5005, P5.HashingTheHobbit
//

#ifndef P5_HASHINGTHEHOBBIT_WORDCOUNTER_H
#define P5_HASHINGTHEHOBBIT_WORDCOUNTER_H

#include "LinkedList.h"
#include <string>


/**
 * The WordCounter Class a HashTable that takes in words and keeps
 * track of how many times the word has been entered into the HashTable
 * The HashTable uses an array of singly LinkedLists and Node within the
 * LinkedList that uses a dictionary/map implementation
 * The client can add and remove words, check how many times a given word has
 * been entered, increment the word count of a given word as well as check
 * the total number of words, number of unique words, and load factor. They
 * can also check to see if the HashTable is empty
 */
class WordCounter {
public:
    // BIG 4
    /**
     * Constructor, asks the client to supply the size
     * @param capacity the size of the array to sue
     */
    explicit WordCounter(int capacity);

    /**
     * Destructor - deletes from The Heap
     */
    ~WordCounter();

    /**
     * Copy constructor
     * Creates a deep copy
     * @param other the WordCounter object to copy
     */
    WordCounter(const WordCounter &other);

    /**
     * Assignment overload
     * @param rhs the WordCounter object to copy
     * Creates a deep copy
     * @return myself, which now is exactly like the other WordCounter
     */
    WordCounter &operator=(const WordCounter &rhs);


    /**
     * Adds a word to the Hashtable, either creates a new entry or increments
     * the associated count if the word already exists
     * @param word to add
     * @return the number of times the word has been added to the HashTable
     */
    int addWord(std::string word);

    /**
     * Removes a word completely from the HashTable (removes duplicates)
     * @param word to remove
     */
    void removeWord(std::string word);

    /**
     * Checks how many times the given word has been entered into the HashTable
     * @param word the word to check
     * @return the number of times the word has been added to the HashTable
     * (zero if never entered)
     */
    int getWordCount(std::string word) const;

    /**
     * Checks to see how burdened the HashTable is
     * @return the number of unique entries divided by the size of the array
     */
    double getLoadFactor() const;

    /**
     * Checks the number of unique words in the HashTable - does not count
     * duplicates
     * @return the number of unique words
     */
    int getUniqueWordCount() const;

    /**
     * Checks the total number of words in the HashTable, including duplicate
     * entries of the same word
     * @return total number of entries
     */
    int getTotalWordCount() const;

    /**
     * Checks whether the HashTable is empty
     * @return true if empty, false if not
     */
    bool empty() const;


private:
    /**
     * Uses the std::hash function to return the hash which will always be the
     * same for the same string
     * @param word the string word to get the hash for
     * @return the hash value
     */
    static int hash(std::string word);

    /**
     * Cleans up the hash value, makes sure it is a positive number and that
     * it is no larger than the size of the array
     * @param word the word to pass to the hash funciton
     * @return the bucket number
     */
    int getBucket(std::string word) const;

    int capacity; // size of the array
    int uniqueWordCount; // number of words not including dups
    int totalWordCount; // total number of words, including dups
    LinkedList *map; // array of LinkedLists

};


#endif //P5_HASHINGTHEHOBBIT_WORDCOUNTER_H
