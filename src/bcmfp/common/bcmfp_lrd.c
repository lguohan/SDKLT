/*! \file bcmfp_lrd.c
 *
 * APIs to fetch FP related information from LRD .
 */
/*
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

#include <shr/shr_error.h>
#include <shr/shr_debug.h>
#include <bcmdrd/bcmdrd_pt.h>
#include <bcmdrd/bcmdrd_types.h>
#include <bcmfp/bcmfp_internal.h>

#define BSL_LOG_MODULE BSL_LS_BCMFP_COMMON

int
bcmfp_group_mode_max_entries(int unit,
                             bcmfp_stage_id_t stage_id,
                             bcmfp_group_mode_t group_mode,
                             uint32_t *max_entries)
{
    bcmfp_stage_t *stage = NULL;
    bcmfp_stage_hw_entry_info_t *hw_entry_info = NULL;

    SHR_FUNC_ENTER(unit);

    SHR_NULL_CHECK(max_entries, SHR_E_PARAM);

    SHR_IF_ERR_EXIT(bcmfp_stage_get(unit, stage_id, &stage));

    hw_entry_info = stage->hw_entry_info[group_mode];

    if (hw_entry_info) {
        *max_entries = hw_entry_info->max_entries;
    } else {
        SHR_RETURN_VAL_EXIT(SHR_E_NOT_FOUND);
    }

exit:
    SHR_FUNC_EXIT();
}

int
bcmfp_group_tcam_size_get(int unit,
                          bool is_presel,
                          bcmfp_stage_id_t stage_id,
                          bcmfp_group_id_t group_id,
                          uint32_t *size)
{
    bcmdrd_sid_t sid;
    bcmfp_stage_t *stage = NULL;
    bcmfp_group_mode_t group_mode;
    bcmfp_group_oper_info_t *group_oper_info = NULL;
    bcmfp_stage_hw_entry_info_t *hw_entry_info = NULL;

    SHR_FUNC_ENTER(unit);

    SHR_NULL_CHECK(size, SHR_E_PARAM);

    SHR_IF_ERR_EXIT(bcmfp_stage_get(unit, stage_id, &stage));

    SHR_IF_ERR_EXIT(
        bcmfp_group_oper_info_get(unit,
                                  stage_id,
                                  group_id,
                                  &group_oper_info));

    group_mode = group_oper_info->group_mode;
    hw_entry_info = stage->hw_entry_info[group_mode];

    if (is_presel) {
        sid = hw_entry_info->presel_sid;
    } else {
        sid = hw_entry_info->sid;
    }

    *size = bcmdrd_pt_entry_wsize(unit, sid);

exit:
    SHR_FUNC_EXIT();
}

int
bcmfp_group_policy_size_get(int unit,
                            bool is_presel,
                            bcmfp_stage_id_t stage_id,
                            bcmfp_group_id_t group_id,
                            uint32_t *size)
{
    bcmdrd_sid_t sid;
    bcmfp_stage_t *stage = NULL;
    bcmfp_group_mode_t group_mode;
    bcmfp_group_oper_info_t *group_oper_info = NULL;
    bcmfp_stage_hw_entry_info_t *hw_entry_info = NULL;

    SHR_FUNC_ENTER(unit);

    SHR_NULL_CHECK(size, SHR_E_PARAM);

    SHR_IF_ERR_EXIT(bcmfp_stage_get(unit, stage_id, &stage));

    SHR_IF_ERR_EXIT(
        bcmfp_group_oper_info_get(unit,
                                  stage_id,
                                  group_id,
                                  &group_oper_info));

    group_mode = group_oper_info->group_mode;
    hw_entry_info = stage->hw_entry_info[group_mode];

    if (is_presel) {
        sid = hw_entry_info->presel_sid_data_only;
    } else {
        sid = hw_entry_info->sid_data_only;
    }

    *size = bcmdrd_pt_entry_wsize(unit, sid);

exit:
    SHR_FUNC_EXIT();
}

int
bcmfp_entry_key_info_get(int unit,
                         bool is_presel,
                         bcmfp_stage_id_t stage_id,
                         bcmfp_group_id_t group_id,
                         uint16_t *start_bit,
                         uint16_t *end_bit)
{
    bcmdrd_sid_t sid;
    bcmfp_stage_t *stage = NULL;
    bcmfp_group_mode_t group_mode;
    bcmfp_group_oper_info_t *group_oper_info = NULL;
    bcmfp_stage_hw_entry_info_t *hw_entry_info = NULL;
    bcmdrd_sym_field_info_t finfo;

    SHR_FUNC_ENTER(unit);

    SHR_NULL_CHECK(end_bit, SHR_E_PARAM);
    SHR_NULL_CHECK(start_bit, SHR_E_PARAM);

    SHR_IF_ERR_EXIT(bcmfp_stage_get(unit, stage_id, &stage));

    SHR_IF_ERR_EXIT(
        bcmfp_group_oper_info_get(unit,
                                  stage_id,
                                  group_id,
                                  &group_oper_info));

    group_mode = group_oper_info->group_mode;
    hw_entry_info = stage->hw_entry_info[group_mode];

    if (is_presel) {
        sid = hw_entry_info->presel_sid;
    } else {
        sid = hw_entry_info->sid;
    }
    if (!(stage->flags & BCMFP_STAGE_ENTRY_TYPE_HASH
          && FALSE == is_presel)) {
        SHR_IF_ERR_VERBOSE_EXIT
            (bcmdrd_pt_field_info_get(unit, sid,
                 hw_entry_info->key_fid, &finfo));

        *start_bit = finfo.minbit;
        *end_bit = finfo.maxbit;
    } else {
        if (stage->key_data_size_info != NULL) {
            *start_bit = 0;
            *end_bit = stage->key_data_size_info->key_size[group_mode] - 1;
        }
    }
exit:
    SHR_FUNC_EXIT();
}

int
bcmfp_entry_mask_info_get(int unit,
                          bool is_presel,
                          bcmfp_stage_id_t stage_id,
                          bcmfp_group_id_t group_id,
                          uint16_t *start_bit,
                          uint16_t *end_bit)
{
    bcmdrd_sid_t sid;
    bcmfp_stage_t *stage = NULL;
    bcmfp_group_mode_t group_mode;
    bcmfp_group_oper_info_t *group_oper_info = NULL;
    bcmfp_stage_hw_entry_info_t *hw_entry_info = NULL;
    bcmdrd_sym_field_info_t finfo;
    SHR_FUNC_ENTER(unit);

    SHR_NULL_CHECK(end_bit, SHR_E_PARAM);
    SHR_NULL_CHECK(start_bit, SHR_E_PARAM);

    SHR_IF_ERR_EXIT(bcmfp_stage_get(unit, stage_id, &stage));
    if (stage->flags & BCMFP_STAGE_ENTRY_TYPE_HASH
        && is_presel == FALSE) {
        SHR_RETURN_VAL_EXIT(SHR_E_NONE);
    }

    SHR_IF_ERR_EXIT(
        bcmfp_group_oper_info_get(unit,
                                  stage_id,
                                  group_id,
                                  &group_oper_info));

    group_mode = group_oper_info->group_mode;
    hw_entry_info = stage->hw_entry_info[group_mode];

    if (is_presel) {
        sid = hw_entry_info->presel_sid;
    } else {
        sid = hw_entry_info->sid;
    }

    SHR_IF_ERR_VERBOSE_EXIT
        (bcmdrd_pt_field_info_get(unit, sid,
             hw_entry_info->mask_fid, &finfo));

    *start_bit = finfo.minbit;
    *end_bit = finfo.maxbit;

exit:
    SHR_FUNC_EXIT();
}

int
bcmfp_entry_valid_bit_set(int unit,
                          bool is_presel,
                          bcmfp_stage_id_t stage_id,
                          bcmfp_group_id_t group_id,
                          uint32_t **entry_words)
{
    uint8_t part = 0;
    uint8_t num_parts = 0;
    uint32_t value = 0;
    bcmdrd_sid_t sid;
    bcmfp_stage_t *stage = NULL;
    bcmfp_group_mode_t group_mode;
    bcmfp_group_oper_info_t *group_oper_info = NULL;
    bcmfp_stage_hw_entry_info_t *hw_entry_info = NULL;
    bcmdrd_sym_field_info_t finfo;

    SHR_FUNC_ENTER(unit);

    SHR_NULL_CHECK(entry_words, SHR_E_PARAM);

    SHR_IF_ERR_EXIT(bcmfp_stage_get(unit, stage_id, &stage));

    if (stage->flags & BCMFP_STAGE_ENTRY_TYPE_HASH
        && is_presel == FALSE) {
        SHR_RETURN_VAL_EXIT(SHR_E_NONE);
    }

    SHR_IF_ERR_EXIT(
        bcmfp_group_oper_info_get(unit,
                                  stage_id,
                                  group_id,
                                  &group_oper_info));

    group_mode = group_oper_info->group_mode;
    hw_entry_info = stage->hw_entry_info[group_mode];

    if (is_presel) {
        sid = hw_entry_info->presel_sid;
    } else {
        sid = hw_entry_info->sid;
    }

    SHR_IF_ERR_VERBOSE_EXIT
        (bcmdrd_pt_field_info_get(unit, sid,
            hw_entry_info->valid_fid, &finfo));
    value = ((1 << (finfo.maxbit - finfo.minbit + 1)) - 1);

    SHR_IF_ERR_EXIT(
        bcmfp_group_parts_count(unit, group_oper_info->flags, &num_parts));

    for (part = 0; part < num_parts; part++) {
        bcmdrd_pt_field_set(unit, sid, entry_words[part],
                            hw_entry_info->valid_fid, &value);
    }

exit:
    SHR_FUNC_EXIT();
}