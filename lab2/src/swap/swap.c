#include "swap.h"

void Swap(char *left, char *right)
{   
	 // Сохраняем значение, на которое указывает left, во временную переменную
    char temp = *left;
    
    // Присваиваем переменной по адресу left значение переменной по адресу right
    *left = *right;
    
    // Присваиваем переменной по адресу right сохраненное значение
    *right = temp;
}
