/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sorter_big.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoskim <hoskim@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 18:38:19 by hoskim            #+#    #+#             */
/*   Updated: 2025/02/04 19:19:36 by hoskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	move_to_b(t_stack *stack_a, t_stack *stack_b)
{
	int	min_num;
	int	max_num;
	int	mid_num;

	while (stack_a->num_of_nodes > 3)
	{
		min_num = get_min(stack_a);
		max_num = get_max(stack_a);
		mid_num = (min_num + max_num) / 2;
		if (stack_a->top_node->number <= mid_num)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
	}
	sort_three_nums(stack_a);
}

static void	move_best_number(t_stack *stack_a, t_stack *stack_b,
							int best_num, int target_positon)
{
	while (stack_b->top_node->number != best_num)
	{
		if (get_position(stack_b, best_num) <= stack_b->num_of_nodes / 2)
			rb(stack_b);
		else
			rrb(stack_b);
	}
	while (find_insert_position(stack_a, stack_b->top_node->number) != 0)
	{
		if (target_positon <= stack_a->num_of_nodes / 2)
			ra(stack_a);
		else
			rra(stack_a);
	}
	pa(stack_b, stack_a);
}

static void	align_stack(t_stack *stack_a)
{
	int	min_num;

	min_num = get_min(stack_a);
	while (stack_a->top_node->number != min_num)
	{
		if (get_position(stack_a, min_num) <= stack_a->num_of_nodes / 2)
			ra(stack_a);
		else
			rra(stack_a);
	}
}

void	sort_big(t_stack *stack_a, t_stack *stack_b)
{
	int	best_num;
	int	target_position;

	move_to_b(stack_a, stack_b);
	while (stack_b->num_of_nodes > 0)
	{
		best_num = find_best_number_from_b(stack_a, stack_b);
		target_position = find_insert_position(stack_a, best_num);
		move_best_number(stack_a, stack_b, best_num, target_position);
	}
	align_stack(stack_a);
}
