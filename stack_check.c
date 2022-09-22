#include "push_swap.h"

int ft_strisnot_digit(char *s)
{
    int i;

    i = -1;
	if (!ft_strrchr(s, '-') && ft_atoi(s) < 0)
		return (1);
	if (ft_strlen(s) > 11)
		return (1);
    while (s[++i])
    {
		if (s[i] == '-' && ft_atoi(s) > 0)
			return (1);
        if (!ft_isdigit(s[i]))
		{
			if (s[i] == '-' && ft_isdigit(s[i + 1]) && s[i + 1] != ' ')
				continue;
			else
            	return (1);
		}
    }
    return (0);
}
int sort_int_tab(int *check_doubles, int nbr, int code)
{
	int i;
	int j;

	i = 0;
    while (i < nbr)
    {
        j = i + 1;
        while (j < nbr - code)
        {
            if (check_doubles[j] == check_doubles[i])
                return (0);  
            else
                j += 1;
        }
        i++;
    }
    return (1);
}
List    init_stack(int ac, List mylist, char **av)
{
	int i;
    int *check_doubles;

    check_doubles = malloc (sizeof(check_doubles) * (ac - 1));
    i = 0;
    
    while (++i < ac)
        check_doubles[i - 1] = ft_atoi(av[i]);
    int nbr;
    
    nbr = ac - 1;

    i = -1;
    while (++i < ac - 1)
        mylist = insert_back_list(mylist, check_doubles[i]);
    free (check_doubles);
    return (mylist);
}
int count_len(char **s)
{
    int i;
    int count;

    i = 0;
    count = 0;
	while (s[++i])
	count ++;
    return (count + 1);
}
List    init_one_arg(char *av, List stack)
{
    int i;
    char **tab;
    int len;
    int *check_doubles;
    
	tab = ft_split(av, ' ');
    i = -1;
	len = count_len(tab);
	check_doubles = malloc (sizeof(check_doubles) * (len));
	while (++i < len)
        check_doubles[i] = ft_atoi(tab[i]);
	i = -1;
			while (++i < len)
				free(tab[i]);
			free(tab);
	i = -1;
    while (++i < len)
        stack = insert_back_list(stack, check_doubles[i]);
    free (check_doubles);
    return (stack);
}