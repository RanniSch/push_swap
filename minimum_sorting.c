/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimum_sorting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 06:33:00 by rschlott          #+#    #+#             */
/*   Updated: 2022/10/19 07:28:04 by rschlott         ###   ########.fr       */
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

/* puts the current Stack a in an array */
int    current_a(struct s_node **a_liste, int *array_a)
{
    struct s_node   *ptr_a;
    int len_a;
    //int b;

    len_a = 0;
    ptr_a = *a_liste;
    //printf("array_a");
    while(ptr_a != NULL)
    {
        array_a[len_a] = ptr_a->data;
        ptr_a = ptr_a->link;
        //printf(" %d", array_a[len_a]);
        len_a++;
    }
    //printf("\n");
    return (len_a - 1);
}

/* checks which number from b needs the smallest amount of opperations to get pushed to a */
void    get_smallest(int *array_a, int len_a, struct s_node **b_liste, int *values_b, int smallest_a, int biggest_a)
{
    struct s_node *ptr_b;
    int     i;
    int     op;
    int     b;
    int     j;

    j = 0;
    b = 0;
    ptr_b = *b_liste;
    while (ptr_b != NULL)
    {
        i = 0;
        op = 0;
        // checks for first and last; EIGENE FUNKTION
        if (ptr_b->data > array_a[i] && ptr_b->data < array_a[i + 1])
            op = 1;
        else if (ptr_b->data < array_a[i] && ptr_b->data > array_a[len_a])
            op = 0;
        else
        {
            if (ptr_b->data != smallest_a && ptr_b->data != biggest_a)
            {
                while (!(ptr_b->data > array_a[i] && ptr_b->data < array_a[i + 1]))
                    i++;
            }
        }
        if (ptr_b->data == smallest_a && ptr_b->data < array_a[i + 1] && array_a[i] > array_a[i + 1])
            op = 1;
        else if (ptr_b->data == smallest_a && ptr_b->data < array_a[i] && array_a[len_a] > array_a[i])
            op = 0;
        else
        {
            if (ptr_b->data == smallest_a)
            {
                while (!(ptr_b->data < array_a[i + 1] && array_a[i] > array_a[i + 1]))
                    i++;
            }
        }
        if (ptr_b->data == biggest_a && ptr_b->data > array_a[i] && array_a[i + 1] < array_a[i])
            op = 1;
        else if (ptr_b->data == biggest_a && ptr_b->data > array_a[len_a] && array_a[i] < array_a[len_a])
            op = 0;
        else
        {
            if (ptr_b->data == biggest_a)
            {
                while (!(ptr_b->data > array_a[i] && array_a[i + 1] < array_a[i]))
                    i++;
            }
        }        
        if (i != 0)
        {
            if (i < ((len_a + 1) / 2))      // len_a nicht als Index sondern als echte Anzahl, daher +1
                op = i + 1;
            else
                op = (len_a + 1) - (i + 1);
            printf("len_a %d op: %d i: %d\n", len_a + 1, op, i);
        }
        if (b > (count_of_nodes(b_liste) / 2))
            values_b[j] = op + (count_of_nodes(b_liste) - b) + 1; // + 1 because of the push
        else
            values_b[j] = op + b + 1;   // + 1 because of the push
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
    if (i < (len / 2) || len == 1)
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
    //printf("index %d\n", index);
    return (index);
}

/* identifies the position where to sort in number from b in stack a */
int sorting_position_a(int *array_a, int len_a, struct s_node **b_liste, int index, int smallest_a, int biggest_a)
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
    //printf("b data %d\n", ptr_b->data);
    while (i < len_a)
    {
        //printf("i %d len_a %d b_data %d array %d\n", i, len_a, ptr_b->data, array_a[i]);
        if (((ptr_b->data > array_a[i] && ptr_b->data < array_a[i + 1]) && i < (len_a / 2)) || len_a == 1)
            checker_a = 1;
        if ((ptr_b->data > array_a[i] && ptr_b->data < array_a[i + 1]) && i >= (len_a / 2))
            checker_a = 2;
        if ((ptr_b->data == smallest_a && ptr_b->data < array_a[i + 1] && array_a[i] > array_a[i + 1] && i < (len_a / 2)) || len_a == 1)
            checker_a = 3;
        if ((ptr_b->data == smallest_a && ptr_b->data < array_a[i + 1] && array_a[i] > array_a[i + 1]) && i >= (len_a / 2))
            checker_a = 4;
        if ((ptr_b->data == biggest_a && ptr_b->data > array_a[i] && array_a[i + 1] < array_a[i] && i < (len_a / 2)) || len_a == 1)
            checker_a = 5;
        if ((ptr_b->data == biggest_a && ptr_b->data > array_a[i] && array_a[i + 1] < array_a[i] && i >= (len_a / 2)))
            checker_a = 6;
        i++;
    }
    //printf("checker a %d\n", checker_a);
    //printf("5/2 = 2: %d\n", 5/2);
    return (checker_a);
}

/* pushes the number from stack b with the smallest amount of operations to stack a */
void    runs_smallest(struct s_node **a_liste, struct s_node **b_liste, int checker_b, unsigned int index, int *array_a, int len_a, int checker_a)
{
    //struct s_node *ptr_a;
    struct s_node *ptr_b;
    int i;

    //ptr_a = *a_liste;
    ptr_b = *b_liste;
    i = 0;
    //printf("index %d\n", index);
    if (checker_b == 0 && index > 0)
    {
        //printf("drin\n");
        while (index--)
        {
            rotate_b(b_liste);
            //ptr_b = *b_liste;
        }
    }
    if (checker_b == 1)
    {
        while (index--)
        {
            reverse_rotate_b(b_liste);
            //ptr_b = *b_liste;
        }
    }
    //now check if rotate or reverse rotate a to push number from b to a!!!   KANN MAN 2 FUNKTIONEN DRAUS MACHEN     
    //Rotate in a and b in the same direction before push = RR or RRR*/
    if (checker_a == 1 || checker_a == 2)
    {
        while(!(ptr_b->data < array_a[i] && ptr_b->data > array_a[len_a]))
        {
            if (checker_a == 1)
                rotate_a(a_liste);
            if (checker_a == 2)
                reverse_rotate_a(a_liste);
            free(array_a);
            current_a(a_liste, array_a);
        }
    }
    if (checker_a == 3 || checker_a == 4)
    {
        while (!(ptr_b->data < array_a[i] && array_a[len_a] > array_a[i]))
        {
            if (checker_a == 3)
                rotate_a(a_liste);
            if (checker_a == 4)
                reverse_rotate_a(a_liste);
            free(array_a);
            current_a(a_liste, array_a);
        }
    }
    if (checker_a == 5 || checker_a == 6)
    {
        while (!(ptr_b->data > array_a[len_a] && array_a[i] < array_a[len_a]))
        {
            if (checker_a == 5)
                rotate_a(a_liste);
            if (checker_a == 6)
                reverse_rotate_a(a_liste);
            free(array_a);
            current_a(a_liste, array_a);
        }
    }
    push_to_a(a_liste, b_liste);
    //ptr_a = *a_liste;
    //ptr_b = *b_liste;
    print_stack(a_liste);       // muss noch raus
    print_stack(b_liste);       // muss noch raus
}

void    final_order(struct s_node **a_liste, int smallest_a, int *array_a, int len_a)
{
    struct s_node *ptr_a;
    int checker_rotate;
    int i;

    i = 0;
    ptr_a = *a_liste;
    printf("smallest a %d", smallest_a);
    while (array_a[i] != smallest_a)
        i++;
    if (i < ((len_a + 1) / 2))
        checker_rotate = 0;
    else
        checker_rotate = 1;
    while (ptr_a->data != smallest_a)
    {
        if (checker_rotate == 0)
            rotate_a(a_liste);
        if (checker_rotate == 1)
            reverse_rotate_a(a_liste);
        ptr_a = *a_liste;
    }
}

/* runs the functions in the correct order. */
int    minimum_sorting(struct s_node **a_liste, struct s_node **b_liste, int smallest_a, int biggest_a)
{
    int *array_a;
    int len_a;
    int *values_b;   // Needs to be freed each time!!!
    int smallest;
    int checker_b;
    int index;
    int checker_a;

    while (b_liste != NULL)
    {
        array_a = (int *)malloc((count_of_nodes(a_liste)) * sizeof(int));
        if (!array_a)
            return(0);
        values_b = (int *)malloc((count_of_nodes(b_liste)) * sizeof(int));
        if (!values_b)
            return(0);
        len_a = current_a(a_liste, array_a);
        get_smallest(array_a, len_a, b_liste, values_b, smallest_a, biggest_a);
        smallest = min(b_liste, values_b);
        checker_b = location_value(b_liste, values_b, smallest);
        index = index_value(values_b, smallest);
        checker_a = sorting_position_a(array_a, len_a, b_liste, index, smallest_a, biggest_a);
        runs_smallest(a_liste, b_liste, checker_b, index, array_a, len_a, checker_a);
        free(array_a);
        free(values_b);
    }
    array_a = (int *)malloc((count_of_nodes(a_liste)) * sizeof(int));
    if (!array_a)
        return(0);
    printf("drin");
    len_a = current_a(a_liste, array_a);
    final_order(a_liste, smallest_a, array_a, len_a);
    free(array_a);
    print_stack(a_liste);
    //print_stack(b_liste);
    return(0);
}
