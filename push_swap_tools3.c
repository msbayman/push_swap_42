/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_tools3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaoub <amsaoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:12:10 by amsaoub           #+#    #+#             */
/*   Updated: 2023/01/05 11:22:06 by amsaoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	push_a_to_b(t_list **heada, t_list **headb, t_list **unq)
{
	int	a;
	int	i;

	i = 0;
	fake_swap(heada, &a, unq);
	while (a < lst_size(heada))
	{
		if (fake_swap(heada, &a, unq))
			continue ;
		else if ((*heada)->push == 0)
			pb(heada, headb, 1);
		else
			push_a_to_b_helper(heada, &i);
	}
}

void	push_a_to_b_helper(t_list **heada, int *i)
{
	t_list	*temp;	
	int		j;

	temp = *heada;
	*i = 0;
	while (1)
	{
		(*i)++;
		if (temp->push == 1)
			break ;
		temp = temp->next;
	}
	temp = *heada;
	j = 0;
	while (1)
	{
		j--;
		if (temp->push == 1)
			break ;
		temp = temp->next;
	}
	if (abs(j) > *i)
		rra(heada, 1);
	else
		ra(heada, 1);
}

void	find_best_move_for_element(t_list *tempb, t_list *heada, int *i)
{
	t_list	*tempa;

	tempa = heada->prev;
	while (1)
	{
		if ((tempb->data > tempa->data && tempb->data < tempa->next->data)
			|| ((tempa->data > tempa->next->data)
				&& (tempb->data > tempa->data
					|| tempb->data < tempa->next->data)))
			break ;
		(*i)++;
		tempa = tempa->next;
		if (tempa->next == heada)
			break ;
	}
	if (*i > lst_size(&heada) / 2)
			*i = *i - lst_size(&heada);
}

void	best_move(t_list **headb, t_list **heada)
{
	t_list	*tempb;
	int		bmb;
	int		i;

	if (lst_size(headb) == 0)
		return ;
	bmb = 0;
	tempb = *headb;
	while (1)
	{
		i = 0;
		find_best_move_for_element(tempb, *heada, &i);
		tempb->bma = i;
		if (bmb > lst_size(headb) / 2)
				tempb->bmb = bmb - lst_size(headb);
		else
			tempb->bmb = bmb;
		bmb++;
		tempb = tempb->next;
		if (tempb == *headb)
			break ;
	}
}

int	best_sum(t_list **headb)
{
	t_list	*temp;

	temp = *headb;
	while (1)
	{
		if (temp->bma < 0 && temp->bmb < 0)
			temp->sum = sup(abs(temp->bma), abs(temp->bmb));
		else if (temp->bma >= 0 && temp->bmb >= 0)
			temp->sum = sup(temp->bma, temp->bmb);
		else
			temp->sum = abs(temp->bma) + abs(temp->bmb);
		temp = temp->next;
		if (temp == *headb)
			break ;
	}
	return (best_sum_helper(headb));
}
