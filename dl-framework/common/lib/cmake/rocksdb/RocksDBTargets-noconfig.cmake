#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "RocksDB::rocksdb" for configuration ""
set_property(TARGET RocksDB::rocksdb APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(RocksDB::rocksdb PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_NOCONFIG "CXX"
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/librocksdb.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS RocksDB::rocksdb )
list(APPEND _IMPORT_CHECK_FILES_FOR_RocksDB::rocksdb "${_IMPORT_PREFIX}/lib/librocksdb.a" )

# Import target "RocksDB::rocksdb-shared" for configuration ""
set_property(TARGET RocksDB::rocksdb-shared APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(RocksDB::rocksdb-shared PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/librocksdb.so.5.9.2"
  IMPORTED_SONAME_NOCONFIG "librocksdb.so.5"
  )

list(APPEND _IMPORT_CHECK_TARGETS RocksDB::rocksdb-shared )
list(APPEND _IMPORT_CHECK_FILES_FOR_RocksDB::rocksdb-shared "${_IMPORT_PREFIX}/lib/librocksdb.so.5.9.2" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
