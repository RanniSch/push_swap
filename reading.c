/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 13:23:03 by rschlott          #+#    #+#             */
/*   Updated: 2022/08/31 16:33:41 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

/* defines the data structure */
struct node
{
    int data;
    struct node *link;
};

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
void    add_at_end(struct node *head, int data)
{
    struct node *ptr;
    struct node *current;

    ptr = head;
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
int    count_of_nodes(struct node *head)
{
    int count;
    
    count = 0;
    if (head == NULL)
        printf("Stack is empty");
    struct node *ptr = NULL;
    ptr = head;
    while (ptr != NULL)
    {
        count++;
        ptr = ptr->link;
    }
    return(count);
}

/* print the data of a linked list */
void    print_stack(struct node *head)
{
    if(head == NULL)
        printf("Linked List is empty");
    struct node *ptr = NULL;
    ptr = head;
    while(ptr != NULL)
    {
        printf("%d ", ptr->data);       // insert printf function!!!!!!!!!!!
        ptr = ptr->link;
    }
    printf("\nnumber of nodes: %d\n", count_of_nodes(head));       // insert printf function!!!!!!!!!!!   
}

/* swap function: Swap the first two elements at the top of the stack */
struct node *swap_elements(struct node *head)
{
    struct node *temp1;
    struct node *temp2;
    struct node *ptr;

    ptr = head;
    temp1 = ptr->link;
    temp2 = temp1->link;
    if (head != NULL && count_of_nodes(head) > 1)          // später error handling an eigener Stelle; head = NULL abbruch; count = 1 ausdrucken
    {        
        head = temp1;
        ptr->link = temp2;
        temp1->link = ptr;
    }
    return (head);
}

/* receiving arguments from user input */
struct node *ft_stack_receive(int argc, char **argv)
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
            //printf("Data: %d", head->data);
        }
        else
        {
            add_at_end(head, ft_atoi(argv[i]));
        }
        //printf("input: %d \n", ints);  //to check each input
        i++;
    }
    //printf("loop: %d \n", *pt_ints);   //to check the output after the loop (should be the last entry)
    return(head);         // how to pass all data with the pointer??? struct node *link helpfull???
}

int main(int argc, char **argv)
{ 
    struct node *head = NULL;
    head = ft_stack_receive(argc, argv);
    print_stack(head);
    head = swap_elements(head);
    print_stack(head);
    //printf("output main: %d\n", ft_stack_receive(argc, argv));  
    return(0);
}
