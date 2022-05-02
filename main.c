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
Bool    search_min(List stack)
{
    ListElement *temp;
    ListElement *temp2;

    temp = stack;
    temp2 = stack;
    while (temp2->next != NULL)
    {
        if (temp->value > temp2->value)
            return false;
        temp2 = temp2->next;
    }
    if (temp->value > temp2->value)
            return false;
    return true;
}
Bool    swap_worth(List stack)
{
    int value;

    value = stack->value;
    stack = stack->next;
    if (value > stack->value)
        return true;
    else
        return false;
}
int push_swap(List *a, List *b, int count, int lenght)
{
    lenght = list_lenght(*a);

        while (!search_min(*a))
        {
            if (swap_worth(*a))
            {
                 *a = swap(*a, 'a');
                 count++;
            }
            else 
            {
                if (opti_rotation(*a,lenght))
                {
                    while (!search_min(*a))
                    {
                        *a = rotate(*a, 'a');
                        count++;
                    }
                }
                else
                {
                    while (!search_min(*a))
                    {
                        *a = reverse_rotate(*a, 'a');
                        count++;
                    }
                }
            }   
        
            /*ft_printf("a = ");
            print_list(*a);
            ft_printf("b = ");
            print_list(*b);*/
        }
    *b = push(*b,a, 'b');
    count++;
    /*ft_printf("a = ");
    print_list(*a);
    ft_printf("b = ");
    print_list(*b);*/
    if (!is_empty_list(*a))
         count = push_swap(a,b, count, lenght);
    /*if (!is_empty_list(b))
    {
        a = push(a, &b, 'a');
        ft_printf("a = ");
        print_list(a);
        ft_printf("b = ");
        print_list(b);
    }*/
    return (count);
}
Bool    opti_rotation(List stack, int lenght)
{
    int comp;
    int count;

    comp = stack->value;
    count = 0;
    while (stack->next != NULL)
    {
        if (count > lenght / 2)
        {
            if (stack->value < comp)
                return false;
        }
        if (stack->value < comp)
            comp = stack->value;
        stack = stack->next;
        count++;
    }
    return true;
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
    int count;
    int lenght;

    count = 0;
    lenght = 0;
    a = new_list();
    b = new_list();
    a = init_stack(ac, a, i, av);
    count = push_swap(&a, &b, count, lenght);
    while (!is_empty_list(b))
    {
        a = push(a, &b, 'a');
        count++;
        /*ft_printf("a = ");
        print_list(a);
        ft_printf("b = ");
        print_list(b);*/
    }
    ft_printf("liste apres le tri = ");
    print_list(a);
    ft_printf("nombre de mouvements = %d\n", count);


    



    return (0);
}