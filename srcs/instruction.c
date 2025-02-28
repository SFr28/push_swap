/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfraslin <sfraslin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 18:18:35 by sfraslin          #+#    #+#             */
/*   Updated: 2025/01/18 18:52:24 by sfraslin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

//intervertit les 2 premiers elements au sommet de la pile
t_pile	*swap(t_pile **pile, char c, int i)
{
	t_pile	*temp;

	if (*pile == NULL)
		return (*pile);
	temp = *pile;
	temp->position = 2;
	*pile = (*pile)->next;
	temp->next = (*pile)->next;
	(*pile)->next = temp;
	(*pile)->position = 1;
	if (i == 1)
	{
		ft_putchar_fd('s', 1);
		ft_putchar_fd(c, 1);
		ft_putchar_fd('\n', 1);
	}
	return (*pile);
}

//push a : prend PREMIER element de b et met sur a
void	push(t_pile **pile_1, t_pile **pile_2, char c, int i)
{
	t_pile	*temp;
	int		p;

	if (*pile_2 == NULL)
		return ;
	temp = *pile_2;
	p = 1;
	*pile_2 = (*pile_2)->next;
	ft_pile_add_front(pile_1, temp);
	temp = *pile_2;
	while (*pile_2 != NULL)
	{
		(*pile_2)->position = p;
		*pile_2 = (*pile_2)->next;
		p++;
	}
	if (i == 1)
	{	
		ft_putchar_fd('p', 1);
		ft_putchar_fd(c, 1);
		ft_putchar_fd('\n', 1);
	}
	*pile_2 = temp;
}

//premier element devient le dernier
t_pile	*rotate(t_pile **pile, char c, int i)
{
	t_pile	*temp;

	if (*pile == NULL || (*pile)->next == NULL)
		return (*pile);
	temp = *pile;
	temp->position = ft_pilesize(*pile);
	*pile = (*pile)->next;
	(*pile)->position = 1;
	temp->next = NULL;
	ft_pile_add_back(pile, temp);
	if (i == 1)
	{
		ft_putchar_fd('r', 1);
		ft_putchar_fd(c, 1);
		ft_putchar_fd('\n', 1);
	}
	return (*pile);
}

//dernier element devient le premier
void	reverse_r(t_pile **pile, char c, int i)
{
	t_pile	*temp;
	t_pile	*first;
	int		j;
	int		size;

	if (*pile == NULL || (*pile)->next == NULL)
		return ;
	size = ft_pilesize(*pile);
	j = 0;
	temp = ft_pilelast(*pile);
	temp->next = (*pile);
	ft_pile_add_front(pile, temp);
	first = *pile;
	while (++j < size)
	{
		first->position = j;
		first = first->next;
	}
	first->next = NULL;
	if (i == 1)
	{
		ft_putstr_fd("rr", 1);
		ft_putchar_fd(c, 1);
		ft_putchar_fd('\n', 1);
	}
}
