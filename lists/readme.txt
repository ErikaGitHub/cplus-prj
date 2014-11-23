#comandi per l'esecuzione
Gli eseguibili sono stati generati e debuggati usando i seguenti tool:
gcc 4.2.1
gdb 6.3
make 3.81

Per generare l'eseguibile e' necessario seguire i seguenti passi:

tar -xzf c_test.tar.gz
cd c_test
make

Per eseguire il programma che simula la soluzione del test e' necessario lanciare il comando:
./main

Per generare un eseguibile da debuggare con gdb o con un livello di log superiore occorre lanciare invece il comando (assicurarsi di aver prima lanciato mak˜ clean):
make debug 

Per debuggare occorre lanciare il comando:

gdb main

Per il debug sono state usate le usuali tecniche basate o sulla definizione di diversi livelli di log tramite "preprocessor directives" o sull'uso di un debugger quale gdb. Sono stati solo illustrati i principi senza dettagliare eccessivamente.

E' possibile modificare il livello di log cambiando il valore della variabile DEBUG nel Makefile.

#note sull'architettura
Ho inteso come "lista di componenti da tenere ordinata per prioritˆ'" una lista di nodi "linkati" organizzata con una logica FIFO o LIFO. 
Pur non avendo usato il c++ ho costruito la soluzione del test riflettendo su una gerarchia fra le collezioni di nodi al fine di isolare i punti sui quali concentrare gli "sforzi" implementativi. L'intero disegno e' fondato sulla "definizione" seguente:

"List e' una qualsiasi collezione di nodi che implementa un metodo per la creazione, uno per la distruzione, uno per la ricerca, uno per l'inserimento di nuovi nodi e uno per la rimozione (interfaccia)"

Le classiche liste organizzate secondo le prioritˆ' LIFO o FIFO (i.e. Queue)  e gli alberi binari ordinati (i.e. Tree) si possono cos“' considerare come delle particolari List.
L'"interfaccia" e' definita nel file list.h e la relativa implementazione nel rispettivo list.c.

La List e' stata implementata come una struttura contenente un puntatore al primo nodo inserito ("head") e un puntatore all'ultimo inserito ("tail").
Nell'esempio elaborato sono stati realizzati casi in cui la "tail" coincide con la "componente corrente" e casi in cui i 2 elementi sono distinti dal momento che non era chiaro dal testo quale fosse l'intenzione.
Ho preferito gestire la componente corrente nel main e non introdurre un ulteriore campo nella List anche se resta aperta questa eventualitˆ' che eviterei.


