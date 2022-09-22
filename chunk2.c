#include "push_swap.h"

int swap_worth(List a, List b)
{
	if (list_lenght(a) < 2 || list_lenght(b) < 2)
	return(0);
	ListElement *temp;
	ListElement *temp2;

	temp = a;
	temp2 = b;
	temp = temp->next;
	temp2 = temp2->next;
	

	if (temp->value < a->value && temp2->value > b->value)
		return (1);
	if (temp->value < a->value)
		return (2);
	if (temp2->value > b->value)
		return(3);
	return (0);
}
int double_rotate_worth(List a, List b)
{
	if (list_lenght(a) < 2 || list_lenght(b) < 2)
	return(0);
	ListElement *temp;
	ListElement *temp2;

	temp = a;
	temp2 = b;
	temp = temp->next;
	temp2 = temp2->next;
	if (temp->value == temp2->value + 1)
		return (1);
	if (temp->value == b->value + 1)
		return (2);
	return (0);
}
int double_reverse_rotate_worth(List a, List b)
{
	if (list_lenght(a) < 2 || list_lenght(b) < 2)
	return(0);
	int last_a;
	int last_b;

	last_a = get_last_elem(a);
	last_b = get_last_elem(b);
	if (last_a == last_b + 1)
		return (1);
	if (last_a == b->value + 1)
		return (2);
	return (0);
}
void	cmd_control(List *a, List *b)
{
	if (swap_worth(*a, *b) == 1)
			swap_stacks(a, b);
		if (swap_worth(*a, *b) == 2)
			swap(a, 'a');
		if (swap_worth(*a, *b) == 3)
			swap(b, 'b');
		if (double_rotate_worth(*a, *b) == 1)
			rotate2(a, b);
		if (double_rotate_worth(*a, *b) == 2)
			rotate(a, 'a');
		if (double_reverse_rotate_worth(*a, *b) == 1)
			reverse_rotate2(a, b);
		if (double_reverse_rotate_worth(*a, *b) == 2)
			reverse_rotate(a, 'a');
}
int	push_next_nbr(List *a, List *b, int i, int len)
{
	if (i == 0)
		{
			push(b, a, 'b');
			return (0);
		}
		if (i == -1)
		{
			reverse_rotate(a, 'a');
			push(b, a, 'b');
			return (0);
		}
		if (i < list_lenght(*a) / 2)
			while (i-- > 1)
			rotate(a, 'a');
		if (i > len / 2)
		{
			i = list_lenght(*a) - i;
			while (i-- > -1)
				reverse_rotate(a, 'a');
		}
		push(b, a, 'b');
		return (1);
}