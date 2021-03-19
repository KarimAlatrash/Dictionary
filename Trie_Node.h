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
    bool isTerminal = false;
public:


    //default constructor
    Trie_Node(char val, Trie_Node* parent_) {
        value = val;
        parent = parent_;
    }
    Trie_Node(bool isTerminal, Trie_Node* parent) {
        isTerminal = true;
        value = ' ';
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
/*
    //NOTE: A WORD HAS ONLY BEEN SUCCESFULLY INSERTED IF IT CREATED A TERMINAL NODE
    bool insert_w(unsigned int current_index, string word) {
        //if we are at the root
        int wordlength = word.length();
        if(value=='*'){
            int alpha_index = (int)word[current_index]-97;
            if(child[ alpha_index ] == nullptr){
                child[ alpha_index ] = new Trie_Node();
                child[ alpha_index ]->parent = this;
            }

            return child[ alpha_index ]->insert_w(current_index, word);
        }
        //this can only occur if no insertions have been made --> terminal nodes are not created
        else if (this->isTerminal && current_index == word.length()) {
            return false;
        }
        //can only occur if we have traversed a whole other word but we still have letters to insert
        else if(this->isTerminal && current_index != word.length() ) {
            child[0] = new Trie_Node();
            child[0]->parent = this;
            return child[0]->insert_w(current_index, word);
        }
        //else insert the letter in the current node, return the status of the insertion
        else {
            int next_alpha_index = (int)word[current_index+1]-97; //should get a value from 0-25
            here is where we pick where the insertion should go

            //in case the child of this node is a terminal node, only child[0] will be filled
            if(parentOfTerminal) {
                return child[0]->insert_w(current_index+1, word);
            }

            //in case we are about to create a terminal node
            if(current_index+1 == word.length() && value == 'E') {
                parentOfTerminal = true;
                next_alpha_index = 0;
            }
            //in case we traversed the length of the word
            else if(current_index == word.length()) {
                //if we are not at a node we have just created, we have not inserted any letters and the insertion was bad
                if(value != 'E')
                    return false;
                //this is the case when we have just created the node, we set this to a terminal node and return true for succesful insertion
                value = ' ';
                isTerminal = true;
                return true;
            }

            value = word[current_index]; //this is redundant for traversing a word that already exists but kept for simplicity
            if(child[next_alpha_index] == nullptr) {
                child[next_alpha_index] = new Trie_Node();
                child[next_alpha_index]->parent = this;
            }


            return child[next_alpha_index]->insert_w(current_index+1, word);
        }


    }*/

    void print(string *all_chars) {
        if(value == '*')
            *all_chars="";
        else
            *all_chars+=value;
        if(isTerminal)
            cout<<*all_chars<<" ";
        for(int i{0}; i<26; i++) {
            if(child[i] != nullptr) {
                child[i]->print(all_chars);
            }
        }
        *all_chars = all_chars->substr(0, all_chars->size()-1);
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

    bool delete_w(bool first_delete) {
        //base case, we have reached the end of the delete

        int alpha_index = (int)value-97; //should get a value from 0-25

        if(value == '*'){
            return true;
        }

        //checks if this is a leaf node
        if(isLeaf(this)) {
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

    bool isLeaf(Trie_Node *node){
        for(int i{0}; i<26; i++) {
            if(node->child[i] != nullptr) {
                return false;
            }
        }
        return true;
    }
};


#endif //P2_TRIE_NODE_H
