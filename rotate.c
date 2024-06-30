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
		ft_putstr_fd("ra\n", 1);
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
		ft_putstr_fd("rb\n", 1);
	}
	}
}

void	rr(t_stcks *stacks, int print)
{
	rot_a(stacks, 0);
	rot_b(stacks, 0);
	if (print) {
		ft_putstr_fd("rr\n", 1);;
	}
}
