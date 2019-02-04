#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/pwmprueba.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/pwmprueba.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=src/pwmprueba.c src/MCHP_QEI1_Interrupt.c src/MCHP_UART1_Interrupt.c src/pwmprueba_main.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/src/pwmprueba.o ${OBJECTDIR}/src/MCHP_QEI1_Interrupt.o ${OBJECTDIR}/src/MCHP_UART1_Interrupt.o ${OBJECTDIR}/src/pwmprueba_main.o
POSSIBLE_DEPFILES=${OBJECTDIR}/src/pwmprueba.o.d ${OBJECTDIR}/src/MCHP_QEI1_Interrupt.o.d ${OBJECTDIR}/src/MCHP_UART1_Interrupt.o.d ${OBJECTDIR}/src/pwmprueba_main.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/src/pwmprueba.o ${OBJECTDIR}/src/MCHP_QEI1_Interrupt.o ${OBJECTDIR}/src/MCHP_UART1_Interrupt.o ${OBJECTDIR}/src/pwmprueba_main.o

# Source Files
SOURCEFILES=src/pwmprueba.c src/MCHP_QEI1_Interrupt.c src/MCHP_UART1_Interrupt.c src/pwmprueba_main.c


CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/pwmprueba.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=33FJ32MC204
MP_LINKER_FILE_OPTION=,--script=p33FJ32MC204.gld
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/src/pwmprueba.o: src/pwmprueba.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/pwmprueba.o.d 
	@${RM} ${OBJECTDIR}/src/pwmprueba.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/pwmprueba.c  -o ${OBJECTDIR}/src/pwmprueba.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/src/pwmprueba.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1    -omf=elf -I"pwmprueba.X/src" -I"." -I"src" -I".." -I"C:/PROGRA~2/MICROC~1/xc16/v1.23/include" -I"C:/PROGRA~2/MICROC~1/xc16/v1.23/support/dsPIC33F/h" -I"C:/PROGRA~2/MICROC~1/xc16/v1.23/support/generic/h" -I"C:/PROGRA~2/MICROC~1/xc16/v1.23/support/PERIPH~2" -I"C:/Program Files/MATLAB/R2013b/simulink/include" -I"C:/Program Files/MATLAB/R2013b/extern/include" -I"C:/Program Files/MATLAB/R2013b/rtw/c/src" -I"C:/Program Files/MATLAB/R2013b/rtw/c/ert" -I"C:/Program Files/MATLAB/R2013b/rtw/c/src/ext_mode/common" -I"C:/Program Files/MATLAB/R2013b/rtw/c/src/ext_mode/custom" -I"C:/Program Files/MATLAB/R2013b/simulink/src" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/src/pwmprueba.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/src/MCHP_QEI1_Interrupt.o: src/MCHP_QEI1_Interrupt.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/MCHP_QEI1_Interrupt.o.d 
	@${RM} ${OBJECTDIR}/src/MCHP_QEI1_Interrupt.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/MCHP_QEI1_Interrupt.c  -o ${OBJECTDIR}/src/MCHP_QEI1_Interrupt.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/src/MCHP_QEI1_Interrupt.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1    -omf=elf -I"pwmprueba.X/src" -I"." -I"src" -I".." -I"C:/PROGRA~2/MICROC~1/xc16/v1.23/include" -I"C:/PROGRA~2/MICROC~1/xc16/v1.23/support/dsPIC33F/h" -I"C:/PROGRA~2/MICROC~1/xc16/v1.23/support/generic/h" -I"C:/PROGRA~2/MICROC~1/xc16/v1.23/support/PERIPH~2" -I"C:/Program Files/MATLAB/R2013b/simulink/include" -I"C:/Program Files/MATLAB/R2013b/extern/include" -I"C:/Program Files/MATLAB/R2013b/rtw/c/src" -I"C:/Program Files/MATLAB/R2013b/rtw/c/ert" -I"C:/Program Files/MATLAB/R2013b/rtw/c/src/ext_mode/common" -I"C:/Program Files/MATLAB/R2013b/rtw/c/src/ext_mode/custom" -I"C:/Program Files/MATLAB/R2013b/simulink/src" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/src/MCHP_QEI1_Interrupt.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/src/MCHP_UART1_Interrupt.o: src/MCHP_UART1_Interrupt.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/MCHP_UART1_Interrupt.o.d 
	@${RM} ${OBJECTDIR}/src/MCHP_UART1_Interrupt.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/MCHP_UART1_Interrupt.c  -o ${OBJECTDIR}/src/MCHP_UART1_Interrupt.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/src/MCHP_UART1_Interrupt.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1    -omf=elf -I"pwmprueba.X/src" -I"." -I"src" -I".." -I"C:/PROGRA~2/MICROC~1/xc16/v1.23/include" -I"C:/PROGRA~2/MICROC~1/xc16/v1.23/support/dsPIC33F/h" -I"C:/PROGRA~2/MICROC~1/xc16/v1.23/support/generic/h" -I"C:/PROGRA~2/MICROC~1/xc16/v1.23/support/PERIPH~2" -I"C:/Program Files/MATLAB/R2013b/simulink/include" -I"C:/Program Files/MATLAB/R2013b/extern/include" -I"C:/Program Files/MATLAB/R2013b/rtw/c/src" -I"C:/Program Files/MATLAB/R2013b/rtw/c/ert" -I"C:/Program Files/MATLAB/R2013b/rtw/c/src/ext_mode/common" -I"C:/Program Files/MATLAB/R2013b/rtw/c/src/ext_mode/custom" -I"C:/Program Files/MATLAB/R2013b/simulink/src" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/src/MCHP_UART1_Interrupt.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/src/pwmprueba_main.o: src/pwmprueba_main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/pwmprueba_main.o.d 
	@${RM} ${OBJECTDIR}/src/pwmprueba_main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/pwmprueba_main.c  -o ${OBJECTDIR}/src/pwmprueba_main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/src/pwmprueba_main.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1    -omf=elf -I"pwmprueba.X/src" -I"." -I"src" -I".." -I"C:/PROGRA~2/MICROC~1/xc16/v1.23/include" -I"C:/PROGRA~2/MICROC~1/xc16/v1.23/support/dsPIC33F/h" -I"C:/PROGRA~2/MICROC~1/xc16/v1.23/support/generic/h" -I"C:/PROGRA~2/MICROC~1/xc16/v1.23/support/PERIPH~2" -I"C:/Program Files/MATLAB/R2013b/simulink/include" -I"C:/Program Files/MATLAB/R2013b/extern/include" -I"C:/Program Files/MATLAB/R2013b/rtw/c/src" -I"C:/Program Files/MATLAB/R2013b/rtw/c/ert" -I"C:/Program Files/MATLAB/R2013b/rtw/c/src/ext_mode/common" -I"C:/Program Files/MATLAB/R2013b/rtw/c/src/ext_mode/custom" -I"C:/Program Files/MATLAB/R2013b/simulink/src" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/src/pwmprueba_main.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
else
${OBJECTDIR}/src/pwmprueba.o: src/pwmprueba.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/pwmprueba.o.d 
	@${RM} ${OBJECTDIR}/src/pwmprueba.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/pwmprueba.c  -o ${OBJECTDIR}/src/pwmprueba.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/src/pwmprueba.o.d"        -g -omf=elf -I"pwmprueba.X/src" -I"." -I"src" -I".." -I"C:/PROGRA~2/MICROC~1/xc16/v1.23/include" -I"C:/PROGRA~2/MICROC~1/xc16/v1.23/support/dsPIC33F/h" -I"C:/PROGRA~2/MICROC~1/xc16/v1.23/support/generic/h" -I"C:/PROGRA~2/MICROC~1/xc16/v1.23/support/PERIPH~2" -I"C:/Program Files/MATLAB/R2013b/simulink/include" -I"C:/Program Files/MATLAB/R2013b/extern/include" -I"C:/Program Files/MATLAB/R2013b/rtw/c/src" -I"C:/Program Files/MATLAB/R2013b/rtw/c/ert" -I"C:/Program Files/MATLAB/R2013b/rtw/c/src/ext_mode/common" -I"C:/Program Files/MATLAB/R2013b/rtw/c/src/ext_mode/custom" -I"C:/Program Files/MATLAB/R2013b/simulink/src" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/src/pwmprueba.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/src/MCHP_QEI1_Interrupt.o: src/MCHP_QEI1_Interrupt.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/MCHP_QEI1_Interrupt.o.d 
	@${RM} ${OBJECTDIR}/src/MCHP_QEI1_Interrupt.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/MCHP_QEI1_Interrupt.c  -o ${OBJECTDIR}/src/MCHP_QEI1_Interrupt.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/src/MCHP_QEI1_Interrupt.o.d"        -g -omf=elf -I"pwmprueba.X/src" -I"." -I"src" -I".." -I"C:/PROGRA~2/MICROC~1/xc16/v1.23/include" -I"C:/PROGRA~2/MICROC~1/xc16/v1.23/support/dsPIC33F/h" -I"C:/PROGRA~2/MICROC~1/xc16/v1.23/support/generic/h" -I"C:/PROGRA~2/MICROC~1/xc16/v1.23/support/PERIPH~2" -I"C:/Program Files/MATLAB/R2013b/simulink/include" -I"C:/Program Files/MATLAB/R2013b/extern/include" -I"C:/Program Files/MATLAB/R2013b/rtw/c/src" -I"C:/Program Files/MATLAB/R2013b/rtw/c/ert" -I"C:/Program Files/MATLAB/R2013b/rtw/c/src/ext_mode/common" -I"C:/Program Files/MATLAB/R2013b/rtw/c/src/ext_mode/custom" -I"C:/Program Files/MATLAB/R2013b/simulink/src" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/src/MCHP_QEI1_Interrupt.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/src/MCHP_UART1_Interrupt.o: src/MCHP_UART1_Interrupt.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/MCHP_UART1_Interrupt.o.d 
	@${RM} ${OBJECTDIR}/src/MCHP_UART1_Interrupt.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/MCHP_UART1_Interrupt.c  -o ${OBJECTDIR}/src/MCHP_UART1_Interrupt.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/src/MCHP_UART1_Interrupt.o.d"        -g -omf=elf -I"pwmprueba.X/src" -I"." -I"src" -I".." -I"C:/PROGRA~2/MICROC~1/xc16/v1.23/include" -I"C:/PROGRA~2/MICROC~1/xc16/v1.23/support/dsPIC33F/h" -I"C:/PROGRA~2/MICROC~1/xc16/v1.23/support/generic/h" -I"C:/PROGRA~2/MICROC~1/xc16/v1.23/support/PERIPH~2" -I"C:/Program Files/MATLAB/R2013b/simulink/include" -I"C:/Program Files/MATLAB/R2013b/extern/include" -I"C:/Program Files/MATLAB/R2013b/rtw/c/src" -I"C:/Program Files/MATLAB/R2013b/rtw/c/ert" -I"C:/Program Files/MATLAB/R2013b/rtw/c/src/ext_mode/common" -I"C:/Program Files/MATLAB/R2013b/rtw/c/src/ext_mode/custom" -I"C:/Program Files/MATLAB/R2013b/simulink/src" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/src/MCHP_UART1_Interrupt.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/src/pwmprueba_main.o: src/pwmprueba_main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/pwmprueba_main.o.d 
	@${RM} ${OBJECTDIR}/src/pwmprueba_main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/pwmprueba_main.c  -o ${OBJECTDIR}/src/pwmprueba_main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/src/pwmprueba_main.o.d"        -g -omf=elf -I"pwmprueba.X/src" -I"." -I"src" -I".." -I"C:/PROGRA~2/MICROC~1/xc16/v1.23/include" -I"C:/PROGRA~2/MICROC~1/xc16/v1.23/support/dsPIC33F/h" -I"C:/PROGRA~2/MICROC~1/xc16/v1.23/support/generic/h" -I"C:/PROGRA~2/MICROC~1/xc16/v1.23/support/PERIPH~2" -I"C:/Program Files/MATLAB/R2013b/simulink/include" -I"C:/Program Files/MATLAB/R2013b/extern/include" -I"C:/Program Files/MATLAB/R2013b/rtw/c/src" -I"C:/Program Files/MATLAB/R2013b/rtw/c/ert" -I"C:/Program Files/MATLAB/R2013b/rtw/c/src/ext_mode/common" -I"C:/Program Files/MATLAB/R2013b/rtw/c/src/ext_mode/custom" -I"C:/Program Files/MATLAB/R2013b/simulink/src" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/src/pwmprueba_main.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemblePreproc
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/pwmprueba.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk  C:/PROGRA~2/MICROC~1/xc16/v1.23/lib/dsPIC33F/libp33FJ32MC204-elf.a C:/PROGRA~2/MICROC~1/xc16/v1.23/lib/libpic30-elf.a C:/PROGRA~2/MICROC~1/xc16/v1.23/lib/libm-elf.a C:/PROGRA~2/MICROC~1/xc16/v1.23/lib/libc-elf.a C:/PROGRA~2/MICROC~1/xc16/v1.23/lib/libq-elf.a C:/PROGRA~2/MICROC~1/xc16/v1.23/lib/libq-dsp-elf.a  
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/pwmprueba.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}    C:\PROGRA~2\MICROC~1\xc16\v1.23\lib\dsPIC33F\libp33FJ32MC204-elf.a C:\PROGRA~2\MICROC~1\xc16\v1.23\lib\libpic30-elf.a C:\PROGRA~2\MICROC~1\xc16\v1.23\lib\libm-elf.a C:\PROGRA~2\MICROC~1\xc16\v1.23\lib\libc-elf.a C:\PROGRA~2\MICROC~1\xc16\v1.23\lib\libq-elf.a C:\PROGRA~2\MICROC~1\xc16\v1.23\lib\libq-dsp-elf.a  -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -omf=elf  -mreserve=data@0x800:0x81F -mreserve=data@0x820:0x821 -mreserve=data@0x822:0x823 -mreserve=data@0x824:0x825 -mreserve=data@0x826:0x84F   -Wl,,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_ICD3=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--library-path="pwmprueba.X/src",--library-path=".",--library-path="src",--library-path="..",--library-path="C:/PROGRA~2/MICROC~1/xc16/v1.23/include",--library-path="C:/PROGRA~2/MICROC~1/xc16/v1.23/support/dsPIC33F/h",--library-path="C:/PROGRA~2/MICROC~1/xc16/v1.23/support/generic/h",--library-path="C:/PROGRA~2/MICROC~1/xc16/v1.23/support/PERIPH~2",--library-path="C:/Program Files/MATLAB/R2013b/simulink/include",--library-path="C:/Program Files/MATLAB/R2013b/extern/include",--library-path="C:/Program Files/MATLAB/R2013b/rtw/c/src",--library-path="C:/Program Files/MATLAB/R2013b/rtw/c/ert",--library-path="C:/Program Files/MATLAB/R2013b/rtw/c/src/ext_mode/common",--library-path="C:/Program Files/MATLAB/R2013b/rtw/c/src/ext_mode/custom",--library-path="C:/Program Files/MATLAB/R2013b/simulink/src",--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem$(MP_EXTRA_LD_POST) 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/pwmprueba.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk  C:/PROGRA~2/MICROC~1/xc16/v1.23/lib/dsPIC33F/libp33FJ32MC204-elf.a C:/PROGRA~2/MICROC~1/xc16/v1.23/lib/libpic30-elf.a C:/PROGRA~2/MICROC~1/xc16/v1.23/lib/libm-elf.a C:/PROGRA~2/MICROC~1/xc16/v1.23/lib/libc-elf.a C:/PROGRA~2/MICROC~1/xc16/v1.23/lib/libq-elf.a C:/PROGRA~2/MICROC~1/xc16/v1.23/lib/libq-dsp-elf.a 
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/pwmprueba.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}    C:\PROGRA~2\MICROC~1\xc16\v1.23\lib\dsPIC33F\libp33FJ32MC204-elf.a C:\PROGRA~2\MICROC~1\xc16\v1.23\lib\libpic30-elf.a C:\PROGRA~2\MICROC~1\xc16\v1.23\lib\libm-elf.a C:\PROGRA~2\MICROC~1\xc16\v1.23\lib\libc-elf.a C:\PROGRA~2\MICROC~1\xc16\v1.23\lib\libq-elf.a C:\PROGRA~2\MICROC~1\xc16\v1.23\lib\libq-dsp-elf.a  -mcpu=$(MP_PROCESSOR_OPTION)        -omf=elf -Wl,,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--library-path="pwmprueba.X/src",--library-path=".",--library-path="src",--library-path="..",--library-path="C:/PROGRA~2/MICROC~1/xc16/v1.23/include",--library-path="C:/PROGRA~2/MICROC~1/xc16/v1.23/support/dsPIC33F/h",--library-path="C:/PROGRA~2/MICROC~1/xc16/v1.23/support/generic/h",--library-path="C:/PROGRA~2/MICROC~1/xc16/v1.23/support/PERIPH~2",--library-path="C:/Program Files/MATLAB/R2013b/simulink/include",--library-path="C:/Program Files/MATLAB/R2013b/extern/include",--library-path="C:/Program Files/MATLAB/R2013b/rtw/c/src",--library-path="C:/Program Files/MATLAB/R2013b/rtw/c/ert",--library-path="C:/Program Files/MATLAB/R2013b/rtw/c/src/ext_mode/common",--library-path="C:/Program Files/MATLAB/R2013b/rtw/c/src/ext_mode/custom",--library-path="C:/Program Files/MATLAB/R2013b/simulink/src",--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem$(MP_EXTRA_LD_POST) 
	${MP_CC_DIR}\\xc16-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/pwmprueba.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -a  -omf=elf  
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
