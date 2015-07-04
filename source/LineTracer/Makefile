#####################################################
#
#     Project:  Line Tracer
#
#     Author:   Luis Ibanez
#
#     Division of Neurosugery
#     Medical Image Display and Analysis Group
#     University of North Carolina at Chapel Hill
#     Chapel Hill, NC 27599
#
#     email: ibanez@cs.unc.edu
#     URL:   http://www.cs.unc.edu/~ibanez
#
####################################################

RESULT = $(HOME_BIN)/LineTracing

OBJS  =  main.o


INCLUDES = -I.  $(MTL_INCLUDE)  


LIBDIRS  = -L$(HOME_LIB) 

LIBFILES = -lm 

LIBS = $(LIBDIRS)  $(LIBFILES)

COPTIONS =  -Wall

COMOPTIONS = $(COPTIONS) 



#################################################
#
#	Suffixes :
#
#################################################

.SUFFIXES: .o .cpp .h 


################################################
#
#	Implicit Rules
#
################################################
.cpp.o:
	$(CXX) -c  $<  $(COMOPTIONS)  $(INCLUDES)



#######################################################
#
#		Target
#
#######################################################
all:	$(RESULT)


clean:
	rm *.o
	rm $(RESULT)


zip:	../LineTracer.tgz



../LineTracer.tgz:
	cd ..; tar -czf LineTracer.tgz  --exclude *.o --exclude *.bak --exclude documentation LineTracer



$(RESULT):	$(OBJS)
	$(CXX)	-o $(RESULT) $(OBJS) $(LIBS)


link:
	$(CXX)	-o $(RESULT) $(OBJS) $(LIBS)






