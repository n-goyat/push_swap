#include "./includes/push_swap.h"
int *allocate_and_parse_numbers(int argc, char *argv[])
{
    int *numbers = (int *)malloc((argc - 1) * sizeof(int));
    if (!numbers)
    {
        write(1, "Error, mal\n", 11);
        return (NULL);
    }
    int i = 0;
    while (i < argc - 1)
    {
        numbers[i] = ft_atol(argv[i + 1]);
        i++;
    }
    return (numbers);
}

int handle_multiple_arguments(int argc, char *argv[], t_stcks *stacks)
{
    int *numbers = allocate_and_parse_numbers(argc, argv);
    if (!numbers)
        return (0);
    if (has_duplicates(numbers, argc - 1))
    {
        write(1, "Error, dup\n", 11);
        free(numbers);
        return (0);
    }
    init_list(argc, argv, stacks);
    free(numbers);
    return (1);
}

int *allocate_and_parse_single_argument(int argc, char *argv[])
{
    int *numbers = (int *)malloc(argc * sizeof(int));
    if (!numbers)
    {
        write(1, "Error, mal\n", 11);
        return (NULL);
    }
    int i = 0;
    while (i < argc)
    {
        numbers[i] = ft_atol(argv[i]);
        i++;
    }
    return (numbers);
}

int handle_single_argument(int argc, char *argv[], t_stcks *stacks)
{
    int *numbers = allocate_and_parse_single_argument(argc, argv);
    if (!numbers)
        return (0);
    if (has_duplicates(numbers, argc))
    {
        write(1, "Error, dup\n", 11);
        free(numbers);
        return (0);
    }
    init_list(argc + 1, argv - 1, stacks);
    free(numbers);
    return (1);
}
