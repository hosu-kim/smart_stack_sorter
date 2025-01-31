/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoskim <hoskim@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 20:03:36 by hoskim            #+#    #+#             */
/*   Updated: 2025/01/31 22:38:02 by hoskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rra(t_stack *stack_a)
{
	t_node	*prev;
	t_node	*last;

	if (stack_a->num_of_nodes < 2)
		return ;
	prev = stack_a->first_node;
	while (prev->next->next)
		prev = prev->next;
	last = prev->next;
	prev->next = NULL;
	last->next = stack_a->first_node;
	stack_a->first_node = last;
	write(1, "rra\n", 4);
}

void	rrb(t_stack *stack_b)
{
	t_node	*prev;
	t_node	*last;

	if (stack_b->num_of_nodes < 2)
		return ;
	prev = stack_b->first_node;
	while (prev->next->next)
		prev = prev->next;
	last = prev->next;
	prev->next = NULL;
	last->next = stack_b->first_node;
	stack_b->first_node = last;
	write(1, "rrb\n", 4);
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->num_of_nodes >= 2 && stack_b->num_of_nodes >= 2)
	{
		rra(stack_a);
		rrb(stack_b);
		write(1, "rrr used.\n", 4);
	}
}
