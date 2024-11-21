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
    toto.lastname = "frfr";
    strcpy(toto.name, "toto");

    struct Person* toto_add =&toto;


    struct Person titi;
    titi.age = 25;
    titi.lastname = "titi";
    strcpy(titi.name, "titi");


    for( int i= 0; i<12; i++){
        printf("%c ", toto.name[i]);
    }

     for( int i= 0; i<12; i++){
        printf("%c ", titi.name[i]);
    }

    printf("\n");


    printf("age of person is: %d\n",toto.age);
    printf("name is: %s\n", toto.name);
    printf("lastname is: %s\n",toto.lastname);
    printf(" the name is %s, the lastname is %s and he's %d years old.\n", toto.name, toto.lastname, toto.age);
    printf("l'adresse est: %p\n",toto_add );
    printf("--------------------------");
    printf("age of person is: %d\n",titi.age);
    printf("name is: %s\n", titi.name);
    printf("lastname is: %s\n",titi.lastname);
    printf(" the name is %s, the lastname is %s and he's %d years old.\n", titi.name, titi.lastname, titi.age);

    return 0;
};