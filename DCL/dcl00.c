/* Const-qualify immutable objects */

/* BAD */

float pi = 3.14159f;
float degrees;
float radians;
/*
radians = degrees * pi / 180;
 */

/* NOT BAD */

const float pi = 3.14159f;
float degrees;
float radians;
/*
radians = degrees * pi / 180;
 */
