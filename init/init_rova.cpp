/*
 * Copyright (C) 2021 The LineageOS Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <android-base/file.h>

#include <libinit_msm8937.h>

static const variant_info_t rolex_info = {
    .brand = "Xiaomi",
    .device = "rolex",
    .marketname = "",
    .model = "Redmi 4A",
    .build_description = "google-user 11 RQ3A.211001.001 7641976 release-keys",
    .build_fingerprint = "google/redfin/redfin:11/RQ3A.211001.001/7641976:user/release-keys",
};

static const variant_info_t riva_info = {
    .brand = "Xiaomi",
    .device = "riva",
    .marketname = "",
    .model = "Redmi 5A",
    .build_description = "google-user 11 RQ3A.211001.001 7641976 release-keys",
    .build_fingerprint = "google/redfin/redfin:11/RQ3A.211001.001/7641976:user/release-keys",
};

static void determine_device()
{
    std::string proc_cmdline;
    android::base::ReadFileToString("/proc/cmdline", &proc_cmdline, true);
    if (proc_cmdline.find("S88503") != proc_cmdline.npos)
        set_variant_props(rolex_info);
    else if (proc_cmdline.find("S88505") != proc_cmdline.npos)
        set_variant_props(riva_info);
}

void vendor_load_properties() {
    determine_device();
    set_dalvik_heap_size();
}
