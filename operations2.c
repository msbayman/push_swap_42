/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaoub <amsaoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:44:49 by amsaoub           #+#    #+#             */
/*   Updated: 2023/01/05 13:37:48 by amsaoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	rb(t_list **lst, int i)
{
	if (lst_size(lst) < 2)
		return ;
	*lst = (*lst)->next;
	if (i == 1)
		write(1, "rb\n", 3);
}

void	rr(t_list **lsta, t_list **lstb, int i)
{
	if (lst_size(lstb) < 2 || lst_size(lsta) < 2)
		return ;
	*lsta = (*lsta)->next;
	*lstb = (*lstb)->next;
	if (i == 1)
		write(1, "rr\n", 3);
}

void	rra(t_list **lst, int i)
{
	if (lst_size(lst) < 2)
		return ;
	(*lst) = (*lst)->prev;
	if (i == 1)
		write(1, "rra\n", 4);
}

void	rrb(t_list **lst, int i)
{
	if (lst_size(lst) < 2)
		return ;
	(*lst) = (*lst)->prev;
	if (i == 1)
		write(1, "rrb\n", 4);
}

void	rrr(t_list **lsta, t_list **lstb, int i)
{
	if (lst_size(lstb) > 1)
		(*lstb) = (*lstb)->prev;
	if (lst_size(lsta) > 1)
		(*lsta) = (*lsta)->prev;
	if (i == 1)
		write(1, "rrr\n", 4);
}
