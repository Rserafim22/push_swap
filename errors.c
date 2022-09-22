#include "push_swap.h"
int check_min_max(int *check_doubles, int len)
{
	int i;

	i = -1;
	while (++i < len)
		if (check_doubles[i] > 2147483647 || check_doubles[i] < -2147483648)
			return (0);
	return (1);
}
int	check_errors_one(char **tab, int *check_doubles, int len)
{
	int i;

	i = -1;
	while (++i < len)
		check_doubles[i] = ft_atoi(tab[i]);
	if (!sort_int_tab(check_doubles, len, 0))
		return (0);
	if (!check_min_max(check_doubles, len))
		return (0);
	return (1);
}
int	check_errors_more(int *check_doubles, int len, char **av)
{
	int i;

	i = 0;
	while (++i < len)
		check_doubles[i - 1] = ft_atoi(av[i]);
	if (!sort_int_tab(check_doubles, len, 1))
		return (0);
	if (!check_min_max(check_doubles, len))
		return (0);
	return (1);

}
int	error_manager_1(int ac, char **av)
{
    char **tab;
    int len;
	int *check_doubles;
	int i;

	i = -1;
    tab = ft_split(av[1], ' ');
	while (tab[i])
	i++;
	if (i == 1)
	{
		free_tab(tab);
		return (2);
	}
    len = count_len(tab);
	if (ext_error_1(tab, len, i) == 0)
		return (0);
	check_doubles = malloc (sizeof(check_doubles) * (len));
	i = check_errors_one(tab, check_doubles,len);
	free_tab(tab);
    free(check_doubles);
	return (i);
}
int	error_manager_2(int ac, char **av)
{
	int i;
	int code;
	int *check_doubles;

	i = -1;
	code = 0;
	i = 0;
	while (++i < ac)
			if (ft_strisnot_digit(av[i]))
				return (0);
	if (ac == 2)
		if (ft_strisnot_digit(av[1]))
				return (0);
	check_doubles = malloc (sizeof(check_doubles) * (ac - 1));
	code = check_errors_more(check_doubles, ac, av);
	free(check_doubles);
	return (code);
}