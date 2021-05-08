#include <stdio.h>
#include "list.h"

// множество предметов
enum predm {
p_matan,
p_informatika,
p_diskretka,
p_istoriya,
p_linal
};

// предметы текстом
char *predm2[]={"matan","informatika","diskretka","istoriya","linal"};

// преобразует строку в элемент множества предметов
enum predm fromstring(char a[20])
{
	if(strcmp(a,predm2[0])==0)
		return p_matan;
	if(strcmp(a,predm2[1])==0)
		return p_informatika;
	if(strcmp(a,predm2[2])==0)
		return p_diskretka;
	if(strcmp(a,predm2[3])==0)
		return p_istoriya;
	if(strcmp(a,predm2[4])==0)
		return p_linal;
	else
		return -1;
}

int main(int argc,char *argv[])
{
    printf("команды:\n"
    "i <elem> <idx> - вставка элемента по индексу\n"
    "b <elem> - вставка элемента в конец листа\n"
    "g <idx> - получение элемента по индексу\n"
    "r <idx> - удаление элемента по индексу\n"
    "d <elem> - удаление элемента по значению\n"
    "s - распечатать размер списка\n"
    "p - распечатать все элементы списка\n"
    "z - задание: развернуть список\n"
    "q - выход и освобождение ресурсов\n");
    char in3[20];
    List *ml=list_create();
    char run=1;
    while(run)
    {
        printf("> ");
        char in;
        read:
        scanf("%c",&in);
        switch(in)
        {
            case 'i':
            {
                int in2;
                scanf("%s %d",in3,&in2);
                list_insert(ml,fromstring(in3),in2);
                break;
            }
            case 'b':
            {
                scanf("%s",in3);
                list_push(ml,fromstring(in3));
                break;
            }
            case 'g':
            {
                int in2;
                scanf("%d",&in2);
                printf("%s\n",predm2[list_get(ml,in2)]);
                break;
            }
            case 'r':
            {
                int in2;
                scanf("%d",&in2);
                list_remove(ml,in2);
                break;
            }
            case 'd':
            {
                scanf("%s",in3);
                list_delete(ml,fromstring(in3));
                break;
            }
            case 'p':
            {
            	list_print(ml,predm2);
            	break;
            }
            case 's':
            {
            	printf("размер списка: %d\n",ml->size);
            	break;
            }
            case 'z':
            {
            	list_reverse(ml);
            	break;
            }
            case '\n':
            {
            	goto read;
            }
            case 'q':
            {
            	run=0;
            	break;
            }
            default:
            {
            	printf("неверная команда\n>");
            	goto read;
            }
        }
    }
    list_destroy(ml);
    return 0;
}

