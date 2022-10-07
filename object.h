#pragma once

#include "common.h"
#include "value.h"

#define OBJ_TYPE(value) (AS_OBJ(value)->type)
#define IS_STRING(value) isObjType(value, OBJ_STRING)

#define AS_STRING(value) ((ObjString*)AS_OBJ(value))            // struct ObjString
#define AS_CSTRING(value) (((ObjString*)AS_OBJ(value))->chars)  // array of characters

typedef enum ObjType {
    OBJ_STRING,
} ObjType;

// Base object
struct Obj {
    ObjType type;
    struct Obj* next;
};

struct ObjString {
    Obj obj;  // base struct/type punning ( must be first member in order for it to work)
    int length;
    char* chars;
};

ObjString* takeString(char* chars, int length);
ObjString* copyString(const char* chars, int length);
void printObject(Value value);

static inline bool isObjType(Value value, ObjType type) {
    return IS_OBJ(value) && AS_OBJ(value)->type == type;
}