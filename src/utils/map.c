#include "map.h"


int keys[MAP_SIZE] = {0};
int values[MAP_SIZE] = {0};
int elements = 0;

int hash(int n){
    return (n % MAP_SIZE) & 0x7fffffff;
}

int put_map(int key, int value){
    if(elements == MAP_SIZE){
        return 0;
    }
    int index, iterations = 0;
    index = hash(key);
    key++; 
    while(keys[index] != 0 && keys[index] != key && iterations < elements){
        index += 2;
        index %= MAP_SIZE;
        iterations++;
    }

    if(keys[index] == key) return -1;

    keys[index] = key;
    values[index] = value;
    elements++;
    return 1;
}

int get_map(int key){
    int index, iterations = 0;
    index = hash(key);

    key++; 
    while(keys[index] != 0 && keys[index] != key && iterations < elements){
        index += 2;
        index %= MAP_SIZE;
        iterations++;
    }
    return keys[index] == key ? values[index] : -1;
}

int remove_map(int key){
    int index, iterations = 0;
    index = hash(key);
    int value = -1;
    key++;

    while(keys[index] != 0 && keys[index] != key && iterations < elements){
        index += 2;
        index %= MAP_SIZE;
        iterations++;
    }

    if(keys[index] == key){
        value = values[index];
        values[index] = 0;
        keys[index] = 0;
    }

    return value;
}

int contains_map(int key){
    return get_map(key) != -1;
}