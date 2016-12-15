#ifndef MH_HULTIHASH_H
#define MH_HULTIHASH_H

#include <stddef.h>

/**
 * returns hash code or error (which is < 0)
 * @param mh the multihash
 * @param len the length of the multihash
 * @returns errors ( < 0 ) or the multihash
 */
int mh_multihash_hash(const unsigned char *multihash, size_t len);

/***
 * returns the length of the multihash's data section
 * @param mh the multihash
 * @param len the length of the multihash
 * @returns the length of the data section, or an error if < 0
 */
int mh_multihash_length(const unsigned char *multihash, size_t len);

/**
 * gives access to raw digest inside multihash buffer
 * @param multihash the multihash
 * @param len the length
 * @param digest the results
 * @returns error if less than zero, otherwise 0
 */
int mh_multihash_digest(const unsigned char *multihash, size_t len,
	 unsigned char **digest, size_t *digest_len);

/**
 * determine the size of the multihash given the data size
 * @param code currently not used
 * @param hash_len the data size
 * @returns hash_len + 2 (until the code parameter (varint) is added
 */
int mh_new_length(int code, size_t digest_len);

/***
 * create a multihash based on some data
 * @param buffer where to put the multihash
 * @param code the code
 * @param digest the data within the multihash
 * @returns error (if < 0) or 0
 */
int mh_new(unsigned char* buffer, int code, const unsigned char *digest,
	size_t digest_len);

#endif /* end of include guard */
