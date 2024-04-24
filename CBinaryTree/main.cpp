#include "BinaryTree.h"

using namespace std;

int main()
{
    int vals[] = {52, 2, 43, 231, 0, 24, 64, 100, 53};
    auto root = new BinaryTree<int>(vals[0]);
    for (int i = 1; i < sizeof(vals)/sizeof(vals[0]); ++i) {
        root->insert(vals[i]);
    }
    BinaryTree<int>::inOrder(root);
    delete root;
	return 0;
}