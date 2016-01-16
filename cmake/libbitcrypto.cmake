
IF (WIN32)
    FIND_PATH(BITCRYPTO_INCLUDE_PATH bitcrypto/Key.hpp
        $ENV{BITCRYPTO_INCLUDE_PATH}
        $ENV{PROGRAMFILES}/bitcrypto
        DOC "The directory where bitcrypto/Key.hpp resides")
    FIND_LIBRARY(BITCRYPTO_LIBRARY
        NAMES bitcrypto
        PATHS
        $ENV{BITCRYPTO_LIBRARY}
        $ENV{PROGRAMFILES}/bitcrypto
        DOC "The bitcrypto library")
ELSE (WIN32)
    FIND_PATH(BITCRYPTO_INCLUDE_PATH bitcrypto/Key.hpp
        $ENV{BITCRYPTO_INCLUDE_PATH}
        /usr/local/include
        /usr/include
        /sw/include
        /opt/local/include
        DOC "The directory where libbitcrypto/Key.hpp resides")
    FIND_LIBRARY(BITCRYPTO_LIBRARY
        NAMES bitcrypto
        PATHS
        $ENV{BITCRYPTO_LIBRARY}
        /usr/local/lib64
        /usr/local/lib
        /usr/lib64
        /usr/lib
        /sw/lib
        /opt/local/lib
        DOC "The bitcrypto library")
ENDIF (WIN32)


IF (BITCRYPTO_INCLUDE_PATH)
    SET(BITCRYPTO_FOUND 1)
ELSE (FOO_INCLUDE_PATH)
    SET(BITCRYPTO_FOUND 0)
ENDIF (BITCRYPTO_INCLUDE_PATH)

MARK_AS_ADVANCED( BITCRYPTO_FOUND )
