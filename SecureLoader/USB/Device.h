/*
             LUFA Library
     Copyright (C) Dean Camera, 2016.

  dean [at] fourwalledcubicle [dot] com
           www.lufa-lib.org
*/

/*
  Copyright 2016  Dean Camera (dean [at] fourwalledcubicle [dot] com)

  Permission to use, copy, modify, distribute, and sell this
  software and its documentation for any purpose is hereby granted
  without fee, provided that the above copyright notice appear in
  all copies and that both that the copyright notice and this
  permission notice and warranty disclaimer appear in supporting
  documentation, and that the name of the author not be used in
  advertising or publicity pertaining to distribution of the
  software without specific, written prior permission.

  The author disclaims all warranties with regard to this
  software, including all implied warranties of merchantability
  and fitness.  In no event shall the author be liable for any
  special, indirect or consequential damages or any damages
  whatsoever resulting from loss of use, data or profits, whether
  in an action of contract, negligence or other tortious action,
  arising out of or in connection with the use or performance of
  this software.
*/

#ifndef __USBDEVICE_H__
#define __USBDEVICE_H__

	/* Includes: */
		#include "Common/Common.h"

	/* Enable C linkage for C++ Compilers: */
		#if defined(__cplusplus)
			extern "C" {
		#endif

	/* Preprocessor Checks: */
		#if !defined(__INCLUDE_FROM_USB_DRIVER)
			#error Do not include this file directly. Include LUFA/Drivers/USB/USB.h instead.
		#endif

	/* Public Interface - May be used in end-application: */
		/* Function Prototypes: */
			/** Function to retrieve a given descriptor's size and memory location from the given descriptor type value,
			 *  index and language ID. This function MUST be overridden in the user application (added with full, identical
			 *  prototype and name so that the library can call it to retrieve descriptor data.
			 *
			 *  \param[in] wValue                  The type of the descriptor to retrieve in the upper byte, and the index in the
			 *                                     lower byte (when more than one descriptor of the given type exists, such as the
			 *                                     case of string descriptors). The type may be one of the standard types defined
			 *                                     in the DescriptorTypes_t enum, or may be a class-specific descriptor type value.
			 *  \param[in] wIndex                  The language ID of the string to return if the \c wValue type indicates
			 *                                     \ref DTYPE_String, otherwise zero for standard descriptors, or as defined in a
			 *                                     class-specific standards.
			 *  \param[out] DescriptorAddress      Pointer to the descriptor in memory. This should be set by the routine to
			 *                                     the address of the descriptor.
			 *
			 *  \return Size in bytes of the descriptor if it exists, zero or \ref NO_DESCRIPTOR otherwise.
			 */
			uint16_t CALLBACK_USB_GetDescriptor(const uint16_t wValue,
			                                    const uint16_t wIndex,
			                                    const void** const DescriptorAddress
			                                    ) ATTR_WARN_UNUSED_RESULT ATTR_NON_NULL_PTR_ARG(3);

		/* Inline Functions: */
			static inline void USB_Device_SetFullSpeed(void) ATTR_ALWAYS_INLINE;
			static inline void USB_Device_SetFullSpeed(void)
			{
				UDCON &= ~(1 << LSM);
			}

			static inline void USB_Device_SetDeviceAddress(const uint8_t Address) ATTR_ALWAYS_INLINE;
			static inline void USB_Device_SetDeviceAddress(const uint8_t Address)
			{
				UDADDR = (UDADDR & (1 << ADDEN)) | (Address & 0x7F);
			}

			static inline void USB_Device_EnableDeviceAddress(void) ATTR_ALWAYS_INLINE;
			static inline void USB_Device_EnableDeviceAddress(void)
			{
				UDADDR |= (1 << ADDEN);
			}

			static inline bool USB_Device_IsAddressSet(void) ATTR_ALWAYS_INLINE ATTR_WARN_UNUSED_RESULT;
			static inline bool USB_Device_IsAddressSet(void)
			{
				return (UDADDR & (1 << ADDEN));
			}

	/* Disable C linkage for C++ Compilers: */
		#if defined(__cplusplus)
			}
		#endif

#endif

/** @} */
