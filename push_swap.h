#ifndef _PUSH_SWAP_H
#define _PUSH_SWAP_H

#include "libft/libft.h"

typedef enum
{
    false,
    true
}Bool;

typedef struct ListElement
{
    int value;
    struct ListElement *next;
}ListElement, *List;

List new_list(void);
Bool is_empty_list(List li);
int list_lenght(List li);
void print_list(List li);
List insert_back_list(List li, int x);
List insert_front_list(List li, int x);
List remove_back_list(List li);
List remove_front_list(List li);
List clear_list(List li);

int ft_strisnot_digit(char *s);
int *sort_int_tab(int *check_doubles, int ac,int i, int *j);
List    init_stack(int ac, List mylist, int i, char **av);

int swap(List *stack, int code);
int    swap_stacks(List *a, List *b);
int    rotate(List *stack, int code);
int    rotate2(List *a, List *b);
int reverse_rotate(List *stack, int code);
int    reverse_rotate2(List *a, List *b);

Bool    opti_rotation(List stack, int lenght);
Bool    is_sorted(List stack, int code);
Bool    is_okay(List stack);
#endif