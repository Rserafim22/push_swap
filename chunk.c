#include "push_swap.h"
Bool	is_chunk(List stack, int limit, int start)
{
	if (is_empty_list(stack))
		return false;
	while (stack->next != NULL)
	{
		if (stack->value <= limit && stack->value >= start)
			return true;
		stack = stack->next;
	}
	if (stack->value <= limit)
			return true;
	return false;
}
int	find_next_nbr(List stack, int start, int limit)
{
	int i;
	int j;
	int x;
	int len;

	len = list_lenght(stack);
	i = find_next_nbr2(stack, start, limit, len);
	x = i;
	while (x-- > 0)
		stack = stack->next;
	j = 0;
	while (stack->next != NULL)
	{
		j++;
		if (stack->value <= limit && stack->value >= start)
			if (len - j < i)
				return (j);
		stack = stack->next;
	}
	if (stack->value <= limit && stack->value >= start)
		j++;
	if (len - j < i)
		return (j);
	return (i);
}
int	do_chunk(List *a, List *b, int start, int limit)
{
	int i;
	int len;

	len = list_lenght(*a);
	while (is_chunk(*a, limit, start))
	{
		cmd_control(a,b);
		i = find_next_nbr(*a, start, limit);
		push_next_nbr(a, b, i, len);
	}
	return (1);
}
int *get_chunk(List a)
{
	int i;
	int	min;
	int max;
	int chunk;
	int *tab;

	i = 1;
	max = search_max_value(a);
	min = search_min_value(a);
	tab = malloc(sizeof(tab) * 6);
	tab[0] = min;
	chunk = (max - min) / 5;
	while (i < 5)
	{
		tab[i] = tab[i - 1] + chunk;
		i++;
	}
	tab[i] = max;
	return (tab);
}
int	sort_chunk(List *a, List *b)
{
	while (!is_empty_list(*b))
	{
		
		while (!is_max_value(*b))
		{
			if (opti_rotation(*b, list_lenght(*b), search_max_value(*b)))
				rotate(b, 'b');
			else
				reverse_rotate(b, 'b');
		}
		push(a, b, 'a');
	}
	return (1);
}