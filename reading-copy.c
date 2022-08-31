/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading-copy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 13:23:03 by rschlott          #+#    #+#             */
/*   Updated: 2022/08/31 10:34:29 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* converts char to int */
int	ft_atoi(const char *str)
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
void    add_at_end(struct node **liste, int data)
{
    struct node *ptr;
    struct node *current;

    ptr = *liste;
    current = (struct node *)malloc(sizeof(struct node));
    current->data = data;
    current->link = NULL;
    while(ptr->link != NULL)
    {
        ptr = ptr->link;
    }
    ptr->link = current;
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
    printf("\nnumber of nodes: %d\n", count_of_nodes(liste));       // insert printf function!!!!!!!!!!!   
}

/* swap function: Swap the first two elements at the top of the stack */
void swap_elements(struct node **liste)
{
    int count;
    struct node *temp2;
    struct node *temp1;
    struct node *ptr;

    ptr = *liste;
    count = count_of_nodes(liste);
    if (*liste != NULL && count > 1)          // später error handling an eigener Stelle; head = NULL abbruch; count = 1 ausdrucken
    {
        temp1 = ptr;
        temp2 = temp1->link;
        printf("temp1: %d\n", temp1->data);
        printf("temp1: %p\n", temp1);
        printf("temp2: %d\n", temp2->data);
        printf("temp2: %p\n", temp2);
        temp1->link = temp2->link;     // 2000 link wird zu 3000 link
        printf("temp1 neu: %d\n", temp1->data);
        temp2->link = ptr->link;     // 3000 link wird zu 1000 link
        ptr->link = temp2;           // erste Node zeigt zur zweiten Node
        liste = &temp2;
    }
    //return (head);
}

/* receiving arguments from user input */
void ft_stack_receive(int argc, char **argv, struct node **liste)
{
    //int *ptr_len;
    int i;

    i = 1;
    struct node *head = NULL;
    /* argc zählt den ersten String in argv mit und der ist immer ./a.out */
    while (i < argc)
    {
        if (i == 1 && argv)
        {
            head = (struct node *)malloc(sizeof(struct node));
            head->data = ft_atoi(argv[i]);
            head->link = NULL;
            *liste = head;      // double pointer points to head
            //printf("Data: %d", head->data);
        }
        else
        {
            add_at_end(liste, ft_atoi(argv[i]));
        }
        //printf("input: %d \n", ints);  //to check each input
        i++;
    }
    //printf("loop: %d \n", *pt_ints);   //to check the output after the loop (should be the last entry)
    //return(head);         // how to pass all data with the pointer??? struct node *link helpfull???
}

int main(int argc, char **argv)
{ 
    struct node *liste = NULL;
    /* &liste gibt die Adresse des Pointers, der zur Liste zeigt durch = double pointer */
    ft_stack_receive(argc, argv, &liste);
    print_stack(&liste);
    swap_elements(&liste);
    print_stack(&liste);
    //printf("output main: %d\n", ft_stack_receive(argc, argv));  
    return(0);
}
