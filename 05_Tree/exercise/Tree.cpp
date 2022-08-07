#include <iostream>
#include "Tree.hpp"

/*
out tree
            A
          /   \
        B       C
      /    \  /    \   
      D    E  F    G
*/

int main() {
    BiTree<char> Tree;
    std::cout << "InOrder:";
    Tree.InOrder(Tree.root);
    std::cout << "PreOrder:";
    Tree.PreOrder(Tree.root);
    std::cout << "PostOrder:";
    Tree.PostOrder(Tree.root);
    std::cout << "LevelOrder:";
    Tree.LevelOrder(Tree.root);
    std::cout << "Tree Depth:";
    Tree.Depth(Tree.root);
    std::cout << "Tree Leaf Count:";
    Tree.Count(Tree.root);
}