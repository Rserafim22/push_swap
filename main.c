#include "push_swap.h"

int algo_100(List *a, List *b)
{
	int *chunks;
	int i;
	int max;

	i = -1;
	chunks = get_chunk(*a);
	while (i < 4)
	{
		++i;
		do_chunk(a, b, chunks[i],chunks[i + 1]);
		if (list_lenght(*a) == 2 && !is_sorted(*a, '<'))
			swap(a, 'a');
	}
	sort_chunk(a, b);
	i = -1;
	free(chunks);
	return (1);
}
int algo_5(List *a, List *b, int len)
{
	while (!is_sorted(*a, '<') && list_lenght(*a) > 3)
	{
		while(!is_min_value(*a))
		{
			if (opti_rotation(*a, list_lenght(*a), search_min_value(*a)))
				rotate(a, 'a');
			else
				reverse_rotate(a, 'a');
		}
		push(b, a, 'b');
	}
	if (!is_sorted(*a, '<'))
		algo_3(a, search_min_value(*a),search_max_value(*a));
	while (!is_empty_list(*b))
	{
		push(a, b, 'a');
	}
	return (1);
}
int algo_3(List *a, int min, int max)
{
	int current;
	ListElement *tmp;

	tmp = *a;
	current = tmp->value;
	if (current == max)
	{
		rotate(a, 'a');
		if (!is_sorted(*a, '<'))
			swap(a, 'a');
		return (0);
	}
	if (current == min)
	{
		reverse_rotate(a, 'a');
		swap(a, 'a');
		return (0);
	}
	if (get_last_elem(*a) == min)
		reverse_rotate(a, 'a');
	else
		swap(a, 'a');
	return (1);
}
int push_swap(List *a)
{
	int lenght;
	List b;

	lenght = list_lenght(*a);
	if (is_empty_list(*a))
		return (0);
	if (is_sorted(*a, '<'))
		return (0);
	b = new_list();
	if (lenght < 3)
		swap(a, 'a');
	if (lenght == 3)
		algo_3(a, search_min_value(*a),search_max_value(*a));
	if (lenght > 3 && lenght <= 20)
		algo_5(a, &b, lenght);
	if (lenght > 20)
		algo_100(a, &b);
	clear_list(b);
	return (1);
}
int main(int ac, char **av)
{	
if (ac < 2)
		return (0);
    List a;
	int code;

	if (ac == 2)
		code = error_manager_1(ac, av);
		if (code == 2)
			code = error_manager_2(ac, av);
	if (ac > 2)
		code = error_manager_2(ac, av);
	if (code == 0)
	{
		write_error();
		return (0);
	}
	a = new_list();
	if (ac == 2)
		a = init_one_arg(av[1], a);
	if (ac > 2)
		a = init_stack(ac, a, av);
	push_swap(&a);
	clear_list(a);
    return (1);
}