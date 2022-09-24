/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 13:23:47 by rschlott          #+#    #+#             */
/*   Updated: 2022/09/24 12:14:51 by rschlott         ###   ########.fr       */
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
void    ft_lis_process(struct node **a_liste, struct node **b_liste, struct node **ptr_lis, int count)
{
    int length[count];
    int subsequence[count];

    length_initializer_lis(&subsequence[0], &length[0], a_liste);
    longest_increasing_subsequence(a_liste, &subsequence[0], &length[0]);
    correct_subsequence(a_liste, ptr_lis, &subsequence[0], &length[0]);
    only_subsequence_in_a(a_liste, b_liste, ptr_lis);
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
    /* checks if function works correct
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
    printf("\n");*/
}

void    correct_subsequence(struct node **a_liste, struct node **ptr_lis, int *subsequence, int *length)
{
    int biggest_num;
    struct node *ptr;
    int i;

    ptr = *a_liste;
    i = 0;
    biggest_num = max(length, count_of_nodes(a_liste));
    while (length[ptr->index] != biggest_num)
    {
        ptr = ptr->link;
        i++;
    }
    push_first_element(&ptr, ptr_lis);
    //printf("num: %d index: %d sub_data %d\n", ptr_lis->data, ptr_lis->index, subsequence[i]);
    while (subsequence[i] != 0)
    {
        ptr = *a_liste;
        while (ptr->index != subsequence[i])
            ptr = ptr->link;
        i = 0;
        while (i < ptr->index)
            i++;
        push_first_element(&ptr, ptr_lis);
        //printf("num: %d index: %d sub_data %d\n", ptr_lis->data, ptr_lis->index, subsequence[i]);
    }
    print_stack(ptr_lis);
}

void    only_subsequence_in_a(struct node **a_liste, struct node **b_liste, struct node **ptr_lis)
{
    struct node *ptr_a;
    struct node *ptr_l;

    ptr_a = *a_liste;
    ptr_l = *ptr_lis;
    if (ptr_l != NULL)
    {
        while (ptr_l->link != NULL)
        {
            while (ptr_a->data != ptr_l->data)
                push_first_element(&ptr_a, b_liste);
            if (ptr_a->data == ptr_l->data)
                rotate_elements(&ptr_a);
            ptr_l = ptr_l->link;
        }
    }
    print_stack(a_liste);
    print_stack(b_liste);
}
