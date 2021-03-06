cmake_minimum_required(VERSION 3.15)
set (CMAKE_CXX_STANDARD 17)
set(CMAKE_DEBUG_POSTFIX _g)

project(MidiEmBackend LANGUAGES CXX)

set(TARGET_NAME "base-arpeggiator")

set(SOURCES
    "Arpeggiator.cpp"
    "ArpSequence.cpp"
    "ArpSequencePlayer.cpp"
    "ArpSequenceFactory.cpp"
    "BaseSequence.cpp"
    "NoteContainer.cpp"
)
set(HEADERS
    "Interface/Arpeggiator.h"
    "Interface/ArpTypes.h"
    "ArpSequence.h"
    "ArpSequencePlayer.h"
    "ArpSequenceFactory.h"
    "BaseSequence.h"
    "NoteContainer.h"
)

add_library(${TARGET_NAME} ${SOURCES} ${HEADERS})
target_include_directories(${TARGET_NAME}
    PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/Interface"
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}
)
target_link_libraries(${TARGET_NAME} 
    PUBLIC Util
    PRIVATE Tempo
    PRIVATE Loguru
)