#ifndef _SIB_H_
#define _SIB_H_
//==========================================================================
//
//      sib.h
//
//      RedBoot - structure of ARM flash file format
//
//==========================================================================
//####COPYRIGHTBEGIN####
//                                                                          
// -------------------------------------------                              
// The contents of this file are subject to the Red Hat eCos Public License 
// Version 1.1 (the "License"); you may not use this file except in         
// compliance with the License.  You may obtain a copy of the License at    
// http://www.redhat.com/                                                   
//                                                                          
// Software distributed under the License is distributed on an "AS IS"      
// basis, WITHOUT WARRANTY OF ANY KIND, either express or implied.  See the 
// License for the specific language governing rights and limitations under 
// the License.                                                             
//                                                                          
// The Original Code is eCos - Embedded Configurable Operating System,      
// released September 30, 1998.                                             
//                                                                          
// The Initial Developer of the Original Code is Red Hat.                   
// Portions created by Red Hat are                                          
// Copyright (C) 1998, 1999, 2000, 2001 Red Hat, Inc.                             
// All Rights Reserved.                                                     
// -------------------------------------------                              
//                                                                          
//####COPYRIGHTEND####
//==========================================================================
//#####DESCRIPTIONBEGIN####
//
// Author(s):    Philippe Robin
// Contributors: Philippe Robin, jskov
// Date:         2001-10-31
// Purpose:      
// Description:  
//              
// This code is part of RedBoot (tm).
//
//####DESCRIPTIONEND####
//
//==========================================================================

#include <cyg/hal/hal_io.h>

/*     type information :-
 * 0xffff ffff     -        deleted (usual flash erased value)
 * 0x0000 xxxx     -        Reserved for ARM usage:
 * Bit 0           -        ARM Executable Image
 * Bit 1           -        System Information Block
 * Bit 2           -        File System Block
 * 0xyyyy 0000     -        Available for customers (y != 0)
 */
#define TYPE_DELETED        0xFFFFFFFF
#define TYPE_ARM_MASK       0x0000FFFF
#define TYPE_CUSTOM_MASK    0xFFFF0000
#define TYPE_ARM_EXEC       0x00000001
#define TYPE_ARM_SIB        0x00000002
#define TYPE_ARM_SYSBLOCK   0x00000004

/* This is the type we use for RedBoot blocks */
#define TYPE_REDHAT_REDBOOT 0x52420000

/* The ARM monitor may be using a different memory mapping than RedBoot */
#ifndef _ADDR_REDBOOT_TO_ARM
# define _ADDR_REDBOOT_TO_ARM(x)
#endif

/* Filetypes */

#define  UNKNOWN_FILE      0x00000000
#define  MOT_S_RECORD      0x00000001
#define  INTEL_HEX         0x00000002
#define  ELF               0x00000004
#define  DWARF             0x00000008
#define  ARM_AOF           0x00000010
#define  ARM_AIF           0x00000020
#define  PLAIN_BINARY      0x00000040
#define  ARM_AIF_BIN       0x00000080
#define  MCS_TYPE          0x00000100

#define  CONVERT_TYPE      (MOT_S_RECORD | INTEL_HEX | MCS_TYPE | ELF)

#define SIB_OWNER_STRING_SIZE   32
#define MAX_SIB_SIZE            512
#define MAX_SIB_INDEX		64

#define SIB_HEADER_SIGNATURE    0xA00FFF9F /* This is an invalid instruction - MULGE pc,pc,pc */
#define FLASH_FOOTER_SIGNATURE  0xA0FFFF9F /* This is an invalid instruction - SMULALGES pc,pc,pc */


typedef struct SIBType {
    cyg_uint32  signature;
    cyg_uint32  size;
    char        owner[SIB_OWNER_STRING_SIZE];
    cyg_uint32  index;
    cyg_uint32  revision;
    cyg_uint32  checksum;
} tSIB; 

typedef struct SIBInfoType {
    cyg_uint32 SIB_number;      /* Unique number of SIB Block            */
    cyg_uint32 SIB_Extension;   /* Base of SIB Flash Block               */
    char Label[16];             /* String space for ownership string     */
    cyg_uint32 checksum;        /* SIB Image checksum                    */
} tSIBInfo;

typedef struct FooterType {
    void        *infoBase;      /* Address of first word of ImageFooter  */
    char        *blockBase;     /* Start of area reserved by this footer */
    cyg_uint32  signature;      /* 'Magic' number proves it's a footer   */
    cyg_uint32  type;           /* Area type: ARM Image, SIB, customer   */
    cyg_uint32  checksum;       /* Just this structure                   */
} tFooter ;

typedef struct ImageInfoType {
    cyg_uint32 bootFlags;       /* Boot flags, compression etc.          */
    cyg_uint32 imageNumber;     /* Unique number, selects for boot etc.  */
    char *loadAddress;          /* Address program should be loaded to   */
    cyg_uint32 length;          /* Actual size of image                  */
    char *address;                /* Image is executed from here           */
    char name[16];              /* Null terminated                       */
    char *headerBase;           /* Flash Address of any stripped header  */
    cyg_uint32 header_length;   /* Length of header in memory            */
    cyg_uint32 headerType;      /* AIF, RLF, s-record etc.               */
    cyg_uint32 checksum;        /* Image checksum (inc. this struct)     */
} tImageInfo;


#endif // _SIB_H_
