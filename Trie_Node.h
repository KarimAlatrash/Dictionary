//
// Created by Karim Alatrash on 2021-03-18.
//

#ifndef P2_TRIE_NODE_H
#define P2_TRIE_NODE_H
#include <string>
#include <iostream>

using namespace std;

//a=97
//z=122
class Trie_Node {
private:
    Trie_Node* child[26]{nullptr};
    Trie_Node* parent = nullptr;
    char value = 'E';
public:
    bool isTerminal = false;

    char get_val() {
        return value;
    }
    //default constructor
    Trie_Node(char val, Trie_Node* parent_) {
        value = val;
        parent = parent_;
    }

    void set_val(char new_val) {
        value = new_val;
    }

    bool insert_w(string word) {
        //base case
        if(word.empty()) {
            if(isTerminal)
                return false;
            else {
                isTerminal = true;
                return true;
            }
        }

        int next_alpha_index = (int)word[0]-97; //should get a value from 0-25
        if(child[next_alpha_index] == nullptr) {
            child[next_alpha_index] = new Trie_Node(word[0], this);
        }
        word.erase(0,1);
        return child[next_alpha_index]->insert_w(word);
    }


    void print(string *current_word, string *final_string) {
        if(value == '*')
            *current_word="";
        else
            *current_word+=value;
        if(isTerminal)
            *final_string += *current_word + " ";
        for(int i{0}; i<26; i++) {
            if(child[i] != nullptr) {
                child[i]->print(current_word, final_string);
            }
        }
        *current_word = current_word->substr(0, current_word->size() - 1);
    }

    void print_subtree(string *current_word, string prefix, string *final_string) {
        if(value == '*')
            *current_word=prefix;
        else
            *current_word+=value;
        if(isTerminal)
            *final_string += *current_word + " ";
        for(int i{0}; i<26; i++) {
            if(child[i] != nullptr) {
                child[i]->print_subtree(current_word, prefix, final_string);
            }
        }
        *current_word = current_word->substr(0, current_word->size() - 1);
    }

    Trie_Node* search(string search_word) {
        //base case
        if(search_word == "") {
            if(isTerminal)
                return this;
            else {
                return nullptr;
            }
        }

        int next_alpha_index = (int)search_word[0]-97; //should get a value from 0-25

        if(child[next_alpha_index] == nullptr) {
            return nullptr;
        }

        search_word.erase(0,1);
        return child[next_alpha_index]->search(search_word);
    }

    Trie_Node* search_substr(string substr) {
        //base case
        if(substr == "") {
            return this;
        }

        int next_alpha_index = (int)substr[0]-97; //should get a value from 0-25

        if(child[next_alpha_index] == nullptr) {
            return nullptr;
        }

        substr.erase(0,1);
        return child[next_alpha_index]->search_substr(substr);
    }

    bool delete_w(bool first_delete) {
        //base case, we have reached the end of the delete

        int alpha_index = (int)value-97; //should get a value from 0-25

        if(value == '*'){
            return true;
        }

        bool leaf_status = this->isLeaf();

        if(leaf_status && isTerminal && !first_delete) {
            return true;
        }

        //checks if this is a leaf node
        else if(leaf_status) {
            Trie_Node* temp = parent;
            temp->child[alpha_index] = nullptr;
            delete this;
            return temp->delete_w(false);
        }

        //the case that we are deleting a node which is the end of a subword
        else if(isTerminal && first_delete) {
            isTerminal = false;
        }

        return true;

    }

    bool isLeaf(){
        for(int i{0}; i<26; i++) {
            if(child[i] != nullptr) {
                return false;
            }
        }
        return true;
    }

    void clear() {
        for(int i{0}; i<26; i++) {
            if(child[i] != nullptr) {
                child[i]->clear();
            }
        }
        if(value != '*') {
            int alpha_index = (int)value-97; //should get a value from 0-25
            Trie_Node* temp = parent;
            temp->child[alpha_index] = nullptr;
            parent = nullptr;
            delete this;
        }
    }







};


#endif //P2_TRIE_NODE_H
