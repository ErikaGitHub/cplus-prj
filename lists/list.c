/*file contenente l'implementazione delle interfaccia per la List, la Queue e il Tree (vedi file readme.txt) */

#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "list.h"

//"costruttore" di un integer
integer* build_integer (int new_int){
	
	integer *new_integer;
	if (!(new_integer =  malloc(sizeof(integer)))) {
		return 0;
	}
	new_integer->i = new_int; 
	
	return new_integer;
}

//"stampatore" di un integer
void print_integer(void* a){
	printf("%d\n",((integer*)a)->i);
	
}

//operatore di confronto di un integer
int compare_integer (void* a, void* b){
	return (((integer*)a)->i - ((integer*)b)->i);
}

//"distruttore" di un integer
void free_integer(void* a){
	free((integer*)a);
}

//costruttore di una string
string* build_string (char* new_cstring){
	
	string* new_string;
	if (!(new_string =  malloc(sizeof(string)))) {
		return 0;
	}
	new_string->s = new_cstring; 
	
	return new_string;
}

//"stampatore" di una string
void print_string(void* a){
	printf("%s\n",((string*)a)->s);
	
}

//operatore di confornto di una string
int compare_string (void* a, void* b){
	return strcmp(((string*)a)->s,((string*)b)->s);
}

//distruttore di una string
void free_string(void* a){
	free((string*)a);
}

//costruisce una "list" formata dall'unico nodo new_object (metodo not abstract della classe List ovvero non deve essere implementato dalle sottoclassi)
list* build_list(void* new_object){
	
	list *new_list;
	if (!(new_list =  malloc(sizeof(list)))) {
		return 0;
	}
	if (!(new_list->head =  malloc(sizeof(node)))) {
		return 0;
	}
	(new_list->head)->prev = NULL;
	(new_list->head)->next = NULL;
	(new_list->head)->object = new_object;
	new_list->tail = new_list->head;
	new_list->size = 0; 
	
	return new_list;
}

//stampa una "Queue" dalla tail
void queue_print(list* my_list, void (*print)(void*)){
	node** current_node = &(my_list->tail);
	while (*current_node != NULL) {
		print((*current_node)->object);
		current_node = &((*current_node)->prev);
	}
	printf("\n");
	return;
}

//cerca un elemento in una "Queue" dalla tail
node** queue_search(list* my_list, int (*compare)(void* ,void* ), void* object) {
	node** current_node = &(my_list->tail);
	
	while (*current_node != NULL) {
		int compare_result = compare(object, (*current_node)->object);
		if (compare_result != 0)
			current_node = &((*current_node)->prev);
		else
			break;
	}
	if (*current_node != NULL)
		return current_node;
	else {
		return &(my_list->tail->next);
	}
}

//inserisce un elemento in una "Queue" dopo averlo cercato e aggiorna la tail
node** queue_insert_search(list* my_list, int (*compare)(void* ,void* ), void* new_object){
	if (my_list->head == NULL || my_list->tail == NULL) {
		return NULL;
	}
	node** new_node = queue_search(my_list,compare,new_object);
	if ( *new_node == NULL){
		if (!(*new_node =  malloc(sizeof(node)))) {
			//e' giusta la gestione dell'errore ?
			return NULL;
		}
		(*new_node)->prev = my_list->tail;
		(*new_node)->next = NULL;
		(*new_node)->object = new_object;
		
		my_list->tail = *new_node;
		(my_list->size)++;
	}
	return new_node;
}

//inserisce un elemento in una "Queue" con almeno un nodo e aggiorna la tail
node** queue_insert(list* my_list, void* new_object){
	if (my_list->head == NULL || my_list->tail == NULL) {
		return NULL;
	}
	
	node** new_node = &(my_list->tail->next);
	if ( *new_node == NULL){
		if (!(*new_node =  malloc(sizeof(node)))) {
			return NULL;
		}
		(*new_node)->prev = my_list->tail;
		(*new_node)->next = NULL;
		(*new_node)->object = new_object;
		my_list->tail = *new_node;
		(my_list->size)++; 
	}
	
	return new_node;
}

//costruisce una "Queue" a partire da un array. Usa il metodo insert
list* queue_build(void* new_object_array [], int object_number){
	list *new_list;
	new_list = build_list(new_object_array[0]);
	for (int i = 1; i<object_number; i++) {
		queue_insert(new_list, new_object_array[i]);	
	}
	
	return new_list;
}

//inserisce un nodo in un punto qualsiasi di una "Queue" (distinto dalla head) 
int queue_insert_here(list* my_list, node** my_node, void* new_object){
	if (my_list->head == NULL || my_list->tail == NULL) {
		return 0;
	}
	node *new_node;
	if (!(new_node =  malloc(sizeof(node)))) {
		return 0;
	}
	
	new_node->prev = (*my_node)->prev;
	new_node->next = *my_node;
	new_node->object = new_object;
	
	(*my_node)->prev = new_node;
	
	return 1;
}

//rimozione di nodo qualsiasi di una "Queue"
void queue_delete_node(node** current_node, void (*free_object)(void*)){
	node* old_node = *current_node;
	*current_node = (*current_node)->prev;
	free_object(old_node->object);
	free(old_node);
	
	return;
}

//rimozione di un elemento distinto dalla "head" e dalla tail in una "Queue" e senza aggiornamento della tail
void queue_delete(list *my_list, node** current_node, void (*free_object)(void*)){
	if (my_list->head == NULL || my_list->tail == NULL) {
		return;
	}
	
	queue_delete_node(current_node, free_object);
	
	(my_list->size)--;
	
	return;	
}

//rimozione della coda per una Queue
int queue_delete_tail(list *my_list, void (*free_object)(void*)){
	
	if (my_list->head == NULL || my_list->tail == NULL) {
		return 0;
	}
	node *old_tail;
	old_tail = my_list->tail;
	
	my_list->tail = my_list->tail->prev;
	
	free_object(old_tail->object);
	free(old_tail);
	
	return 1;
}

//costruisce un alberello di test 
list* build_test_tree(){
	
	list *new_list;
	if (!(new_list =  malloc(sizeof(list)))) {
		return 0;
	}
	if (!(new_list->head =  malloc(sizeof(node)))) {
		return 0;
	}
	node* nodeChild1 = malloc(sizeof(node));
	node* nodeChild2 = malloc(sizeof(node));
	
	int i = 2;
	integer* my_integer = build_integer(i);
	(new_list->head)->prev = nodeChild1;
	(new_list->head)->next = nodeChild2;
	(new_list->head)->object = my_integer;
	
	i=1;
	my_integer = build_integer(i);
	nodeChild1->prev = NULL;
	nodeChild1->next = NULL;
	nodeChild1->object = my_integer;
	
	i=3;
	my_integer = build_integer(i);
	nodeChild2->prev = NULL;
	nodeChild2->next = NULL;
	nodeChild2->object = my_integer;
	
	new_list->tail = nodeChild2;
	new_list->size = 2; 
	
	return new_list;
}

//cerca un elemento nell' albero
node** tree_search(list *my_list, int (*compare)(void* ,void* ), void* object) {
	node** current_node = &(my_list->head);
	while (*current_node != NULL) {
		int compare_result = compare(object, (*current_node)->object);
		if (compare_result < 0)
			current_node = &((*current_node)->prev);
		else if (compare_result > 0)
			current_node = &((*current_node)->next);
		else
			break;
	}
	return current_node;
}

//stampa un albero
void tree_print(list *my_list, void (*print)(void*)){	
	node** current_root = &(my_list->head);
	node** current_node;
	while (*current_root != NULL) {
		current_node = current_root;
		while (*current_node != NULL) {
			print((*current_node)->object);
			current_node = &((*current_node)->next);
		}
		current_root = &((*current_root)->prev);
	}
	printf("\n");
}

//inserisce un nuovo nodo nell'albero se non esiste
node** tree_insert(list *my_list, int (*compare)(void* ,void* ), void* new_object){
	if (my_list->head == NULL || my_list->tail == NULL) {
		return NULL;
	}
	node** new_node = tree_search(my_list,compare,new_object);
	if ( *new_node == NULL){
		if (!(*new_node =  malloc(sizeof(node)))) {
			return NULL;
		}
		(*new_node)->prev = NULL;
		(*new_node)->next = NULL;
		(*new_node)->object = new_object;
		my_list->tail = *new_node;
		(my_list->size)++;
	}
	return new_node;
}

//costruisce un "Tree" a partire da un array. Usa il metodo insert
list* tree_build(int (*compare)(void* ,void* ), void* new_object_array [], int object_number){
	list *new_list;
	new_list = build_list(new_object_array[0]);
	for (int i = 1; i<object_number; i++) {
		tree_insert(new_list, compare, new_object_array[i]);	
	}
	
	return new_list;
}

//rimuove un nodo da un Tree sostituendolo con il precedente nella relazione d'ordine dei dati
void tree_delete_node_prev(node** current_node, void (*free_object)(void*)){
	node* old_node = *current_node;
	if ((*current_node)->prev == NULL) {
		*current_node = (*current_node)->next;
		free_object(old_node->object);
		free(old_node);
	}else if ((*current_node)->next == NULL) {
		*current_node = (*current_node)->prev;
		free_object(old_node->object);
		free(old_node);
	}else {
		node** orderdata_prev = &((*current_node)->prev);
		while ((*orderdata_prev)->next != NULL) {
			orderdata_prev = &((*orderdata_prev)->next);
		}
		
		void* temp = (*orderdata_prev)->object;
		(*orderdata_prev)->object = (*current_node)->object;
		(*current_node)->object = temp;
		
		tree_delete_node_prev(orderdata_prev,free_object);
	}
	return;
}

//rimuove un nodo da un Tree "sostituendolo" con il successore nella relazione d'ordine dei dati
void tree_delete_node_next(node** current_node, void (*free_object)(void*)){
	node* old_node = *current_node;
	if ((*current_node)->prev == NULL) {
		*current_node = (*current_node)->next;
		
		free_object(old_node->object);
		free(old_node);
	}else if ((*current_node)->next == NULL) {
		*current_node = (*current_node)->prev;
		free_object(old_node->object);
		free(old_node);
	}else {
		node** orderdata_next = &((*current_node)->next);
		while ((*orderdata_next)->prev != NULL) {
			orderdata_next= &((*orderdata_next)->prev);
		}
		
		void* temp = (*orderdata_next)->object;
		(*orderdata_next)->object = (*current_node)->object;
		(*current_node)->object = temp;
		
		tree_delete_node_next(orderdata_next,free_object);
	}
	return;
}

//rimuove un nodo da un Tree e pone la tail uguale al nodo successivo se esiste o alla primo
void tree_delete(list *my_list, node** current_node, void (*free_object)(void*)){
	if (my_list->head == NULL || my_list->tail == NULL) {
		return;
	}
	tree_delete_node_next(current_node, free_object);
	if ( my_list->tail->next != NULL ){
		my_list->tail = my_list->tail->next;
	}else {
		my_list->tail = my_list->head;
	}
	
	(my_list->size)--;
	
	return;
}






