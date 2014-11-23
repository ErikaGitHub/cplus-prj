/*file contenente un esempio che riproduce le richieste del test*/
#include<stdio.h>

#include "list.h"

int main(){
	int NCOMPONENTMAX = 10;
	int NSUBCOMPONENTMAX = 5;

//lista delle componenti
	list* c_list;
//componente corrente
	node* current_component;
//array delle sottocomponenti correnti
	node* current_subcomponent_array[NCOMPONENTMAX];
	
//la precedente della componente corrente
	node* current_component_precedent;
//la lista delle sottocomponenti della precedente della componente corrente
	list* current_component_precedent_sublist;
	
//array delle liste delle sottocomponenti	
	list* s_list_array[NCOMPONENTMAX];

//costruzione della lista delle sottocomponenti della prima componente oranizzate in un "Tree" di oggetti "integer"
	s_list_array[0] = build_test_tree();
	
#if LOG_LEVEL  >= 1
	printf("tree_print \n");
	tree_print(s_list_array[0],print_integer);
	printf("tail \n");
	print_integer((integer *)((s_list_array[0]->tail)->object));
	printf("size %d \n",s_list_array[0]->size);
	printf("tree_print \n");
#endif
	
	int main_int_array[NSUBCOMPONENTMAX];
	main_int_array[0] = 2;
	main_int_array[1] = 7;
	main_int_array[2] = 6;
	main_int_array[3] = 8;
	main_int_array[4] = 9;
	
	void* main_integer_array[NSUBCOMPONENTMAX];
	for (int i=0; i<NSUBCOMPONENTMAX; i++) {
		main_integer_array[i] = build_integer(main_int_array[i]);
	}
//costruzione della lista delle sottocomponenti della seconda componente organizzate in una "Queue"	di oggetti "integer"
	s_list_array[1] = queue_build(main_integer_array, NSUBCOMPONENTMAX);

#if LOG_LEVEL  >= 1
	printf("queue_print \n");
	queue_print(s_list_array[1],print_integer);
	printf("tail \n");
	print_integer((integer *)((s_list_array[1]->tail)->object));
	printf("size %d \n",s_list_array[1]->size);
	printf("queue_print \n");
#endif
	
	main_int_array[0] = 10;
	main_int_array[1] = 7;
	main_int_array[2] = 9;
	main_int_array[3] = 6;
	main_int_array[4] = 11;
	
	for (int i=0; i<NSUBCOMPONENTMAX; i++) {
		main_integer_array[i] = build_integer(main_int_array[i]);
	}
	
//costruzione della lista delle sottocomponenti della terza componente organizzate in un "Tree"	di oggetti "integer"	
	s_list_array[2] = tree_build(compare_integer,main_integer_array, NSUBCOMPONENTMAX);
	
#if LOG_LEVEL  >= 1
	printf("tree_print \n");
	tree_print(s_list_array[2],print_integer);
	printf("tail \n");
	print_integer((integer *)((s_list_array[2]->tail)->object));
	printf("size %d \n",s_list_array[2]->size);
	printf("tree_print \n");
#endif
	
	main_int_array[0] = 6;
	main_int_array[1] = 4;
	main_int_array[2] = 3;
	main_int_array[3] = 5;
	main_int_array[4] = 7;
	
	for (int i=0; i<NSUBCOMPONENTMAX; i++) {
		main_integer_array[i] = build_integer(main_int_array[i]);
	}
	
//costruzione della lista delle sottocomponenti della quarta componente organizzate in un "Tree" di oggetti "integer"
	s_list_array[3] = tree_build(compare_integer, main_integer_array, NSUBCOMPONENTMAX);

#if LOG_LEVEL  >= 1
	printf("tree_print \n");
	tree_print(s_list_array[3],print_integer);
	printf("tail \n");
	print_integer((integer *)((s_list_array[3]->tail)->object));
	printf("size %d \n",s_list_array[3]->size);
	printf("tree_print \n");
#endif
	
	char* main_cstring_array[NSUBCOMPONENTMAX];
	void* main_string_array[NSUBCOMPONENTMAX];
	
	main_cstring_array[0] = "libro";
	main_cstring_array[1] = "tavolo";
	main_cstring_array[2] = "quadro";
	main_cstring_array[3] = "statua";
	main_cstring_array[4] = "casa";
	
	for (int i=0; i<NSUBCOMPONENTMAX; i++) {
		main_string_array[i] = build_string(main_cstring_array[i]);
	}

//costruzione della lista delle sottocomponenti della quinta componente organizzate in una "Queue" di oggetti "string"	
	s_list_array[4] = queue_build(main_string_array, NSUBCOMPONENTMAX);

#if LOG_LEVEL  >= 1
	printf("tree_print \n");
	queue_print(s_list_array[4],print_string);
	printf("tail \n");
	print_string((string *)((s_list_array[4]->tail)->object));
	printf("size %d \n",s_list_array[4]->size);
	printf("tree_print \n");
#endif
	
	main_cstring_array[0] = "matita";
	main_cstring_array[1] = "foca";
	main_cstring_array[2] = "dado";
	main_cstring_array[3] = "gatto";
	main_cstring_array[4] = "orso";
	
	for (int i=0; i<NSUBCOMPONENTMAX; i++) {
		main_string_array[i] = build_string(main_cstring_array[i]);
	}

	s_list_array[5] = tree_build(compare_string, main_string_array, NSUBCOMPONENTMAX);

#if LOG_LEVEL  >= 1
	printf("tree_print \n");
	tree_print(s_list_array[5],print_string);
	printf("tail \n");
	print_string((string *)((s_list_array[5]->tail)->object));
	printf("size %d \n",s_list_array[5]->size);
	printf("tree_print \n");
#endif
	
	main_cstring_array[0] = "pippo";
	main_cstring_array[1] = "pluto";
	main_cstring_array[2] = "cesare";
	main_cstring_array[3] = "abelardo";
	main_cstring_array[4] = "dante";
	
	for (int i=0; i<NSUBCOMPONENTMAX; i++) {
		main_string_array[i] = build_string(main_cstring_array[i]);
	}
	
	//costruzione della lista delle sottocomponenti della sesta componente organizzate in un "Tree" di oggetti "string"	
	s_list_array[6] = tree_build(compare_string, main_string_array, NSUBCOMPONENTMAX);

#if LOG_LEVEL  >= 1
	printf("tree_print \n");
	tree_print(s_list_array[6],print_string);
	printf("tail \n");
	print_string((string *)((s_list_array[6]->tail)->object));
	printf("size %d \n",s_list_array[6]->size);
	printf("tree_print \n");
#endif

//popolamento della lista delle componenti organizzante in una "Queue"
	
	c_list = build_list(s_list_array[0]);
	current_component = c_list->tail;
	printf("current component \n");
	tree_print(current_component->object,print_integer);
	current_subcomponent_array[0] = s_list_array[0]->tail;
	printf("current subcomponent \n");
	print_integer(current_subcomponent_array[0]->object);
	printf("\n");
	
	queue_insert(c_list,s_list_array[1]);
	current_component = c_list->tail;
	printf("current component \n");
	tree_print(current_component->object,print_integer);
	current_subcomponent_array[1] = s_list_array[1]->tail;
	printf("current subcomponent \n");
	print_integer(current_subcomponent_array[1]->object);
	printf("\n");
	
	queue_insert(c_list,s_list_array[2]);
	current_component = c_list->tail;
	printf("current component \n");
	tree_print(current_component->object,print_integer);
	current_subcomponent_array[2] = s_list_array[2]->tail;
	printf("current subcomponent \n");
	print_integer(current_subcomponent_array[2]->object);
	printf("\n");
	
	queue_insert(c_list,s_list_array[3]);
	current_component = c_list->tail;
	printf("current component \n");
	tree_print(current_component->object,print_integer);
	current_subcomponent_array[3] = s_list_array[3]->tail;
	printf("current subcomponent \n");
	print_integer(current_subcomponent_array[3]->object);
	printf("\n");
	
//prove di inserimento e rimozione di una sottocomponente di tipo "integer"
	printf("INSERT AND REMOVE START\n\n");
	int k = 2;
	integer* new_integer = build_integer(k);
	tree_insert(s_list_array[3],compare_integer,new_integer);
	printf("inserted %d \n",k);
	current_subcomponent_array[3] = s_list_array[3]->tail;
	printf("new current subcomponent \n");
	print_integer(current_subcomponent_array[3]->object);
	
	node** node_reference;
	k=3;
	new_integer = build_integer(k);
	node_reference = tree_search(s_list_array[3], compare_integer, new_integer);
	tree_delete(s_list_array[3], node_reference, free_integer);
	printf("deleted %d \n",k);
	current_subcomponent_array[3] = s_list_array[3]->tail;
	printf("new current subcomponent \n");
	print_integer(current_subcomponent_array[3]->object);
	
	printf("INSERT AND REMOVE END\n\n");	
	
	queue_insert(c_list,s_list_array[4]);
	current_component = c_list->tail;
	printf("current component \n");
	queue_print(current_component->object,print_string);
	current_subcomponent_array[4] = s_list_array[4]->tail;
	printf("current subcomponent \n");
	print_string(current_subcomponent_array[4]->object);
	printf("\n");
	
	queue_insert(c_list,s_list_array[5]);
	current_component = c_list->tail;
	printf("current component \n");
	tree_print(current_component->object,print_string);
	current_subcomponent_array[5] = s_list_array[5]->tail;
	printf("current subcomponent \n");
	print_string(current_subcomponent_array[5]->object);
	printf("\n");
	
	queue_insert(c_list,s_list_array[6]);
	current_component = c_list->tail;
	printf("current component \n");
	tree_print(current_component->object,print_string);
	current_subcomponent_array[6] = s_list_array[6]->tail;
	printf("current subcomponent \n");
	print_string(current_subcomponent_array[6]->object);
	printf("\n");
	
	//prove di inserimento e rimozione di una sottocomponente di tipo "string"
	printf("INSERT AND REMOVE START \n\n");
	char* test_s = "abate";
	string* new_string = build_string(test_s);
	tree_insert(s_list_array[6],compare_string,new_string);
	printf("inserted %s \n",test_s);
	current_subcomponent_array[6] = s_list_array[6]->tail;
	printf("new current subcomponent \n");
	print_string(current_subcomponent_array[6]->object);
	
	node** string_node_reference;
	test_s="abelardo";
	new_string = build_string(test_s);
	string_node_reference = tree_search(s_list_array[6], compare_string, new_string);
	tree_delete(s_list_array[6], node_reference, free_integer);
	printf("deleted %s \n",test_s);
	current_subcomponent_array[6] = s_list_array[6]->tail;
	printf("new current subcomponent \n");
	print_string(current_subcomponent_array[6]->object);	
	printf("INSERT AND REMOVE END \n\n");	
	
	current_component_precedent = c_list->tail->prev;
	current_component_precedent_sublist = current_component_precedent->object;
	
	printf("current component precedent sublist \n");
	tree_print(current_component_precedent_sublist, print_string);
	
	//per riprodurre una situazione generale supponiamo che l'attuale sottocomponente corrente non coincida con l'ultima componente inserita (i.e. tail), ma coincida con il nodo "foca" 
	char* tmp_s = "foca";
	node** current_subcomponent_reference = tree_search(current_component_precedent_sublist, compare_string ,build_string(tmp_s));
	printf("current subcomponent \n");
	print_string((*current_subcomponent_reference)->object);
	
	//aggiornamento della sottocomponente corrente
	current_component_precedent_sublist->tail = (*current_subcomponent_reference)->prev;
	
	printf("new current subcomponent \n");
	print_string(current_component_precedent_sublist->tail->object); 
		
	return 1;

}

