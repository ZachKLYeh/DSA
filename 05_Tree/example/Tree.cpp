#include<iostream>
using T = char;
#include<queue>
using namespace std;

template<typename T>
class BiTree {
public:
	struct BiNode {
		T data;
		BiNode* Lchild{ 0 };
		BiNode* Rchild{ 0 };
	};

	BiNode* root;
	BiTree() {
		//root = PreCreat(); //因為要建立新的二元樹，所以原本的可以先註解掉
		
		root = new BiNode(); root->data = 'A';
		root->Lchild = new BiNode(); root->Lchild->data = 'B';
		root->Rchild = new BiNode(); root->Rchild->data = 'C';
		BiNode* P = root->Lchild;
		P->Lchild = new BiNode(); P->Lchild->data = 'D';
		P->Rchild = new BiNode(); P->Rchild->data = 'E';
		BiNode* S = root->Rchild;
		S->Lchild = new BiNode(); S->Lchild->data = 'F';
		S->Rchild = new BiNode(); S->Rchild->data = 'G';
		
	}
	void Inorder(BiNode* T) {
		if (!T)return;
		Inorder(T->Lchild);
		std::cout << T->data << " ";
		Inorder(T->Rchild);
	}

	void Preorder(BiNode* T) {
		if (!T) {
			std::cout << "#" << " ";
			return;
		} 
		std::cout << T->data;
		Preorder(T->Lchild);
		Preorder(T->Rchild);
	}

	void Postorder(BiNode* T) {
		if (!T)return;
		Postorder(T->Lchild);
		Postorder(T->Rchild);
		std::cout << T->data << " ";
	}
	void Level_order(BiNode* T) {
		queue<BiNode*> Q;
		Q.push(T);
		while (!Q.empty()) {
			BiNode* p = Q.front();
			Q.pop();
			std::cout << p->data << " ";
			if (p->Lchild) Q.push(p->Lchild);
			if (p->Rchild) Q.push(p->Rchild);
		}
	}
	void Inorder() {
		Inorder(root);
	}
	void Preorder() {
		Preorder(root);
	}
	void Postorder() {
		Postorder(root);
	}
	void Level_order() {
		Level_order(root);
	}
	int Depth(BiNode* T){
		if (!T) return 0;
		int L = Depth(T->Lchild);
		int R = Depth(T->Rchild);
		return L > R ? L + 1 : R + 1; //如果L>R，那麼樹深將會是L的深度+1，否則是R的深度+1
	}
	int Depth() {
		return Depth(root);
}
	int Count(BiNode* T) {
		if (!T) return 0;
		int L = Count(T->Lchild);
		int R = Count(T->Rchild);
		if (!T->Lchild && !T->Rchild) //如果Lchild不為0且Rchild不為0
			return L + R + 1;
		else
			return L + R;
	}
	int Count() {
		return Count(root);
	}
	BiNode* PreCreat() {
		T e;
		std::cin >> e;
		if (e == '#') return 0;
		BiNode* J = new BiNode();
		J->data = e;
		J->Lchild = PreCreat();
		J->Rchild = PreCreat();
		return J;
	}
};

using T = char;
int main() {
	BiTree<char> bt;
	bt.Inorder(); std::cout << "\n";
	bt.Preorder(); std::cout << "\n";
	bt.Postorder(); std::cout << "\n";
	bt.Level_order(); std::cout << "\n";
	std::cout << std::endl;

	std:cout<<bt.Count()<< "\n";
}