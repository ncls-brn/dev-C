#include <stdio.h>

typedef struct Person {
    int age;
} Person;

typedef struct Book {
    int pages;
} Book;


int are_persons_equals(Person *p1, Person *p2) {
    return p1->age == p2->age;
}


int are_books_equals(Book *b1, Book *b2) {
    return b1->pages == b2->pages;
}


int are_equals(void *obj1, void *obj2, int (*compare_fnc)(void *, void *)) {
    return compare_fnc(obj1, obj2);
}

int main() {
    Person person1 = {30};
    Person person2 = {50};

    Book book1 = {300};
    Book book2 = {200};

  
    if (are_equals(&person1, &person2, (int (*)(void *, void *))are_persons_equals)) {
        printf("Les deux personnes ont le même âge.\n");
    } else {
        printf("Les deux personnes n'ont pas le même âge.\n");
    }

   
    if (are_equals(&book1, &book2, (int (*)(void *, void *))are_books_equals)) {
        printf("Les deux livres ont le même nombre de pages.\n");
    } else {
        printf("Les deux livres n'ont pas le même nombre de pages.\n");
    }

    return 0;
}
