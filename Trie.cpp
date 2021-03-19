//
// Created by Karim Alatrash on 2021-03-18.
//

#include "Trie.h"
#include <string>
#include <iostream>

using namespace std;


Trie::Trie() {
    head = new Trie_Node('*', nullptr);
}
bool Trie::is_empty() {
    if(size == 0) {
        return true;
    }
    return false;
}
unsigned int Trie::get_size() {
    return size;
}

void Trie::insert_w(string word) {


    bool succesful = head->insert_w(word);
    if(succesful) {
        cout << "succesfully inserted"<<endl;
    }
    else {
        cout << "not inserted"<<endl;
    }
}
void Trie::insert_c(string word, Trie_Node* curr_node) {

}

Trie::~Trie() {

}

void Trie::print() {
    string all_chars;
    //head->print(&all_words);
    head->print(&all_chars);
    cout<<endl;
    //cout<<all_chars<<endl;
}

Trie_Node * Trie::search_w(string search_word, bool print_status) {
    Trie_Node *result = head->search(search_word);

    if(print_status) {
        if(result!= nullptr)
            cout<<"found "<<search_word<<endl;
        else
            cout<<"not found"<<endl;
    }
    return result;
}

void Trie::delete_w(string delete_word) {
    Trie_Node* last_char = search_w(delete_word, false);
    if(last_char != nullptr) {


        bool isDeleted = last_char->delete_w(true);
        if(isDeleted)
            cout<<"success"<<endl;
        else
            cout<<"failure"<<endl;
        return;
    }
    cout<<"failure"<<endl;

}
