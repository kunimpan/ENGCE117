#include <stdio.h>

struct opaspun {
    int age;
    int height;
    int weight;
};

int main() {
    struct opaspun body;
    body.age = 20;
    body.height = 170;
    body.weight = 58;
    printf("Oaspun age : %d year\n", body.age );
    printf("Oaspun height : %d cm\n", body.height );
    printf("Oaspun weight : %d kg\n", body.weight );
    return 0;
}