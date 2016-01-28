
IF (WIN32)
    FIND_PATH(ETHKEY_INCLUDE_PATH ethkey/KeyPair.hpp
        $ENV{ETHKEY_INCLUDE_PATH}
        $ENV{PROGRAMFILES}/ethkey
        DOC "The directory where ethkey/KeyPair.hpp resides")
    FIND_LIBRARY(ETHKEY_LIBRARY
        NAMES ethkey
        PATHS
        $ENV{ETHKEY_LIBRARY}
        $ENV{PROGRAMFILES}/ethkey
        DOC "The ethkey library")
ELSE (WIN32)
    FIND_PATH(ETHKEY_INCLUDE_PATH ethkey/KeyPair.hpp
        $ENV{ETHKEY_INCLUDE_PATH}
        /usr/local/include
        /usr/include
        /sw/include
        /opt/local/include
        DOC "The directory where libethkey/KeyPair.hpp resides")
    FIND_LIBRARY(ETHKEY_LIBRARY
        NAMES ethkey
        PATHS
        $ENV{ETHKEY_LIBRARY}
        /usr/local/lib64
        /usr/local/lib
        /usr/lib64
        /usr/lib
        /sw/lib
        /opt/local/lib
        DOC "The ethkey library")
ENDIF (WIN32)


IF (ETHKEY_INCLUDE_PATH)
    SET(ETHKEY_FOUND 1)
ELSE (FOO_INCLUDE_PATH)
    SET(ETHKEY_FOUND 0)
ENDIF (ETHKEY_INCLUDE_PATH)

MARK_AS_ADVANCED( ETHKEY_FOUND )
