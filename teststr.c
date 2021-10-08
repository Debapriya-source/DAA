#include<string.h>
#include<stdio.h>
void main(){
    char str1[]="abcd";
    char str2[]="cdef";
    if(strcmp(str1,str2))
    printf("%s<%s",str1,str2);
}