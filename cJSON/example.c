#include <stdio.h>
#include "cJSON.h"

int main(void)
{
	cJSON *root = cJSON_CreateObject();
	cJSON *node1 = cJSON_CreateObject();
	cJSON *node2 = cJSON_CreateObject();
	cJSON *node3 = cJSON_CreateObject();
	cJSON *node4 = cJSON_CreateObject();

	cJSON_AddItemToObject(root, "root_node1", node1);
	cJSON_AddFalseToObject(node1, "node1_key1");
	cJSON_AddTrueToObject(node1, "node1_key2");
	cJSON_AddItemToObject(node1, "node1_node3", node3);
	cJSON_AddNumberToObject(node3, "node3_key1", 123);
	cJSON_AddNumberToObject(node3, "node3_key2", 456);
	cJSON_AddNumberToObject(node3, "node3_key3", 789);

	cJSON_AddItemToObject(root, "root_node2", node2);
	cJSON_AddStringToObject(node2, "node2_key1", "node2_value1");
	cJSON_AddStringToObject(node2, "node2_key2", "node2_value2");

	cJSON_AddItemToObject(root, "root_node4", node4);
	cJSON_AddStringToObject(node4, "node4_key1", "node4_value1");
	cJSON_AddStringToObject(node4, "node4_key2", "node4_value2");


	


	char *buf = cJSON_Print(root);
	printf("json:\n%s\n", buf);

	cJSON *parse_node = cJSON_Parse(buf);

	cJSON_Delete(root);
	cJSON_Delete(parse_node);
	free(buf);
	return 0;
}

