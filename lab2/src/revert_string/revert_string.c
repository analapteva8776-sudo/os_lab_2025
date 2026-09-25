#include "revert_string.h"

void RevertString(char *str)
{
    // Находим длину строки
    int len = 0;
    while (str[len] != '\0')
    {
        len++;
    }

    // Меняем символы местами: первый с последним, второй с предпоследним и т.д.
    int left = 0;
    int right = len - 1;
    while (left < right)
    {
        char temp = str[left];
        str[left] = str[right];
        str[right] = temp;

        left++;
        right--;
    }
}
