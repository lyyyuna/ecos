//==========================================================================
//
//      snmp/snmpagent/current/src/mibgroup/mibII/interfaces.c
//
//
//==========================================================================
//####ECOSGPLCOPYRIGHTBEGIN####
// -------------------------------------------
// This file is part of eCos, the Embedded Configurable Operating System.
// Copyright (C) 1998, 1999, 2000, 2001, 2002 Red Hat, Inc.
//
// eCos is free software; you can redistribute it and/or modify it under
// the terms of the GNU General Public License as published by the Free
// Software Foundation; either version 2 or (at your option) any later version.
//
// eCos is distributed in the hope that it will be useful, but WITHOUT ANY
// WARRANTY; without even the implied warranty of MERCHANTABILITY or
// FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
// for more details.
//
// You should have received a copy of the GNU General Public License along
// with eCos; if not, write to the Free Software Foundation, Inc.,
// 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA.
//
// As a special exception, if other files instantiate templates or use macros
// or inline functions from this file, or you compile this file and link it
// with other works to produce a work based on this file, this file does not
// by itself cause the resulting work to be covered by the GNU General Public
// License. However the source code for this file must still be made available
// in accordance with section (3) of the GNU General Public License.
//
// This exception does not invalidate any other reasons why a work based on
// this file might be covered by the GNU General Public License.
//
// Alternative licenses for eCos may be arranged by contacting Red Hat, Inc.
// at http://sources.redhat.com/ecos/ecos-license
// -------------------------------------------
//####ECOSGPLCOPYRIGHTEND####
//####UCDSNMPCOPYRIGHTBEGIN####
//
// -------------------------------------------
//
// Portions of this software may have been derived from the UCD-SNMP
// project,  <http://ucd-snmp.ucdavis.edu/>  from the University of
// California at Davis, which was originally based on the Carnegie Mellon
// University SNMP implementation.  Portions of this software are therefore
// covered by the appropriate copyright disclaimers included herein.
//
// The release used was version 4.1.2 of May 2000.  "ucd-snmp-4.1.2"
// -------------------------------------------
//
//####UCDSNMPCOPYRIGHTEND####
//==========================================================================
//#####DESCRIPTIONBEGIN####
//
// Author(s):    hmt
// Contributors: hmt
// Date:         2000-05-30
// Purpose:      Port of UCD-SNMP distribution to eCos.
// Description:  
//              
//
//####DESCRIPTIONEND####
//
//==========================================================================
/********************************************************************
       Copyright 1989, 1991, 1992 by Carnegie Mellon University
 
                          Derivative Work -
Copyright 1996, 1998, 1999, 2000 The Regents of the University of California
 
                         All Rights Reserved
 
Permission to use, copy, modify and distribute this software and its
documentation for any purpose and without fee is hereby granted,
provided that the above copyright notice appears in all copies and
that both that copyright notice and this permission notice appear in
supporting documentation, and that the name of CMU and The Regents of
the University of California not be used in advertising or publicity
pertaining to distribution of the software without specific written
permission.
 
CMU AND THE REGENTS OF THE UNIVERSITY OF CALIFORNIA DISCLAIM ALL
WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS.  IN NO EVENT SHALL CMU OR
THE REGENTS OF THE UNIVERSITY OF CALIFORNIA BE LIABLE FOR ANY SPECIAL,
INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING
FROM THE LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF
CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN
CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
*********************************************************************/
/* This file was generated by mib2c and is intended for use as a mib module
   for the ucd-snmp snmpd agent. */


/* This should always be included first before anything else */
#include <config.h>


/* minimal include directives */
#include "mibincl.h"
#include "mibgroup/util_funcs.h"
#include "mibgroup/mibII/interfaces.h"

#include <net/if_types.h>

// Get info about the device
#include <pkgconf/system.h>

// These two two acquire all the statistics.
#include <cyg/io/eth/eth_drv.h>
#include <cyg/io/eth/eth_drv_stats.h>
#include <sys/sockio.h>

/* 
 * interfaces_variables_oid:
 *   this is the top level oid that we want to register under.  This
 *   is essentially a prefix, with the suffix appearing in the
 *   variable below.
 */
oid interfaces_variables_oid[] = { 1,3,6,1,2,1,2 };


extern struct ifnet_head ifnet;



/* 
 * variable4 interfaces_variables:
 *   this variable defines function callbacks and type return information 
 *   for the interfaces mib section 
 */


struct variable4 interfaces_variables[] = {
/*  magic number        , variable type , ro/rw , callback fn  , L, oidsuffix */
#define   IFNUMBER              1
  { IFNUMBER            , ASN_INTEGER   , RONLY , var_interfaces, 1, { 1 } },
#define   IFINDEX               4
  { IFINDEX             , ASN_INTEGER   , RONLY , var_ifTable, 3, { 2,1,1 } },
#define   IFDESCR               5
  { IFDESCR             , ASN_OCTET_STR , RONLY , var_ifTable, 3, { 2,1,2 } },
#define   IFTYPE                6
  { IFTYPE              , ASN_INTEGER   , RONLY , var_ifTable, 3, { 2,1,3 } },
#define   IFMTU                 7
  { IFMTU               , ASN_INTEGER   , RONLY , var_ifTable, 3, { 2,1,4 } },
#define   IFSPEED               8
  { IFSPEED             , ASN_GAUGE     , RONLY , var_ifTable, 3, { 2,1,5 } },
#define   IFPHYSADDRESS         9
  { IFPHYSADDRESS       , ASN_OCTET_STR , RONLY , var_ifTable, 3, { 2,1,6 } },
#define   IFADMINSTATUS         10
  { IFADMINSTATUS       , ASN_INTEGER   , RWRITE, var_ifTable, 3, { 2,1,7 } },
#define   IFOPERSTATUS          11
  { IFOPERSTATUS        , ASN_INTEGER   , RONLY , var_ifTable, 3, { 2,1,8 } },
#define   IFLASTCHANGE          12
  { IFLASTCHANGE        , ASN_TIMETICKS , RONLY , var_ifTable, 3, { 2,1,9 } },
#define   IFINOCTETS            13
  { IFINOCTETS          , ASN_COUNTER   , RONLY , var_ifTable, 3, { 2,1,10 } },
#define   IFINUCASTPKTS         14
  { IFINUCASTPKTS       , ASN_COUNTER   , RONLY , var_ifTable, 3, { 2,1,11 } },
#define   IFINNUCASTPKTS        15
  { IFINNUCASTPKTS      , ASN_COUNTER   , RONLY , var_ifTable, 3, { 2,1,12 } },
#define   IFINDISCARDS          16
  { IFINDISCARDS        , ASN_COUNTER   , RONLY , var_ifTable, 3, { 2,1,13 } },
#define   IFINERRORS            17
  { IFINERRORS          , ASN_COUNTER   , RONLY , var_ifTable, 3, { 2,1,14 } },
#define   IFINUNKNOWNPROTOS     18
  { IFINUNKNOWNPROTOS   , ASN_COUNTER   , RONLY , var_ifTable, 3, { 2,1,15 } },
#define   IFOUTOCTETS           19
  { IFOUTOCTETS         , ASN_COUNTER   , RONLY , var_ifTable, 3, { 2,1,16 } },
#define   IFOUTUCASTPKTS        20
  { IFOUTUCASTPKTS      , ASN_COUNTER   , RONLY , var_ifTable, 3, { 2,1,17 } },
#define   IFOUTNUCASTPKTS       21
  { IFOUTNUCASTPKTS     , ASN_COUNTER   , RONLY , var_ifTable, 3, { 2,1,18 } },
#define   IFOUTDISCARDS         22
  { IFOUTDISCARDS       , ASN_COUNTER   , RONLY , var_ifTable, 3, { 2,1,19 } },
#define   IFOUTERRORS           23
  { IFOUTERRORS         , ASN_COUNTER   , RONLY , var_ifTable, 3, { 2,1,20 } },
#define   IFOUTQLEN             24
  { IFOUTQLEN           , ASN_GAUGE     , RONLY , var_ifTable, 3, { 2,1,21 } },
#define   IFSPECIFIC            25
  { IFSPECIFIC          , ASN_OBJECT_ID , RONLY , var_ifTable, 3, { 2,1,22 } },

};
/*    (L = length of the oidsuffix) */


/*
 * init_interfaces():
 *   Initialization routine.  This is called when the agent starts up.
 *   At a minimum, registration of your variables should take place here.
 */
void init_interfaces(void) {


  /* register ourselves with the agent to handle our mib tree */
  REGISTER_MIB("interfaces", interfaces_variables, variable4,
               interfaces_variables_oid);


  /* place any other initialization junk you need here */
}


/*
 * var_interfaces():
 *   This function is called every time the agent gets a request for
 *   a scalar variable that might be found within your mib section
 *   registered above.  It is up to you to do the right thing and
 *   return the correct value.
 *     You should also correct the value of "var_len" if necessary.
 *
 *   Please see the documentation for more information about writing
 *   module extensions, and check out the examples in the examples
 *   and mibII directories.
 */
unsigned char *
var_interfaces(struct variable *vp, 
               oid     *name, 
               size_t  *length, 
               int     exact, 
               size_t  *var_len, 
               WriteMethod **write_method)
{
    

    /* variables we may use later */
    static long long_ret;
//    static unsigned char string[SPRINT_MAX_LEN];
//    static oid objid[MAX_OID_LEN];
//    static struct counter64 c64;


    if ( MATCH_FAILED ==
         header_generic(vp,name,length,exact,var_len,write_method) )
        return NULL;

    /* 
     * this is where we do the value assignments for the mib results.
     */
    switch(vp->magic) {
    case IFNUMBER: {
        register struct ifnet *ifp;
        long_ret = 0;
        for (ifp = ifnet.tqh_first; ifp != 0; ifp = ifp->if_list.tqe_next)
            long_ret++;
        
        return (unsigned char *) &long_ret;
    }   

    default:
        ERROR_MSG("");
    }
    return NULL;
}


/*
 * var_ifTable():
 *   Handle this table separately from the scalar value case.
 *   The workings of this are basically the same as for var_interfaces above.
 */
unsigned char *
var_ifTable(struct variable *vp,
    	    oid     *name,
    	    size_t  *length,
    	    int     exact,
    	    size_t  *var_len,
    	    WriteMethod **write_method)
{


    /* variables we may use later */
    static long long_ret;
    static unsigned char string[SPRINT_MAX_LEN];
    static oid objid[MAX_OID_LEN];
//  static struct counter64 c64;
    
    register struct ifnet *ifp;
    int interface_count = 0;
    
    for (ifp = ifnet.tqh_first; ifp != 0; ifp = ifp->if_list.tqe_next)
        interface_count++;
        
    /* 
     * This assumes that the table is a 'simple' table.
     *	See the implementation documentation for the meaning of this.
     *	You will need to provide the correct value for the TABLE_SIZE parameter
     *
     * If this table does not meet the requirements for a simple table,
     * you will need to provide the replacement code yourself.
     * Mib2c is not smart enough to write this for you.
     * Again, see the implementation documentation for what is required.
     */
    if ( header_simple_table( vp,name,length,exact,var_len,write_method,
                              interface_count)
         == MATCH_FAILED )
        return NULL;
    
    for ( interface_count = name[ (*length)-1 ], ifp = ifnet.tqh_first;
          interface_count > 1 && ifp != 0;
          interface_count-- )
        ifp = ifp->if_list.tqe_next;

    if ( ! ifp )
        return NULL;

// This is to assist customers with their own special interfaces; if they
// define IFT_CUSTOMER_SPECIAL to whatever their own device is, then its
// ioctl() will be called to handle these enquiries.
#ifdef IFT_CUSTOMER_SPECIAL
    if ( (ifp->if_type == IFT_CUSTOMER_SPECIAL) && (NULL != ifp->if_ioctl) )
    {
       if( (vp->magic == IFDESCR) || (vp->magic == IFPHYSADDRESS) )
       {
            (*ifp->if_ioctl)(ifp, vp->magic, (caddr_t)string);
	    *var_len = strlen(string);
	    return (unsigned char *) string;
       }
       else
       {
            (*ifp->if_ioctl)(ifp, vp->magic, (caddr_t)&long_ret);
	    return (unsigned char *) &long_ret;
       }
    }
#endif // IFT_CUSTOMER_SPECIAL

    if ( IFT_ETHER == ifp->if_type &&
         ((IFDESCR == vp->magic) ||
          (IFSPEED == vp->magic) ||
          (IFOUTDISCARDS == vp->magic) ||
          (IFOUTQLEN == vp->magic) )
        ) {
        // then acquire up to date information and deal with the relevent
        // keys (only):
        int i = -1;
        struct ether_drv_stats x;
        bzero( &x, sizeof( x ) );

        // Call the ioctl to get all the info.
        // (We KNOW it's an ether dev here, it should have an ioctl())
        if ( NULL != ifp->if_ioctl )
            i = (*ifp->if_ioctl)(ifp, SIOCGIFSTATSUD, (caddr_t)&x);

        switch(vp->magic) {
        case IFDESCR:
            if ( i || 0 == x.description[0] ) 
                strcpy( string, "<Ethernet, details not available>" );
            else
                strcpy( string, x.description );
            *var_len = strlen(string);
            return (unsigned char *) string;

        case IFSPEED:
            long_ret = x.speed;
            return (unsigned char *) &long_ret;

        case IFOUTDISCARDS:
            long_ret = x.tx_dropped;
            return (unsigned char *) &long_ret;

        case IFOUTQLEN:
            long_ret = x.tx_queue_len;
            return (unsigned char *) &long_ret;

        default:
            CYG_FAIL( "Bad magic; shouldn't be in here" );
            break;
        }
    }

    switch(vp->magic) {
    
    case IFINDEX:
        long_ret = name[(*length)-1];
        return (unsigned char *) &long_ret;
        
    case IFDESCR:
        switch ( ifp->if_type ) {
        case IFT_LOOP:
            strcpy( string, "(Loopback device)" );
            break;
        case IFT_PROPVIRTUAL:
            strcpy( string, "(Proprietary Virtual/Internal)" );
            break;
        default:
            strcpy( string, "Some shy network adaptor" );
            break;
        }
        *var_len = strlen(string);
        return (unsigned char *) string;

    case IFTYPE:
        long_ret = ifp->if_type;
        return (unsigned char *) &long_ret;

    case IFMTU:
        long_ret = ifp->if_mtu;
        return (unsigned char *) &long_ret;
        
    case IFSPEED:
        if ( IFT_LOOP == ifp->if_type )
            long_ret = 0;
        else
            long_ret = ifp->if_baudrate;
        return (unsigned char *) &long_ret;

    case IFPHYSADDRESS: {
        if ( IFT_ETHER == ifp->if_type ) {
            struct arpcom *ac = (struct arpcom *)ifp;
            bcopy(&ac->ac_enaddr, string, ETHER_ADDR_LEN);
        }
        else {
            bzero( string, ETHER_ADDR_LEN );
        }
        *var_len = ETHER_ADDR_LEN;
        return (unsigned char *) string;
    }
    case IFADMINSTATUS:
        //NOTSUPPORTED: *write_method = write_ifAdminStatus;
        long_ret = (ifp->if_flags & IFF_RUNNING) ? 1 : 2;
        return (unsigned char *) &long_ret;

    case IFOPERSTATUS:
        long_ret = (ifp->if_flags & IFF_UP) ? 1 : 2;
        return (unsigned char *) &long_ret;

    case IFLASTCHANGE:
        long_ret = 0; //FIXME: ifp->if_lastchange;
        return (unsigned char *) &long_ret;

    case IFINOCTETS:
        long_ret = ifp->if_ibytes;
        return (unsigned char *) &long_ret;

    case IFINUCASTPKTS:
        long_ret = ifp->if_ipackets - ifp->if_imcasts;
        return (unsigned char *) &long_ret;

    case IFINNUCASTPKTS:
        long_ret = ifp->if_imcasts;
        return (unsigned char *) &long_ret;

    case IFINDISCARDS:
        long_ret = ifp->if_iqdrops;
        return (unsigned char *) &long_ret;

    case IFINERRORS:
        long_ret = ifp->if_ierrors;
        return (unsigned char *) &long_ret;

    case IFINUNKNOWNPROTOS:
        long_ret = ifp->if_noproto;
        return (unsigned char *) &long_ret;

    case IFOUTOCTETS:
        long_ret = ifp->if_obytes;
        return (unsigned char *) &long_ret;

    case IFOUTUCASTPKTS:
        long_ret = ifp->if_opackets - ifp->if_omcasts;
        return (unsigned char *) &long_ret;

    case IFOUTNUCASTPKTS:
        long_ret = ifp->if_omcasts;
        return (unsigned char *) &long_ret;

    case IFOUTDISCARDS:
        long_ret = 0; // ETHER case dealt with above
        return (unsigned char *) &long_ret;

    case IFOUTERRORS:
        long_ret = ifp->if_oerrors;
        return (unsigned char *) &long_ret;

    case IFOUTQLEN:
        long_ret = 0; // ETHER case dealt with above
        return (unsigned char *) &long_ret;

    case IFSPECIFIC:
        objid[0] = 0;
        objid[1] = 0;
        *var_len = 2*sizeof(oid);
        return (unsigned char *) objid;
        
    default:
        ERROR_MSG("");
    }
    return NULL;
}



//NOTSUPPORTED: 
#if 0
int
write_ifAdminStatus(int      action,
            u_char   *var_val,
            u_char   var_val_type,
            size_t   var_val_len,
            u_char   *statP,
            oid      *name,
            size_t   name_len)
{
  static long *long_ret;
  int size;


  switch ( action ) {
        case RESERVE1:
          if (var_val_type != ASN_INTEGER){
              fprintf(stderr, "write to ifAdminStatus not ASN_INTEGER\n");
              return SNMP_ERR_WRONGTYPE;
          }
          if (var_val_len > sizeof(long_ret)){
              fprintf(stderr,"write to ifAdminStatus: bad length\n");
              return SNMP_ERR_WRONGLENGTH;
          }
          break;


        case RESERVE2:
          size = var_val_len;
          long_ret = (long *) var_val;


          break;


        case FREE:
             /* Release any resources that have been allocated */
          break;


        case ACTION:
             /* The variable has been stored in long_ret for you to use,
             and you have just been asked to do something with it.  Note
             that anything done here must be reversable in the UNDO case */
          break;


        case UNDO:
             /* Back out any changes made in the ACTION case */
          break;


        case COMMIT:
             /* Things are working well, so it's now safe to make the change
             permanently.  Make sure that anything done here can't fail! */
          break;
  }
  return SNMP_ERR_NOERROR;
}

#endif

// EOF interfaces.c
