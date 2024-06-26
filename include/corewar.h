/*
** EPITECH PROJECT, 2024
** B-CPE-200-BDX-2-1-COREWAR-florian.labadie
** File description:
** COREWAR
*/

#ifndef COREWAR_F_H_
    #define COREWAR_F_H_

    #include <stdbool.h>
    #include <stdint.h>

typedef struct champion_s {
    bool is_alive;
    int cycle_to_die;

    char *prog_name;
    int prog_number;

    int prog_size;
    __uint8_t *instructions;

    int load_address;
    int pc;
    int current_pc;
    __uint16_t regs[REG_NUMBER];

    int cycle_to_wait;

    bool carry;
} champion_t;

typedef struct corewar_s {
    __uint8_t arena[MEM_SIZE];

    int dump;
    int champs_nbr;
    int nbr_of_cycles;
    int cycle_to_die;

    int current_nbr_live;

    champion_t **champions;
} corewar_t;

#endif /* COREWAR_F_H_ */
