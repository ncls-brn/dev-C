#include <iostream>

typedef struct Person {
  int age;
}Person;

int main(){
  char c ='z';
  char *p = &c;
  char&r=c;
  
  Person person = {};
  Person &p2 = person;
  person.age = 10;
  std::cout<<p2.age << std::endl;

  p2.age =14; 
  std::cout << person.age << std::endl;

  Person *p3 =&person;
  p3->age = 900;
  p3 =0;
  std::cout << person.age << std::endl;


  return 0;

};