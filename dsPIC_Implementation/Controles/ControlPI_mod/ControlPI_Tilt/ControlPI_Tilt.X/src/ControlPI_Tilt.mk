#
# File: ControlPI_Tilt.mk
#
#--------------------------------------------------------------
#   Embedded Coder for Microchip dsPIC30/dsPIC33/PIC24 family. |
#   Generate .c and .h files from your Matlab/simulink model   |
#   and compile the diagram to .hex / .elf or .coff file that  |
#   can be downloaded directly into the microcontroller        |
#                                                              |
#      The Microchip name PIC, dsPIC, and MPLAB are            |
#      registered trademarks of Microchip Technology Inc.      |
#      MATLAB, Simulink, and Real-Time Workshop are            |
#      registered trademarks of The MathWorks, Inc.            |
#                                                              |
#--------------------------------------------------------------

MAKE 			 = "C:\Program Files\MATLAB\R2013b\bin/win64/gmake"
#MAKE 			 = "|>GMAKE_PLACE<|"
#MAKE			 = C:\PROGRA~1\MATLAB\R2013b\bin/win64/gmake
HOST             = PC
BUILD            = yes
BUILD_SUCCESS    = *** Created
SYS_TARGET_FILE  = MCHP_dsPIC_stf.tlc

#---------------------- Tokens expanded by make_rtw ----------------------------
#
# The following tokens, when wrapped with "|>" and "<|" are expanded by the 
# Real-Time Workshop build procedure.
#   
MODEL               = ControlPI_Tilt
MODULES             = ControlPI_Tilt_main.c MCHP_UART1_Interrupt.c receive.c 
MAKEFILE            = ControlPI_Tilt.mk
MATLAB_ROOT         = C:\Program Files\MATLAB\R2013b
ALT_MATLAB_ROOT     = C:\PROGRA~1\MATLAB\R2013b
S_FUNCTIONS         = 
S_FUNCTIONS_LIB     = 
NUMST               = 2
NCSTATES            = 0
COMPUTER            = PCWIN64
BUILDARGS           =  MULTI_INSTANCE_CODE=0 GENERATE_ASAP2=0 TMW_EXTMODE_TESTING=0 MCHP_AUTO_FLASH=0 MCHP_MULTITHREAD_COMPILATION=0
MULTITASKING        = 1
MODELREFS           = 
SHARED_SRC          = 
SHARED_SRC_DIR      = 
SHARED_BIN_DIR      = 
SHARED_LIB          = 
GEN_SAMPLE_MAIN     = 0
TARGET_LANG_EXT     = c
EXT_MODE            = 0
EXTMODE_TRANSPORT   = 0
EXTMODE_STATIC      = 0
EXTMODE_STATIC_SIZE = 1000000
NUMST               = 2


#--------------------------- Model and reference models -----------------------
MODELLIB                  = ControlPI_Tiltlib_lib.a
MODELREF_LINK_LIBS        = 
MODELREF_INC_PATH         = 
# warning: .. is different from MAtlab 2013a version (pointing to a folder beyong)
# RELATIVE_PATH_TO_ANCHOR   = ..
RELATIVE_PATH_TO_ANCHOR   = ..\..
RELATIVE_PATH_TO_ANCHOR_True = ..
# NONE: standalone, SIM: modelref sim, RTW: modelref rtw
MODELREF_TARGET_TYPE       = NONE

# New : to support Continuous States ? find in "Upgrading from V3.2.1 or V3.2"
CPP_REQ_DEFINES = -DMODEL=$(MODEL) -DNUMST=$(NUMST) -DNCSTATES=$(NCSTATES) \
-DMAT_FILE=$(MAT_FILE)
-DINTEGER_CODE=$(INTEGER_CODE) \
-DONESTEPFCN=$(ONESTEPFCN) -DTERMFCN=$(TERMFCN) \
-DHAVESTDIO
-DMULTI_INSTANCE_CODE=$(MULTI_INSTANCE_CODE) \
-DADD_MDL_NAME_TO_GLOBALS=$(ADD_MDL_NAME_TO_GLOBALS)

#-- In the case when directory name contains space ---
ifneq ($(MATLAB_ROOT),$(ALT_MATLAB_ROOT))
MATLAB_ROOT := $(ALT_MATLAB_ROOT)
endif

# RTW option makevariables that are not expanded in the template makefile are
# automatically passed into make. To avoid this, create NOOP replacements.
# For this custom target, these ERT makevariables are not used.
#
NOOP = 0
NOOP = 0
NOOP = 0
NOOP = 1
NOOP = 0

#------------------------------ Tool Locations ---------------------------------
#

GCC1 = xc16-gcc.exe
AR1 = xc16-ar -r
BIN2HEX = xc16-bin2hex 	
OBJDUMP = xc16-objdump
# pic30-bin2hex or xc16-bin2hex

AssemblyListing = 0

ProduceHexOutput = 1

GCCPATH	= C:\PROGRA~2\MICROC~1\xc16\v1.24\bin
ifeq ($(strip $(GCCPATH)),)
CC   = $(GCC1)  
CPP  = $(GCC1) 
LD   = $(GCC1) 
AR   = $(AR1)

else
CC   = "$(GCCPATH)\$(GCC1)"
CPP  = "$(GCCPATH)\$(GCC1)"
LD   = "$(GCCPATH)\$(GCC1)"
AR   = "$(GCCPATH)\$(AR1)"
endif

ifeq ($(HOST),PC)
DEL = del /Q
else
DEL = rm -rf
endif
#------------------------------ parameter controlled from simulink ----------------

OMF = elf
OUT = $(subst coff,cof,$(OMF))

OPTIM_GCC 		=  -O0 -fschedule-insns -fschedule-insns2
											#-O3 -fschedule-insns -fschedule-insns2
LDFLAGS 		= -Xlinker -t -Xlinker --report-mem -Xlinker -Map=info.map -Xlinker -cref -Xlinker --heap=16
											#-t --report-mem -Map ../untitled.map --heap 0  -cref
LINKER_SCRIPT 	= "C:\PROGRA~2\MICROC~1\xc16\v1.24\support\dsPIC33F\gld\P372F1~1.GLD"
											#C:\PROGRA~1\MICROC~1\MPLABC~1\support\gld\p30f2012.gld
PIC_LIB 		= C:\PROGRA~2\MICROC~1\xc16\v1.24\lib\dsPIC33F\libp33FJ128MC804-elf.a C:\PROGRA~2\MICROC~1\xc16\v1.24\lib\libpic30-elf.a C:\PROGRA~2\MICROC~1\xc16\v1.24\lib\libm-elf.a C:\PROGRA~2\MICROC~1\xc16\v1.24\lib\libc-elf.a C:\PROGRA~2\MICROC~1\xc16\v1.24\lib\libq-elf.a C:\PROGRA~2\MICROC~1\xc16\v1.24\lib\libq-dsp-elf.a
											#C:\PROGRA~1\MICROC~1\MPLABC~1\lib\...
PIC_INCLUDES 	= -IC:\PROGRA~2\MICROC~1\xc16\v1.24\include -IC:\PROGRA~2\MICROC~1\xc16\v1.24\support\dsPIC33F\h -IC:\PROGRA~2\MICROC~1\xc16\v1.24\support\generic\h -IC:\PROGRA~2\MICROC~1\xc16\v1.24\support\PERIPH~2
PIC_REF 		= 33FJ128MC804

MCPU 			= -mcpu=$(PIC_REF)

CC_OPTS 		= $(MCPU)  -omf=$(OMF) $(OPTIM_GCC) 
T_LINKER_SCRIPT = -omf=$(OMF) -Xlinker --script=$(LINKER_SCRIPT)
												#-T C:\PROGRA~1\MICROC~1\MPLABC~1\support\gld\p30f2012.gld
LDLIBPIC = $(PIC_LIB)
												#-LC:\PROGRA~1\MICROC~1\MPLABC~1\lib\ -lp30F2012 -lm -lc -lpic30

# Keep following line, help the Matlab programming tool to find the programmer. 												
# Additional info : PICREF{33FJ128MC804} PROGRAMMER{}
												
#------------------------------ Include Path -----------------------------------
#
MATLAB_INCLUDES = \
	-I$(MATLAB_ROOT)/simulink/include \
  -I$(MATLAB_ROOT)/extern/include \
	-I$(MATLAB_ROOT)/rtw/c/src \
	-I$(MATLAB_ROOT)/rtw/c/ert \
	-I$(MATLAB_ROOT)/rtw/c/src/ext_mode/common

# Additional includes 
#
ADD_INCLUDES = \
	-IC:\Users\Maestria01\Dropbox\TESIS_Maestria\Matlab\mplabtoolbox\Controles_PI\ControlPI_mod\ControlPI_Tilt\ControlPI_Tilt.X\src \
	-IC:\Users\Maestria01\Dropbox\TESIS_Maestria\Matlab\mplabtoolbox\Controles_PI\ControlPI_mod\ControlPI_Tilt \
	-IC:\Users\Maestria01\Dropbox\TESIS_Maestria\Matlab\mplabtoolbox\Controles_PI\ControlPI_mod\ControlPI_Tilt\Source \



USER_INCLUDES = 

SHARED_INCLUDES =
ifneq ($(SHARED_SRC_DIR),)
SHARED_INCLUDES = -I$(SHARED_SRC_DIR) 
endif

INCLUDES = -I. -I$(RELATIVE_PATH_TO_ANCHOR) $(MATLAB_INCLUDES) $(ADD_INCLUDES) \
           $(USER_INCLUDES) $(PIC_INCLUDES) $(MODELREF_INC_PATH) \
           $(SHARED_INCLUDES)

#-------------------------------- C Flags --------------------------------------
# General User Options 

CFLAGS    =$(CC_OPTS)  $(INCLUDES) 
CPPFLAGS = $(CC_OPTS)  $(INCLUDES)

LIBS =






LIBS += $(S_FUNCTIONS_LIB)

#----------------------------- Source Files ------------------------------------
SHARED_OUTPUT_OPTS = -o $@
SRCS = $(MODULES) $(S_FUNCTIONS)
ifeq ($(MODELREF_TARGET_TYPE), NONE)
  # Top-level model for RTW
  PRODUCT            = $(RELATIVE_PATH_TO_ANCHOR)/$(MODEL).$(OUT)
  BUILD_PRODUCT_TYPE = "executable"
  SRCS               += $(MODEL).$(TARGET_LANG_EXT)  $(EXT_SRC)

#ifeq ($(GEN_SAMPLE_MAIN),0)
#    SRCS += main.c
#  else
#    SRCS += ert_main.c
#  endif

else
  # sub-model for RTW
  PRODUCT            = $(MODELLIB)
  BUILD_PRODUCT_TYPE = "library"
endif

#ifeq ($(ExtMode),1)
  # external mode sources
#  EXT_SRC  = ext_svr.c
#  EXT_SRC += updown.c
#  EXT_SRC += ext_work.c
#  EXT_SRC += ext_svr_serial_transport.c
#  EXT_SRC += ext_serial_pkt.c
#  EXT_SRC += ext_serial_c167_port.c
#  
  # static memory management (optional)
#  ifeq ($(ExtModeStatMemAlloc),1) 
    # memory manager
#	EXT_SRC += mem_mgr.c
#  endif
#  SRCS += EXT_SRC
#endif


USER_SRCS =
USER_OBJS = $(addsuffix .o, $(basename $(USER_SRCS)))
LOCAL_USER_OBJS = $(notdir $(USER_OBJS))

OBJS      = $(addsuffix .o, $(basename $(SRCS))) $(USER_OBJS)
LINK_OBJS = $(addsuffix .o, $(basename $(SRCS))) $(LOCAL_USER_OBJS)

SHARED_SRC := $(wildcard $(SHARED_SRC))
SHARED_OBJS = $(addsuffix .o, $(basename $(SHARED_SRC)))

#--------------------------------- Rules ---------------------------------------
ifeq ($(MODELREF_TARGET_TYPE),NONE)
# Top-level model for RTW


$(RELATIVE_PATH_TO_ANCHOR)/$(MODEL).$(OUT) : $(OBJS) $(SHARED_LIB) $(MODELREF_LINK_LIBS) $(LIBS)
	$(LD) $(MCPU) $(LINK_OBJS) $(MODELREF_LINK_LIBS) $(SYSLIBS) $(SHARED_LIB) $(LIBS) $(LDLIBPIC) -o $(RELATIVE_PATH_TO_ANCHOR)/$(MODEL).$(OUT) $(T_LINKER_SCRIPT) $(LDFLAGS)	 		
		@echo "$(BUILD_SUCCESS) $(BUILD_PRODUCT_TYPE): $@  [$(PIC_REF)]"
ifeq ($(ProduceHexOutput),1)
	$(GCCPATH)/$(BIN2HEX) -omf=$(OMF) $(RELATIVE_PATH_TO_ANCHOR)/$(MODEL).$(OUT)
	@echo "*** Converted $(MODEL).$(OUT) to $(MODEL).hex"	
endif		
ifeq ($(AssemblyListing),1)			
	$(GCCPATH)/$(OBJDUMP) -omf=$(OMF) -S -f -Msymbolic $(RELATIVE_PATH_TO_ANCHOR)/$(MODEL).$(OUT) > $(RELATIVE_PATH_TO_ANCHOR)/$(MODEL).lst
	@echo "*** Created Assembly list file $(MODEL).lst"	
endif	


ifeq ($(OMF),elf)
ifeq ($(wildcard $(RELATIVE_PATH_TO_ANCHOR)/$(MODEL).cof),)	# if file exist
else
	$(DEL) $(RELATIVE_PATH_TO_ANCHOR)\$(MODEL).cof
endif
endif

ifeq ($(OMF),coff)
ifeq ($(wildcard $(RELATIVE_PATH_TO_ANCHOR)/$(MODEL).elf),)	# if file exist
else
	$(DEL) $(RELATIVE_PATH_TO_ANCHOR)\$(MODEL).elf
endif
endif
				
ifeq ($(ProduceHexOutput),0)
ifeq ($(wildcard $(RELATIVE_PATH_TO_ANCHOR)/$(MODEL).hex),)	# if file exist
else
	$(DEL) $(RELATIVE_PATH_TO_ANCHOR)\$(MODEL).hex
endif
endif

ifeq ($(AssemblyListing),0)
ifeq ($(wildcard $(RELATIVE_PATH_TO_ANCHOR)/$(MODEL).lst),)		# if file exist
else
	$(DEL) $(RELATIVE_PATH_TO_ANCHOR)\$(MODEL).lst
endif
endif
		
		
else
# sub-model for RTW
$(PRODUCT) : $(OBJS) $(SHARED_OBJS)
	$(AR) $(MODELLIB) $(LINK_OBJS)
	@echo "### $(MODELLIB) Created"
	@echo "$(BUILD_SUCCESS) $(BUILD_PRODUCT_TYPE): $@"	
endif
	
%.o : %.c
	$(CC) -c $(CFLAGS) $<

%.o : %.cpp
	$(CC) -c $(CPPFLAGS) $<

%.o : %.s
	$(CC) -c -mcpu=$(PIC_REF) $< -Wa,-g
	
%.o : ../%.c
	$(CC) -c $(CFLAGS) $<

%.o : ../%.cpp
	$(CC) -c $(CPPFLAGS) $<
	
%.o : ../%.s
	$(CC) -c -mcpu=$(PIC_REF) $< -Wa,-g

%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.c
	$(CC) -c $(CFLAGS) $<

%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.cpp
	$(CC) -c $(CPPFLAGS) $<
	
%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.s
	$(CC) -c -mcpu=$(PIC_REF) $< -Wa,-g
	

%.o : $(MATLAB_ROOT)/rtw/c/src/%.c
	$(CC) -c $(CFLAGS) $<

%.o : $(MATLAB_ROOT)/rtw/c/src/ext_mode/common/%.c
	$(CC) -c $(CFLAGS) $<

%.o : $(MATLAB_ROOT)/rtw/c/src/ext_mode/custom/%.c
	$(CC) -c $(CFLAGS) $<

%.o : C:\Users\Maestria01\Dropbox\TESIS_Maestria\Matlab\mplabtoolbox\Controles_PI\ControlPI_mod\ControlPI_Tilt\Source/%.c
	$(CC) -c $(CFLAGS) $<
%.o : $(MATLAB_ROOT)\rtw\c\src/%.c
	$(CC) -c $(CFLAGS) $<
%.o : $(MATLAB_ROOT)\simulink\src/%.c
	$(CC) -c $(CFLAGS) $<


%.o : C:\Users\Maestria01\Dropbox\TESIS_Maestria\Matlab\mplabtoolbox\Controles_PI\ControlPI_mod\ControlPI_Tilt\Source/%.cpp
	$(CC) -c $(CPPFLAGS) $<
%.o : $(MATLAB_ROOT)\rtw\c\src/%.cpp
	$(CC) -c $(CPPFLAGS) $<
%.o : $(MATLAB_ROOT)\simulink\src/%.cpp
	$(CC) -c $(CPPFLAGS) $<


%.o : C:\Users\Maestria01\Dropbox\TESIS_Maestria\Matlab\mplabtoolbox\Controles_PI\ControlPI_mod\ControlPI_Tilt\Source/%.s
	$(CC) -c -mcpu=$(PIC_REF) $< -Wa,-g
%.o : $(MATLAB_ROOT)\rtw\c\src/%.s
	$(CC) -c -mcpu=$(PIC_REF) $< -Wa,-g
%.o : $(MATLAB_ROOT)\simulink\src/%.s
	$(CC) -c -mcpu=$(PIC_REF) $< -Wa,-g


%.o : $(MATLAB_ROOT)/simulink/src/%.c
	$(CC) -c $(CFLAGS) $<

%.o : $(MATLAB_ROOT)/simulink/src/%.cpp
	$(CC) -c $(CPPFLAGS) $<

	
	
#------------------------------- Libraries -------------------------------------





#----------------------------- Dependencies ------------------------------------

$(OBJS) : $(MAKEFILE) rtw_proj.tmw

$(SHARED_OBJS) : $(SHARED_BIN_DIR)/%.o : $(SHARED_SRC_DIR)/%.c  
	$(CC) -c $(CFLAGS) $(SHARED_OUTPUT_OPTS) $<

$(SHARED_OBJS) : $(SHARED_BIN_DIR)/%.o : $(SHARED_SRC_DIR)/%.s  
	$(CC) -c -mcpu=$(PIC_REF) $< -Wa,-g
	
$(SHARED_LIB) : $(SHARED_OBJS)
	@echo "### Creating $@ "
	$(AR) $@ $(SHARED_OBJS)
	@echo "### $@ Created "

