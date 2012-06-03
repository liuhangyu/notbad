/* Declare functions that return errno with a return type of errno_t */

/* BAD */

enum { NO_FILE_POS_VALUES = 3 };
 
int opener(
  FILE *file,
  int *width,
  int *height,
  int *data_offset
) {
  int file_w;
  int file_h;
  int file_o;
  fpos_t offset;
 
  if (file == NULL) { return EINVAL; }
  errno = 0;
  if (fgetpos(file, &offset) != 0) { return errno; }
  if (fscanf(file, "%i %i %i", &file_w, &file_h, &file_o)
        != NO_FILE_POS_VALUES) {
    return EIO;
  }
 
  errno = 0;
  if (fsetpos(file, &offset) != 0) { return errno; }
 
  if (width != NULL) { *width = file_w; }
  if (height != NULL) { *height = file_h; }
  if (data_offset != NULL) { *data_offset = file_o; }
 
  return 0;
}

/* NOT BAD */

#include <errno.h>
 
enum { NO_FILE_POS_VALUES = 3 };
 
errno_t opener(
  FILE *file,
  int *width,
  int *height,
  int *data_offset
) {
  int file_w;
  int file_h;
  int file_o;
  fpos_t offset;
 
  if (file == NULL) { return EINVAL; }
  errno = 0;
  if (fgetpos(file, &offset) != 0 ) { return errno; }
  if (fscanf(file, "%i %i %i", &file_w, &file_h, &file_o)
        != NO_FILE_POS_VALUES) {
    return EIO;
  }
 
  errno = 0;
  if (fsetpos(file, &offset) != 0 ) { return errno; }
 
  if (width != NULL) { *width = file_w; }
  if (height != NULL) { *height = file_h; }
  if (data_offset != NULL) { *data_offset = file_o; }
 
  return 0;
}
