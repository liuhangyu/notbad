/* Do not begin integer constants with 0 when specifying a decimal value */

/* BAD */

i_array[0] = 2719;
i_array[1] = 4435;
i_array[2] = 0042;

/* NOT BAD */

i_array[0] = 2719;
i_array[1] = 4435;
i_array[2] =   42;
