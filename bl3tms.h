#ifndef BL3TMS_H
#define BL3TMS_H 1

#include <stdint.h>

struct chunk_info {
	uint64_t comp_size;
	uint64_t decomp_size;
};

struct chunk_data {
	uint64_t chunk_length;
	char* data;
	char* decomp_data;
};

struct tms_file {
	uint32_t decomp_size;
	uint32_t num_files;
	uint64_t magic;
	uint64_t max_decomp_size;
	uint64_t total_comp_size;
	uint64_t decomp_size_2;
	// COMMENTED OUT TO PREVENT STRUCT WEIRDNESS AND EXCESSIVE NESTING
	// struct chunk_info* chunkinfo;
	// struct chunk_data* chunkdata;
	uint32_t footer_1;
	uint32_t footer_2;
	char* footer_text; // 53
};

#endif
