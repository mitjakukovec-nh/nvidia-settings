/*
 * nvidia-settings: A tool for configuring the NVIDIA X driver on Unix
 * and Linux systems.
 *
 * Copyright (C) 2006 NVIDIA Corporation.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of Version 2 of the GNU General Public
 * License as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See Version 2
 * of the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the:
 *
 *           Free Software Foundation, Inc.
 *           59 Temple Place - Suite 330
 *           Boston, MA 02111-1307, USA
 *
 */

#ifndef __CTK_VCS_H__
#define __CTK_VCS_H__

#include "ctkevent.h"
#include "ctkconfig.h"

G_BEGIN_DECLS

#define CTK_TYPE_VCS (ctk_vcs_get_type())

#define CTK_VCS(obj) \
    (G_TYPE_CHECK_INSTANCE_CAST ((obj), CTK_TYPE_VCS, \
                                 CtkVcs))

#define CTK_VCS_CLASS(klass) \
    (G_TYPE_CHECK_CLASS_CAST ((klass), CTK_TYPE_VCS, \
                              CtkVcsClass))

#define CTK_IS_VCS(obj) \
    (G_TYPE_CHECK_INSTANCE_TYPE ((obj), CTK_TYPE_VCS))

#define CTK_IS_VCS_CLASS(class) \
    (G_TYPE_CHECK_CLASS_TYPE ((klass), CTK_TYPE_VCS))

#define CTK_VCS_GET_CLASS(obj) \
    (G_TYPE_INSTANCE_GET_CLASS ((obj), CTK_TYPE_VCS, \
                                CtkVcsClass))


typedef struct _CtkVcs
{
    GtkVBox parent;

    CtkConfig *ctk_config;
    NvCtrlAttributeHandle *handle;

} CtkVcs;

typedef struct _CtkVcsClass
{
    GtkVBoxClass parent_class;
} CtkVcsClass;


GType       ctk_vcs_get_type  (void) G_GNUC_CONST;
GtkWidget*  ctk_vcs_new       (NvCtrlAttributeHandle *, CtkConfig *);

GtkTextBuffer *ctk_vcs_create_help(GtkTextTagTable *,
                                    CtkVcs *);

G_END_DECLS

#endif /* __CTK_VCS_H__ */