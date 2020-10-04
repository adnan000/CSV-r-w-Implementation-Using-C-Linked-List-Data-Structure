# CSV-r-w-Implementation-Using-C-Linked-List-Data-Structure
This program could be used as a open library to read or write csv files. It uses C with implementation of Linked List as data structrue

Here will be listed all function uses for the programs.

createDoubleList
Syntax :  createDoubleList(double_linked_list_t **ppList)
Function : initiate double linked list with one head, one tail, and NULL initial value

deleteDoubleList
Syntax :  deleteDoubleList(double_linked_list_t **ppList)
Function : remove linked list by setting all pointer to NULL

addFrontDoubleList
Syntax : addFrontDoubleList(double_linked_list_t **ppList
Function : push data to top of list (head)

addBackDoubleList
Syntax :  addBackDoubleList(double_linked_list_t **ppList)
Function : push data to bottom of list (tail)

removeFrontDoubleList
Syntax : removeFrontDoubleList(double_linked_list_t **ppList
Function : pop data from top of list (head)

removeBackDoubleList
Syntax : removeBackDoubleList(double_linked_list_t *ppList)
Function : pop data from bottom of list (tail)

printDoubleList 
Syntax : printDoubleList(double_linked_list_t *ppList)
Function : print double linked list data to terminal

isListNotEmpty 
Syntax :  isListNotEmpty(double_linked_list_t *ppList)
Function : check whether list empty or not. Return 0 with NULL and 1 if not NULL
