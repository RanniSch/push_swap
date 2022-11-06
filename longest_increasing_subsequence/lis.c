/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 13:23:47 by rschlott          #+#    #+#             */
/*   Updated: 2022/11/06 10:47:11 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Identifies longest increasing subsequence. Highest num of length is at same 
index as biggest number of lis. At this index, number of subsequence shows 
to which index to jump next, to get the second biggest number of lis... */
void	longest_increasing_subsequence(struct s_node **a_liste,
		int *subsequence, int *length)
{
	struct s_node	*walker;
	struct s_node	*iterator;

	iterator = *a_liste;
	iterator = iterator->link;
	while (iterator != NULL)
	{
		walker = *a_liste;
		while (walker->index < iterator->index)
		{
			if (walker->data < iterator->data)
			{
				if (length[iterator->index] <= length[walker->index] + 1)
				{
					length[iterator->index] = length[walker->index] + 1;
					subsequence[iterator->index] = walker->index;
				}
			}
			walker = walker->link;
		}
		iterator = iterator->link;
	}
}

/* Puts the longest increasing subsequence in one array -> array_lis */
int	correct_subsequence(struct s_node **a_liste, int *subsequence, int *length,
		int *array_lis)
{
	struct s_node	*ptr;
	int				i;
	int				len_lis;

	ptr = *a_liste;
	i = 0;
	len_lis = 0;
	while (length[ptr->index] != max(length, count_of_nodes(a_liste)))
	{
		ptr = ptr->link;
		i++;
	}
	array_lis[len_lis] = ptr->data;
	while (ptr->index != 0 && length[ptr->index] != 1)
	{
		ptr = *a_liste;
		while (ptr->index != subsequence[i])
			ptr = ptr->link;
		i = 0;
		while (i < ptr->index)
			i++;
		array_lis[++len_lis] = ptr->data;
	}
	return (len_lis + 1);
}

/* Uses rotate & push until all numbers that aren't in lis are in stack b */
void	only_subsequence_in_a(struct s_node **a_liste, struct s_node **b_liste,
		int *array_lis, int len_lis)
{
	struct s_node	*ptr_a;
	int				count;
	int				len_anti;

	ptr_a = *a_liste;
	count = count_of_nodes(a_liste);
	len_anti = count - len_lis;
	while (count > 0 && len_lis >= 0 && len_anti >= 0)
	{
		if (ptr_a->data == array_lis[len_lis - 1])
		{
			rotate_a(a_liste);
			len_lis--;
		}
		else
		{
			push_to_b(a_liste, b_liste);
			len_anti--;
		}
		count--;
		ptr_a = *a_liste;
	}
}

/* runs the functions in the correct order. */
int	lis_process(struct s_node **a_liste, struct s_node **b_liste, int count)
{
	int	*subsequence;
	int	*length;
	int	*array_lis;
	int	len_lis;

	subsequence = (int *)malloc(count * sizeof(int));
	if (subsequence == NULL)
		return (0);
	length = (int *)malloc(count * sizeof(int));
	if (length == NULL)
		return (0);
	array_lis = (int *)malloc(count * sizeof(int));
	if (array_lis == NULL)
		return (0);
	length_initializer_lis(subsequence, length, count);
	longest_increasing_subsequence(a_liste, subsequence, length);
	len_lis = correct_subsequence(a_liste, subsequence, length, array_lis);
	free(subsequence);
	free(length);
	only_subsequence_in_a(a_liste, b_liste, array_lis, len_lis);
	free(array_lis);
	return (0);
}
