#ifndef __IDCOPY_H__
#define __IDCOPY_H__

#include "RC522.h"
#include "iccard.h"

uint8_t id_copy_init();
uint8_t idcopy_write(uint8_t *write_buf);
uint8_t idcopy_read(uint8_t *read_buf);

#endif