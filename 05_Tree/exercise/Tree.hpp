/*
There are two main implementation of a binary tree
1. Array-based
the index of array is like this
            A
          /   \
        B       C
      /    \  /    \   
      D    E  F    G

Array[] = {A, B, C, D, E, F, G}

Pros: fast access to tree elements
Cons: waste of memory when not saving full binary tree
      when the tree expands, it may need to reallocte the array

2. List-based
Each node in the tree contain two pointers
One pointer points to the left child, second pointer points to right child

Pros: Good to saving non full tree and skew tree. Which doesn't waste memory space.
      Good to expand, without futher memoery realloctaion.

Cons: Bad to save full tree, which waste a lot of memory saving pointers
      And also have a access time worst case of O(h)


Today, we are implementing a tree using linked list
*/
#include "Queue.hpp"
template<typename T>
class BiTree {
private:
    struct BiNode {
        T data;
        BiNode* Lchild;
        BiNode* Rchild;
    };

public:
    BiNode* root;
    BiTree() {
    root = new BiNode();
    root->data = 'A';
    root->Lchild = new BiNode();
    root->Rchild = new BiNode();
    root->Lchild->data = 'B';
    root->Rchild->data = 'C';
    BiNode* X = root->Lchild;
    BiNode* Y = root->Rchild;
    X->Lchild = new BiNode();
    X->Rchild = new BiNode();
    X->Lchild->data = 'D';
    X->Rchild->data = 'E';
    Y->Lchild = new BiNode();
    Y->Rchild = new BiNode();
    Y->Lchild->data = 'F';
    Y->Rchild->data = 'G';
    }

// walk through binary tree with different methods
    // inorder, buttom up, Lchild->root->Rchild
    void _InOrder(BiNode*N) {
        if (!N) return;
        // LRroot
        _InOrder(N->Lchild);
        std::cout << N->data;
        _InOrder(N->Rchild);
    }

    void InOrder(BiNode* N) {
        _InOrder(N);
        std::cout << "\n";
    }

    // preOrder, top down, root->Lchild->Rchild
    void _PreOrder(BiNode* N) {
        if (!N) return;
        // rootLR
        std::cout << N->data;
        _PreOrder(N->Lchild);
        _PreOrder(N->Rchild);
    }

    void PreOrder(BiNode* N) {
        _PreOrder(N);
        std::cout << "\n";
    }

    // postorder, buttom up, Lchild->Rchild->Root
    void _PostOrder(BiNode* N) {
        if (!N) return;
        //LRroot
        _PostOrder(N->Lchild);
        _PostOrder(N->Rchild);
        std::cout << N->data;
    }

    void PostOrder(BiNode* N) {
        _PostOrder(N);
        std::cout << "\n";
    }

    void LevelOrder(BiNode* N) {
        Queue<BiNode*> Q;
        // first push the root node in to queue
        Q.Push(N);
        while(!Q.Empty()) {
            // pop the first in node
            BiNode* current = Q.Pop();
            // if it is a leaf node, print #
            if (!current->Lchild && !current->Rchild) std::cout << "leaf:";
            std::cout << current->data << "  ";
            // if there exist leaf nodes, push into queue
            if (current->Lchild) Q.Push(current->Lchild);
            if (current->Rchild) Q.Push(current->Rchild);
        }
        std::cout << std::endl;
    }

    int _Depth(BiNode* N) {
        if (!N) return 0;
        int LDepth = _Depth(N->Lchild);
        int RDepth = _Depth(N->Rchild);
        return LDepth > RDepth? LDepth+1 : RDepth+1;
    }

    void Depth(BiNode* N) {
        std::cout << _Depth(N) << "\n";
    }

    int _Count(BiNode* N) {
        if (!N) return 0;
        int LCount = _Count(N->Lchild);
        int RCount = _Count(N->Rchild);
        if (!N->Lchild && !N->Rchild) {
            return 1;
        } else {
            return LCount + RCount;
        }
    }

    void Count(BiNode* N) {
        std::cout << _Count(N) << "\n";
    }

};