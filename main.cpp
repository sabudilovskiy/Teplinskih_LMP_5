#include <iostream>
#include <fstream>
#include "Tree.h"
#include "Que.h"
int main() {
    setlocale(LC_ALL, "Russian");
    std::ifstream in("in.txt");
    std::ofstream out("out.txt");
    std::cout << "������� ������� ��� ������: ";
    char elem;
    elem = std::cin.get();
    int i = 1;
    while (!in.eof()){
        std::string temp;
        std::getline(in, temp);
        int begin = 0;
        Tree::Node* tree = Tree::create_from_string(temp, begin);
        out << Tree::find_element(tree, elem) << '\n';
        std::cout << "������ �" << i++ << '\n';
        Tree::print(tree, 0);
        Tree::clear(tree);
    }
    out.close();
    std::cout << "��� ���������� ��������� ������� �� ����� ������... ";
    std::cin.get();
    std::cin.get();
}
