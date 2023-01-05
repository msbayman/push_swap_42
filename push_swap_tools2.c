/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_tools2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaoub <amsaoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:58:48 by amsaoub           #+#    #+#             */
/*   Updated: 2023/01/05 11:21:38 by amsaoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	final_push(t_list **heada, t_list **headb)
{
	int		best_index;
	t_list	*tempb;

	if (lst_size(headb) == 0)
		return ;
	tempb = *headb;
	best_index = best_sum(headb);
	while (1)
	{
		if (best_index == tempb->sum)
			break ;
		tempb = tempb ->next;
	}
	while (tempb->bma > 0 && tempb->bmb > 0)
	{
		rr(heada, headb, 1);
		(tempb->bma)--;
		(tempb->bmb)--;
	}
	final_push2(heada, headb, tempb);
}

void	final_push2(t_list **heada, t_list **headb, t_list *tempb)
{
	while (tempb->bma < 0 && tempb->bmb < 0)
	{
		rrr(heada, headb, 1);
		(tempb->bma)++;
		(tempb->bmb)++;
	}
	while (tempb ->bmb < 0)
	{
		rrb(headb, 1);
		(tempb->bmb)++;
	}
	while (tempb ->bmb > 0)
	{
		rb(headb, 1);
		(tempb->bmb)--;
	}
	final_push3(heada, headb, tempb);
}

void	final_push3(t_list **heada, t_list **headb, t_list *tempb)
{
	while (tempb->bma > 0)
	{
		ra(heada, 1);
		(tempb->bma)--;
	}
	while (tempb->bma < 0)
	{
		rra(heada, 1);
		(tempb->bma)++;
	}
	pa(heada, headb, 1);
}

void	indexing(t_list **heada)
{
	t_list	*temp;
	int		i;

	temp = *heada;
	i = 0;
	if (*heada)
	{
		while (1)
		{
			if (i > lst_size(heada) / 2)
				temp->indix = i - lst_size(heada);
			else
				temp->indix = i;
			i++;
			temp = temp->next;
			if (temp == *heada)
				break ;
		}
	}
}

void	end(t_list **heada)
{
	t_list	*temp;
	t_list	*best;
	int		k;
	int		min;

	k = 0;
	temp = *heada;
	indexing(heada);
	while (1)
	{
		temp = temp->next;
		if (temp == *heada)
			break ;
	}
	if (*heada)
	{
		min = temp->data;
		best = temp;
		end_helper(heada, &best, &min);
		k = best->indix;
		end_rotate(heada, k);
	}
}
