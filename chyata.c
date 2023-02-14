/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chyata.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaoub <amsaoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:46:15 by amsaoub           #+#    #+#             */
/*   Updated: 2023/02/14 12:39:47 by amsaoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include"push_swap.h"

void	ra(t_list **lst, int i)
{
	if (lst_size(lst) < 2)
		return ;
	*lst = (*lst)->next;
	if (i == 1)
		write(1, "ra\n", 3);
}

int	check_nul(char	**tab, int ac)
{
	int	i;

	i = 0;
	while (i < ac - 1)
	{
		if (tab[i] == NULL)
			return (0);
		i++;
	}
	return (1);
}

void	end_h(t_list **heada, t_list **best, int *min)
{
	t_list	*temp;

	temp = *heada;
	while (1)
	{
		if (temp->data < *min)
		{
			*best = temp;
			*min = temp->data;
		}
		temp = temp->next;
		if (temp == *heada)
			break ;
	}
}

void	end_rotate(t_list **heada, int k)
{
	while (k)
	{
		if (k > 0)
		{
			ra(heada, 1);
			k--;
		}
		else
		{
			rra(heada, 1);
			k++;
		}
	}
}

int	best_sum_helper(t_list **headb)
{
	int		sum;
	t_list	*temp;

	sum = (*headb)->sum;
	temp = *headb;
	while (1)
	{
		if (sum > temp->sum)
				sum = temp->sum;
		temp = temp->next;
		if (temp == *headb)
			break ;
	}
	return (sum);
}
