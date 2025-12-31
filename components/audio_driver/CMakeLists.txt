set(INCLUDES ".")
file(GLOB_RECURSE SOURCES ./*.c)

idf_component_register(SRCS ${SOURCES}
                    INCLUDE_DIRS ${INCLUDES}
                    REQUIRES driver
                    PRIV_REQUIRES spiffs)