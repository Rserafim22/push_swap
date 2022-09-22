#include "push_swap.h"

List insert_front_list(List li, int x)
{
    ListElement *element;

    element = malloc(sizeof(*element));

    if (element == NULL)
    {
        free(element);
        return (li);
    }
    element->value = x;
    if (is_empty_list(li))
        element->next = NULL;
    else
        element->next = li;
    return (element);
}
List remove_back_list(List li)
{
    if (is_empty_list(li))
        return new_list();
    if (li->next == NULL)
    {
        free (li);
        li = NULL;
        return new_list();
    }
    ListElement *temp;
    ListElement *before;

    temp = li;
    before = li;
    while (temp->next != NULL)
    {
        before = temp;
        temp = temp->next;
    }
    before->next = NULL;
    free (temp);
    temp = NULL;
    return (li);
}
List remove_front_list(List li)
{
    if (is_empty_list(li))
        return new_list();
    ListElement *element;

    element = li->next;
    free (li);
    li = NULL;
    return (element);
}
List clear_list(List li)
{
    if (is_empty_list(li))
        return new_list();
    while (li != NULL)
        li = remove_front_list(li);
    li = NULL;
    return (li);
}
int get_last_elem(List stack)
{
    while (stack->next != NULL)
        stack = stack->next;
    return (stack->value);
}