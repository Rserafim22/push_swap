#include "push_swap.h"

int swap(List *stack, int code)
{
    if (is_empty_list(*stack) || list_lenght(*stack) < 2)
        return (0);
    ListElement *temp;
    int i;
    int j;

    temp = *stack;
    i = temp->value;
    temp = temp->next;
    j = temp->value;
    *stack = remove_front_list(*stack);
    *stack = remove_front_list(*stack);
    *stack = insert_front_list(*stack, i);
    *stack = insert_front_list(*stack, j);
    if (code == 'a')
        ft_printf("sa\n");
    if (code == 'b')
        ft_printf("sb\n");
    return (1);
}
int push(List *take, List *send, int code)
{
    if (is_empty_list(*send))
        return (0);
    ListElement *value;

    value = *send;
    *take = insert_front_list(*take, value->value);
    *send = remove_front_list(*send);
    if (code == 'a')
        ft_printf("pa\n");
    if (code == 'b')
        ft_printf("pb\n");
    return (1);
}
int    rotate(List *stack, int code) //1 2 3 4 -> 2 3 4 1//
{
    if (is_empty_list(*stack) || list_lenght(*stack) < 2)
        return (0);
	ListElement *temp;

    temp = *stack;
    *stack = insert_back_list(*stack, temp->value);
    *stack = remove_front_list(*stack);
    if (code == 'a')
        ft_printf("ra\n");
    if (code == 'b')
        ft_printf("rb\n");
    return (1);
}
int reverse_rotate(List *stack, int code) //insert le dernier devant la liste//1 2 3 4 -> 4 1 2 3//
{
    if (is_empty_list(*stack) || list_lenght(*stack) < 2)
        return (0);
    ListElement *temp;

    temp = *stack;
    while (temp->next != NULL)
        temp = temp->next;
    *stack = insert_front_list(*stack, temp->value);
    *stack = remove_back_list(*stack);
    if (code == 'a')
        ft_printf("rra\n");
    if (code == 'b')
        ft_printf("rrb\n");
    return (1);
}