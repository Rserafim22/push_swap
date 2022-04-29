#include "push_swap.h"

int ft_strisnot_digit(char *s)
{
    int i;

    i = 0;
    while (s[i])
    {
        if (!ft_isdigit(s[i]) && s[i] != '-')
            return (1);
        i++;
    }
    return (0);
}
int *sort_int_tab(int *check_doubles, int nbr, int i, int *j)
{
    int k;

    while (i < nbr)
    {
        *j = i + 1;
        while (*j < nbr)
        {
            if (check_doubles[*j] == check_doubles[i])
            {
                k = *j;
                while (k < nbr)
                {
                  check_doubles[k] = check_doubles[k + 1];
                  k++;
                }
                nbr--;  
            }
            else
                *j += 1;
        }
        i++;
    }
    i = 0;
    return (check_doubles);
}
List    init_stack(int ac, List mylist, int i, char **av)
{
    int *check_doubles;

    check_doubles = malloc (sizeof(check_doubles) * (ac - 1));
    i = 1;
    mylist = new_list();
    while (i < ac)
    {
        check_doubles[i - 1] = ft_atoi(av[i]);
        i++;
    }
    int j;
    int nbr;
    
    nbr = ac - 1;

    i = 0;
    check_doubles = sort_int_tab(check_doubles, nbr, i, &j);
    while (i < j) /*J = fin du tableau sans doublons*/
    {
        mylist = insert_back_list(mylist, check_doubles[i]);
        i++;
    }
    free (check_doubles);
    return (mylist);
}