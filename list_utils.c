#include "push_swap.h"

List new_list(void)
{
    return (NULL);
}
Bool is_empty_list(List li)
{
    if (li == NULL)
        return true;
    return false;
}
int list_lenght(List li)
{
    int size;

    size = 0;

    if (!is_empty_list(li))
        while (li != NULL)
        {
            ++size;
            li = li->next;
        }

    return (size);
}
void print_list(List li)
{
    if (is_empty_list(li))
    {
        ft_printf("Rien a afficher, la liste est vide\n");
        return;
    }

    while (li != NULL)
    {
        ft_printf("[%d] ", li->value);
        li = li->next;
    }
    ft_printf("\n");
}
List insert_back_list(List li, int x)
{
    ListElement *element;

    element = malloc(sizeof(*element));

    if (element == NULL)
    {
        free(element);
        return (li);
    }
    element->value = x;
    element->next = NULL;
    if (is_empty_list(li))
        return (element);
    ListElement *temp;
    temp = li;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = element;
    return (li);
}