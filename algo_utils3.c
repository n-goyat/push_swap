#include "./includes/push_swap.h"

int find_min_value(t_stcks *stacks)
{
	t_clst *tmp;
	int min;

	tmp = stacks->stack_a->next;
	min = tmp->value;
	while (tmp != stacks->stack_a)
	{
		if (min > tmp->value)
			min = tmp->value;
		tmp = tmp->next;
	}
	if (min > stacks->stack_a->value)
		min = stacks->stack_a->value;
	return min;
}

int find_max_value(t_stcks *stacks)
{
	t_clst *tmp;
	int max;

	tmp = stacks->stack_a->next;
	max = tmp->value;
	while (tmp != stacks->stack_a)
	{
		if (max < tmp->value)
			max = tmp->value;
		tmp = tmp->next;
	}
	if (max < stacks->stack_a->value)
		max = stacks->stack_a->value;
	return max;
}

void push_between_median(t_stcks *stacks, int from, int to)
{
	int *ints;
	int i;
	t_clst *tmp;

	ints = malloc(sizeof(int) * stacks->size_a);
	tmp = stacks->stack_a->next;
	i = 0;
	while (i < stacks->size_a)
	{
		ints[i] = tmp->value;
		tmp = tmp->next;
		i++;
	}
	while (i > 0)
	{
		if (ints[i] <= to && ints[i] > from)
			push_b(stacks, 1);
		else
			rot_a(stacks, 1);
		i--;
	}
	free(ints);
}

void move_to_value(t_stcks *stacks, int value)
{
	t_clst *tmp;
	int i;

	tmp = stacks->stack_a->next;
	i = 0;
	while (tmp != stacks->stack_a)
	{
		if (tmp->value == value)
			break ;
		i++;
		tmp = tmp->next;
	}
	if (i < (stacks->size_a / 2))
	{
		while (i > 0)
		{
			rot_a(stacks, 1);
			i--;
		}
	}
	else
	{
		while (i < stacks->size_a)
		{
			rev_rot_a(stacks, 1);
			i++;
		}
	}
}

void get_block(t_stcks *stacks, long min, long max)
{
	t_clst *tmp;

	tmp = stacks->stack_a->next;
	while (tmp != stacks->stack_a)
	{
		if (tmp->value >= min && tmp->value <= max)
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
	if (tmp->value >= min && tmp->value <= max)
		push_b(stacks, 1);
}
