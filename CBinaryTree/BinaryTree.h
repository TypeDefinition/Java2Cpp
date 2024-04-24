#pragma once

#include <type_traits>
#include <functional>
#include <iostream>

using namespace std;

template<typename T, typename C = less<T>>
class BinaryTree {
private:
    const T value;
    const C comparator;
    BinaryTree* left;
    BinaryTree* right;

public:
    BinaryTree(T val)
        : value(val)
        , left(nullptr)
        , right(nullptr)
    {}

    ~BinaryTree() {
        if (left) { delete left; }
        if (right) { delete right; }
    }

    const T& getValue() const {
        return value;
    }

    const BinaryTree* getLeft() const {
        return left;
    }

    const BinaryTree* getRight() const {
        return right;
    }

    void insert(T val) {
        if (comparator(this->value, val)) {
            if (!right) {
                right = new BinaryTree(val);
            } else {
                right->insert(val);
            }
        } else {
            if (!left) {
                left = new BinaryTree(val);
            } else {
                left->insert(val);
            }
        }
    }

    static void preOrder(const BinaryTree* node) {
        cout << node->value << endl;
        if (node->getLeft()) { preOrder(node->getLeft()); }
        if (node->getRight()) { preOrder(node->getRight()); }
    }

    static void inOrder(const BinaryTree* node) {
        if (node->getLeft()) { inOrder(node->getLeft()); }
        cout << node->value << endl;
        if (node->getRight()) { inOrder(node->getRight()); }
    }

    static void postOrder(const BinaryTree* node) {
        if (node->getLeft()) { postOrder(node->getLeft()); }
        if (node->getRight()) { postOrder(node->getRight()); }
        cout << node->value << endl;
    }
};