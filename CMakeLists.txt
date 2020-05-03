cmake_minimum_required(VERSION 3.5)

if (NOT CMAKE_BUILD_TYPE)
    message(STATUS "No build type selected, defaulting to Release")
    set(CMAKE_BUILD_TYPE "Release")
endif ()

set(SOURCES
      x16rv3.c
      sph_blake.c
      sph_bmw.c
      sph_groestl.c
      sph_jh.c
      sph_keccak.c
      sph_skein.c
      sph_cubehash.c
      sph_echo.c
      sph_luffa.c
      sph_simd.c
      sph_hamsi.c
      sph_hamsi_helper.c
      sph_fugue.c
      sph_shavite.c
      sph_shabal.c
      sph_whirlpool.c
      sph_sha2big.c
      aes.c
)

add_library(x16rv3_hash STATIC ${SOURCES})

