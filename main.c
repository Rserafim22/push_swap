#include "push_swap.h"
/*
void    reverse_rotate2(List *a, List *b)
{
    *a = reverse_rotate(*a, 0, count);
    *b = reverse_rotate(*b, 0, count);
    count++;
    ft_printf("RRR\n");
}*/
int reverse_rotate(List *stack, int code)
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
        ft_printf("RRA\n");
    if (code == 'b')
        ft_printf("RRB\n");
    return (1);
}/*
void    rotate2(List *a, List *b)
{
    *a = rotate(*a, 0, count);
    *b = rotate(*b, 0, count);
    count++;
    ft_printf("RR\n");
}*/
int    rotate(List *stack, int code)
{
    if (is_empty_list(*stack) || list_lenght(*stack) < 2)
        return (0);
	ListElement *temp;

    temp = *stack;
    *stack = insert_back_list(*stack, temp->value);
    *stack = remove_front_list(*stack);
    if (code == 'a')
        ft_printf("RA\n");
    if (code == 'b')
        ft_printf("RB\n");
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
        ft_printf("PA\n");
    if (code == 'b')
        ft_printf("PB\n");
    return (1);
}/*
void    swap_stacks(List *a, List *b,int *count)
{
    *a = swap(*a, 0, count);
    *b = swap(*b, 0, count);
    count++;
    ft_printf("SS\n");
}*/
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
        ft_printf("SA\n");
    if (code == 'b')
        ft_printf("SB\n");
    return (1);
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
int    search_min_value(List stack)
{
    ListElement *temp;
	int min;

    temp = stack;
	min = stack->value;
    while (temp->next != NULL)
    {
        if (min > temp->value)
			min = temp->value;
        temp = temp->next;
    }
	if (min > temp->value)
			min = temp->value;
    return (min);
}
int	value_position(List stack, int x)
{
	ListElement *temp;
	int i;

	temp = stack;
	i = 0;
	while (temp->next != NULL)
	{
		i++;
		if (x == temp->value)
			break;
		temp = temp->next;
	}
	return (i);
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
Bool    is_sorted(List stack, int code)
{
    int value;

    value = stack->value;
    if (code == '<')
    {
        while (stack->next != NULL)
        {
            stack = stack->next;
            if (value > stack->value)
                return false;
            value = stack->value;
        }
    }
    if (code == '>')
    {
        while (stack->next != NULL)
        {
            if (value < stack->value)
                return false;
            value = stack->value;
            stack = stack->next;
        }
    }
    return true;
}
Bool    is_okay(List stack)
{
    int value;
    int value2;

    value = stack->value;
    while (stack->next != NULL)
    {
        stack = stack->next;
        value2 = stack->value;
        if (value > value2)
            return false;

    }
    return true;
}
int cut_stack_impair(List *a, List *b, int count)
{
	while (list_lenght(*a) != list_lenght(*b) - 1)
    {
        while (!search_min(*a))
        {
            if (swap_worth(*a))
                 count += swap(a, 'a');
            else
			{
                if (opti_rotation(*a,list_lenght(*a)))
                    while (!search_min(*a))
                        count += rotate(a, 'a');
                else
                    while (!search_min(*a))
						count += reverse_rotate(a, 'a');
			}
            ft_printf("a = ");
            print_list(*a);
            ft_printf("b = ");
            print_list(*b);
        }
        count += push(b,a, 'b');
	}
	ft_printf("sortie cut_stack pair\n");
	return (count);
}
int cut_stack_pair(List *a, List *b, int count)
{
	while (list_lenght(*a) != list_lenght(*b))
    {
        //while (!search_min(*a))
        //{
			ft_printf("lenght a = %d\n", list_lenght(*a));
			ft_printf("lenght b = %d\n", list_lenght(*b));
            if (search_min(*a) && swap_worth(*a))
                 count += swap(a, 'a');
            else
			{ 
                if (opti_rotation(*a,list_lenght(*a)))
				{
                    while (!search_min(*a))
                        count += rotate(a, 'a');
				}
                if (!opti_rotation(*a,list_lenght(*a)))
                    while (!search_min(*a))
						count += reverse_rotate(a, 'a');
			}        
            ft_printf("a = ");
            print_list(*a);
            ft_printf("b = ");
            print_list(*b);
        //}
        count += push(b,a, 'b');
	}
	ft_printf("sortie cut_stack pair\n");
	return (count);
}
int algo2(List *a, List *b, int count)
{
	count += cut_stack_pair(a, b, count);
    ft_printf("a = ");
    print_list(*a);
    ft_printf("b = ");
    print_list(*b);
        while (!is_sorted(*a,'<'))
        {
            if (is_okay(*a))
            {
                count += reverse_rotate(a, 'a');
                count += reverse_rotate(a, 'a');
            }
            while (!search_min(*a))
            {
                if (swap_worth(*a) && !(is_okay(*a)))
                    count += swap(a, 'a');
                count += reverse_rotate(a, 'a');
            }
        ft_printf("a = ");
        print_list(*a);
        ft_printf("b = ");
        print_list(*b);
    	}
    return (count);
}
int algo1(List *a, List *b, int count)
{
	count += cut_stack_impair(a, b, count);
	ft_printf("a = ");
	print_list(*a);
	ft_printf("b = ");
	print_list(*b);
	while (!is_sorted(*a,'<'))
	{
		if (is_okay(*a))
		{
			count += reverse_rotate(a, 'a');
			count += reverse_rotate(a, 'a');
		}
		while (!search_min(*a))
		{
			if (swap_worth(*a) && !(is_okay(*a)))
				count += swap(a, 'a');
				count += reverse_rotate(a, 'a');
		}
		ft_printf("a = ");
		print_list(*a);
		ft_printf("b = ");
		print_list(*b);
		}
		ft_printf("sortie algo\n");
		return (count);
}
int algo3(List *a, List *b, int count)
{
	count += cut_stack_pair(a, b, count);
	while (!is_sorted(*a, '<'))
	{
		if (swap_worth(*a))
			count += swap(a, 'a');
		else 
			count += rotate(a, 'a');
	}
	return (count);
}
int algo4(List *a, List *b, int count)
{
	count += cut_stack_impair(a, b, count);
	while (!is_sorted(*a, '<'))
	{
		if (swap_worth(*a))
			count += swap(a, 'a');
		else 
			count += rotate(a, 'a');
	}
	return (count);
}
int push_swap(List *a, List *b, int count, int lenght)
{
	ft_printf("lenght = %d\n", lenght);
	if (is_sorted(*a, '<'))
		return (0);
	if (lenght % 2 != 0)
	{
        if (lenght > 6)
        count = algo1(a,b,count);
		else
			algo4(a, b, count);
	}
	 if (lenght % 2 == 0)
	 {
		if (lenght > 6)
        count = algo2(a,b,count);
		else
			count = algo3(a, b, count);
	 }
	 ft_printf("sortie push_swap\n");
    return (count);
}
Bool    opti_rotation(List stack, int lenght)
{
		ft_printf("min value postion = %d\n", value_position(stack, search_min_value(stack)));
        if (value_position(stack, search_min_value(stack)) < (lenght / 2) + 1)
    		return true;
		else
			return (false);
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
    a = new_list();
    b = new_list();
    a = init_stack(ac, a, i, av);
	lenght = list_lenght(a);
    count = push_swap(&a, &b, count, lenght);
    while (!is_empty_list(b))
    {
        count += push(&a, &b, 'a');
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