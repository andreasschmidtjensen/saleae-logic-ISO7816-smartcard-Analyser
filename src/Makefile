SDK=../../AnalyzerSDK/
SOLIB=libISO7816Analyzer.so

SRCS= \
Convert.cpp \
iso7816Analyzer.cpp \
iso7816AnalyzerResults.cpp \
iso7816AnalyzerSettings.cpp \
ISO7816Atr.cpp \
Iso7816BitDecoder.cpp \
ISO7816Pps.cpp \
Iso7816Session.cpp \
iso7816SimulationDataGenerator.cpp \
Logging.cpp \
ProtocolFrames.cpp \
SaleaeHelper.cpp \
Util.cpp \

GDB=-g -ggdb

CFLAGS=-I$(SDK)/include -I. -O3 -w -c -fpic -Wall $(GDB)
LDFLAGS=-L$(SDK)/lib -lAnalyzer -shared $(GDB)
OBJECTS=$(SRCS:.cpp=.o)
CC=g++

all: clean $(OBJECTS) $(SOLIB) Makefile

clean:
	rm -f $(OBJECTS) $(SOLIB)

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

$(SOLIB): $(OBJECTS)
	$(CC) $(LDFLAGS) -o $(SOLIB) $(OBJECTS)
