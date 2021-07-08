#include "list.h"

/**
 * add_node_end - Add a new node to the end of a double circular linked list
 *
 * @list: a pointer to the head of the linkd list
 * @str: the string to copy into the new node
 * Return: Address of the new node, or NULL on failure
 */
List *add_node_end(List **list, char *str)
{
	List *new = NULL, *last = NULL;

	if (!list)
		return (NULL);

	new = malloc(sizeof(List));
	if (!new)
		return (NULL);

	new->prev = NULL;
	new->next = NULL;
	new->str = strdup(str);

	if (str && !new->str)
	{
		free(new);
		return (NULL);
	}

	if (!*list)
	{
		new->prev = new;
		new->next = new;
		return (*list = new);
	}

	last = (*list)->prev;
	new->next = *list;
	last->next = new;
	new->prev = last;
	(*list)->prev = new;
	return (new);
}

/**
 * add_node_begin - Add a new node to the beginning of a
 * double circular linked list
 *
 * @list: a pointer to the head of the linkd list
 * @str: the string to copy into the new node
 * Return: Address of the new node, or NULL on failure
 */
List *add_node_begin(List **list, char *str)
{
	List *new = add_node_end(list, str);

	if (!new)
		return (NULL);
	*list = (*list)->prev;
	return (*list);
}
