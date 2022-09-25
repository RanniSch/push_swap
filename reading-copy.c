/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading-copy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 13:23:03 by rschlott          #+#    #+#             */
/*   Updated: 2022/09/25 09:40:21 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* converts char to int */
int ft_atoi(const char *str)
{
	int			sign;
	long int	convert;

	sign = 1;
	convert = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = sign * (-1);
		str++;
	}
	while (*str && *str > 47 && *str < 58)
	{
		convert = (convert * 10) + *str - '0';
		str++;
		if (convert > 2147483647 && sign == 1)
			return (-1);
		if (convert > 2147483648 && sign == -1)
			return (0);
	}
	return (convert * sign);
}

/* adds a new node to the list */
void    add_at_end(struct node **a_liste, int data)
{
    struct node *ptr;
    struct node *current;

    ptr = *a_liste;
    current = (struct node *)malloc(sizeof(struct node));
    current->data = data;
    current->link = NULL;
    if (ptr != NULL)
    {
        while(ptr->link != NULL)
        {
            ptr = ptr->link;
        }
        ptr->link = current;
    }
    else
        *a_liste = current;    
}

/* adds an index to each node; one node now has the value of the data and the value of the index */
void    set_index(struct node **a_liste)
{
    struct node *ptr;
    int i;
    
    ptr = *a_liste;
    i = 0;
    if (ptr != NULL)
    {    
        while(ptr != NULL)
        {
            ptr->index = i;
            ptr = ptr->link;
            i++;
        }

    } 
}

/* counts the number of nodes */
int    count_of_nodes(struct node **liste)
{
    int count;
    
    count = 0;
    if (*liste == NULL)
        printf("Stack is empty");
    struct node *ptr = NULL;
    ptr = *liste;
    while (ptr != NULL)
    {
        count++;
        ptr = ptr->link;
    }
    return(count);
}

/* print the data of a linked list */
void    print_stack(struct node **liste)
{
    if(*liste == NULL)
        printf("Linked List is empty");
    struct node *ptr = NULL;
    ptr = *liste;
    while(ptr != NULL)
    {
        printf("%d ", ptr->data);       // insert printf function!!!!!!!!!!!
        ptr = ptr->link;
    }
    printf("\n");
    //printf("\nnumber of nodes: %d\n", count_of_nodes(liste));       // insert printf function!!!!!!!!!!!   
}

/* receiving arguments from user input */
void ft_stack_receive(int argc, char **argv, struct node **a_liste)
{
    int i;

    i = 1;
    /* argc zählt den ersten String in argv mit und der ist immer ./a.out */
    while (i < argc)
    {
        add_at_end(a_liste, ft_atoi(argv[i]));
        i++;
    }
}

int main(int argc, char **argv)
{ 
    struct node *a_liste;
    struct node *b_liste;
    
    a_liste = NULL;
    b_liste = NULL;
    /* &a_liste gibt die Adresse des Pointers, der zur Liste zeigt durch = double pointer */
    ft_stack_receive(argc, argv, &a_liste);
    print_stack(&a_liste);
    set_index(&a_liste);
    ft_lis_process(&a_liste, &b_liste, count_of_nodes(&a_liste));
    //swap_elements(&a_liste);
    //print_stack(&a_liste);
    //rotate_elements(&a_liste);
    //print_stack(&a_liste);
    //rotate_rev_elements(&a_liste);
    //print_stack(&a_liste);
    //push_first_element(&a_liste, &b_liste);
    //print_stack(&a_liste);
    //print_stack(&b_liste);
    //push_first_element(&a_liste, &b_liste);
    //print_stack(&a_liste);
    //print_stack(&b_liste);
    //swap_a_b(&a_liste, &b_liste);
    //print_stack(&a_liste);
    //print_stack(&b_liste);
    //rotate_a_b(&a_liste, &b_liste);
    //print_stack(&a_liste);
    //print_stack(&b_liste);
    return(0);
}
