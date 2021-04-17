#ifndef BL3TMS_H
#define BL3TMS_H 1

/* LIBBL3MOD SYSTEM CODE: LICENSED UNDER THE TERMS OF THE GPLV3 LICENSE. */
/* FAILURE TO COMPLY WITH THE LICENSE TERMS */
/* SPECIFIED WILL RESULT IN CONSEQUENCES. */

/* (not required) #include <stdint.h> */
/* HS 4/11/21 Removed dependency on C89 stuff. */

struct chunk_info {
	unsigned long comp_size;
	unsigned long decomp_size;
};

struct chunk_data {
	unsigned long chunk_length;
	char* data;
	char* decomp_data;
};

struct tms_file {
	unsigned int decomp_size;
	unsigned int num_files;
	unsigned long magic;
	unsigned long max_decomp_size;
	unsigned long total_comp_size;
	unsigned long decomp_size_2;
	/* COMMENTED OUT TO PREVENT STRUCT WEIRDNESS */
	/* struct chunk_info* chunkinfo; */
	/* struct chunk_data* chunkdata; */
	unsigned int footer_1;
	unsigned int footer_2;
	/* This should always be 53 bytes long. */
	char* footer_text;
};

#endif
