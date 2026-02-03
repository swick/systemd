/* SPDX-License-Identifier: LGPL-2.1-or-later */

#include "sd-varlink-idl.h"

#include "varlink-io.systemd.App.h"

// Moves caller into the cgroup (i.e. starts a scope)
static SD_VARLINK_DEFINE_METHOD(
                Register,
                SD_VARLINK_FIELD_COMMENT("The app's ID"),
                SD_VARLINK_DEFINE_INPUT(id, SD_VARLINK_STRING, 0));

com.rdns.something="foobar"

static SD_VARLINK_DEFINE_METHOD(
                SetPermissions,
                <connected socket fd> | <pidfd> (optional),

                SD_VARLINK_FIELD_COMMENT("The app's ID"),
                SD_VARLINK_DEFINE_INPUT(id, SD_VARLINK_STRING, 0));

static SD_VARLINK_DEFINE_METHOD(
                QueryPermissions,
                <connected socket fd> | <pidfd> (optional)
                );

SD_VARLINK_DEFINE_INTERFACE(
                io_systemd_App,
                "io.systemd.App",
                SD_VARLINK_INTERFACE_COMMENT("API for managing apps"),
                SD_VARLINK_SYMBOL_COMMENT("TODO"),
                &vl_method_Register,
                SD_VARLINK_SYMBOL_COMMENT("TODO"),
                &vl_method_Query);


// - systemd automatically registers any service w/ appd that matches the service naming pattern
// - we treat static permissions and dynamic permissions identically from appd's perspective
// - app registers itself, but also so can sandbox runtime. If sandbox registers, it blows a fuse and then everything inside of the cgroup is no longer allowed to change its own permissions
//
