cmake_minimum_required(VERSION 3.27)

set(CMAKE_CXX_STANDARD 17)
set(HEADER_FILES
        SynonymTable.h
        WordsList.h
        FileReader.h
        WordsListFileReader.h
        SynonymTableFileReader.h
        WordsListFileWriter.h
)
set(SOURCE_FILES
        SynonymTable.cpp
        WordsList.cpp
        WordsListFileReader.cpp
        SynonymTableFileReader.cpp
        WordsListFileWriter.cpp
)

add_library(SynonymTableLib STATIC ${HEADER_FILES} ${SOURCE_FILES})