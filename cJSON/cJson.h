#pragma once

#ifndef _CJSON_H_
#define _CJSON_H_

#define cJSON_False		0
#define cJSON_True		1
#define cJSON_NULL		2
#define cJSON_Number	3
#define cJSON_String	4
#define cJSON_Array		5
#define cJSON_Object	6

#define cJSON_AddFalseToObject(object, name) \
	cJSON_AddItemToObject(object, name, cJSON_CreateFalse())

#define cJSON_AddTrueToObject(object,name) \
	cJSON_AddItemToObject(object, name, cJSON_CreateTrue())

#define cJSON_AddBoolToObject(object,name, b) \
	cJSON_AddItemToObject(object, name, cJSON_CreateBool(b))

#define cJSON_AddNULLToObject(object,name) \
	cJSON_AddItemToObject(object, name, cJSON_CreateNull())

#define cJSON_AddNumberToObject(object, name, number) \
	cJSON_AddItemToObject(object, name, cJSON_CreateNumber(number))

#define cJSON_AddStringToObject(object, name, s) \
	cJSON_AddItemToObject(object, name, cJSON_CreateString(s))

#define cJSON_SetIntValue(object, val)\
	((object)?((object)->valueInt=(object)->valueDouble=(val)):(val))

#define cJSON_SetNumberValue(object, val)\
	((object)?((object)->valueInt=(object)->valueDouble=(val)):(val))

typedef struct cJSON {
	struct cJSON *next, *prev;
	struct cJSON *child;

	int type;

	char *valueString;
	int valueInt;
	double valueDouble;

	char *string;
}cJSON;



cJSON *cJSON_Parse(const char *value);

char *cJSON_Print(cJSON *item);

void cJSON_Delete(cJSON *c);

cJSON *cJSON_CreateObject(void);

cJSON *cJSON_CreateString(const char *string);

cJSON *cJSON_CreateNumber(double num);

cJSON *cJSON_CreateArray(void);

cJSON *cJSON_CreateBool(int b);

cJSON *cJSON_CreateTrue(void);

cJSON *cJSON_CreateFalse(void);

cJSON *cJSON_CreateNull(void);


void cJSON_AddItemToObject(cJSON *object, const char *string, cJSON *item);


void cJSON_AddItemToArray(cJSON *array, cJSON *item);


cJSON *cJSON_ParseWithOpts(const char *value, const char **return_parse_end, int require_null_terminated);

cJSON *cJSON_New_Item();

const char *skip(const char *in);
char *cJSON_GetEndPosition();

const char *parse_value(cJSON *item, const char *value);

const char* parse_string(cJSON *item, const char *str);
const char* parse_number(cJSON *item, const char *num);
const char* parse_Array(cJSON *item, const char *value);
const char* parse_Object(cJSON *item, const char *value);

char *cJSON_strdup(const char *str);
char *print_number(cJSON *item);
char *print_string(cJSON *item, int isName);

char *print_array(cJSON *item, int depth, int fmt);
char *print_object(cJSON *item, int depth, int fmt);
char *print_value(cJSON *item,int depth, int fmt);

cJSON *cJSON_DetachItemFromArray(cJSON *array, int which);
void cJSON_DeleteItemFromArray(cJSON *array, int which);

int cJSON_strcasecmp(const char *s1, const char *s2); //strcmp()

cJSON *cJSON_DetachItemFromObject(cJSON *object, const char *string);
void cJSON_DeleteItemFromObject(cJSON *object, int which);

void cJSON_InsertItemInArray(cJSON *array, int which, cJSON *newItem);

void cJSON_ReplaceItemInArray(cJSON *array, int which, cJSON *newItem);
void cJSON_ReplaceItemInObject(cJSON *object, const char *string, cJSON *newItem);

#endif 
