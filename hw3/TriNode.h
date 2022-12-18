/**
* Title: AVL Trees
* Author: Zeynep Selcen Öztunç
* ID: 21902941
* Section : 1
* Assignment : 3
* Description : Header file for a 2-3 Tree node
*/
#ifndef Two3Node_h
#define Two3Node_h
#include <string>
using namespace std;

class TriNode {
	private:
		
	public:
		TriNode();
		TriNode(const string & anItem);
		string smallItem, largeItem; // Data portion
		TriNode* leftChildPtr; // Left-child pointer
		TriNode* midChildPtr; // Middle-child pointer
		TriNode* rightChildPtr; // Right-child pointer

		//TriNode(const string & anItem, TriNode<string>*leftPtr,
		//TriNode<string>*midPtr, TriNode<string>*rightPtr);
		/*bool isLeaf() const;
		bool isThreeNode() const;
		ItemType getSmallItem() const;
		ItemType getLargeItem() const;
		void setSmallItem(const ItemType & anItem);
	void setLargeItem(const ItemType & anItem);*/
		
		bool isTwoNode() const;

		TriNode* parent;
		bool isLeaf;//whether the node is a leaf
		bool has2Items;//whether the node has two items
		friend class Dictionary23Tree;
};

#endif /* Two3Node_h */