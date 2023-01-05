/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaoub <amsaoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 12:26:49 by amsaoub           #+#    #+#             */
/*   Updated: 2023/01/05 13:39:02 by amsaoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	sa(t_list **lst, int i)
{
	int		temp;
	t_list	*t;

	if (lst_size(lst) < 2)
		return ;
	t = (*lst);
	temp = t->data;
	t->data = t->next->data;
	t->next->data = temp;
	if (i == 1)
		write(1, "sa\n", 3);
}

void	sb(t_list **lst, int i)
{
	int		temp;
	t_list	*t;

	if (lst_size(lst) < 2)
		return ;
	t = *lst;
	temp = t -> data;
	t->data = t->next->data;
	t -> next -> data = temp;
	if (i == 1)
		write(1, "sb\n", 3);
}

void	ss(t_list **lsta, t_list **lstb, int i)
{
	int		temp;
	t_list	*t;
	int		tempp;
	t_list	*tt;

	if (lst_size(lsta) > 1)
	{	
		t = (*lsta);
		temp = t->data;
		t->data = t->next->data;
		t->next->data = temp;
	}
	if (lst_size(lstb) > 1)
	{	
		tt = (*lstb);
		tempp = tt->data;
		tt->data = tt->next->data;
		tt->next->data = tempp;
	}
	if (i == 1)
		write(1, "ss\n", 3);
}

void	pa(t_list **a, t_list **b, int i)
{
	int		temp ;
	t_list	*del;
	int		k;

	if (lst_size(b) < 1)
		return ;
	k = lst_size(b);
	del = *b;
	temp = (*b)->data;
	ft_lstadd_front(a, ft_lstnew(temp));
	(*b)->prev->next = (*b)->next;
	(*b)->next->prev = (*b)->prev;
	(*b) = (*b)->next;
	free(del);
	if (k == 1)
		(*b) = NULL;
	if (i == 1)
		write(1, "pa\n", 3);
}

void	pb(t_list **a, t_list **b, int i)
{
	int		temp ;
	t_list	*del;
	int		k;

	if (lst_size(a) < 1)
		return ;
	k = lst_size(a);
	del = *a;
	temp = (*a)->data;
	ft_lstadd_front(b, ft_lstnew(temp));
	(*a)->prev->next = (*a)->next;
	(*a)->next->prev = (*a)->prev;
	(*a) = (*a)->next;
	free(del);
	if (k == 1)
		(*a) = NULL;
	if (i == 1)
		write(1, "pb\n", 3);
}
