#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Left-rotates a binary tree.
 * @tree: A pointer to the root node of the tree to rotate.
 *
 * Return: A pointer to the new root node after rotation.
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *pivot, *tape;

	if (tree == NULL || tree->right == NULL)
		return (NULL);

	pivot = tree->right;
	tape = pivot->left;
	pivot->left = tree;
	tree->right = tape;
	if (tape != NULL)
		tape->parent = tree;
	tape = tree->parent;
	tree->parent = pivot;
	pivot->parent = tape;
	if (tape != NULL)
	{
		if (tape->left == tree)
			tape->left = pivot;
		else
			tape->right = pivot;
	}

	return (pivot);
}
