hw2: main.o BST.o analysis.o 
	g++ main.o BST.o analysis.o -o hw2
main.o: main.cpp analysis.h BST.h
	g++ -c main.cpp
BST.o: BST.cpp BST.h TreeNode.h
	g++ -c BST.cpp
analysis.o: analysis.cpp analysis.h BST.h
	g++ -c analysis.cpp
remove:
	rm *.o hw2