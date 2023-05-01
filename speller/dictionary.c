// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <cs50.h>
#include <ctype.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;
unsigned int word_count = 0;
// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // Obtener el índice de la tabla hash para la palabra
    int index = hash(word);

    // Puntero a la lista enlazada correspondiente al bucket de la tabla hash
    node *cursor = table[index];

    // Recorre la lista enlazada buscando la palabra
    while (cursor != NULL)
    {
        // Si la palabra está presente en la lista enlazada, devuelve true
        if (strcasecmp(cursor->word, word) == 0)
        {
            return true;
        }

        // Avanza al siguiente nodo en la lista enlazada
        cursor = cursor->next;
    }

    // Si la palabra no se encontró en la lista enlazada, devuelve false
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // Inicializar el valor hash
    unsigned int hash = 0;

    // Recorrer cada caracter en la palabra
    for (int i = 0; word[i] != '\0'; i++)
    {
        char c = tolower(word[i]);
        // Actualizar el valor hash utilizando la función de hash de Bob Jenkins
        hash += c;
        hash += (hash << 10);
        hash ^= (hash >> 6);
    }

    // Realizar una operación final sobre el valor hash para asegurarse de que está dentro del rango de la tabla hash
    hash += (hash << 3);
    hash ^= (hash >> 11);
    hash += (hash << 15);

    return hash % N;
}
// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // Abrir el archivo del diccionario
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }

    // Inicializar la tabla hash
    for (int i = 0; i < N; i++)
    {
        table[i] = NULL;
    }

    // Leer cada palabra del archivo del diccionario
    char word[LENGTH + 1];
    while (fscanf(file, "%s", word) != EOF)
    {
        // Crear un nuevo nodo para la palabra
        node *new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            fclose(file);
            return false;
        }

        // Copiar la palabra en el nodo
        strcpy(new_node->word, word);

        // Calcular el índice de la tabla hash para la palabra
        int index = hash(word);

        // Insertar el nodo al principio de la lista enlazada correspondiente al bucket de la tabla hash
        new_node->next = table[index];
        table[index] = new_node;

        // Incrementar el contador de palabras
        word_count++;
    }

    // Cerrar el archivo del diccionario
    fclose(file);

    // Devolver true si se cargaron las palabras correctamente
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // word_count es una variable global que lleva el conteo de las palabras
    if (word_count > 0)
    {
        return word_count;
    }
    else
    {
        return 0;
    }
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        // Puntero a la lista enlazada del índice actual
        node *cursor = table[i];

        // Recorre la lista enlazada liberando la memoria de cada nodo
        while (cursor != NULL)
        {
            node *temp = cursor;
            cursor = cursor->next;
            free(temp);
        }
    }

    return true;
}
