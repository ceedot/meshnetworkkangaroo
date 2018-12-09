/*!
* The Clear BSD License
* Copyright (c) 2015, Freescale Semiconductor, Inc.
* Copyright 2016-2017 NXP
* All rights reserved.
*
* \file
*
* This file contains the structure used by every module present to identify itself
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted (subject to the limitations in the
* disclaimer below) provided that the following conditions are met:
* 
* * Redistributions of source code must retain the above copyright
*   notice, this list of conditions and the following disclaimer.
* 
* * Redistributions in binary form must reproduce the above copyright
*   notice, this list of conditions and the following disclaimer in the
*   documentation and/or other materials provided with the distribution.
* 
* * Neither the name of the copyright holder nor the names of its
*   contributors may be used to endorse or promote products derived from
*   this software without specific prior written permission.
* 
* NO EXPRESS OR IMPLIED LICENSES TO ANY PARTY'S PATENT RIGHTS ARE
* GRANTED BY THIS LICENSE. THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT
* HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED
* WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
* MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
* DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
* LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
* CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
* SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
* BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
* WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
* OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
* IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef _MODULE_INFO_H_
#define _MODULE_INFO_H_

/************************************************************************************
*************************************************************************************
* Include
*************************************************************************************
************************************************************************************/
#include "EmbeddedTypes.h"

/************************************************************************************
*************************************************************************************
* Public macros
*************************************************************************************
************************************************************************************/
#if defined(__GNUC__)

  extern uint32_t __start_VERSION_TAGS[];
  extern uint32_t __stop_VERSION_TAGS[];

  #define gVERSION_TAGS_startAddr_d ((moduleInfo_t*)__start_VERSION_TAGS)
  #define gVERSION_TAGS_endAddr_d   ((moduleInfo_t*)__stop_VERSION_TAGS)

#elif defined(__IAR_SYSTEMS_ICC__)
  #define gVERSION_TAGS_startAddr_d ((moduleInfo_t*)__section_begin(".VERSION_TAGS"))
  #define gVERSION_TAGS_endAddr_d   ((moduleInfo_t*)__section_end(".VERSION_TAGS"))
#else
  #define gVERSION_TAGS_startAddr_d ((moduleInfo_t*)0)
  #define gVERSION_TAGS_endAddr_d   ((moduleInfo_t*)0)
  #warning Module informaion will not be stored!
#endif

#define gVERSION_TAGS_entries_d  ( ((uint32_t)gVERSION_TAGS_endAddr_d - \
                                    (uint32_t)gVERSION_TAGS_startAddr_d)/ \
                                    sizeof(moduleInfo_t) )

#define gVERSION_TAGS_entrySizeNoPadding_d (sizeof(moduleInfo_t) -  \
                                            GetSizeOfMember(moduleInfo_t, padding))

/* Concatenate macros */
#define QU(x) #x
#define QUH(x) QU(x)

/************************************************************************************
*************************************************************************************
* Public type definitions
*************************************************************************************
************************************************************************************/

/* VERSION_TAGS is the section where module information will be stored */
#if defined(__IAR_SYSTEMS_ICC__)
#pragma section=".VERSION_TAGS"
#endif

typedef PACKED_STRUCT moduleInfo_tag {
  char **  moduleString;
  uint8_t  moduleId;
  uint8_t  versionNumber[3];
  uint16_t buildNumber;
  uint8_t  padding[2];
} moduleInfo_t;

/* MODULE INFO (VERSION_TAGS) REGISTER MACRO, DO NOT EDIT or REMOVE */
#define SET_MODULE_NAME(name) name##_##VERSION
#if defined(__IAR_SYSTEMS_ICC__)
#define RegisterModuleInfo(moduleName, moduleNameString, moduleId, versionNoMajor, versionNoMinor, versionNoPatch, buildNo) \
    _Pragma("location=\".VERSION_TAGS\"") __root \
    const moduleInfo_t \
    SET_MODULE_NAME(moduleName) \
      = { &moduleNameString, moduleId, {versionNoMajor, versionNoMinor, versionNoPatch}, buildNo }
#elif defined(__GNUC__)
#define RegisterModuleInfo(moduleName, moduleNameString, moduleId, versionNoMajor, versionNoMinor, versionNoPatch, buildNo) \
    const moduleInfo_t \
    SET_MODULE_NAME(moduleName) \
    __attribute__((section (".VERSION_TAGS"), used)) \
    = { &moduleNameString, moduleId, {versionNoMajor, versionNoMinor, versionNoPatch}, buildNo }
#else
#define RegisterModuleInfo(moduleName, moduleNameString, moduleId, versionNoMajor, versionNoMinor, versionNoPatch, buildNo)
    const moduleInfo_t \
    SET_MODULE_NAME(moduleName) \
    = { &moduleNameString, moduleId, {versionNoMajor, versionNoMinor, versionNoPatch}, buildNo } \
   #warning Unknown/undefined toolchain!
#endif

#endif /* _MODULE_INFO_H_ */
