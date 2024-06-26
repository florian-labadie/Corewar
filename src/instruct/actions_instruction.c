/*
** EPITECH PROJECT, 2024
** B-CPE-200-BDX-2-1-corewar-florian.labadie
** File description:
** actions_instruction
*/

#include "my.h"

static void sti_loop(corewar_t *corewar, int *args,
    instruct_types_t *types, int prog_nbr)
{
    int load = 0;
    uint32_t reg_value = 0;

    for (int i = 1; i < 3; i += 1) {
        if (types[i] == REGISTER)
            load += corewar->champions[prog_nbr]->regs[args[i] - 1];
        if (types[i] == DIRECT || types[i] == INDIRECT)
            load += args[i];
    }
    reg_value = my_htonl(corewar->champions[prog_nbr]->regs[args[0] - 1]);
    my_corcpy(&corewar->arena, corewar->champions[prog_nbr]->current_pc +
            load % IDX_MOD, (uint8_t *)(&reg_value), REG_SIZE);
}

static void st_args(corewar_t *corewar, champion_t **champion,
    int *args, instruct_types_t *types)
{
    uint32_t reg_value = 0;

    if (types[1] == REGISTER)
        (*champion)->regs[args[1] - 1] =
            (*champion)->regs[args[0] - 1];
    if (types[1] == INDIRECT) {
        reg_value = my_htonl((*champion)->regs[args[0] - 1]);
        my_corcpy(&corewar->arena, (*champion)->current_pc +
            args[1] % IDX_MOD, (uint8_t *)(&reg_value), REG_SIZE);
    }
}

int st_i(corewar_t *corewar, champion_t ***champion, int prog_nbr)
{
    int *args = NULL;
    instruct_types_t *types =
        get_instruct_types(corewar->arena[
            ((*champion)[prog_nbr]->pc + 1) % MEM_SIZE], ST);

    (*champion)[prog_nbr]->current_pc = (*champion)[prog_nbr]->pc;
    if (!types)
        return KO;
    (*champion)[prog_nbr]->cycle_to_wait += op_tab[ST].nbr_cycles;
    (*champion)[prog_nbr]->pc = ((*champion)[prog_nbr]->pc + 2) % MEM_SIZE;
    args = parse_parameter(corewar, types, ST, &(*champion)[prog_nbr]);
    if (!args)
        return KO;
    st_args(corewar, &(*champion)[prog_nbr], args, types);
    free(args);
    free(types);
    return OK;
}

int sti(corewar_t *corewar, champion_t ***champion, int prog_nbr)
{
    int *args = NULL;
    instruct_types_t *types =
        get_instruct_types(corewar->arena[
            ((*champion)[prog_nbr]->pc + 1) % MEM_SIZE], STI);

    (*champion)[prog_nbr]->current_pc = (*champion)[prog_nbr]->pc;
    if (!types)
        return KO;
    (*champion)[prog_nbr]->cycle_to_wait += op_tab[STI].nbr_cycles;
    (*champion)[prog_nbr]->pc = ((*champion)[prog_nbr]->pc + 2) % MEM_SIZE;
    args = parse_parameter(corewar, types, STI, &(*champion)[prog_nbr]);
    if (!args)
        return KO;
    sti_loop(corewar, args, types, prog_nbr);
    free(args);
    free(types);
    return OK;
}

int aff(corewar_t *corewar, champion_t ***champion, int prog_nbr)
{
    int *args = NULL;
    instruct_types_t *types =
        get_instruct_types(corewar->arena[
            ((*champion)[prog_nbr]->pc + 1) % MEM_SIZE], AFF);
    uint16_t aff = 0;

    (*champion)[prog_nbr]->current_pc = (*champion)[prog_nbr]->pc;
    if (!types)
        return KO;
    (*champion)[prog_nbr]->cycle_to_wait += op_tab[AFF].nbr_cycles;
    (*champion)[prog_nbr]->pc = ((*champion)[prog_nbr]->pc + 2) % MEM_SIZE;
    args = parse_parameter(corewar, types, AFF, &(*champion)[prog_nbr]);
    if (!args)
        return KO;
    aff = (*champion)[prog_nbr]->regs[args[0] - 1] % (IDX_MOD / 2);
    my_putchar(aff);
    free(args);
    free(types);
    return OK;
}
