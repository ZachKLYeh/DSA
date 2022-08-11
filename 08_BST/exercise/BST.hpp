/*
Binary Search Tree is a tree specify for binary search
In a binary search tree, 
each left child is smaller then root
each rchild is larger then root

There exist four operations
1. insert: insert into BST doen't require swapping
    we simply check if the inserted number is larger/smaller then the root
    then go to its lchild/rchid, if there exist a child, keepwaking, if there's not
    insert here.

2. search: compare the searching number with root, 
    smaller, root = lchild, 
    larger, root = rchild

3. delete:
    to delete an element, we need to relace the original element with another
    to keep that rchild is smaller and lchild is larger, there are two methods
    1. use largest element in lchid to replace
    2. use min element in rchild to replace

*/
#include "Queue.hpp"

template<typename T>
class BST {
public:
    struct BiNode {
        T data;
        BiNode* lchild;
        BiNode* rchild;
        BiNode() = default;
        BiNode(T element): data(element){}
    };

    BiNode* root;

    BST(){
        root = new BiNode();
    };

    // return a binode pointer because the recurrision send nodes, not values
    BiNode* Insert(BiNode* root, T element) {
        if (!root) return new BiNode(element); // exit condition
        if (element < root->data) root->lchild = Insert(root->lchild, element);
        if (element > root->data) root->rchild = Insert(root->rchild, element);
        return root;
    }

    BiNode* Delete(BiNode* root, T element) {
		if (!root) return root;  // stop condition
		if (element < root->data) { // if the delete elemet is smaller then root
			// then change the left child to the deleted subtree
			root->lchild = Delete(root->lchild, element);
		}
		else if (element > root->data)  {
			root->rchild = Delete(root->rchild, element);
		}
		else { // when root->data == element
			if (!root->lchild && !root->rchild) { // when it is a leaf node
				delete(root);
				return nullptr;
			}
			else if (!root->rchild) { // only lchild
				BiNode* temp = root->lchild;
				delete(root);
				return temp;
			}
			else if (!root->lchild) { // only rchild
				BiNode* temp = root->rchild;
				delete(root);
				return temp;
			}
			else { // both rchild and lchild exists
				// try to find the minum number in rchild subtree, then replace root with it
				BiNode* temp = root->lchild;
				while(temp->rchild) {
					temp = temp->rchild;
				}
				root->data = temp->data;
				root->lchild = Delete(root->lchild, temp->data);
		    }
        }
        return root;
    }

    BiNode* _Search(BiNode* root, T key) {
        if (!root) return 0; // exit condifiton
        if (root->data == key) return root;
        if (key < root->data) return _Search(root->lchild, key);
        else return _Search(root->rchild, key);
    }

    void Search(BiNode*root, T key) {
        BiNode* result = _Search(root, key);
        if (result == 0) std::cout << "the number is not found\n";
        else std::cout << "found " << key << " at pointer " << result << "\n";
    }

    int Depth(BiNode* N) {
        if (!N) return 0;
        int LDepth = Depth(N->lchild);
        int RDepth = Depth(N->rchild);
        return LDepth > RDepth? LDepth+1 : RDepth+1;
    }

    void LevelOrder(BiNode* root) {
        Queue<BiNode*> Q;
        Q.Push(root);
        int depth = Depth(root);
        while(!Q.Empty()) {
            BiNode* current = Q.Pop();

            if (!current->lchild && !current->rchild) std::cout << "leaf:";
            if (current->data) std::cout << current->data << "  ";
            // if there exist leaf nodes, push into queue
            if (current->lchild) Q.Push(current->lchild);
            if (current->rchild) Q.Push(current->rchild);
        }
        std::cout << std::endl;
    }

};
