/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 13:23:47 by rschlott          #+#    #+#             */
/*   Updated: 2022/09/23 17:59:50 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* identifies the biggest number in an array. */
int		max(int *tab, unsigned int len)
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
	return(max);
}

/* creates an array "length" and fills it with ones. Creates an array "subsequence" and fills it with zeroes.
Both have the same size as the list. */
void    length_initializer_lis(int *subsequence, int *length, struct node **a_liste)
{
    int i;

    i = 0;
    while (i < count_of_nodes(a_liste))
    {
        subsequence[i] = 0;
        length[i] = 1;
        i++;
    }   
}

/* runs the functions in the correct order. */
void    ft_lis_process(struct node **a_liste, int count)
{
    int length[count];
    int subsequence[count];

    length_initializer_lis(&subsequence[0], &length[0], a_liste);
    longest_increasing_subsequence(a_liste, &subsequence[0], &length[0]);
}

/* Identify longest increasing subsequence. 
The highest number of length is at the same index as the biggest number of lis. At the same index, 
the number of the subsequence shows to which index to jump next, to get the second biggest number of lis and so on. */
void    longest_increasing_subsequence(struct node **a_liste, int *subsequence, int *length)
{
    struct node *walker;
    struct node *iterator;

    iterator = *a_liste;
    iterator = iterator->link;
    while (iterator != NULL)
    {
        walker = *a_liste;
        while (walker->index < iterator->index)
        {
            if (walker->data < iterator->data)
            {
                length[iterator->index] = length[walker->index] + 1;
                subsequence[iterator->index] = walker->index;
            }            
            walker = walker->link;
        }
        iterator = iterator->link;
    }
    /* checks if function works correct */
    int i = 0;
    printf("subseq: ");
    while (i <= 5)
    {
        printf("%d ", subsequence[i]);
        i++;
    }
    printf("\nlength: ");
    i = 0;
    while (i <= 5)
    {
        printf("%d ", length[i]);
        i++;
    }    
    printf("\n");
    correct_subsequence(a_liste, &subsequence[0], &length[0]);
}

void    correct_subsequence(struct node **a_liste, int *subsequence, int *length)
{
    int biggest_num;
    struct node *ptr;

    ptr = *a_liste;
    biggest_num = max(length, count_of_nodes(a_liste));
    while (length[ptr->index] != biggest_num)
    {
        ptr = ptr->link;
        subsequence++;
    }        
    printf("num: %d index: %d sub_data %d\n", ptr->data, ptr->index, *subsequence);
    
    ptr = *a_liste;
    while (ptr->index != *subsequence)
        ptr = ptr->link;
    if (*subsequence && subsequence != 0)
        subsequence--;  // until sub_index = lis_index  
    printf("num: %d index: %d sub_data %d\n", ptr->data, ptr->index, *subsequence);
    ptr = *a_liste;
    while (ptr->index != *subsequence)
        ptr = ptr->link;
    if (*subsequence && subsequence != 0)
        subsequence--; // until sub_index = lis_index
    if (*subsequence && subsequence != 0)
        subsequence--; // until sub_index = lis_index
    printf("num: %d index: %d sub_data %d\n", ptr->data, ptr->index, *subsequence);
    ptr = *a_liste;
    while (ptr->index != *subsequence)
        ptr = ptr->link;
    if (*subsequence && subsequence != 0)
        subsequence--; // until sub_index = lis_index
    if (*subsequence && subsequence != 0)
        subsequence--; // until sub_index = lis_index
    printf("num: %d index: %d sub_data %d\n", ptr->data, ptr->index, *subsequence);
}
