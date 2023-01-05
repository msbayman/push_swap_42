/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaoub <amsaoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 12:08:16 by amsaoub           #+#    #+#             */
/*   Updated: 2023/01/02 16:17:05 by amsaoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	the_best_head(t_list **head, t_list **unq)
{
	t_list	*temp;

	temp = *head;
	while (1)
	{
		temp->sin = 0;
		the_best_head_helper(temp);
		temp = temp->next;
		if (temp == *head)
			break ;
	}
	new_head(head, unq);
	zero_one(unq);
}

void	the_best_head_helper(t_list *temp)
{
	t_list	*i;
	t_list	*j;

	i = temp;
	j = temp;
	while (1)
	{
		if (i->data <= j->data)
		{
			temp->sin++;
			i = j;
		}
		j = j->next;
		if (j == temp)
			break ;
	}
}

int	check_min_sin_lis(t_list **heada, t_list **unq)
{
	int		max;
	t_list	*temp;

	the_best_head(heada, unq);
	max = -1;
	temp = *heada;
	while (1)
	{
		if (temp->sin > max)
			max = temp->sin;
		temp = temp ->next;
		if (temp == *heada)
			break ;
	}
	return (max);
}

int	fake_swap(t_list **heada, int *k, t_list **unq)
{
	int	p;
	int	n;

	p = check_min_sin_lis(heada, unq);
	sa(heada, 0);
	n = check_min_sin_lis(heada, unq);
	if (n <= p)
	{
		sa(heada, 0);
		*k = check_min_sin_lis(heada, unq);
		return (0);
	}
	else
	{
		*k = check_min_sin_lis(heada, unq);
		write(1, "sa\n", 3);
		return (1);
	}
}

void	new_head(t_list **heada, t_list **unq)
{
	t_list	*temp;
	t_list	*new_head;
	int		max;

	max = -1;
	temp = *heada;
	while (1)
	{
		if (temp->sin > max)
		{
			max = temp->sin;
			new_head = temp;
		}
		temp = temp->next;
		if (temp == *heada)
			break ;
	}
	*unq = new_head;
}
