/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimum_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 12:25:11 by rschlott          #+#    #+#             */
/*   Updated: 2022/11/06 08:19:56 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* identifies if minimal value is located in the first or 
second half of stack b */
bool	location_value_b(struct s_node **b_liste, int *values_b, int smallest)
{
	int	i;
	int	len;

	i = 0;
	len = count_of_nodes(b_liste);
	while (values_b[i] != smallest)
		i++;
	if (i < (len / 2) || len == 1)
	{
		return (true);
	}
	return (false);
}

/* identifies the position of the minimal value in stack b */
int	index_value(int *values_b, int smallest)
{
	unsigned int	index;

	index = 0;
	while (values_b[index] != smallest)
	{
		index++;
	}
	return (index);
}

/* moves pointer of stack b to number which will be sorted in later. */
int	identifies_best_b(struct s_node **b_liste, int index)
{
	struct s_node	*ptr_b;

	ptr_b = *b_liste;
	set_index(b_liste);
	while (index != ptr_b->index)
	{
		ptr_b = ptr_b->link;
	}
	return (ptr_b->data);
}

/* brings number in b with smallest operations to the top of the stack. */
void	run_best_b(struct s_node **b_liste, int *values_b, int smallest,
		int index)
{
	if (location_value_b(b_liste, values_b, smallest) && index > 0)
	{
		while (index--)
			rotate_b(b_liste);
	}
	if (!location_value_b(b_liste, values_b, smallest))
	{
		index = count_of_nodes(b_liste) - index;
		while (index--)
			reverse_rotate_b(b_liste);
	}
}
