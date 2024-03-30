#include "binary_trees.h"

/**
 * bst_insert - Inserts a value in a Binary Search Tree.
 * @tree: A double pointer to the root node of the BST to insert the value.
 * @value: The value to store in the node to be inserted.
 *
 * Return: A pointer to the created node, or NULL on failure.
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *cuser, *new;

	if (tree != NULL)
	{
		cuser = *tree;

		if (cuser == NULL)
		{
			new = binary_tree_node(cuser, value);
			if (new == NULL)
				return (NULL);
			return (*tree = new);
		}

		if (value < cuser->n) /* insert in left subtree */
		{
			if (cuser->left != NULL)
				return (bst_insert(&cuser->left, value));

			new = binary_tree_node(cuser, value);
			if (new == NULL)
				return (NULL);
			return (cuser->left = new);
		}
		if (value > cuser->n) /* insert in right subtree */
		{
			if (cuser->right != NULL)
				return (bst_insert(&cuser->right, value));

			new = binary_tree_node(cuser, value);
			if (new == NULL)
				return (NULL);
			return (cuser->right = new);
		}
	}
	return (NULL);
}
