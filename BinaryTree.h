#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>
#include <string>
#include "Node.h"

class BinaryTree {
private:
    Node* root;
public:
    BinaryTree(int value) {
        root = new Node(value);
    }
    void insertLeft(int value) {
        root->left = new Node(value);
    }
    void insertRight(int value) {
        root->right = new Node(value);
    }

    std::string inOrderTraverse() {
        std::string result = "";
        inOrder(root, result);
        return result;
    }
    std::string preOrderTraverse() {
        std::string result = "";
        preOrder(root, result);
        return result;
    }
    std::string postOrderTraverse() {
        std::string result = "";
        postOrder(root, result);
        return result;
    }

    Node* getroot() {
        return root;
    }

    //Exercise 2 
    void insertValue(int Value)
    {
        insertRandom(root, Value);
    }
    void TreePrinter(Node* node, bool isLeft, std::string Branch)
    {
        if ( node == nullptr)
        {
            return;
        }
        std::cout << Branch;
        std::cout << ( isLeft == true ? "|_ " : "   |_") << node->data << std::endl;
        std::string NewBranch = Branch +(isLeft == true ? "   " : "       ");
        TreePrinter(node->left,true, NewBranch);
        TreePrinter(node->right, false, NewBranch);
    }
    int getLeftHeight( Node* node) 
    {
        int Height = 0;
        while ( node != nullptr)
        {
            Height += 1;
            node = node->left;
        }
        return Height;
    }
    int getRightHeight(Node* node) 
    {
        int Height = 0;
        while ( node != nullptr)
        {
            Height += 1;
            node = node->right;
        }
        return Height;
    }

private:
     void inOrder(Node* node, std::string& result) {
        //your code here
        if ( node == nullptr)
        {
            return;
        } 
        inOrder(node->left, result);
        result += std::to_string(node->data) + " ";
        inOrder(node->right, result);
    };
    void preOrder(Node* node, std::string& result) {
        //your code here
        if ( node == nullptr)
        {
            return;
        } 
        result += std::to_string(node->data) + " ";
        preOrder(node->left, result);
        preOrder(node->right, result);
    };
    void postOrder(Node* node, std::string& result) {
        //your code here
        if ( node == nullptr)
        {
            return;
        } 
        postOrder(node->left, result);
        postOrder(node->right, result);
        result += std::to_string(node->data) + " ";
    }

    //Exercise 2
    void insertRandom(Node* node, int Value)
    {
        int AutoStore = std::rand() % 2;
        if ( AutoStore == 1)
        {
            if (node->left)
            {
                insertRandom(node->left, Value);
            }
            else
            {
                node->left = new Node(Value);
            }
        }
        else
        {
            if (node->right)
            {
                insertRandom(node->right, Value);
            }
            else
            {
                node->right = new Node(Value);
            }
        }
    }
};

#endif // BINARYTREE_H
