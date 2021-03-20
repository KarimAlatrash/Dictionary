//
// Created by Karim Alatrash on 2021-03-18.
//

#include "Trie.h"
#include <string>
#include <iostream>
#include "illegal_exception.h"
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
        cout << "success"<<endl;
        size++;
    }
    else {
        cout << "failure"<<endl;
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
    if(size != 0)//in the event something was printed
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
        if(isDeleted) {
            cout << "success" << endl;
            size--;
        }
        else
            cout<<"failure"<<endl;
        return;
    }
    cout<<"failure"<<endl;

}

void Trie::autocomplete(string word) {

    Trie_Node* end_of_substr = head->search_substr(word);

    if(end_of_substr != nullptr) {
        char val = end_of_substr->get_val();
        string temp;
        end_of_substr->set_val('*');
        end_of_substr->print_subtree(&temp, word);
        if(!end_of_substr->isTerminal) //in the event something was printed
            cout<<endl;
        end_of_substr->set_val(val);
    }


}

void Trie::clear_trie() {
    head->clear();
}




