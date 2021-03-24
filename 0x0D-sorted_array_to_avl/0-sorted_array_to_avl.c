#include "binary_trees.h"

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array
 *
 * @array: Pointer to the first element of the array to be converted
 * @size: The number of elements in the array
 *
 * Return: pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (!array)
		return (NULL);
	return (insert_AVL_node(NULL, array, 0, (int)size - 1));
}

/**
 * insert_AVL_node - Creates recursively an AVL tree.
 * @parent: pointer to the parent node of the node to create
 * @array: Pointer to the first element of the array to be converted
 * @start: start index to get the middle point to divide the array
 * @end: end index to get the middle point to divide the array
 *
 * Return: pointer to the created node, or NULL on failure
 */
avl_t *insert_AVL_node(avl_t *parent, int *array, int start, int end)
{
	size_t middle;
	avl_t *root = NULL;

	if (start > end)
		return (NULL);

	middle = (start + end) / 2;
	root = new_node(parent, array[middle]);

	if (!root)
		return (NULL);

	root->left = insert_AVL_node(root, array, start, middle - 1);
	root->right = insert_AVL_node(root, array, middle + 1, end);

	return (root);
}

/**
 * new_node - Creates an AVL tree node
 * @parent: pointer to the parent node of the node to create
 * @value: value to store in the new node
 *
 * Return: pointer to the created node, or NULL on failure
 */
avl_t *new_node(avl_t *parent, size_t value)
{
	avl_t *node = malloc(sizeof(avl_t));

	if (!node)
		return (NULL);

	node->n = value;
	node->parent = parent;
	node->left = NULL;
	node->right = NULL;
	return (node);
}
