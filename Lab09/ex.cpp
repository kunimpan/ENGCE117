#include <stdio.h>
#include <stdlib.h>

struct student{
    char name[20];
    char sex;
    int age;
    float gpa;
};

void writeText();
void readText();
void writeBinaryText();
void readBinaryText();
void writeBinaryStructText();
void readBinaryStructText();

int main(){
    // writeText();
    // readText();
    // writeBinaryText();
    // readBinaryText();
    // writeBinaryStructText();
    readBinaryStructText();
    return 0;
}

void writeText(){
    FILE *fp;
    fp = fopen( "D:/FILES_LAB09/student.dat", "w" );
    if( fp == NULL ){
        printf("Can't open file!");
        exit( 0 );
    }

    char name[20], sex;
    int age, i;
    float gpa;
    for( i = 0 ; i < 2 ; i++ ){
        printf( "Enter Name, Sex, Age and GPA : " );
        scanf( "%s %c %d %f", name, &sex, &age, &gpa );
        fprintf( fp, "%s %c %d %f\r\n", name, sex, age, gpa );
    } // end loop

    fclose( fp );
} //end function

void readText(){
    FILE *fp;
    fp = fopen( "D:/FILES_LAB09/student.dat", "r" );
    if( fp == NULL ){
        printf("Can't open file!");
        exit( 0 );
    }

    char name[20], sex;
    int age, i;
    float gpa;
    for( i = 0 ; i < 20 ; i++ ){
        if( fscanf( fp, "%s %c %d %f", name, &sex, &age, &gpa ) == EOF ){
            break;
        }
        printf( "%d: %10s %2c %2d %4.2f\n", i, name, sex, age, gpa );
    } // end loop

    fclose( fp );
} //end function

void writeBinaryText(){
    FILE *fp;
    fp = fopen( "D:/FILES_LAB09/student.dat", "w" );
    if( fp == NULL ){
        printf("Can't open file!");
        exit( 0 );
    }

    char name[20], sex;
    int age, i;
    float gpa;
    for( i = 0 ; i < 2 ; i++ ){
        printf( "Enter Name, Sex, Age and GPA : " );
        scanf( "%s %c %d %f", name, &sex, &age, &gpa );
        fwrite( name, sizeof( char[20] ) , 1, fp );
        fwrite( &sex, sizeof( char ) , 1, fp );
        fwrite( &age, sizeof( int ) , 1, fp );
        fwrite( &gpa, sizeof( float ) , 1, fp );
    } // end loop

    fclose( fp );
} //end function

void readBinaryText(){
    FILE *fp;
    fp = fopen( "D:/FILES_LAB09/student.dat", "r" );
    if( fp == NULL ){
        printf("Can't open file!");
        exit( 0 );
    }

    char name[20], sex;
    int age, i;
    float gpa;
    for( i = 0 ; i < 20 ; i++ ){
        if( fread( name, sizeof( char[20] ) , 1, fp ) == 0 ){ break; }
        if( fread( &sex, sizeof( char ) , 1, fp ) == 0 ){ break; }
        if( fread( &age, sizeof( int ) , 1, fp ) == 0 ){ break; }
        if( fread( &gpa, sizeof( float ) , 1, fp ) == 0 ){ break; }
        printf( "%d: %10s %2c %2d %4.2f\n", i, name, sex, age, gpa );
    } // end loop

    fclose( fp );
} //end function

void writeBinaryStructText(){
    FILE *fp;
    fp = fopen( "D:/FILES_LAB09/student.dat", "w" );
    if( fp == NULL ){
        printf("Can't open file!");
        exit( 0 );
    }

    struct student child;
    int i;
    for( i = 0 ; i < 2 ; i++ ){
        printf( "Enter Name, Sex, Age and GPA : " );
        scanf( "%s %c %d %f", child.name, &child.sex, &child.age, &child.gpa );
        fwrite( &child, sizeof( struct student ) , 1, fp );
    } // end loop

    fclose( fp );
} //end function

void readBinaryStructText(){
    FILE *fp;
    fp = fopen( "D:/FILES_LAB09/student.dat", "r" );
    if( fp == NULL ){
        printf("Can't open file!");
        exit( 0 );
    }

    struct student child;
    int i;
    for( i = 0 ; i < 20 ; i++ ){
        if( fread( &child, sizeof( struct student ) , 1, fp ) == 0 ){ 
            break; 
        }
        printf( "%d: %10s %2c %2d %4.2f\n", i, child.name, &child.sex, &child.age, &child.gpa );
    } // end loop

    fclose( fp );
} //end function




