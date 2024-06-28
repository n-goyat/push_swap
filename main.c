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
			exit(write(1, "Error, char\n", 12));
		else
			result = result * 10 + str[i] - '0';
		i++;
	}
	if (result > INT_MAX || result < INT_MIN)
		exit(write(1, "Error, rang\n", 12));
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
			exit(write(1, "Error, dup\n", 11));
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

//int	handle_multiple_arguments(int argc, char *argv[], t_stcks *stacks)
//{
//    int *numbers;
//    int i;
//
//    numbers = (int *)malloc((argc - 1) * sizeof(int));
//    if (!numbers)
//    {
//        write(1, "Error, mal\n", 11);
//        return (0);
//    }
//    i = 0;
//    while (i < argc - 1)
//    {
//        numbers[i] = ft_atol(argv[i + 1]);
//        i++;
//    }
//    if (has_duplicates(numbers, argc - 1))
//    {
//        write(1, "Error, dup\n", 11);
//        free(numbers);
//        return (0);
//    }
//    else
//	{
//        init_list(argc, argv, stacks);
//        free(numbers);
//        return (1);
//    }
//
//}
//
//int handle_single_argument(int argc, char *argv[], t_stcks *stacks)
//{
//    int *numbers;
//    int i;
//
//    numbers = (int *)malloc(argc * sizeof(int));
//    if (!numbers)
//    {
//        write(1, "Error, mal\n", 11);
//        return (0);
//    }
//    i = 0;
//    while (i < argc)
//    {
//        numbers[i] = ft_atol(argv[i]);
//        i++;
//    }
//    if (has_duplicates(numbers, argc))
//    {
//        write(1, "Error, dup\n", 11);
//        free(numbers);
//        return (0);
//    }
//    else
//    {
//        init_list(argc + 1, argv - 1, stacks);
//        free(numbers);
//        return (1);
//    }
//}

void ft_sort(t_stcks *stacks)
{
    print_stack(stacks->stack_a, stacks->size_a, "Stack A");
    // Choose the appropriate algorithm based on the size of stack A
    if (stacks->size_a <= 3)
        small_alg(stacks);
    else if (stacks->size_a <= 5)
        med_alg(stacks);
    else if (stacks->size_a <= 100)
        big_alg(stacks);
    else
        biggest_alg(stacks);
    print_stack(stacks->stack_a, stacks->size_a, "Stack A");
    free_stack(stacks);
}

void print_stack(t_clst *stack, int size, char *stack_name) {
    t_clst *current = stack;
    printf("%s: ", stack_name);
    for (int i = 0; i < size; i++) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}


int main(int argc, char *argv[])
{
    char	**res_split;
    t_stcks stacks;

    res_split = NULL;
    if (argc < 2)
    {
        write(1, "Error, arg\n", 11);
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
