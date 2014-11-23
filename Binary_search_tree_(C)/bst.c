/*a dummy binary tree implementation*/
#include <stdlib.h>
#include "bst.h"

struct bst_node** search(struct bst_node** root, comparator compare, void* data) {
    struct bst_node** node = root;
    while (*node != NULL) {
        int compare_result = compare(data, (*node)->data);
        if (compare_result < 0)
            node = &(*node)->left;
        else if (compare_result > 0)
            node = &(*node)->right;
        else
            break;
    }
    return node;
}
void insert(struct bst_node** root, comparator compare, void* data) {
    struct bst_node** node = search(root, compare, data);
    if (*node == NULL) {
        *node = new_node(data);
    }
}
void delete(struct bst_node** node) {
    struct bst_node* old_node = *node;
    if ((*node)->left == NULL) {
        *node = (*node)->right;
        free_node(old_node);
    } else if ((*node)->right == NULL) {
        *node = (*node)->left;
        free_node(old_node);
    } else {
        struct bst_node** pred = &(*node)->left;
	while ((*pred)->right != NULL) {
	    pred = &(*pred)->right;
	}

	/* Swap values */
	void* temp = (*pred)->data;
	(*pred)->data = (*node)->data;
	(*node)->data = temp;

	delete(pred);
    }
}
