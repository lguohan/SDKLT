/*******************************************************************************
 *
 * DO NOT EDIT THIS FILE!
 * This file is auto-generated by fltg from INTERNAL/fltg/xgs/tnl/TNL_IPV6_ENCAP.tbl.ltl
 * Edits to this file will be lost when it is regenerated.
 *
 * Copyright: (c) 2018 Broadcom. All Rights Reserved. "Broadcom" refers to 
 * Broadcom Limited and/or its subsidiaries.
 * 
 * Broadcom Switch Software License
 * 
 * This license governs the use of the accompanying Broadcom software. Your 
 * use of the software indicates your acceptance of the terms and conditions 
 * of this license. If you do not agree to the terms and conditions of this 
 * license, do not use the software.
 * 1. Definitions
 *    "Licensor" means any person or entity that distributes its Work.
 *    "Software" means the original work of authorship made available under 
 *    this license.
 *    "Work" means the Software and any additions to or derivative works of 
 *    the Software that are made available under this license.
 *    The terms "reproduce," "reproduction," "derivative works," and 
 *    "distribution" have the meaning as provided under U.S. copyright law.
 *    Works, including the Software, are "made available" under this license 
 *    by including in or with the Work either (a) a copyright notice 
 *    referencing the applicability of this license to the Work, or (b) a copy 
 *    of this license.
 * 2. Grant of Copyright License
 *    Subject to the terms and conditions of this license, each Licensor 
 *    grants to you a perpetual, worldwide, non-exclusive, and royalty-free 
 *    copyright license to reproduce, prepare derivative works of, publicly 
 *    display, publicly perform, sublicense and distribute its Work and any 
 *    resulting derivative works in any form.
 * 3. Grant of Patent License
 *    Subject to the terms and conditions of this license, each Licensor 
 *    grants to you a perpetual, worldwide, non-exclusive, and royalty-free 
 *    patent license to make, have made, use, offer to sell, sell, import, and 
 *    otherwise transfer its Work, in whole or in part. This patent license 
 *    applies only to the patent claims licensable by Licensor that would be 
 *    infringed by Licensor's Work (or portion thereof) individually and 
 *    excluding any combinations with any other materials or technology.
 *    If you institute patent litigation against any Licensor (including a 
 *    cross-claim or counterclaim in a lawsuit) to enforce any patents that 
 *    you allege are infringed by any Work, then your patent license from such 
 *    Licensor to the Work shall terminate as of the date such litigation is 
 *    filed.
 * 4. Redistribution
 *    You may reproduce or distribute the Work only if (a) you do so under 
 *    this License, (b) you include a complete copy of this License with your 
 *    distribution, and (c) you retain without modification any copyright, 
 *    patent, trademark, or attribution notices that are present in the Work.
 * 5. Derivative Works
 *    You may specify that additional or different terms apply to the use, 
 *    reproduction, and distribution of your derivative works of the Work 
 *    ("Your Terms") only if (a) Your Terms provide that the limitations of 
 *    Section 7 apply to your derivative works, and (b) you identify the 
 *    specific derivative works that are subject to Your Terms. 
 *    Notwithstanding Your Terms, this license (including the redistribution 
 *    requirements in Section 4) will continue to apply to the Work itself.
 * 6. Trademarks
 *    This license does not grant any rights to use any Licensor's or its 
 *    affiliates' names, logos, or trademarks, except as necessary to 
 *    reproduce the notices described in this license.
 * 7. Limitations
 *    Platform. The Work and any derivative works thereof may only be used, or 
 *    intended for use, with a Broadcom switch integrated circuit.
 *    No Reverse Engineering. You will not use the Work to disassemble, 
 *    reverse engineer, decompile, or attempt to ascertain the underlying 
 *    technology of a Broadcom switch integrated circuit.
 * 8. Termination
 *    If you violate any term of this license, then your rights under this 
 *    license (including the license grants of Sections 2 and 3) will 
 *    terminate immediately.
 * 9. Disclaimer of Warranty
 *    THE WORK IS PROVIDED "AS IS" WITHOUT WARRANTIES OR CONDITIONS OF ANY 
 *    KIND, EITHER EXPRESS OR IMPLIED, INCLUDING WARRANTIES OR CONDITIONS OF 
 *    MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, TITLE OR 
 *    NON-INFRINGEMENT. YOU BEAR THE RISK OF UNDERTAKING ANY ACTIVITIES UNDER 
 *    THIS LICENSE. SOME STATES' CONSUMER LAWS DO NOT ALLOW EXCLUSION OF AN 
 *    IMPLIED WARRANTY, SO THIS DISCLAIMER MAY NOT APPLY TO YOU.
 * 10. Limitation of Liability
 *    EXCEPT AS PROHIBITED BY APPLICABLE LAW, IN NO EVENT AND UNDER NO LEGAL 
 *    THEORY, WHETHER IN TORT (INCLUDING NEGLIGENCE), CONTRACT, OR OTHERWISE 
 *    SHALL ANY LICENSOR BE LIABLE TO YOU FOR DAMAGES, INCLUDING ANY DIRECT, 
 *    INDIRECT, SPECIAL, INCIDENTAL, OR CONSEQUENTIAL DAMAGES ARISING OUT OF 
 *    OR RELATED TO THIS LICENSE, THE USE OR INABILITY TO USE THE WORK 
 *    (INCLUDING BUT NOT LIMITED TO LOSS OF GOODWILL, BUSINESS INTERRUPTION, 
 *    LOST PROFITS OR DATA, COMPUTER FAILURE OR MALFUNCTION, OR ANY OTHER 
 *    COMMERCIAL DAMAGES OR LOSSES), EVEN IF THE LICENSOR HAS BEEN ADVISED OF 
 *    THE POSSIBILITY OF SUCH DAMAGES.
 */
#include <bcmltd/bcmltd_internal.h>
#include "bcmltd_strpool.h"
static const bcmltd_field_rep_t bcmltd_tnl_ipv6_encap_t_fields[] = {
    {
        .name  = bcmltd_strpool_tnl_encap_id,  /* TNL_ENCAP_ID */
        .flags = BCMLTD_FIELD_F_KEY,
        .width = 16,
        .depth = 0,
        .desc = "Index into the TNL_IPV6_ENCAP table.",
    },
    {
        .name  = bcmltd_strpool_dst_mac,  /* DST_MAC */
        .flags = 0,
        .width = 48,
        .depth = 0,
        .desc = "Destination MAC address of the packet.",
    },
    {
        .name  = bcmltd_strpool_src_mac,  /* SRC_MAC */
        .flags = 0,
        .width = 48,
        .depth = 0,
        .desc = "Source MAC address of the packet.",
    },
    {
        .name  = bcmltd_strpool_src_ipv6_upper,  /* SRC_IPV6_UPPER */
        .flags = 0,
        .width = 64,
        .depth = 0,
        .desc = "Source IP address of the packet.",
    },
    {
        .name  = bcmltd_strpool_src_ipv6_lower,  /* SRC_IPV6_LOWER */
        .flags = 0,
        .width = 64,
        .depth = 0,
        .desc = "Source IP address of the packet.",
    },
    {
        .name  = bcmltd_strpool_dst_ipv6_upper,  /* DST_IPV6_UPPER */
        .flags = 0,
        .width = 64,
        .depth = 0,
        .desc = "Destination IP address of the packet.",
    },
    {
        .name  = bcmltd_strpool_dst_ipv6_lower,  /* DST_IPV6_LOWER */
        .flags = 0,
        .width = 64,
        .depth = 0,
        .desc = "Destination IP address of the packet.",
    },
    {
        .name  = bcmltd_strpool_tnl_type,  /* TNL_TYPE */
        .flags = BCMLTD_FIELD_F_ENUM,
        .width = 32,
        .depth = 0,
        .desc = "Tunnel type for IPv6 tunnel.",
    },
    {
        .name  = bcmltd_strpool_hop_limit,  /* HOP_LIMIT */
        .flags = 0,
        .width = 8,
        .depth = 0,
        .desc = "Hop limit value for tunnel IPv6 header.",
    },
    {
        .name  = bcmltd_strpool_flow_label,  /* FLOW_LABEL */
        .flags = 0,
        .width = 20,
        .depth = 0,
        .desc = "Flow label for IPV6 header.",
    },
    {
        .name  = bcmltd_strpool_phb_egr_dscp_action,  /* PHB_EGR_DSCP_ACTION */
        .flags = BCMLTD_FIELD_F_ENUM,
        .width = 32,
        .depth = 0,
        .desc = "Specifies which DSCP to choose to put in the outer tunnel header.",
    },
    {
        .name  = bcmltd_strpool_phb_egr_ip_int_pri_to_dscp_id,  /* PHB_EGR_IP_INT_PRI_TO_DSCP_ID */
        .flags = 0,
        .width = 16,
        .depth = 0,
        .desc = "PHB_EGR_IP_INT_PRI_TO_DSCP logical table index. Applicable only\n when PHB_EGR_DSCP_ACTION == MAP.\n",
    },
    {
        .name  = bcmltd_strpool_dscp,  /* DSCP */
        .flags = 0,
        .width = 6,
        .depth = 0,
        .desc = "DSCP value to set in the tunnel. Applicable only\n when PHB_EGR_DSCP_ACTION == FIXED.\n",
    },
    {
        .name  = bcmltd_strpool_src_l4_port,  /* SRC_L4_PORT */
        .flags = 0,
        .width = 16,
        .depth = 0,
        .desc = "Layer 4 source port.",
    },
    {
        .name  = bcmltd_strpool_dst_l4_port,  /* DST_L4_PORT */
        .flags = 0,
        .width = 16,
        .depth = 0,
        .desc = "Layer 4 destination port.",
    },
    {
        .name  = bcmltd_strpool_ecn_tnl_encap_id,  /* ECN_TNL_ENCAP_ID */
        .flags = 0,
        .width = 8,
        .depth = 0,
        .desc = "ECN_TNL_ENCAP_IP_PAYLOAD logical table index. Applicable\n when the payload is IP.\n ECN_TNL_ENCAP_NON_IP_PAYLOAD logical table index. Applicable\n when the payload is non-IP.\n",
    },
};
const bcmltd_table_rep_t bcmltd_tnl_ipv6_encap_t = {
    .name = bcmltd_strpool_tnl_ipv6_encap, /* TNL_IPV6_ENCAP */
    .flags = BCMLTD_TABLE_F_TYPE_INDEX_ALLOC,
    .fields = 16,
    .field = bcmltd_tnl_ipv6_encap_t_fields,
    .desc = "\n The TNL_IPV6_ENCAP table is used to set IPV6 tunnel parameters\n during encapsulation of packets.\n\n",
};
