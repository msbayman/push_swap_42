/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libf2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaoub <amsaoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 06:01:22 by amsaoub           #+#    #+#             */
/*   Updated: 2023/02/14 12:39:47 by amsaoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include"push_swap.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*p;
	t_list	*lp;

	p = lst;
	lp = lst;
	if (p == NULL)
		return (NULL);
	else
	{
		while (lp -> next != p)
			lp = lp -> next;
		return (lp);
	}
}

t_list	*ft_lstnew(int k)
{
	t_list	*p;

	p = malloc(sizeof(t_list));
	if (!p)
		er();
	p->data = k;
	p->next = p;
	p->prev = p;
	p->sin = 0;
	p->push = 0;
	p->indix = 0 ;
	return (p);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*nextlst;
	t_list	*head;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	head = *lst;
	nextlst = *lst;
	while (nextlst->next != head)
		nextlst = nextlst->next;
	nextlst->next = new;
	new->next = head;
	new->prev = nextlst;
	head->prev = new;
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new)
		return ;
	new->next = new;
	new->prev = new;
	if (*lst)
	{
		new->next = *lst;
		new->prev = (*lst)->prev;
		(*lst)->prev->next = new;
		(*lst)->prev = new;
	}
	*lst = new;
}

int	ft_strlen(char *str)
{
	int	n;

	n = 0;
	while (str[n])
		n++;
	return (n);
}
