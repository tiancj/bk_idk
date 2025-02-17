/*
 * Copyright (c) 2022, sakumisu
 *
 * SPDX-License-Identifier: Apache-2.0
 */
#ifndef USBH_MSC_H
#define USBH_MSC_H

#include "usb_msc.h"
#include "usb_scsi.h"

struct usbh_msc {
    struct usbh_hubport *hport;

    uint8_t intf; /* Data interface number */
    uint8_t sdchar;
    usbh_pipe_t bulkin;          /* Bulk IN endpoint */
    usbh_pipe_t bulkout;         /* Bulk OUT endpoint */
    struct usbh_urb bulkin_urb;  /* Bulk IN urb */
    struct usbh_urb bulkout_urb; /* Bulk OUT urb */
    uint32_t blocknum;           /* Number of blocks on the USB mass storage device */
    uint16_t blocksize;          /* Block size of USB mass storage device */
};

int usbh_device_write(uint32_t first_block, const uint8_t *dest, uint32_t block_num);
int usbh_device_read(uint32_t first_block, const uint8_t *dest, uint32_t block_num);
uint8_t usbh_ms_media_get_status();

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
}
#endif

#endif /* USBH_MSC_H */
