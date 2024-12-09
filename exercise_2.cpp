#include <iostream>
#include "BinaryTree.h"
#include "Node.h"

int main() {
    //1.	Create a binary Tree
    BinaryTree MyTree(10);
    Node* root = MyTree.getroot();
    //2.	Randomly generate 50 numbers
    for ( int i = 0; i < 50; i++)
    {
        int MyNumber = std::rand() % 100;
        MyTree.insertValue(MyNumber);
    }
    //3.	Insert each number into the tree
    //4.    Print a tree result
    MyTree.TreePrinter(root, true, "");
    //5.    Challenge: Implement a function that returns the height of the tree
    std::cout << MyTree.getLeftHeight(root) << std::endl;;
    std::cout << MyTree.getRightHeight(root) << std::endl;;
}