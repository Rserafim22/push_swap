#ifndef _PUSH_SWAP_H
#define _PUSH_SWAP_H

#include "libft/libft.h"
#include <unistd.h>

typedef struct s_chuncks
{
    int min;
    int one;
    int two;
    int three;
    int four;
    int max;
}chuncks;

typedef enum
{
    false,
    true
}Bool;

typedef struct ListElement
{
    int value;
    struct ListElement *next;
}ListElement, *List;

List new_list(void);
Bool is_empty_list(List li);
int list_lenght(List li);
void print_list(List li);
List insert_back_list(List li, int x);
List insert_front_list(List li, int x);
List remove_back_list(List li);
List remove_front_list(List li);
List clear_list(List li);

int push_swap(List *a);
int ft_strisnot_digit(char *s);
int sort_int_tab(int *check_doubles, int nbr, int code);
List    init_stack(int ac, List mylist, char **av);
List    init_one_arg(char *av, List stack);
int count_len(char **s);
int    error_manager_1(int ac, char **av);
int	error_manager_2(int ac, char **av);

int swap(List *stack, int code);
int    swap_stacks(List *a, List *b);
int    rotate(List *stack, int code);
int    rotate2(List *a, List *b);
int reverse_rotate(List *stack, int code);
int    reverse_rotate2(List *a, List *b);
int push(List *take, List *send, int code);

Bool    opti_rotation(List stack, int lenght, int value);
Bool    is_sorted(List stack, int code);
Bool    is_okay(List stack);
int     algo_3(List *a, int min, int max);
int algo_5(List *a, List *b, int len);
int    search_min_value(List stack);
int    search_max_value(List stack);
int next_command(List *a, List *b, int count);
int get_last_elem(List stack);
int	do_chunk(List *a, List *b, int start, int limit);
Bool	is_chunk(List stack, int limit, int start);
int swap_control(List *a, List *b, int count);
int	value_position(List stack, int x);
Bool is_max_value(List stack);
Bool is_min_value(List stack);
int *get_chunk(List a);
void write_error(void);
int	sort_chunk(List *a, List *b);
int go_to_value(List *stack, List *stack2,int value, int count);
int swap_worth(List a, List b);
int double_rotate_worth(List a, List b);
int double_reverse_rotate_worth(List a, List b);
int	find_next_nbr2(List stack, int start, int limit, int len);
int	ext_error_1(char **tab, int len, int i);
void free_tab(char **tab);
void	cmd_control(List *a, List *b);
int	push_next_nbr(List *a, List *b, int i, int len);

#endif