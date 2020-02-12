/* iso_alloc.h - A secure memory allocator
 * Copyright 2020 - chris.rohlf@gmail.com */

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

#define EXTERNAL_API __attribute__((visibility("default")))

typedef void iso_alloc_zone_handle;

EXTERNAL_API void *iso_alloc(size_t size);
EXTERNAL_API void *iso_calloc(size_t nmemb, size_t size);
EXTERNAL_API void iso_free(void *p);
EXTERNAL_API void iso_free_permanently(void *p);
EXTERNAL_API void *iso_realloc(void *p, size_t size);
EXTERNAL_API size_t iso_chunksz(void *p);
EXTERNAL_API iso_alloc_zone_handle *iso_alloc_from_zone(size_t size, iso_alloc_zone_handle *zone);
EXTERNAL_API iso_alloc_zone_handle *iso_realloc_from_zone(void *p, size_t size, iso_alloc_zone_handle *zone);
EXTERNAL_API iso_alloc_zone_handle *iso_alloc_new_zone(size_t size);
EXTERNAL_API void iso_alloc_destroy_zone(iso_alloc_zone_handle *zone);
EXTERNAL_API void iso_alloc_protect_root();
EXTERNAL_API void iso_alloc_unprotect_root();
EXTERNAL_API int32_t iso_alloc_detect_zone_leaks(iso_alloc_zone_handle *zone);
EXTERNAL_API int32_t iso_alloc_detect_leaks();
EXTERNAL_API int32_t iso_alloc_zone_mem_usage(iso_alloc_zone_handle *zone);
EXTERNAL_API int32_t iso_alloc_mem_usage();
