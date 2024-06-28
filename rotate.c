//rotate.c
#include "./includes/push_swap.h"
void	rot_a(t_stcks *stacks, int print)
{
	t_clst	*tmp;

	if (stacks->size_a > 1)
	{
		tmp = stacks->stack_a->next;
		stacks->stack_a = tmp;
		if (print) {
        ft_putstr_fd("pa\n", 1);
        print_stack(stacks->stack_a, stacks->size_a, "Stack A");
        print_stack(stacks->stack_b, stacks->size_b, "Stack B");
    }
	}
}

void	rot_b(t_stcks *stacks, int print)
{
	t_clst	*tmp;

	if (stacks->size_b > 1)
	{
		tmp = stacks->stack_b->next;
		stacks->stack_b = tmp;
		if (print) {
        ft_putstr_fd("pa\n", 1);
        print_stack(stacks->stack_a, stacks->size_a, "Stack A");
        print_stack(stacks->stack_b, stacks->size_b, "Stack B");
    }
	}
}

void	rr(t_stcks *stacks, int print)
{
	rot_a(stacks, 0);
	rot_b(stacks, 0);
	if (print) {
        ft_putstr_fd("pa\n", 1);
        print_stack(stacks->stack_a, stacks->size_a, "Stack A");
        print_stack(stacks->stack_b, stacks->size_b, "Stack B");
    }
}
