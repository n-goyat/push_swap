//rev_rot.c
#include "./includes/push_swap.h"
void	rev_rot_a(t_stcks *stacks, int print)
{
	t_clst	*tmp;

	if (stacks->size_a > 1)
	{
		tmp = stacks->stack_a->next;
		while (tmp->next != stacks->stack_a)
		{
			tmp = tmp->next;
		}
		stacks->stack_a = tmp;
		if (print) {
        ft_putstr_fd("pa\n", 1);
        print_stack(stacks->stack_a, stacks->size_a, "Stack A");
        print_stack(stacks->stack_b, stacks->size_b, "Stack B");
    }
	}
}

void	rev_rot_b(t_stcks *stacks, int print)
{
	t_clst	*tmp;

	if (stacks->size_b > 1)
	{
		tmp = stacks->stack_b->next;
		while (tmp->next != stacks->stack_b)
		{
			tmp = tmp->next;
		}
		stacks->stack_b = tmp;
		if (print) {
        ft_putstr_fd("pa\n", 1);
        print_stack(stacks->stack_a, stacks->size_a, "Stack A");
        print_stack(stacks->stack_b, stacks->size_b, "Stack B");
    }
	}
}

void	rrr(t_stcks *stacks, int print)
{
	if (stacks->size_a > 1 && stacks->size_b > 1)
	{
		rev_rot_a(stacks, 0);
		rev_rot_b(stacks, 0);
		if (print) {
        ft_putstr_fd("pa\n", 1);
        print_stack(stacks->stack_a, stacks->size_a, "Stack A");
        print_stack(stacks->stack_b, stacks->size_b, "Stack B");
    }
	}
}
