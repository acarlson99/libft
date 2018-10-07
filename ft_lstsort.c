/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_manip.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 10:41:57 by acarlson          #+#    #+#             */
/*   Updated: 2018/10/06 17:49:07 by acarlson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_list          *ft_lstsort(t_list **lst, int (*cmp)(t_list *a, t_list *b))
{
    t_list  *head;
    t_list  *tmp;
    t_list  *t2;
    int     done;

    ft_lstadd(&*lst, ft_lstnew(NULL, sizeof(NULL)));
    head = *lst;
    done = 0;
    while (!(done))
    {
        done = 1;
        while ((*lst)->next->next)
        {
            if (cmp((*lst)->next, (*lst)->next->next) > 0)
            {
                done = 0;
                tmp = (*lst)->next->next;
                t2 = (*lst)->next;
                t2->next = (*lst)->next->next->next;
                tmp->next = t2;
                (*lst)->next = tmp;
            }
            *lst = (*lst)->next;
        }
        *lst = head;
    }
    *lst = head->next;
    ft_lstdelone(&head, thing);
    return (*lst);
}
