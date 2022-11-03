/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimum_sorting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 06:33:00 by rschlott          #+#    #+#             */
/*   Updated: 2022/11/03 15:36:13 by rschlott         ###   ########.fr       */
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
    return (len_a);
}

/* checks if current b_data is smaller than the smallest entry in Stack a */
bool	min_limit_checker(int *array_a, unsigned int len_a, int b_data)
{
    int min;

	if (!len_a)
		return (0);
    min = array_a[--len_a];
	while (len_a--)
	{
		if (array_a[len_a] < min)
			min = array_a[len_a];
	}
    if (b_data < min)
    {
        return (true);
    }        
	return (false);
}

/* checks if current b_data is bigger than the biggest entry in Stack a */
bool	max_limit_checker(int *array_a, unsigned int len_a, int b_data)
{
	int max;

	if (!len_a)
		return (0);
    max = array_a[--len_a];
	while (len_a--)
	{
		if (array_a[len_a] > max)
			max = array_a[len_a];
	}
    if (b_data > max)
    {
        return (true);
    }        
	return (false);
}

/* checks which number from b needs the smallest amount of opperations to get pushed to a */
void    get_smallest(int *array_a, int len_a, struct s_node **b_liste, int *values_b)
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
        if (ptr_b->data > array_a[i] && ptr_b->data < array_a[i + 1])
            op = 1;
        else if (ptr_b->data < array_a[i] && ptr_b->data > array_a[len_a - 1])
            op = 0;
        else
        {
            if (!min_limit_checker(array_a, len_a, ptr_b->data) && !max_limit_checker(array_a, len_a, ptr_b->data))
            {
                while (!(ptr_b->data > array_a[i] && ptr_b->data < array_a[i + 1]))
                    i++;
            }
        }
        if (min_limit_checker(array_a, len_a, ptr_b->data) && ptr_b->data < array_a[i + 1] && array_a[i] > array_a[i + 1])
            op = 1;
        else if (min_limit_checker(array_a, len_a, ptr_b->data) && ptr_b->data < array_a[i] && array_a[len_a - 1] > array_a[i])
            op = 0;
        else
        {
            if (min_limit_checker(array_a, len_a, ptr_b->data))
            {
                while (!(ptr_b->data < array_a[i + 1] && array_a[i] > array_a[i + 1]))
                    i++;
            }
        }
        if (max_limit_checker(array_a, len_a, ptr_b->data) && ptr_b->data > array_a[i] && array_a[i + 1] < array_a[i])
            op = 1;
        else if (max_limit_checker(array_a, len_a, ptr_b->data) && ptr_b->data > array_a[len_a - 1] && array_a[i] < array_a[len_a - 1])
            op = 0;
        else
        {
            if (max_limit_checker(array_a, len_a, ptr_b->data))
            {
                while (!(ptr_b->data > array_a[i] && array_a[i + 1] < array_a[i]))
                    i++;
            }
        }        
        if (i != 0)
        {
            if (i < ((len_a) / 2))
                op = i + 1;
            else
                op = (len_a) - (i + 1);
        }
        if (b > (count_of_nodes(b_liste) / 2))
            values_b[j] = op + (count_of_nodes(b_liste) - b) + 1;
        else
            values_b[j] = op + b + 1;
        j++;
        ptr_b = ptr_b->link;
        b++;
    }
}

/* identifies if minimal value is located in the first or second half of stack b */
bool    location_value_b(struct s_node **b_liste, int *values_b, int smallest)
{
    int i;
    int len;

    i = 0;
    len = count_of_nodes(b_liste);
    while (values_b[i] != smallest)
        i++;
    if (i < (len / 2) || len == 1)
    {
        return (true);
    }
    return (false);
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
    //printf("index %d smallest %d\n", index, smallest);
    return (index);
}

/* identifies the position where to sort in number from b in stack a */
int sorting_position_a(int *array_a, int len_a, struct s_node **b_liste, int index)
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
    while (i < (len_a - 1))
    {
        //printf("0: %d 1: %d i: %d len_a %d\n", array_a[i], array_a[i + 1], i, len_a);
        if (((ptr_b->data > array_a[i] && ptr_b->data < array_a[i + 1]) && i < ((len_a - 1) / 2)) || len_a == 2)
            checker_a = 1;
        if ((ptr_b->data > array_a[i] && ptr_b->data < array_a[i + 1]) && i >= ((len_a - 1) / 2))
            checker_a = 2;
        if (min_limit_checker(array_a, len_a, ptr_b->data))
        {
            if((ptr_b->data < array_a[i + 1] && array_a[i] > array_a[i + 1] && i < ((len_a - 1) / 2)) || len_a == 2)
                checker_a = 3;
        }            
        if (min_limit_checker(array_a, len_a, ptr_b->data))
        {
            if((ptr_b->data < array_a[i + 1] && array_a[i] > array_a[i + 1]) && i >= ((len_a - 1) / 2))
                checker_a = 4;
        }    
        if (max_limit_checker(array_a, len_a, ptr_b->data))
        {
            if((ptr_b->data > array_a[i] && array_a[i + 1] < array_a[i] && i < ((len_a - 1) / 2)) || len_a == 2)
                checker_a = 5;
        }   
        if (max_limit_checker(array_a, len_a, ptr_b->data))
        {
            if(ptr_b->data > array_a[i] && array_a[i + 1] < array_a[i] && i >= ((len_a - 1) / 2))
                checker_a = 6;
        }            
        i++;
    }
    //printf("i %d len_a %d\n", i, len_a);
    return (checker_a);
}

void    best_b(struct s_node **b_liste, int *values_b, int smallest, int index)
{
    if (location_value_b(b_liste, values_b, smallest) && index > 0)
    {
        while (index--)
            rotate_b(b_liste);
    }
    if (!location_value_b(b_liste, values_b, smallest))
    {
        index = count_of_nodes(b_liste) - index;
        while (index--)
            reverse_rotate_b(b_liste);
    }
}

/* pushes the number from stack b with the smallest amount of operations to stack a */
void    runs_smallest(struct s_node **a_liste, struct s_node **b_liste, int *array_a, int len_a, int checker_a)
{
    struct s_node *ptr_b;

    ptr_b = *b_liste;
    //printf("b %d\n", ptr_b->data);
    //now check if rotate or reverse rotate a to push number from b to a!!!   KANN MAN 2 FUNKTIONEN DRAUS MACHEN     
    //Rotate in a and b in the same direction before push = RR or RRR*/
    if (checker_a == 1)
    {
        while(!(ptr_b->data < array_a[0] && ptr_b->data > array_a[len_a - 1]))
        {
            //printf("b_data %d a(i) %d a(len) %d\n", ptr_b->data, array_a[i], array_a[len_a]);
            rotate_a(a_liste);
            rotate_array_a(array_a, len_a);
        }
    }
    if (checker_a == 2)
    {
        //printf("b data %d\n", ptr_b->data);
        while(!(ptr_b->data < array_a[0] && ptr_b->data > array_a[len_a - 1]))
        {
            //printf("b_data %d a(i) %d a(len) %d\n", ptr_b->data, array_a[i], array_a[len_a]);
            //printf("b %d a(i) %d a(len) %d\n", ptr_b->data, array_a[i], array_a[len_a]);
            reverse_rotate_a(a_liste);
            reverse_rotate_array_a(array_a, len_a);
            //printf("b %d a(i) %d a(len) %d\n", ptr_b->data, array_a[i], array_a[len_a]);  // array_a != a_liste --> checken!!!  ggf. Zeile 275 unnötig!!!
        }
    }
    if (checker_a == 3)
    {
        while (!(ptr_b->data < array_a[0] && array_a[len_a - 1] > array_a[0]))
        {
            rotate_a(a_liste);
            rotate_array_a(array_a, len_a);
        }
    }
    if (checker_a == 4)
    {
        while (!(ptr_b->data < array_a[0] && array_a[len_a - 1] > array_a[0]))
        {
            reverse_rotate_a(a_liste);
            reverse_rotate_array_a(array_a, len_a);
        }
    }
    if (checker_a == 5)
    {
        while (!(ptr_b->data > array_a[len_a - 1] && array_a[0] < array_a[len_a - 1]))
        {
            rotate_a(a_liste);
            rotate_array_a(array_a, len_a);
        }
    }
        if (checker_a == 6)
    {
        while (!(ptr_b->data > array_a[len_a - 1] && array_a[0] < array_a[len_a - 1]))
        {
            reverse_rotate_a(a_liste);
            reverse_rotate_array_a(array_a, len_a);
        }
    }
    push_to_a(a_liste, b_liste);
    /*if (ptr_b == NULL)
    {
        free(ptr_b);
        free(b_liste);
    }*/
    //print_stack(a_liste);       // muss noch raus
    //print_stack(b_liste);       // muss noch raus
}

void    the_process(struct s_node **a_liste, struct s_node **b_liste, int *array_a, int *values_b)
{
    int len_a;
    int smallest;
    int index;
    int checker_a;

    len_a = current_a(a_liste, array_a);
    get_smallest(array_a, len_a, b_liste, values_b);
    smallest = min(b_liste, values_b);
    //printf("smallest val %d\n", smallest);
    index = index_value(values_b, smallest);
    //printf("index %d\n", index);
    checker_a = sorting_position_a(array_a, len_a, b_liste, index);
    //printf("checker_a %d b %d\n", checker_a, ptr_b->data);
    best_b(b_liste, values_b, smallest, index);
    runs_smallest(a_liste, b_liste, array_a, len_a, checker_a);
}

void    final_order(struct s_node **a_liste, int smallest_a)
{
    struct s_node *ptr_a;
    int checker_rotate;
    int i;

    i = 0;
    ptr_a = *a_liste;
    while (ptr_a->data != smallest_a && ptr_a != NULL)
    {
        ptr_a = ptr_a->link;
        i++;
    }   
    if (i < (count_of_nodes(a_liste) / 2))
        checker_rotate = 0;
    else
        checker_rotate = 1;
    ptr_a = *a_liste;
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
int    minimum_sorting(struct s_node **a_liste, struct s_node **b_liste, int smallest_a)
{
    int *array_a;
    //int len_a;
    int *values_b;
    //int smallest;
    //int index;
    //int checker_a;
    struct s_node *ptr_b;

    ptr_b = *b_liste;
    while (ptr_b != NULL)
    {
        array_a = (int *)malloc((count_of_nodes(a_liste)) * sizeof(int));
        values_b = (int *)malloc((count_of_nodes(b_liste)) * sizeof(int));
        if (!values_b || !array_a)
            return(0);
        the_process(a_liste, b_liste, array_a, values_b);
        free(array_a);
        free(values_b);
        ptr_b = *b_liste;
    }
    final_order(a_liste, smallest_a);
    //print_stack(a_liste);
    return(0);
}
