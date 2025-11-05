#include "libft.h"

void ft_lstclear(t_list **lst, void (*del)(void*))
{
    t_list *last;
    if ((lst == NULL) || (*lst == NULL))
        return ;
    last = *lst;
    while (*lst)
    {
        last = (*lst)->next;
        del((*lst)->content);
        free(*lst);
        *lst = last;
    }
    *lst = NULL;
}