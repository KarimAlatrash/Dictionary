//
// Created by Karim Alatrash on 2021-03-18.
//

#ifndef P2_TRIE_H
#define P2_TRIE_H

#include <string>
#include "Trie_Node.h"

using namespace std;

class Trie {


private:
    unsigned int size{0};

public:
    Trie();
    ~Trie();
    unsigned int get_size();
    void clear_trie();
    bool is_empty();
    void autocomplete(string word);
    void print();
    void insert_w(string new_word);
    void delete_w(string delete_word);
    Trie_Node* search_w(string search_word, bool print_status);
    Trie_Node* head;

};


#endif //P2_TRIE_H
