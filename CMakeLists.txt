cmake_minimum_required (VERSION 3.13)

project(iso7816Analyzer)

add_definitions( -DLOGIC2 )

# enable generation of compile_commands.json, helpful for IDEs to locate include files.
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# custom CMake Modules are located in the cmake directory.
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

include(ExternalAnalyzerSDK)

set(SOURCES 
src/ByteBuffer.hpp
src/ByteElement.hpp
src/Convert.cpp
src/Convert.hpp
src/Definitions.hpp
src/Exceptions.hpp
src/ISO7816Atr.cpp
src/ISO7816Atr.hpp
src/ISO7816Pps.cpp
src/ISO7816Pps.hpp
src/Iso7816BitDecoder.cpp
src/Iso7816BitDecoder.h
src/Iso7816Session.cpp
src/Iso7816Session.h
src/Logging.cpp
src/Logging.hpp
src/Makefile
src/ProtocolFrames.cpp
src/ProtocolFrames.h
src/SaleaeHelper.cpp
src/SaleaeHelper.hpp
src/T1Frame.h
src/TxFrame.h
src/Util.cpp
src/Util.h
src/iso7816Analyzer.cpp
src/iso7816Analyzer.h
src/iso7816AnalyzerResults.cpp
src/iso7816AnalyzerResults.h
src/iso7816AnalyzerSettings.cpp
src/iso7816AnalyzerSettings.h
src/iso7816SimulationDataGenerator.cpp
src/iso7816SimulationDataGenerator.h
)

add_analyzer_plugin(${PROJECT_NAME} SOURCES ${SOURCES})
