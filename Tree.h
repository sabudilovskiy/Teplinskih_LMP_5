//
// Created by MRV on 21.12.2021.
//

#ifndef TEPLINSKIH_LMP_5_TREE_H
#define TEPLINSKIH_LMP_5_TREE_H
#include <string>
#include <vector>
namespace Tree{
    class Node{
        Node* left;
        Node* right;
        char info;
    public:
        Node(char info) : info(info){}
        Node *get_left() const {
            return left;
        }
        void set_left(Node *left) {
            Node::left = left;
        }
        Node *get_right() const {
            return right;
        }
        void set_right(Node *right) {
            Node::right = right;
        }
        char get_info() const {
            return info;
        }
        void set_info(char info) {
            Node::info = info;
        }
    };
    Node* create_from_string(const std::string& str, int& begin){
        Node* tree = nullptr;
        if (begin <  str.length()){
            if (str[begin] != '*'){
                tree = new Node(str[begin]);
            }
            else tree = nullptr;
            begin++;
        }
        if (tree){
            Node* left = nullptr;
            Node* right = nullptr;
            if (begin < str.length()){
                left = create_from_string(str, begin);
            }
            if (begin < str.length()){
                right = create_from_string(str, begin);
            }
            tree->set_left(left);
            tree->set_right(right);
        }
        return tree;
    }
    int find_element(Node* tree, const char& element);
    void print (Node* t, int level)
    {
        if (t)
        {
            print(t->get_right(), level + 1);
            for (int i = 0; i <= level; i++)
                std::cout << ' ';
            std::cout << t->get_info() << '\n';
            print(t->get_left(), level + 1);
        }
    }
    void clear(Node*& tree);

}
#endif //TEPLINSKIH_LMP_5_TREE_H
