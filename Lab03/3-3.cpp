#include <stdio.h>
#include <string.h>
struct soldier {
    char name[20];
    int age;
    int kill;
};

struct soldier findKill(struct soldier people[], int count); // prototype

int main() {
    struct soldier people[5];
    strcpy(people[0].name, "pun");
    people[0].age = 21;
    people[0].kill = 59;
    for( int i = 1 ; i < 5 ; i++ ){
        printf("People %d : name, age, kill : ", i);
        scanf("%s %d %d", people[i].name, 
                         &people[i].age, 
                         &people[i].kill);
    } // End loop

    struct soldier mostKill;
    mostKill = findKill( people, 5 );
    printf("Kill the most : %s %d %d", mostKill.name, mostKill.age, mostKill.kill);
    return 0;
}

struct soldier findKill(struct soldier people[], int count) {
    int maxKill, maxI;
    maxKill = people[0].kill;
    maxI = 0;
    for ( int i = 1 ; i < count ; i++ ){
        if ( people[i].kill > maxKill ){
            maxKill = people[i].kill;
            maxI = i;
        }
    } // End loop
    return people[maxI];
}