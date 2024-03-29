/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 17:31:56 by rschlott          #+#    #+#             */
/*   Updated: 2022/11/06 12:39:09 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

bool	sorted_numbers(struct s_node **a_liste)
{
	int				i;
	struct s_node	*ptr_a;

	i = 0;
	ptr_a = *a_liste;
	while (ptr_a->link != NULL && ptr_a->data < ptr_a->link->data)
	{
		ptr_a = ptr_a->link;
		i++;
	}
	i++;
	if (i == count_of_nodes(a_liste))
		return (true);
	return (false);
}

void	shorten_stack_a(struct s_node **a_liste, struct s_node **b_liste)
{
	if (count_of_nodes(a_liste) == 4)
		push_to_b(a_liste, b_liste);
	if (count_of_nodes(a_liste) == 5)
	{
		push_to_b(a_liste, b_liste);
		push_to_b(a_liste, b_liste);
	}
}

int	little_input(struct s_node **a_liste, struct s_node **b_liste,
		int smallest_a)
{
	int	*array_a;
	int	len_a;
	int	count;

	if (count_of_nodes(a_liste) == 2)
		two_arguments(a_liste);
	else if (!sorted_numbers(a_liste))
	{
		count = count_of_nodes(a_liste);
		shorten_stack_a(a_liste, b_liste);
		array_a = (int *)malloc((count_of_nodes(a_liste)) * sizeof(int));
		if (!array_a)
			return (0);
		len_a = current_a(a_liste, array_a);
		three_arguments(a_liste, array_a, len_a);
		free(array_a);
		if (count == 4)
			four_arguments(a_liste, b_liste);
		if (count == 5)
			five_arguments(a_liste, b_liste, smallest_a);
	}
	return (0);
}
