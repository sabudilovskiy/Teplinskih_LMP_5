//
// Created by MRV on 21.12.2021.
//

#ifndef TEPLINSKIH_LMP_5_QUE_H
#define TEPLINSKIH_LMP_5_QUE_H
#include "Tree.h"

template <class T>
class Que{
    class Node{
        Node* next;
        T* info;
    public:
        Node(const T& info){
            this->info = new T(info);
            next = nullptr;
        }
        Node(T* info) {
            this->info = info;
            next = nullptr;
        }
        Node *get_next() const {
            return next;
        }

        void set_next(Node *next) {
            Node::next = next;
        }

        T *get_info() const {
            return info;
        }
    };
    Node* first;
    Node* last;
    int n;
public:
    Que() : first(nullptr), last(nullptr), n(0){}
    T* give_first(){
        if (first){
            T* answer = first->get_info();
            Que::Node* remove = first;
            first = first->get_next();
            if (first == nullptr){
                last = nullptr;
            }
            delete remove;
            n--;
            return answer;
        }
        else return nullptr;
    }
    void push_bacK(T* value){
        if (last){
            last->set_next(new Node(value));
            last = last->get_next();
        }
        else first = last = new Node(value);
        n++;
    }
    void push_bacK(const T& value){
        if (last){
            last->set_next(new Node(value));
            last = last->get_next();
        }
        else first = last = new Node(value);
        n++;
    }
    const int& get_N() {
        return n;
    }
    ~Que(){
        Node* cur = first;
        while (cur){
            Node* next = cur->get_next();
            delete cur->get_info();
            delete cur;
            cur = next;
        }
    }
};

int Tree::find_element(Node* tree, const char &element) {
    int found = -1;
    if (tree != nullptr){
        //очередь на обход
        Que<Tree::Node*> que;
        //очередь, в которой лежит информацию по длине пути до соответствующей вершины
        Que<int> que_length;
        //начинаем с корня
        que.push_bacK(tree);
        //длина до него 0
        que_length.push_bacK(0);
        while (que.get_N() > 0 && found == -1){
            //берём из очереди первую вершину
            Tree::Node** cur_node = que.give_first();
            int* cur_length = que_length.give_first();
            //если в ноде наш элемент, то
            if ((*(cur_node))->get_info() == element) {
                //запоминаем длину
                found = *cur_length;
            }
            //если нет, то добавляем потомков нода в очередь
            else{
                //если есть левый потомок
                if ((*cur_node)->get_left()) {
                    que.push_bacK((*cur_node)->get_left());
                    que_length.push_bacK(*cur_length + 1);
                }
                if ((*cur_node)->get_right()) {
                    que.push_bacK((*cur_node)->get_right());
                    que_length.push_bacK(*cur_length + 1);
                }
            }
            //чистим память
            delete cur_node;
            delete cur_length;
        }
    }
    return found;
}

//удаление дерева при помощи обхода в ширину(нафиг рекурсию)
void Tree::clear(Node *&tree) {
    if (tree != nullptr){
        //очередь на обход
        Que<Tree::Node*> que;
        //начинаем с корня
        que.push_bacK(tree);
        while (que.get_N() > 0){
            //берём из очереди первую вершину
            Tree::Node** cur_node = que.give_first();
            //доавляем в очередь потомков
            if ((*cur_node)->get_left()) {
                que.push_bacK((*cur_node)->get_left());
            }
            if ((*cur_node)->get_right()) {
                que.push_bacK((*cur_node)->get_right());
            }
            //чистим память
            delete (*cur_node);
            delete cur_node;
        }
        tree = nullptr;
    }
}
#endif //TEPLINSKIH_LMP_5_QUE_H
