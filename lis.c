/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 13:23:47 by rschlott          #+#    #+#             */
/*   Updated: 2022/09/24 15:57:58 by rschlott         ###   ########.fr       */
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
void    ft_lis_process(struct node **a_liste, struct node **b_liste, int count)
{
    int length[count];
    int subsequence[count];
    int array_lis[count];

    length_initializer_lis(&subsequence[0], &length[0], a_liste);
    longest_increasing_subsequence(a_liste, &subsequence[0], &length[0]);
    //correct_subsequence(a_liste, &subsequence[0], &length[0], &array_lis[0]);
    only_subsequence_in_a(a_liste, b_liste, &array_lis[0], correct_subsequence(a_liste, &subsequence[0], &length[0], &array_lis[0]));
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

int    correct_subsequence(struct node **a_liste, int *subsequence, int *length, int *array_lis)
{
    int biggest_num;
    struct node *ptr;
    int i;
    int len_lis;

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
    printf("lis: %d ", array_lis[len_lis]);
    len_lis++;
    //printf("num: %d index: %d sub_data %d\n", ptr_lis->data, ptr_lis->index, subsequence[i]);
    while (subsequence[i] != 0)
    {
        ptr = *a_liste;
        while (ptr->index != subsequence[i])
            ptr = ptr->link;
        i = 0;
        while (i < ptr->index)
            i++;
        array_lis[len_lis] = ptr->data;
        printf("%d ", array_lis[len_lis]);
        len_lis++;
        //printf("num: %d index: %d sub_data %d\n", ptr_lis->data, ptr_lis->index, subsequence[i]);
    }
    printf("\nlen_lis: %d\n", len_lis);
    print_stack(a_liste);
    return (len_lis);
}

void    only_subsequence_in_a(struct node **a_liste, struct node **b_liste, int *array_lis, int len_lis)
{
    struct node *ptr_a;

    ptr_a = *a_liste;
    if (ptr_a != NULL)
    {
        while (ptr_a->link != NULL && array_lis[len_lis])
        {
            ptr_a = *a_liste;
            if (ptr_a->data != array_lis[len_lis])
            {
                push_first_element(a_liste, b_liste);
            }
            else
            {
                rotate_elements(a_liste);
                len_lis--;
            }
        }
    }
    print_stack(a_liste);
    print_stack(b_liste);
}
