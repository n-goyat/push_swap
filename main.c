//main.c
#include "./includes/push_swap.h"
long long	ft_atol(const char *str)
{
	int			i;
	int			sign;
	long long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	while (str && str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			exit(ft_putstr_fd("Error\n", 1));
		else
			result = result * 10 + str[i] - '0';
		i++;
	}
	if (result > INT_MAX || result < INT_MIN)
		exit(ft_putstr_fd("Error\n", 1));
	return (result * sign);
}

int	has_duplicates(int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < size - 1)
	{
		if (j == size)
		{
			i++;
			j = i + 1;
		}
		else if (arr[i] == arr[j])
		{
			free(arr);
			exit(ft_putstr_fd("Error\n", 1));
		}
		else
			j++;
	}
	return (0);
}

int	word_count(const char *str)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	if (!ft_strncmp(str, "", ft_strlen(str)))
		return (0);
	while (str && str[i])
	{
		while (str[i] == ' ' || str[i] == '\t')
			i++;
		if (str[i])
		{
			i++;
			if (str[i] == ' ' || str[i] == '\t' || str[i] == '\0')
			{
				counter++;
				continue ;
			}
		}
	}
	return (counter);
}

void ft_sort(t_stcks *stacks)
{
	if (stacks->size_a <= 3)
		small_alg(stacks);
	else if (stacks->size_a <= 5)
		med_alg(stacks);
	else if (stacks->size_a <= 100)
		big_alg(stacks);
	else
		biggest_alg(stacks);
	free_stack(stacks);
}

//void print_stack(t_clst *stack, int size, char *stack_name) {
//	t_clst *current = stack;
//	printf("%s: ", stack_name);
//	for (int i = 0; i < size; i++) {
//		printf("%d ", current->value);
//		current = current->next;
//	}
//	printf("\n");
//}


int main(int argc, char *argv[])
{
	char	**res_split;
	t_stcks stacks;

	res_split = NULL;
	if (argc < 2)
	{
		ft_putstr_fd("Error\n", 1);
		return (1);
	}
	if (argc == 2)
	{
		if (word_count(argv[1]) >= 1)
			res_split = ft_split(argv[1], ' ');
		if (handle_single_argument(word_count(argv[1]), res_split, &stacks))
		{
			ft_sort(&stacks);
		}
	}
	else if (handle_multiple_arguments(argc, argv, &stacks))
	{
		ft_sort(&stacks);
	}
	return (0);
}
