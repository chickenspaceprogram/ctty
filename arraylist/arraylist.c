#include "arraylist.h"

#define INITIAL_SIZE 16
#define GROWTH_FACTOR 2

// keeping fields private
typedef struct al_data {
    void *elements;
    size_t len;
    size_t array_size;
    size_t element_size;
};

// "public" methods
static void *get(ArrayList *this, size_t index);
static ArrayList *push(ArrayList *this, void *element);
static ArrayList *set(ArrayList *this, size_t index, void *element);
static ArrayList *pop(ArrayList *this);
static ArrayList *clear(ArrayList *this);
static void free_list(ArrayList *this);
static size_t len(ArrayList *this);

// "private" methods
static void *double_size(void *elements, size_t num_elements, size_t element_size);

ArrayList *newArrayList(size_t element_size) {
    ArrayList *new = malloc(sizeof(ArrayList));

    if (new == NULL) {
        return NULL;
    }

    new->data.elements = malloc(INITIAL_SIZE * new->data.element_size);

    if (new->data.elements == NULL) {
        return NULL;
    }

    new->data.len = 0;
    new->data.array_size = INITIAL_SIZE;
    new->data.element_size = element_size;

    new->get = &get;
    new->push = &push;
    new->set = &set;
    new->pop = &pop;
    new->clear = &clear;
    new->free = &free_list;
}

void *get(ArrayList *this, size_t index) {

    if (index >= this->data.array_size || index < 0) {
        return NULL;
    }

    return this->data.elements + this->data.element_size * index;
}

ArrayList *push(ArrayList *this, void *element) {
    // cursed pointer arithmetic
    memcpy(this->data.elements + this->data.element_size * this->data.len, element, this->data.element_size);
    ++(this->data.len);
    if (this->data.len == this->data.array_size) {
        this->data.elements = double_size(this->data.elements, this->data.len, this->data.element_size);

        if (this->data.elements == NULL) {
            free(this); // freeing ArrayList because we couldn't allocate new elements
            return NULL;
        }

        this->data.array_size *= GROWTH_FACTOR;
        return this;
    }
}

ArrayList *set(ArrayList *this, size_t index, void *element) {
    if (index >= this->data.len || index < 0) {
        return NULL;
    }
    memcpy(this->data.elements + this->data.element_size * index, element, this->data.element_size);
}

ArrayList *pop(ArrayList *this) {
    if (this->data.len == 0) {
        return NULL;
    }
    --this->data.len;
    return this;
}

ArrayList *clear(ArrayList *this) {
    this->data.len = 0;
    this->data.array_size = INITIAL_SIZE;
    this->data.elements = realloc(this->data.elements, this->data.array_size * this->data.element_size);
    if (this->data.elements == NULL) {
        free(this); // freeing ArrayList because we couldn't allocate new space
        return NULL;
    }
}

void free_list(ArrayList *this) {
    free_list(this->data.elements);
    free_list(this);
}

/* Private Functions */
static void *double_size(void *elements, size_t num_elements, size_t element_size) {
    // if realloc returns null, we return that. if it moves the array, we return the address of the moved array
    return realloc(elements, num_elements * element_size * GROWTH_FACTOR);
}

