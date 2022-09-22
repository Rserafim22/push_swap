#include "push_swap.h"
int	ext_error_1(char **tab, int len, int i)
{
	while (++i < len)
		{
			if (ft_strisnot_digit(tab[i]))
			{
				free_tab(tab);
				return (0);
			}
		}
	return (1);
}
int	find_next_nbr2(List stack, int start, int limit, int len)
{
	int i;

	i = 0;
	if (stack->value <= limit && stack->value >= start)
		return(0);
	if (get_last_elem(stack) <= limit && get_last_elem(stack) >= start)
		return (-1);
	while (stack->next != NULL)
	{
		i++;
		if (stack->value <= limit && stack->value >= start)
			break;
		stack = stack->next;
	}
	return (i);
}
int go_to_value(List *stack, List *stack2, int value, int count)
{
	if (list_lenght(*stack) < 2 || list_lenght(*stack2) < 2)
		return(0);
	while (value_position(*stack, value) != 1)
	{
		if (opti_rotation(*stack, list_lenght(*stack), value))
				count += rotate(stack, 'a');
			else
				count += reverse_rotate(stack, 'a');
	}
	return (count);
}
void free_tab(char **tab)
{
	int i;

	i = -1;
		while (tab[++i])
			free(tab[i]);
		free(tab);
}