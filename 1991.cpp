#include<iostream>

using namespace std;

typedef struct tree
{
	char node;
	tree* left;
	tree* right;
}Tree;

void preorder(Tree* root);
void inorder(Tree* root);
void postorder(Tree* root);

////typedef tree* Tree;

int main(void)
{
	int howMany;
	char node, left, right;
	
	cin >> howMany;
	Tree *tree= new Tree[howMany];
	
	for (int i = 0; i < howMany; i++)
	{
		
		cin >> node >> left >> right;
		tree[(int)node - 'A'].node=node;

		if(left == '.')
			tree[(int)node - 'A'].left =NULL;
		else
			tree[(int)node - 'A'].left = &(tree[(int)left-'A']);
		
		if (right == '.')
			tree[(int)node - 'A'].right = NULL;
		else
			tree[(int)node - 'A'].right = &(tree[(int)right - 'A']);

	}
	
	preorder(&tree[0]);
	cout << endl;
	inorder(&tree[0]);
	cout << endl;
	postorder(&tree[0]);
	
	return 0;

}

void preorder(Tree *root)
{
	if (root == NULL)
		return;
	cout << root->node;
	preorder(root->left);
	preorder(root->right);
}

void inorder(Tree *root)
{
	if (root == NULL)
		return;
	inorder(root->left);
	cout << root->node;
	inorder(root->right);
}

void postorder(Tree *root)
{
	if (root == NULL)
		return;
	postorder(root->left);
	postorder(root->right);
	cout << root->node;
}
