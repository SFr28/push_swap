/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfraslin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:44:26 by sfraslin          #+#    #+#             */
/*   Updated: 2025/01/14 11:44:31 by sfraslin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

long int	ft_atol(char *str, int sign)
{	
	long int	nb;
	int			i;

	i = 0;
	nb = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb *= 10;
		nb += str[i] - 48;
		i++;
	}
	if (str[i])
		return (0);
	return (nb *= sign);
}

long int	ft_mean(t_pile **pile_a)
{
	long int	mean;
	t_pile		*first;

	first = *pile_a;
	mean = 0;
	while (*pile_a != NULL)
	{
		mean += (*pile_a)->nb;
		*pile_a = (*pile_a)->next;
	}
	*pile_a = first;
	mean /= ft_pilesize(*pile_a);
	return (mean);
}
