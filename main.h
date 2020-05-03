/* $Id: sph_blake.h 252 2011-06-07 17:55:14Z tp $ */
/**
 
 */

#ifndef MAIN_H__
#define MAIN_H__

#ifdef __cplusplus
extern "C"{
#endif

void be32enc(void *pp, uint32_t x);
void le32enc(void *pp, uint32_t x);
 uint32_t be32dec(const void *pp);


#ifdef __cplusplus
}
#endif

#endif
