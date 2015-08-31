/*输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
   假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
   例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。*/


#include "iostream"
#include "vector"
using namespace std;

//Definition for binary tree
struct TreeNode {
								int val;
								TreeNode *left;
								TreeNode *right;
								TreeNode() : left(NULL), right(NULL) {
								};
								TreeNode(int x) : val(x), left(NULL), right(NULL) {
								};
};

//后序遍历二叉树：打印
void treePrint(struct TreeNode *node) {
								if (node == NULL)
																return;
								treePrint(node->left);
								treePrint(node->right);
								cout << node->val;
}

class Solution {
public:
struct TreeNode * reConstructBinaryTree(vector<int> pre, vector<int> in) {
								if (pre.size() == 0 || in.size() == 0) {
																return NULL;
								}
								TreeNode *node = new TreeNode;
								node->val = pre[0];
								auto iter_in = in.begin();
								int i;
								for (i = 0; iter_in != in.end(); iter_in++, i++) {
																break;
								}
								std::vector<int> in_left_tree;
								std::vector<int> in_right_tree;
								in_left_tree.assign(in.begin(), iter_in);
								in_right_tree.assign(iter_in + 1, in.end());
								/*for (auto loc = in_left_tree.begin(); loc != in_left_tree.end(); loc++)
								   cout << *loc;
								   cout << endl << "----------------------------------" << endl;
								   for (auto loc = in_right_tree.begin(); loc != in_right_tree.end(); loc++)
								   cout << *loc;
								   cout << endl<<endl<<endl;*/
								std::vector<int> pre_left_tree;
								std::vector<int> pre_right_tree;
								pre_left_tree.assign(pre.begin() + 1, pre.begin() + i + 1);
								pre_right_tree.assign(pre.begin() + i + 1, pre.end());
								/*for (auto loc = pre_left_tree.begin(); loc != pre_left_tree.end(); loc++)
								   cout << *loc;
								   cout << endl << "----------------------------------" << endl;
								   for (auto loc = pre_right_tree.begin(); loc != pre_right_tree.end(); loc++)
								   cout << *loc;
								   cout << endl;*/

								node->left=reConstructBinaryTree(pre_left_tree, in_left_tree);
								node->right = reConstructBinaryTree(pre_right_tree, in_right_tree);
								cout << node->val;
								return node;

}
};

int main(int argc, char const *argv[])
{
								vector<int> pre = {1, 2, 4, 7, 3, 5, 6, 8};
								vector<int> in = {4, 7, 2, 1, 5, 3, 8, 6};
								Solution so;
								TreeNode *root = new TreeNode;
								root = so.reConstructBinaryTree(pre, in);
								cout << endl;
								treePrint(root);
								cout << endl;
								return 0;
}

/*#include <iostream>
   #include <fstream>
   #include <string>
   using namespace std;
   struct TreeNode
   {
   struct TreeNode* left;
   struct TreeNode* right;
   char  elem;
   };

   void BinaryTreeFromOrderings(const char* inorder, const char* preorder, int length)
   {
   if (length == 0)
   {
   //cout<<"invalid length";
   return;
   }
   TreeNode* node = new TreeNode;//Noice that [new] should be written out.
   node->elem = *preorder;
   int rootIndex = 0;
   for (; rootIndex < length; rootIndex++)
   {
   if (inorder[rootIndex] == *preorder)
   break;
   }
   //Left
   BinaryTreeFromOrderings(inorder, preorder + 1, rootIndex);
   //Right
   BinaryTreeFromOrderings(inorder + rootIndex + 1, preorder + rootIndex + 1, length - (rootIndex + 1));
   cout << node->elem << endl;
   return;
   }


   int main(int argc, char* argv[])
   {
   printf("Hello World!\n");
   const char* pr = "GDAFEMHZ";
   const char* in = "ADEFGHMZ";
   BinaryTreeFromOrderings(in, pr, 8);

   printf("\n");
   return 0;
   }*/
