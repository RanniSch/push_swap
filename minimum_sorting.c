/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimum_sorting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 06:33:00 by rschlott          #+#    #+#             */
/*   Updated: 2022/10/15 10:37:17 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* identifies the smallest number in an array. */
int	min(struct s_node **b_liste, int *values_b)
{
	int	min;
    int len;

    len = count_of_nodes(b_liste);
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
void    get_smallest(int *array_lis, int len_lis, struct s_node **b_liste, int *values_b)
{
    struct s_node *ptr_b;
    int     i;
    int     op;
    int     b;
    int     j;

    i = 0;
    op = 0;
    j = 0;
    b = 0;
    ptr_b = *b_liste;
    while (ptr_b != NULL)
    {
        // checks for first and last 
        if (ptr_b->data < array_lis[i] && ptr_b->data > array_lis[len_lis])
            op = 0;
        // checks for first half
        while (i < (len_lis / 2))
        {
            if (ptr_b->data > array_lis[i] && ptr_b->data < array_lis[i + 1])
                op = i;
            i++;
        }
        // checks for second half
        if (op == 0)
        {
            while (!(ptr_b->data > array_lis[i] && ptr_b->data < array_lis[i + 1]) && i < len_lis)
                i++;
            op = len_lis - i + 1;
        }
        if (b > (count_of_nodes(b_liste) / 2))
            values_b[j] = op + (count_of_nodes(b_liste) - b) + 1; // + 1 because of the push
        else
            values_b[j] = op + b + 1;
        printf("moves %d\n", values_b[j]);
        j++;
        ptr_b = ptr_b->link;
        b++;
    }
}

/* identifies if minimal value is located in the first or second half of stack b */
int location_value(struct s_node **b_liste, int *values_b, int smallest)
{
    int i;
    int checker_b;
    int len;

    i = 0;
    checker_b = 1;
    len = count_of_nodes(b_liste);
    while (values_b[i] != smallest)
        i++;
    if (i < (len / 2))
        checker_b = 0;
    return (checker_b);
}

/* identifies the position of the minimal value in stack b */
int index_value(int *values_b, int smallest)
{
    unsigned int index;

    index = 0;
    while (values_b[index] != smallest)
    {
        index++;
    }
    return (index);
}

/* identifies the position where to sort in number from b in stack a */
int sorting_position_a(int *array_lis, int len_lis, struct s_node **b_liste, int index)
{
    int checker_a;
    int i;
    struct s_node *ptr_b;

    i = 0;
    checker_a = 0;
    ptr_b = *b_liste;
    set_index(b_liste);
    while (index != ptr_b->index)
        ptr_b = ptr_b->link;
    while (i < len_lis)
    {
        if ((ptr_b->data > array_lis[i] && ptr_b->data < array_lis[i + 1]) && i < (len_lis / 2))
            checker_a = 1;
        if ((ptr_b->data > array_lis[i] && ptr_b->data < array_lis[i + 1]) && i >= (len_lis / 2))
            checker_a = 2;
        i++;
    }
    return (checker_a);
}

/* pushes the number from stack b with the smallest amount of operations to stack a */
void    runs_smallest(struct s_node **a_liste, struct s_node **b_liste, int checker_b, unsigned int index, int *array_lis, int checker_a)
{
    //struct s_node *ptr_a;
    struct s_node *ptr_b;
    int i;

    //ptr_a = *a_liste;
    ptr_b = *b_liste;
    i = 0;
    if (checker_b == 0)
    {
        while (index--)
        {
            rotate_b(b_liste);
            ptr_b = *b_liste;
        }
    }
    if (checker_b == 1)
    {
        while (index--)
        {
            reverse_rotate_b(b_liste);
            ptr_b = *b_liste;
        }
    }
    //now check if rotate or reverse rotate a to push number from b to a!!!   KANN MAN 2 FUNKTIONEN DRAUS MACHEN
    //checks for first and last; no need --> will be automatically the third case
    //if (array_lis[i] > ptr_b->data && array_lis[len_lis] < ptr_b->data)
    //{
    //    push_to_a(a_liste, b_liste);
    //    ptr_a = *a_liste;
    //    ptr_b = *b_liste;
    //}      
    //checks for first half || Größte Zahl und kleinste Zahl nicht immer in lis!!! Rotate in a and b before push = rr*/
    if (checker_a == 1)
    {
        while (!(ptr_b->data > array_lis[i] && ptr_b->data < array_lis[i + 1]))
        {
            rotate_a(a_liste);
            //ptr_a = *a_liste;
            i++;
        }
    }
    // checks for second half
    if (checker_a == 2)
    {
        while (!(ptr_b->data > array_lis[i] && ptr_b->data < array_lis[i + 1]))
        {
            reverse_rotate_a(a_liste);
            //ptr_a = *a_liste;
            i++;
        }
    }
    push_to_a(a_liste, b_liste);
    //ptr_a = *a_liste;
    ptr_b = *b_liste;
    print_stack(a_liste);
    print_stack(b_liste);
}

/* runs the functions in the correct order. */
int    *minimum_sorting(struct s_node **a_liste, struct s_node **b_liste, int *array_lis, int len_lis)
{
    int *values_b;   // Needs to be freed each time!!! Ggf. auch array mit Zahlen aus Stack a, könnte einfacher sein!!!
    int smallest;
    int checker_b;
    int index;
    int checker_a;

    while (b_liste != NULL)
    {
        values_b = (int *)malloc((count_of_nodes(b_liste)) * sizeof(int));
        if (!values_b)
            return(NULL);
        get_smallest(array_lis, len_lis, b_liste, values_b);
        smallest = min(b_liste, values_b);
        checker_b = location_value(b_liste, values_b, smallest);
        index = index_value(values_b, smallest);
        checker_a = sorting_position_a(array_lis, len_lis, b_liste, index);
        runs_smallest (a_liste, b_liste, checker_b, index, array_lis, checker_a);
        free(values_b);
        printf("Nodes a: %d Nodes b: %d\n", count_of_nodes(a_liste), count_of_nodes(b_liste));
        //print_stack(a_liste);
        //print_stack(b_liste);
    }
    free(array_lis);
    return(0);
}
