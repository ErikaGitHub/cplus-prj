/*
file contenente la definizione dell' "interfaccia" per la "classe" List (vedi file readme.txt).
*/

#ifndef _LIST_H
#define _LIST_H

//definizione di nodo di una lista
typedef struct node_s {
	void *object;
	struct node_s *prev;
	struct node_s *next;	
} node;

/*
 object contiene il puntatore al dato 
 prev il puntatore al nodo precedente
 next il puntatore al nodo successivo
 */

//definizione del tipo di dato integer (wrapper di un int)
typedef struct integer_s {
	int i;
} integer;

integer* build_integer (int new_int);
void print_integer(void* a);
int compare_integer (void* a, void* b);
void free_integer(void* a);

//definizione del tipo di dato string (wrapper di un char*)
typedef struct string_s {
	char* s;
} string;

string* build_string (char* new_cstring);
void print_string(void* a);
int compare_string (void* a, void* b);
void free_string(void* a);

//definizione di una lista
typedef struct list_s {
	node *head;
	node *tail;
	int size;
} list;
/*
 head puntatore al primo nodo inserito
 tail puntatore all'ultimo nodo inserito
 size numero di nodi distinto dalla head
 */

/*definizione dell'interfaccia*/
list* build_list(void* new_object);
void queue_print(list* my_list, void (*print)(void*));
node** queue_search(list* my_list, int (*compare)(void* ,void* ), void* object);
node** queue_insert_search(list* my_list, int (*compare)(void* ,void* ), void* new_object);
node** queue_insert(list* my_list, void* new_object);
list* queue_build(void* new_object_array [], int object_number);
int queue_insert_here(list* my_list, node** my_node, void* new_object);
void queue_delete_node(node** current_node, void (*free_object)(void*));
void queue_delete(list *my_list, node** current_node, void (*free_object)(void*));
int queue_delete_tail(list *my_list, void (*free_object)(void*));
list* build_test_tree();
node** tree_search(list *my_list, int (*compare)(void* ,void* ), void* object);
void tree_print(list *my_list, void (*print)(void*));
node** tree_insert(list *my_list, int (*compare)(void* ,void* ), void* new_object);
list* tree_build(int (*compare)(void* ,void* ), void* new_object_array [], int object_number);
void tree_delete_node_prev(node** current_node, void (*free_object)(void*));
void tree_delete_node_next(node** current_node, void (*free_object)(void*));
void tree_delete(list *my_list, node** current_node, void (*free_object)(void*));

#endif