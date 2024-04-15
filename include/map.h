#ifndef MAP_H
#define MAP_H

typedef struct Entry {
    char *key;
    void *value;
    struct Entry *next;
} Entry;

typedef struct Map {
    Entry *table[100];
} Map;

unsigned int hash(const char *key);
Map* create_map();
void insert_map(Map *map, char *key, void *value);
void* lookup_map(Map *map, char *key);
void free_map(Map *map);

#endif /* MAP_H */
