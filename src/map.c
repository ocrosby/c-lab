#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 100

typedef struct Entry {
    char *key;
    void *value;
    struct Entry *next;
} Entry;

// The Map structure contains an array of pointers to Entries.
typedef struct Map {
    Entry *table[TABLE_SIZE];
} Map;

// The hash function takes a string key and returns an index in the range [0, TABLE_SIZE).
unsigned int hash(const char *key) {
    unsigned int hash = 0;
    while (*key) {
        hash = (hash << 5) - hash + *key++;
    }
    return hash % TABLE_SIZE;
}

// The create_map function allocates memory for a new Map and initializes all linked lists to NULL.
Map* create_map() {
    Map *map = (Map*)malloc(sizeof(Map));
    memset(map, 0, sizeof(Map));
    return map;
}

// The insert_map function creates a new Node with the given key and value and inserts it into the appropriate linked list in the Map.
void insert_map(Map *map, char *key, void *value) {
    unsigned int idx = hash(key);
    Entry *entry = (Entry*)malloc(sizeof(Entry));
    entry->key = strdup(key);
    entry->value = value;
    entry->next = map->table[idx];
    map->table[idx] = entry;
}

// The lookup_map function searches the appropriate LinkedList in the Map for a Node with the given key and returns its value.
void* lookup_map(Map *map, char *key) {
    unsigned int idx = hash(key);
    for (Entry *entry = map->table[idx]; entry != NULL; entry = entry->next) {
        if (strcmp(entry->key, key) == 0) {
            return entry->value;
        }
    }
    return NULL;
}

// The free_map function frees all memory allocated for the Map, including the LinkedLists and Nodes it contains.
void free_map(Map *map) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Entry *entry = map->table[i];
        while (entry != NULL) {
            Entry *next = entry->next;
            free(entry->key);
            free(entry);
            entry = next;
        }
    }
    free(map);
}
