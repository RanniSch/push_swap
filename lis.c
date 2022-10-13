/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 13:23:47 by rschlott          #+#    #+#             */
/*   Updated: 2022/10/13 10:04:54 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* identifies the biggest number in an array. */
int	max(int *tab, unsigned int len)
{
	int	max;

	if (!len)
		return (0);
	max = tab[--len];
	while (len--)
	{
		if (tab[len] > max)
			max = tab[len];
	}
	return (max);
}

/* creates an array "length" and fills it with ones. Creates an array "subsequence" and fills it with zeroes.
Both have the same size as the list. */
void	length_initializer_lis(int *subsequence, int *length, struct s_node **a_liste)
{
	int	i;

	i = 0;
	while (i < count_of_nodes(a_liste))
	{
		subsequence[i] = 0;
		length[i] = 1;
		i++;
	}
}

/* runs the functions in the correct order. */
int	*lis_process(struct s_node **a_liste, struct s_node **b_liste, int count)
{
	int	*subsequence;
	int *length;
	int	*array_lis;
    int len_lis;
	//int	*anti_lis;
    
	subsequence = (int *)malloc(count * sizeof(int));
	if (subsequence == NULL)
		return(NULL);
	length = (int *)malloc(count * sizeof(int));
	if (length == NULL)
		return(NULL);
	array_lis = (int *)malloc(count * sizeof(int));
	if (array_lis == NULL)
		return(NULL);
	//anti_lis = (int *)malloc(count * sizeof(int));
	//if (anti_lis == NULL)
		//return(NULL);
	length_initializer_lis(subsequence, length, a_liste);
	longest_increasing_subsequence(a_liste, subsequence, length);
	len_lis = correct_subsequence(a_liste, subsequence, length, array_lis);
	//anti_subsequence(a_liste, array_lis, anti_lis, len_lis);
	only_subsequence_in_a(a_liste, b_liste, array_lis, len_lis);
	return(0);
}

/* Identifies longest increasing subsequence. 
The highest number of length is at the same index as the biggest number of lis. At the same index,
the number of the subsequence shows to which index to jump next,
to get the second biggest number of lis and so on. */
void	longest_increasing_subsequence(struct s_node **a_liste, int *subsequence, int *length)
{
	struct s_node	*walker;
	struct s_node	*iterator;
	//int				i;

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
	/* checks if function works correct */
	/*i = 0;
	printf("subseq: ");
	while (i < count_of_nodes(a_liste))
	{
		printf("%d ", subsequence[i]);
		i++;
	}
	printf("\nlength: ");
	i = 0;
	while (i < count_of_nodes(a_liste))
	{
		printf("%d ", length[i]);
		i++;
	}
	printf("\n");*/
}

/* Puts the longest increasing subsequence in one array -> array_lis */
int	correct_subsequence(struct s_node **a_liste, int *subsequence, int *length, int *array_lis)
{
	int				biggest_num;
	struct s_node	*ptr;
	int				i;
	int				len_lis;

	ptr = *a_liste;
	i = 0;
	len_lis = 0;
	biggest_num = max(length, count_of_nodes(a_liste));
	while (length[ptr->index] != biggest_num)
	{
		ptr = ptr->link;
		i++;
	}
	array_lis[len_lis] = ptr->data;
	//printf("array: %d\n", array_lis[len_lis]);
	len_lis++;
	while (ptr->index != 0 && length[ptr->index] != 1)
	{
		ptr = *a_liste;
		while (ptr->index != subsequence[i])
			ptr = ptr->link;
		i = 0;
		while (i < ptr->index)
			i++;
		array_lis[len_lis] = ptr->data;
		//printf("array: %d\n", array_lis[len_lis]);
		len_lis++;
	}
	free (subsequence);
	free (length);
	return (len_lis - 1);
}

/* puts all numbers that are not in the lis in the array anti_lis. Function works, but I don't need it!
int	anti_subsequence(struct s_node **a_liste, int *array_lis, int *anti_lis, int len_lis)
{
	struct s_node *ptr;
	int	len_anti;

	len_anti = 0;
	ptr = *a_liste;
	while (ptr != NULL)
	{
		if (array_lis[len_lis] != ptr->data)
		{
			anti_lis[len_anti] = ptr->data;
			printf("anti lis: %d\n", anti_lis[len_anti]);
			len_anti++;
		}
		if (array_lis[len_lis] == ptr->data)
		{
			len_lis--;
		}
		ptr = ptr->link;
	}
	printf("len anti %d\n", len_anti);
	return (len_anti);
}*/

/* Uses rotate and push until all numbers that are not in the lis are in stack b */
void	only_subsequence_in_a(struct s_node **a_liste, struct s_node **b_liste, int *array_lis, int len_lis)
{
	struct s_node *ptr_a;
    int count;
	int len_anti;

	ptr_a = *a_liste;
    count = count_of_nodes(a_liste);
	len_anti = count - len_lis - 1;
	while (count > 0 && len_anti > 0)
	{
		if (ptr_a->data == array_lis[len_lis])
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
	free (array_lis);
	print_stack(a_liste);
	print_stack(b_liste);
}

/* Uses rotate and push until all numbers that are not in the lis are in stack b. It works but needs more operations. 
void	only_subsequence_in_a(struct s_node **a_liste, struct s_node **b_liste, int *array_lis, int len_lis)
{
	struct s_node *ptr_a;
    int count;

	ptr_a = *a_liste;
    count = count_of_nodes(a_liste);
	while (count > 0)
	{
		//printf("count: %d\n", count);
		if (ptr_a->data == array_lis[len_lis])
		{
			rotate_a(a_liste);
			len_lis--;
            count--;
		}
		else
        {
            push_to_b(a_liste, b_liste);
            count--;
        }
		ptr_a = *a_liste;
	}
	free (array_lis);
	print_stack(a_liste);
	print_stack(b_liste);
}*/
