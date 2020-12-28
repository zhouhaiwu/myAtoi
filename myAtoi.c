#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int myAtoi(char * s){
    int len = strlen(s);
    int i = 0;
    long long num = 0;
    int flag = 0; //  有符号整数的标识
    int flag1 = 0; // 第一个非空字符的标识

    for(i=0; i<len; i++) {
        printf("bbb\n");
        if (((s[i] >'9') || (s[i] <'0') || s[i] == ' ') && (flag1 == 1)) {
            break;
        }
        if(s[i] == '+' && flag1 == 0) {
            printf("ccc\n");
            flag1 = 1;
        }
        if(s[i] == '-' && flag1 == 0) {
            printf("ccc\n");
            flag = 1;
            flag1 = 1;
        }
        if (s[i] <='9' && s[i] >='0') {
            if (flag1 == 0) {
                flag1 = 1;
            }
            printf("s[i]:%c\n", s[i]);
            if (num > 2147483647 && flag == 0) {
                return 2147483647;
            }
            if (num > 2147483648 && flag == 1) {
                return -2147483648;
                }
            if(num >= -2147483648 && num <= 2147483647) {
                num = num * 10 + s[i] - '0';
                //printf("num:%d\n", num);
            }
        }
        if (((s[i] >'9') || (s[i] <'0')) && (flag1 == 0)) {
            //printf("aaa\n");
            if (s[i] != ' ')
            return 0;
        }
    }
    if (num > 2147483647 && flag == 0) {
            //printf("haha\n");
            return 2147483647;
        }
    if (num > 2147483648 && flag == 1) {
            return -2147483648;
        }
    if (flag == 1) {
        num = 0 - num;
    }
    return (int)num; 
}

int main() {
    //char *s = "4193 with words";
    //char *s = "-42";
    //char *s = "   -42";
    //char *s = "4193 with words";
    //char *s = "20000000000000000000";
    char *s = "21474836460";
               //2147483646
               //2147483647
    //char *s = "words and 987";
    if (s[0] == ' ') {
        printf("AAA\n");
    }
    int len;
    len = myAtoi(s);
    printf("len:%d\n", len);
    return 0;
}