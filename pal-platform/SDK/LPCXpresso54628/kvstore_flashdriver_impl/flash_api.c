/* mbed Microcontroller Library
 * Copyright (c) 2018 ARM Limited
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include "flash_api.h"

#include "arm_pal_storage.h"

int32_t flash_init(flash_t *obj)
{
    return arm_pal_storage_init();
}

int32_t flash_free(flash_t *obj)
{    
    return arm_pal_storage_deinit();
}

int32_t flash_erase_sector(flash_t *obj, uint32_t address)
{
    return arm_pal_storage_erase_sector(address);
}

int32_t flash_read(flash_t *obj, uint32_t address, uint8_t *data, uint32_t size)
{
    return arm_pal_storage_read(address, data, size);
}

int32_t flash_program_page(flash_t *obj, uint32_t address, const uint8_t *data, uint32_t size)
{
    return arm_pal_storage_program_page(address, data, size);
}

uint32_t flash_get_sector_size(const flash_t *obj, uint32_t address)
{
    uint32_t size = arm_pal_storage_get_sector_size(address);

    return (size) ? size : MBED_FLASH_INVALID_SIZE;
}

uint32_t flash_get_page_size(const flash_t *obj)
{
    return arm_pal_storage_get_page_size();
}

uint32_t flash_get_start_address(const flash_t *obj)
{
    return arm_pal_storage_get_start_address();
}

uint32_t flash_get_size(const flash_t *obj)
{
    return arm_pal_storage_get_size();
}

uint8_t flash_get_erase_value(const flash_t *obj)
{
    return arm_pal_storage_get_erase_value();
}
