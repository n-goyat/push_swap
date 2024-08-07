//algo_utils2.c
#include "./includes/push_swap.h"
void	push_below_median(t_stcks *stacks, int median)
{
	t_clst	*tmp;
	t_clst	*last;

	tmp = stacks->stack_a->next;
	last = stacks->stack_a;
	while (tmp != last)
	{
		if (tmp->value <= median)
		{
			tmp = tmp->next;
			push_b(stacks, 1);
		}
		else
		{
			tmp = tmp->next;
			rot_a(stacks, 1);
		}
	}
	if (tmp->value <= median)
		push_b(stacks, 1);
	else
		rot_a(stacks, 1);
}

void	push_above_median(t_stcks *stacks, int median)
{
	t_clst	*tmp;
	t_clst	*last;
	int		min;

	tmp = stacks->stack_a->next;
	last = stacks->stack_a;
	min = find_min_value(stacks);
	while (tmp->value != min)
	{
		if (tmp->value > median)
		{
			tmp = tmp->next;
			push_b(stacks, 1);
		}
		else
		{
			tmp = tmp->next;
			rot_a(stacks, 1);
		}
	}
}

void	move_to_min(t_stcks *stacks)
{
	int	pos;

	pos = find_min(stacks->stack_a);
	if (pos == 0)
		return ;
	if (pos <= (stacks->size_a / 2))
	{
		while (pos > 0)
		{
			rot_a(stacks, 1);
			pos--;
		}
	}
	else
	{
		while (pos < stacks->size_a)
		{
			rev_rot_a(stacks, 1);
			pos++;
		}
	}
}

void	find_min_max(t_stcks *stacks)
{
	int	pos_min;
	int	pos_max;

	pos_min = 0;
	pos_max = 0;
	stacks->pos_min = find_min(stacks->stack_b);
	stacks->pos_max = find_max(stacks->stack_b);
	if (stacks->pos_min > (stacks->size_b / 2))
		pos_min = (stacks->size_b - stacks->pos_min);
	else
		pos_min = stacks->pos_min;
	if (stacks->pos_max > (stacks->size_b / 2))
		pos_max = (stacks->size_b - stacks->pos_max);
	else
		pos_max = stacks->pos_max;
	if (pos_min < pos_max)
		push_min_max(stacks, stacks->pos_min);
	else
		push_min_max(stacks, stacks->pos_max);
}

void	push_min_max(t_stcks *stacks, int pos)
{
	int		count;

	count = 0;
	if (pos <= stacks->size_b / 2)
	{
		while (count < pos)
		{
			rot_b(stacks, 1);
			count++;
		}
	}
	else
	{
		while (count < (stacks->size_b - pos))
		{
			rev_rot_b(stacks, 1);
			count++;
		}
	}
	if (stacks->size_a == 0)
		push_a(stacks, 1);
	else
		push_a(stacks, 1);
	if (pos == stacks->pos_min)
		rot_a(stacks, 1);
}
