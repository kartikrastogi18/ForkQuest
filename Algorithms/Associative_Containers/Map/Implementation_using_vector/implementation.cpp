#include <stdio.h>

#define MAX 100

typedef struct {
    int arr[MAX];
    int size;
} OrderedSet;

// Initialize
void initSet(OrderedSet *set) {
    set->size = 0;
}

// Insert (keeps sorted & avoids duplicates)
void insert(OrderedSet *set, int value) {
    int i, j;

    // Check duplicate
    for (i = 0; i < set->size; i++)
        if (set->arr[i] == value)
            return;

    // Find position to insert
    for (i = 0; i < set->size && set->arr[i] < value; i++);

    // Shift elements right
    for (j = set->size; j > i; j--)
        set->arr[j] = set->arr[j - 1];

    // Insert value
    set->arr[i] = value;
    set->size++;
}

// Print set
void printSet(OrderedSet *set) {
    int i;
    printf("{ ");
    for (i = 0; i < set->size; i++)
        printf("%d ", set->arr[i]);
    printf("}\n");
}

// Remove an element
void removeElement(OrderedSet *set, int value) {
    int i, j;
    for (i = 0; i < set->size; i++) {
        if (set->arr[i] == value) {
            for (j = i; j < set->size - 1; j++)
                set->arr[j] = set->arr[j + 1];
            set->size--;
            return;
        }
    }
}

// Check if value exists
int contains(OrderedSet *set, int value) {
    int i;
    for (i = 0; i < set->size; i++)
        if (set->arr[i] == value)
            return 1;
    return 0;
}

// Example
int main() {
    OrderedSet set;
    initSet(&set);

    insert(&set, 5);
    insert(&set, 3);
    insert(&set, 8);
    insert(&set, 3); // Duplicate ignored
    insert(&set, 1);

    printSet(&set);

    printf("Contains 3? %s\n", contains(&set, 3) ? "Yes" : "No");

    removeElement(&set, 3);
    printSet(&set);

    return 0;
}