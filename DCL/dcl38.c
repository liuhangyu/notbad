/* Use the correct syntax when declaring flexible array members */

/*
  1. The incomplete array type must be the last element within the structure.
  2. There cannot be an array of structures that contain flexible array members.
  3. Structures that contain a flexible array member cannot be used as a member
     in the middle of another structure.
*/

/* BAD */

struct flexArrayStruct {
  int num;
  int data[1];
};
 
/* ... */
 
size_t array_size;
size_t i;
 
/* initialize array_size */
 
/* space is allocated for the struct */
struct flexArrayStruct *structP
  = (struct flexArrayStruct *)
     malloc(sizeof(struct flexArrayStruct)
          + sizeof(int) * (array_size - 1));
if (structP == NULL) {
  /* Handle malloc failure */
}
structP->num = 0;
 
/* access data[] as if it had been allocated
 * as data[array_size] */
for (i = 0; i < array_size; i++) {
  structP->data[i] = 1;
}

/* NOT BAD */

struct flexArrayStruct{
  int num;
  int data[];
};
 
/* ... */
 
size_t array_size;
size_t i;
 
/* Initialize array_size */
 
/* Space is allocated for the struct */
struct flexArrayStruct *structP = (struct flexArrayStruct *)
   malloc(sizeof(struct flexArrayStruct) + sizeof(int) * array_size);
if (structP == NULL) {
  /* Handle malloc failure */
}
 
structP->num = 0;
 
/* Access data[] as if it had been allocated
 * as data[array_size]
 */
for (i = 0; i < array_size; i++) {
  structP->data[i] = 1;
}

