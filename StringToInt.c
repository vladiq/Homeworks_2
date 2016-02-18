#include <stdio.h>

int end_str(char str[]) {
    int i = 0;
    while(str[i] != '\0') {
        i = i + 1;
    }
    return(i - 1);
}

_Bool is_digit(char chr) {
    // return chr>='0' && chr<='9')
    return (chr>='0' && chr<='9');
}

long char_to_digit(char chr) {
    return((long)chr - (int)'0');
}

int str_to_int(char str[], _Bool *is_number) {
    *is_number = 1;
    int number;
    number = 0;
    int i = end_str(str);  //нахожу индекс последнего символа строки
    int dig = 1;  //dig - разряд числа
    while((i >= 0) && (*is_number)) {
        if (is_digit(str[i])) {  //проверяю является ли символ цифрой
            number = (number) + char_to_digit(str[i])*dig;  //прибавляю к искому числу цифру, помноженную на разряд
            i = i - 1;
            dig = dig*10;
        } else {
            *is_number = 0;
            return(-1);
        }
    }
    return(number);
}

int main() {
    char str[] = {'\0'};
    int number;
    _Bool is_number;
    printf("\nEnter something: ");
    scanf("%s", str);
    number = str_to_int(str, &is_number);
    if(is_number) {
        printf("You typed the number %d\n", number);
        printf("%d plus 101 is %d\n",number,number+101);
        printf("%d minus 101 is %d\n",number,number-101);
    } else {
        printf("You didn't type the number\n");
    }
    return 0;
}