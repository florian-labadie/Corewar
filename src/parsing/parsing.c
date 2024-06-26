/*
** EPITECH PROJECT, 2024
** B-CPE-200-BDX-2-1-robotfactory-florian.labadie
** File description:
** parsing
*/

#include "my.h"

static int check_flag_validity(int flag, char const *str, int *i)
{
    *i += 1;
    if (flag == 0 && str[0] != '0')
        return -KO;
    return OK;
}

static int put_flag(char const *const *argv, champion_t **champion, int *i)
{
    if (my_strcmp(argv[*i], "-dump") == 0 && argv[*i + 1]){
        (*champion)->cycle_to_wait = my_getnbr(argv[*i + 1]);
        return check_flag_validity((*champion)->cycle_to_wait,
            argv[*i + 1], i);
    }
    if (my_strcmp(argv[*i], "-n") == 0 && argv[*i + 1]) {
        (*champion)->prog_number = my_getnbr(argv[*i + 1]);
        return check_flag_validity((*champion)->prog_number, argv[*i + 1], i);
    }
    if (my_strcmp(argv[*i], "-a") == 0 && argv[*i + 1]) {
        (*champion)->pc = my_getnbr(argv[*i + 1]) % MEM_SIZE;
        return check_flag_validity((*champion)->pc, argv[*i + 1], i);
    }
    return -KO;
}

static int check_dump(char const *const *argv, corewar_t **corewar, int *i,
    int prog_nbr)
{
    if (my_strcmp(argv[*i], "-dump") == 0 && argv[*i + 1]) {
        (*corewar)->dump = my_getnbr(argv[*i + 1]);
        return check_flag_validity((*corewar)->dump, argv[*i + 1], i);
    }
    return put_flag(argv, &(*corewar)->champions[prog_nbr], i);
}

int parse_war_progs(corewar_t *corewar, int argc, char const *const *argv)
{
    int prog_nbr = 0;
    int return_value = 0;

    if (!corewar || !argv || !argv[0] || argc < 3)
        return KO;
    for (int i = 1; i < argc; i++) {
        if (argv[i][0] == '-') {
            return_value = check_dump(argv, &corewar, &i, prog_nbr);
        } else {
            return_value = parse_champion
                                (&corewar->champions[prog_nbr], argv[i]);
            prog_nbr += 1;
        }
        if (return_value == -KO || return_value == KO)
            return KO;
    }
    return OK;
}
