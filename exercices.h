#include <stdio.h>
#include <string.h>


typedef struct {
    int age;
} Person;

typedef struct {
    int price;
} Book;

int are_persons_equals(void *a, void *b) {
    Person *p1 = (Person *)a;
    Person *p2 = (Person *)b;
    return p1->age == p2->age;
}

int are_books_equals(void *a, void *b) {
    Book *b1 = (Book *)a;
    Book *b2 = (Book *)b;
    return b1->price == b2->price;
}

int is_in_array(void *key, void *array, size_t array_size, size_t element_size,
                int (*compare)(void *, void *)) {
    for (size_t i = 0; i < array_size; i++) {
        void *element = (char *)array + i * element_size;
        if (compare(key, element)) {
            return 1;  // Trouvé
        }
    }
    return 0; 
}

void swap(void *a, void *b, size_t size) {
    char temp[size];
    memcpy(temp, a, size);
    memcpy(a, b, size);
    memcpy(b, temp, size);
}

void sort(void *array, size_t array_size, size_t element_size,
          int (*compare)(void *, void *), void (*swap_fn)(void *, void *, size_t)) {
    for (size_t i = 0; i < array_size - 1; i++) {
        for (size_t j = i + 1; j < array_size; j++) {
            void *elem1 = (char *)array + i * element_size;
            void *elem2 = (char *)array + j * element_size;
            if (compare(elem1, elem2) > 0) {
                swap_fn(elem1, elem2, element_size);
            }
        }
    }
}

int is_greater(void *a, void *b) {
    Person *p1 = (Person *)a;
    Person *p2 = (Person *)b;
    return p1->age - p2->age;
}

void eq_function() {
    Person person1 = {50};
    Person person2 = {50};
    int same_age = are_persons_equals(
        &person1, &person2
    );
    if (same_age == 1) {
        printf("Same age.\n");
    } else {
        printf("Different age.\n");
    }
}

void linear_search() {
    Person person1 = {50};
    Person people[] = {{20}, {50}};
    int found = is_in_array(
        &person1, people,
        sizeof(people) / sizeof(Person), sizeof(Person),
        are_persons_equals
    );
    if (found == 1) {
        printf("Person1 is in the array.\n");
    } else {
        printf("Person1 is not in the array.\n");
    }

    Book book1 = {50};
    Book books[] = {{20}, {50}};
    found = is_in_array(
        &book1, books,
        sizeof(books) / sizeof(Book), sizeof(Book),
        are_books_equals
    );
    if (found == 1) {
        printf("Book1 is in the array.\n");
    } else {
        printf("Book1 is not in the array.\n");
    }
}

void generic_swap() {
    Person person1 = {50};
    Person person2 = {25};
    swap(&person1, &person2, sizeof(Person));

    Book b1 = {50};
    Book b2 = {25};
    swap(&b1, &b2, sizeof(Book));
}




int main() {
    eq_function();
    linear_search();
    generic_swap();

    Person people[] = {{20}, {50}, {188}, {2}};
    sort(
        people,
        sizeof(people) / sizeof(Person),
        sizeof(Person),
        is_greater,
        swap
    );
    for (int i = 0; i < 4; i++) {
        printf("Person %d: %d years old\n", i + 1, people[i].age);
    }

    return 0;
}
