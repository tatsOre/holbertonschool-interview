# 0x0E. Linear search in skip list

Looking for a specific value in a singly linked list always leads to browse every element of the list. A common way to optimize the time complexity of a search in a singly linked list is to modify the list itself by adding an “express lane” to browse it. A linked list with an express lane is called a [skip list](https://en.wikipedia.org/wiki/Skip_list).

Function that searches for a value in a sorted skip list of integers.

* Prototype : skiplist_t *linear_skip(skiplist_t *list, int value);
* Where `list` is a pointer to the head of the skip list to search in
* A node of the express lane is placed every index which is a multiple of the square root of the size of the list
* And `value` is the value to search for
* `list` will be sorted in ascending order
* The function returns a pointer on the first node where `value` is located
* If `value` is not present in `list` or if `head` is `NULL`, the function will return `NULL`
* Every time a value is compared in the list to the searched value, this value will be printed

### Author:
* Tatiana Orejuela Zapata | [Github](https://github.com/tatsOre)

##### Specializations - Interview Preparation ― Algorithms
##### March, 2021. 
