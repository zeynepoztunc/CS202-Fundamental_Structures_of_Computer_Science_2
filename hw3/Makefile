hw3: main.o DictionarySearchTree.o Dictionary23Tree.o DictionaryAVLTree.o DictionaryBST.o BinaryNode.o TriNode.o
	g++ main.o DictionarySearchTree.o Dictionary23Tree.o DictionaryAVLTree.o DictionaryBST.o  BinaryNode.o TriNode.o -o hw3
main.o: main.cpp DictionarySearchTree.h Dictionary23Tree.h DictionaryAVLTree.h DictionaryBST.h
	g++ -c main.cpp
DictionarySearchTree.o: DictionarySearchTree.h DictionarySearchTree.cpp BinaryNode.h
	g++ -c DictionarySearchTree.cpp
BinaryNode.o: BinaryNode.h BinaryNode.cpp
	g++ -c BinaryNode.cpp
TriNode.o: TriNode.h TriNode.cpp
	g++ -c TriNode.cpp
Dictionary23Tree.o: Dictionary23Tree.h Dictionary23Tree.cpp TriNode.h
	g++ -c Dictionary23Tree.cpp
DictionaryAVLTree.o: DictionaryAVLTree.h DictionaryAVLTree.cpp BinaryNode.h
	g++ -c DictionaryAVLTree.cpp
DictionaryBST.o: DictionaryBST.h DictionaryBST.cpp
	g++ -c DictionaryBST.cpp
remove:
	rm *.o hw3