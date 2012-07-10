/* Do not take the size of a pointer to determine the size of the pointed-to type */

/* BAD */

double *allocate_array(size_t num_elems) {
  double *d_array;
 
  if (num_elems > SIZE_MAX/sizeof(d_array)) {
    /* handle error condition */
  }
  d_array = (double *)malloc(sizeof(d_array) * num_elems);
  if (d_array == NULL) {
    /* handle error condition */
  }
  return d_array;
}

/* NOT BAD */

double *allocate_array(size_t num_elems) {
  double *d_array;
 
  if (num_elems > SIZE_MAX/sizeof(*d_array)) {
    /* handle error condition */
  }
  d_array = (double *)malloc(sizeof(*d_array) * num_elems);
  if (d_array == NULL) {
    /* handle error condition */
  }
  return d_array;
}

