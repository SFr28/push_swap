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

static char	**ft_freetab(char **tab, int i)
{
	i--;
	while (i >= 0)
	{
		free(tab[i]);
		i--;
	}
	free(tab);
	return (NULL);
}

t_pile	**ft_arg_to_pile(int ac, char **av, t_pile **pile_a)
{
	char	**tab;
	int		i;
	int		j;
	int		p;

	i = 0;
	p = 1;
	while (++i < ac)
	{
		j = -1;
		tab = ft_split((const char *)av[i], ' ');
		if (ft_check_arg(tab) == 1)
		{
			ft_free_pile(pile_a);
			return (NULL);
		}
		while (tab[++j] != 0)
			ft_create_pile(pile_a, tab[j], p++);
		ft_freetab(tab, j);
	}
	if (ft_check_doubles(pile_a) == 1)
		pile_a = ft_free_pile(pile_a);
	return (pile_a);
}

int	ft_check_arg(char **tab)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i] != 0)
	{
		j = 0;
		while (tab[i][j])
		{
			if (ft_atol(tab[i], 1) == 0)
			{
				if (tab[i][j] < '0' || tab[i][j] > '9')
				{
					ft_error(-1);
					return (1);
				}
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_check_doubles(t_pile **pile)
{
	t_pile	*temp;
	t_pile	*t_next;

	temp = *pile;
	while (temp != NULL)
	{
		t_next = (temp->next);
		while (t_next != NULL)
		{
			if (t_next->nb == temp->nb)
			{
				ft_error(-1);
				return (1);
			}
			t_next = t_next->next;
		}
		temp = temp->next;
	}
	return (0);
}

void	ft_create_pile(t_pile **pile, char *str, int p)
{
	t_pile	*temp;

	temp = ft_pilenew(ft_atol(str, 1));
	temp->position = p;
	ft_pile_add_back(pile, temp);
}
