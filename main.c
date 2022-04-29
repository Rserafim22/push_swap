#include "push_swap.h"
void    reverse_rotate2(List *a, List *b)
{
    *a = reverse_rotate(*a, 0);
    *b = reverse_rotate(*b, 0);
    ft_printf("RRR\n");
}
List reverse_rotate(List stack, int code)
{
    if (is_empty_list(stack) || stack->next == NULL)
        return (stack);
    ListElement *temp;

    temp = stack;
    while (temp->next != NULL)
        temp = temp->next;
    stack = insert_front_list(stack, temp->value);
    stack = remove_back_list(stack);
    if (code == 'a')
        ft_printf("RRA\n");
    if (code == 'b')
        ft_printf("RRB\n");
    return (stack);
}
void    rotate2(List *a, List *b)
{
    *a = rotate(*a, 0);
    *b = rotate(*b, 0);
    ft_printf("RR\n");
}
List    rotate(List stack, int code)
{
    if (is_empty_list(stack) || stack->next == NULL)
        return (stack);
    stack = insert_back_list(stack, stack->value);
    stack = remove_front_list(stack);
    if (code == 'a')
        ft_printf("RA\n");
    if (code == 'b')
        ft_printf("RB\n");
    return (stack);
}
List push(List take, List *send, int code)
{
    if (is_empty_list(*send))
        return (take);
    ListElement *value;

    value = *send;
    take = insert_front_list(take, value->value);
    *send = remove_front_list(*send);
    if (code == 'a')
        ft_printf("PA\n");
    if (code == 'b')
        ft_printf("PB\n");
    return (take);
}
void    swap_stacks(List *a, List *b)
{
    *a = swap(*a, 0);
    *b = swap(*b, 0);
    ft_printf("SS\n");
}
List swap(List stack, int code)
{
    if (is_empty_list(stack) || stack->next == NULL)
        return (stack);
    ListElement *temp;
    int i;
    int j;

    temp = stack;
    i = temp->value;
    temp = temp->next;
    j = temp->value;
    stack = remove_front_list(stack);
    stack = remove_front_list(stack);
    stack = insert_front_list(stack, i);
    stack = insert_front_list(stack, j);
    if (code == 'a')
        ft_printf("SA\n");
    if (code == 'b')
        ft_printf("SB\n"); 
    return (stack);
}

int main(int ac, char **av)
{
    if (ac < 2)
        return (ft_printf("Inserez une liste de nombres\n"));
    int i;

    i = 1;
    while (++i < ac)
        if (ft_strisnot_digit(av[i]))
            return (ft_printf("Inserez une liste de nombres valide\n"));
    List a;
    List b;

    a = new_list();
    b = new_list();
    b = insert_front_list(b, 8);
    b = insert_front_list(b, 7);
    b = insert_front_list(b, 6);
    b = insert_front_list(b, 5);
    a = init_stack(ac, a, i, av);
    ft_printf("a = ");
    print_list(a);
    ft_printf("b = ");
    print_list(b);
    swap_stacks(&a, &b);
    ft_printf("a = ");
    print_list(a);
    ft_printf("b = ");
    print_list(b);
    a = swap(a, 'a');
    b = swap(b, 'b');
    ft_printf("a = ");
    print_list(a);
    ft_printf("b = ");
    print_list(b);
    a = push(a, &b, 'a');
    ft_printf("a = ");
    print_list(a);
    ft_printf("b = ");
    print_list(b);
    a = push(a, &b, 'a');
    a = push(a, &b, 'a');
    a = push(a, &b, 'a');
    a = push(a, &b, 'a');
    ft_printf("a = ");
    print_list(a);
    ft_printf("b = ");
    print_list(b);
    b = push(b, &a, 'b');
    b = push(b, &a, 'b');
    b = push(b, &a, 'b');
    ft_printf("a = ");
    print_list(a);
    ft_printf("b = ");
    print_list(b);
    a = rotate(a, 'a');
    b = rotate(b, 'b');
    ft_printf("a = ");
    print_list(a);
    ft_printf("b = ");
    print_list(b);
    rotate2(&a, &b);
    ft_printf("a = ");
    print_list(a);
    ft_printf("b = ");
    print_list(b);
    a = reverse_rotate(a, 'a');
    b = reverse_rotate(b, 'b');
    ft_printf("a = ");
    print_list(a);
    ft_printf("b = ");
    print_list(b);
    reverse_rotate2(&a, &b);
    ft_printf("a = ");
    print_list(a);
    ft_printf("b = ");
    print_list(b);



    return (0);
}