#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashtable.h" // Assuming hashtable.h is in the same directory.

// Hash table to store the aliases.
Hashtable *aliases;

// Function to add an alias to the hash table.
void add_alias(char *name, char *value) {
    // Create a new hash entry.
    HashEntry *entry = malloc(sizeof(HashEntry));
    entry->key = name;
    entry->value = value;

    // Add the hash entry to the hash table.
    hashtable_put(aliases, entry);
}

// Function to get the value of an alias from the hash table.
char *get_alias(char *name) {
    // Get the hash entry for the alias.
    HashEntry *entry = hashtable_get(aliases, name);

    // If the hash entry does not exist, return NULL.
    if (entry == NULL) {
        return NULL;
    }

    // Return the value of the alias.
    return entry->value;
}

// Function to print all of the aliases in the hash table.
void print_aliases() {
    // Iterate over the hash table and print each alias.
    HashIterator *iterator = hashtable_iterator(aliases);
    while (hash_iterator_has_next(iterator)) {
        HashEntry *entry = hash_iterator_next(iterator);
        printf("%s='%s'\n", entry->key, entry->value);
    }

    // Free the hash iterator.
    hash_iterator_free(iterator);
}

int main(int argc, char *argv[]) {
    // Initialize the hash table.
    aliases = hashtable_init(128);

    // If the user specified any aliases, add them to the hash table.
    for (int i = 1; i < argc; i++) {
        char *alias = argv[i];
        char *name = strtok(alias, "=");
        char *value = strtok(NULL, "=");

        if (name != NULL && value != NULL) {
            add_alias(name, value);
        }
    }

    // If the user did not specify any aliases, print all of the aliases in the hash table.
    if (argc == 1) {
        print_aliases();
    }

    // Free the hash table.
    hashtable_free(aliases);

    return 0;
}
