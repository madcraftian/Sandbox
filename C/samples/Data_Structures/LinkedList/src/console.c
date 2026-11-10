#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "List.h"

typedef struct Entity_ {
	char name[255];
	int health;
	int speed;
} Entity;

void insert_entity(List *list) {
	Entity *tmp = NULL;
	tmp = (Entity*)malloc(sizeof(Entity));
	list_ins_next(list, NULL, (void*) tmp); 
	tmp = NULL;
}

void destroy_entity(void* data) {
	free(data);
	data = NULL;
}

int main(int arc, char* argv[])
{
	List entityList;
	memset(&entityList, 0, sizeof(List));
	list_init(&entityList, destroy_entity);
	insert_entity(&entityList);
	insert_entity(&entityList);
	list_destroy(&entityList);
	return EXIT_SUCCESS;
}
