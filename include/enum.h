/*
** EPITECH PROJECT, 2024
** B-CPE-200-BDX-2-1-corewar-florian.labadie
** File description:
** enum
*/

#ifndef ENUM_H_
    #define ENUM_H_

typedef enum instruct_types_s {
    NO_MORE_TYPE,
    REGISTER,
    DIRECT,
    INDIRECT,
    INSTRUCT_TYPES_SIZE
} instruct_types_t;

typedef enum instructions_s {
    LIVE,
    LD,
    ST,
    ADD,
    SUB,
    AND,
    OR,
    XOR,
    ZJMP,
    LDI,
    STI,
    FORK,
    LLD,
    LLDI,
    LFORK,
    AFF,
    INSTRUCTIONS_SIZE
} instructions_t;

#endif /* !ENUM_H_ */
