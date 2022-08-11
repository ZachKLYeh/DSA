#include <iostream>
#include "BST.hpp"

int main() {
    BST<int> bstree;
    bstree.root = bstree.Insert(bstree.root, 13);
    bstree.root = bstree.Insert(bstree.root, 6);
    bstree.root = bstree.Insert(bstree.root, 25);
    bstree.root = bstree.Insert(bstree.root, 2);
    bstree.root = bstree.Insert(bstree.root, 23);
    bstree.root = bstree.Insert(bstree.root, 11);
    bstree.root = bstree.Insert(bstree.root, 19);

    bstree.LevelOrder(bstree.root);
    std::cout << "search for number 23\n";
    bstree.Search(bstree.root, 23);
    std::cout << "Delete number 6\n";
    bstree.Delete(bstree.root, 6);
    bstree.LevelOrder(bstree.root);

};
