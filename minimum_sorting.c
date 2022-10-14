/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimum_sorting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 06:33:00 by rschlott          #+#    #+#             */
/*   Updated: 2022/10/14 07:25:51 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* identifies the smallest number in an array. */
int	min(int *values_b, unsigned int len)
{
	int	min;

	if (!len)
		return (0);
	min = values_b[--len];
	while (len--)
	{
		if (values_b[len] < min)
			min = values_b[len];
	}
	return (min);
}

/* checks which number from b needs the smallest amount of opperations to get pushed to a */
int get_smallest(struct s_node **a_liste, struct s_node **b_liste, int *values_b)
{
    struct s_node *ptr_a;
    struct s_node *ptr_b;
    int     op;
    int     b;
    int     len_val;

    op = 0;
    b = 0;
    len_val = 0;
    ptr_a = *a_liste;
    ptr_b = *b_liste;
    set_index(a_liste);
    while (ptr_b != NULL)
    {
        while (ptr_a->index < (count_of_nodes(a_liste) / 2))
        {
            //printf("data %d next %d\n", ptr_a->data, ptr_a->link->data);
            if (ptr_b->data > ptr_a->data && ptr_b->data < ptr_a->link->data)
            {
                op++;
                ptr_a = *a_liste;
                while (ptr_b->data > ptr_a->data)
                {
                    op++;
                    ptr_a = ptr_a->link;
                }
            }
            ptr_a = ptr_a->link;
        }
        if (op == 0)            // CHECK IF NUMBER COMES ON TOP!!!
        {
            ptr_a = *a_liste;
            while (ptr_b->data > ptr_a->data)
            {
                ptr_a = ptr_a->link;
            }
            op = count_of_nodes(a_liste) - ptr_a->index + 1;
        }
        values_b[len_val] = op + b;
        printf("moves %d\n", values_b[i]);
        len_val++;
        b++;
        ptr_b = ptr_b->link;
    }
    return(len_val - 1);
}

/* identifies if value is located in the first or second half */
int location_value(int *pointer_array, int len_val, int value)
{
    int i;
    int checker;

    i = 0;
    checker = 1;
    while (pointer_array[i] != value)
    {
        i++;
    }
    if (i < (len_val / 2))
        checker = 0;
    return (checker);
}

/* identifies the position of the value */
int index_value(int *pointer_array, int value)
{
    int index;

    index = 0;
    while (pointer_array[i] != value)
    {
        index++;
    }
    return (index);
}

/* pushes the number from stack b with the smallest amount of operations to stack a */
void    runs_smallest(struct node **a_liste, struct node **b_liste, int checker, int index)
{
    struct s_node *ptr_a;
    struct s_node *ptr_b;

    ptr_a = *a_liste;
    ptr_b = *b_liste;
    set_index(b_liste);
    if (checker == 0)
    {
        while (index != ptr_b->index)       // index -> smallest value; which number in list at same index?
        {
            rotate_b(b_liste);          // wegen Startpointer schauen, wie bei lis gemacht
        }
    }
    if (checker == 1)
    {
        while (index != ptr_b->index)       // index -> smallest value; which number in list at same index?
        {
            reverse_rotate_b(b_liste);          // wegen Startpointer schauen, wie bei lis gemacht
        }
    }
    // now check if rotate or reverse rotate a to push number from b to a!!!
}

/* runs the functions in the correct order. */
int    *minimum_sorting(struct s_node **a_liste, struct s_node **b_liste)
{
    int *values_b;   // Needs to be freed each time!!! Ggf. auch array mit Zahlen aus Stack a, könnte einfacher sein!!!
    int len_val;
    int smallest;
    int checker;
    int index;

    values_b = (int *)malloc((count_of_nodes(b_liste)) * sizeof(int));
    if (!values_b)
        return(NULL);
    len_val = get_smallest(a_liste, b_liste, values_b);
    smallest = min(values_b, len_val);
    checker = location_value(values_b, len_val, smallest);
    index = index_value(pointer_array, smallest);
    runs_smallest (a_liste, b_liste, checker, index);
    //printf("Nodes a: %d Nodes b: %d\n", count_of_nodes(a_liste), count_of_nodes(b_liste));
    return(0);
}
