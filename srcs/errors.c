/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfraslin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 18:23:51 by sfraslin          #+#    #+#             */
/*   Updated: 2025/01/10 15:05:55 by sfraslin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_error(int i)
{
	if (i == -1)
		ft_putstr_fd("Error\nWrong data.\n", 2);
}

t_pile	**ft_free_pile(t_pile **pile_a)
{
	t_pile	*temp;

	while (*pile_a != NULL)
	{
		temp = (*pile_a)->next;
		free(*pile_a);
		*pile_a = temp;
	}
	return (NULL);
}
