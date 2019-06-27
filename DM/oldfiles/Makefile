# which subdirectories and targeto nee_ to be built
#SUBDIRS = /path/to/directory
TARGETS = AnalysisSimple

include Rules.mk

# override tools and flags as needed
$(TARGETS): CC = $(CXX)
$(TARGETS): LDLIBS += $(ROOTLIBS) -lMinuit -lTMVA -lXMLIO -lTreePlayer -lMLP -lRooFitCore -lRooFit -lRooStats -lFoam $(LIBGENVECTOR)

