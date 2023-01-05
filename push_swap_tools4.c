/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_tools4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaoub <amsaoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:12:15 by amsaoub           #+#    #+#             */
/*   Updated: 2023/01/05 18:28:37 by amsaoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	zero_one(t_list **unq)
{
	t_list	*i;
	t_list	*temp;
	t_list	*j;

	i = *unq;
	j = *unq;
	temp = *unq;
	i->push = 1;
	while (1)
	{
		if (i->data <= j->data)
		{
			j->push = 1;
			i = j;
		}
		else
			j->push = 0;
		j = j->next;
		if (j == *unq)
			break ;
	}
}

void	ft_lstclear(t_list **lst)
{
	t_list	*p;
	t_list	*c;
	int		k;

	if (lst)
	{
		p = *lst;
		c = p->next;
		k = lst_size(lst);
		while (k--)
		{
			p = c;
			free(p);
			c = c->next;
		}
	}
}

void	ps(t_list *heada, t_list *headb, t_list *unq)
{
	the_best_head(&heada, &unq);
	push_a_to_b(&heada, &headb, &unq);
	while (headb)
	{
		best_move(&headb, &heada);
		final_push(&heada, &headb);
	}
	end(&heada);
}

void	last_free(char **tab, t_list **heada)
{
	int		i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	if (*heada)
		ft_lstclear(heada);
}
