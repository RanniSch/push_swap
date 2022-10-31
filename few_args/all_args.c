/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 18:04:11 by rschlott          #+#    #+#             */
/*   Updated: 2022/10/31 05:04:42 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	two_arguments(struct s_node **a_liste)
{
	struct s_node	*ptr_a;

	ptr_a = *a_liste;
	if (ptr_a->data > ptr_a->link->data)
		swap_a(a_liste);
}

void	three_arguments(struct s_node **a_liste, int *array_a, int len_a)
{
	if (array_a[len_a - 3] > array_a[len_a - 2]
		&& array_a[len_a - 2] > array_a[len_a - 1])
	{
		swap_a(a_liste);
		reverse_rotate_a(a_liste);
	}
	if (array_a[len_a - 3] > array_a[len_a - 2]
		&& array_a[len_a - 2] < array_a[len_a - 1])
	{
		if (array_a[len_a - 3] > array_a[len_a - 1])
			rotate_a(a_liste);
		else
			swap_a(a_liste);
	}
	if (array_a[len_a - 3] < array_a[len_a - 2]
		&& array_a[len_a - 2] > array_a[len_a - 1])
	{
		reverse_rotate_a(a_liste);
		if (array_a[len_a - 3] < array_a[len_a - 1])
			swap_a(a_liste);
	}
}

void	run_four_arguments(struct s_node **a_liste, struct s_node **b_liste,
		int *array_a)
{
	struct s_node	*ptr_b;
	int				biggest_a;

	ptr_b = *b_liste;
	biggest_a = biggest_in_a(a_liste);
	if (ptr_b->data > array_a[1] && ptr_b->data < array_a[2])
	{
		reverse_rotate_a(a_liste);
		push_to_a(a_liste, b_liste);
		rotate_a(a_liste);
		rotate_a(a_liste);
	}
	else
		push_to_a(a_liste, b_liste);
	if (ptr_b->data > biggest_a)
		rotate_a(a_liste);
	if (ptr_b->data > array_a[0] && ptr_b->data < array_a[1])
		swap_a(a_liste);
}

int	four_arguments(struct s_node **a_liste, struct s_node **b_liste)
{
	int	*array_a;

	array_a = (int *)malloc((count_of_nodes(a_liste)) * sizeof(int));
	if (!array_a)
		return (0);
	current_a(a_liste, array_a);
	run_four_arguments(a_liste, b_liste, array_a);
	free(array_a);
	return (0);
}

int	five_arguments(struct s_node **a_liste, struct s_node **b_liste,
		int smallest_a)
{
	int				*array_a;
	int				*values_b;
	struct s_node	*ptr_b;

	ptr_b = *b_liste;
	while (ptr_b != NULL)
	{
		array_a = (int *)malloc((count_of_nodes(a_liste)) * sizeof(int));
		if (!array_a)
			return (0);
		values_b = (int *)malloc((count_of_nodes(b_liste)) * sizeof(int));
		if (!values_b)
			return (0);
		run_five_arguments(a_liste, b_liste, array_a, values_b);
		free(array_a);
		free(values_b);
		ptr_b = *b_liste;
	}
	final_order(a_liste, smallest_a);
	return (0);
}
