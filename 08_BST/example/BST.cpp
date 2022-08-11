#include <iostream>
using namespace std;
using T = int;
struct BiNode
{
	T data;
	BiNode *Lchild{0};
	BiNode *Rchild{0};
	BiNode() = default;
	BiNode(T x) : data(x), Lchild(0), Rchild(0) {}
};
BiNode *SearchBST(BiNode *root, T key)
{ //編寫搜尋函式
	if (!root)
		return 0; //遞迴出口
	if (root->data == key)
		return root;	  //處理跟部
	if (key < root->data) //如果關鍵字在左子樹
		return SearchBST(root->Lchild, key);
	else //如果關鍵字在右子樹
		return SearchBST(root->Rchild, key);
}

BiNode *SearchBST_(BiNode *root, T key)
{ //利用疊代法找出想要的值
	BiNode *P = root;

	while (P && P->data != key) //當P不是空的且P的值與關鍵字不同
		if (key < P->data)
			P = P->Lchild; //將P改為P的左子節點
		else
			P = P->Rchild; //將P改為P的右子節點
	if (!P)
		return 0;
	return P;
}

void Inorder(BiNode *T)
{
	if (!T)
		return;
	Inorder(T->Lchild);
	std::cout << T->data << " ";
	Inorder(T->Rchild);
}

void Preorder(BiNode *T)
{
	if (!T)
		return;
	std::cout << T->data << " ";
	Preorder(T->Lchild);
	Preorder(T->Rchild);
}

void Postorder(BiNode *T)
{
	if (!T)
		return;
	Postorder(T->Lchild);
	Postorder(T->Rchild);
	std::cout << T->data << " ";
}
#include <queue>
void Level_order(BiNode *T)
{
	queue<BiNode *> Q;
	Q.push(T);
	while (!Q.empty())
	{
		BiNode *p = Q.front();
		Q.pop();
		std::cout << p->data;
		if (p->Lchild)
			Q.push(p->Lchild);
		if (p->Rchild)
			Q.push(p->Rchild);
	}
}
BiNode *InsertBST(BiNode *root, T e)
{
	if (root == 0)
	{ //如果樹跟沒有值，則直接將值傳回樹跟
		return new BiNode(e);
	}
	if (e < root->data) //左子樹
		root->Lchild = InsertBST(root->Lchild, e);
	else if (e > root->data) //右子樹
		root->Rchild = InsertBST(root->Rchild, e);
	return root;
}
BiNode *InsertBST_(BiNode *root, T e)
{
	BiNode *p = root, *parent = 0;
	while (p && p->data != e)
	{
		parent = p;
		if (e < p->data)
			p = p->Lchild; //左子樹
		else
			p = p->Rchild; //右子樹
	}
	if (p)
		return 0;
	if (!parent)
		return new BiNode(e);
	else if (e < parent->data)
	{
		parent->Lchild = new BiNode(e);
		return parent->Lchild;
	}
	else
	{
		parent->Rchild = new BiNode(e);
		return parent->Rchild;
	}
}
BiNode *DeleteBST(BiNode *root, T e)
{ // e為要刪除的值
	if (!root)
		return root;							   //如果是空樹則直接返回
	if (e < root->data)							   //如果e小於根節點的值
		root->Lchild = DeleteBST(root->Lchild, e); //則執行此過程直到值一樣
	else if (e > root->data)					   //同理
		root->Rchild = DeleteBST(root->Rchild, e);
	else
	{ //相等後開始刪除節點
		if (!root->Lchild && !root->Rchild)
		{ //若沒有左右子樹則直接刪除
			delete (root);
			return nullptr; //返回空指針
		}
		else if (!root->Rchild)
		{								//若要刪除的節點沒有右子節點
			BiNode *ret = root->Lchild; //則保存左子節點
			delete (root);
			return ret;
		}
		else if (!root->Lchild)
		{ //概念同上
			BiNode *ret = root->Rchild;
			delete (root);
			return ret;
		}
		else
		{								//若要刪除的節點有兩個子節點
			BiNode *tmp = root->Rchild; //宣告tmp為root(不一定是根節點)的右子節點
			while (tmp->Lchild)			//然後將tmp往左子節點移動直到沒有節點
				tmp = tmp->Lchild;

			root->data = tmp->data; //將tmp和要刪除的節點對調，並更改節點的指針
			root->Rchild = DeleteBST(root->Rchild, e);
		}
	}
	return root;
}

int main()
{
	BiNode *T = new BiNode(30);
	T->Lchild = new BiNode(20);
	T->Rchild = new BiNode(40);
	BiNode *P = T->Lchild;
	P->Lchild = new BiNode(17);
	P->Rchild = new BiNode(25);
	BiNode *S = T->Rchild;
	S->Lchild = new BiNode(38);
	S->Rchild = new BiNode(45);
	/*
	Inorder(T); std::cout << "\n";
	Preorder(T); std::cout << "\n";
	Postorder(T); std::cout << "\n";
	Level_order(T); std::cout << "\n";

	if (P = SearchBST_(T, 17))
		std::cout << "搜尋的值是：" << P->data << std::endl;
	else
		std::cout << "搜尋失敗，沒有找到：" << 17 << std::endl;
	if (P = SearchBST_(T, 23))
		std::cout << "搜尋的值是：" << P->data << std::endl;
	else
		std::cout << "搜尋失敗，沒有找到：" << 23 << std::endl;
	return 0;*/

	InsertBST(T, 23);
	InsertBST(T, 25);
	Inorder(T);
	std::cout << "\n";
	Preorder(T);
	std::cout << "\n";
	Postorder(T);
	std::cout << "\n";
	if (P = SearchBST_(T, 23))
		std::cout << "搜尋的值是：" << P->data << std::endl;
	else
		std::cout << "搜尋失敗，沒有找到：" << 23 << std::endl;

	std::cout << "刪除：" << 23 << endl;
	T = DeleteBST(T, 23);
	Inorder(T);
	std::cout << "\n";
	Preorder(T);
	std::cout << "\n";
	Postorder(T);
	std::cout << "\n";
	return 0;
}