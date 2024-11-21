#include <stdio.h>
#include <string.h>

struct Person{
    int age ;
    char name[5];
    char* lastname;

};


int main(){
    struct Person toto;
    toto.age =33;
    toto.lastname = "titi";
    strcpy(toto.name, "toto");

    struct Person* toto_add =&toto;

    printf("age of person is: %d\n",toto.age);
    printf("name is: %s\n", toto.name);
    printf("lastname is: %s\n",toto.lastname);
    printf(" the name is %s, the lastname is %s and he's %d years old.\n", toto.name, toto.lastname, toto.age);
    printf("l'adresse est: %p\n",toto_add );
    return 0;
};