aux_source_directory(. DIR_SRC_UTIL)
add_library(utils ${DIR_SRC_UTIL})

install (TARGETS utils DESTINATION bin)
install (FILES common-macros.h DESTINATION include/util)
install (FILES csv-reader.h DESTINATION include/util)
install (FILES memory-manager.h DESTINATION include/util)
