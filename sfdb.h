#ifndef __SFDB_H
#define __SFDB_H
#include <stdint.h>

#define SFDB_PAGE_SIZE 512
/*  FORMAT DETAILS
**
**  OFFSET      SIZE        DESCRIPTION
**      0        8          MAGIC STRING "SFDBxxx\0"
**      8        1          保留
**      9        1          保留
**     10        1          保留
**     11        1          数据写入状态
**     12        4          数据指针
**     16        4          当前数据量
**     20        4          最大数据储存储量
**     24        4          数据长度
*/
typedef struct _db_hdr {
    char magic[8];
    uint8_t resv01[3];
    uint8_t record_state;
    uint32_t record_index;
    uint32_t record_count;
    uint32_t max_record_num;
    uint32_t record_len;
} db_hdr_t;

typedef struct _sfdb {
    db_hdr_t hdr;
    uint8_t page_data[SFDB_PAGE_SIZE];
    int fd;
} sfdb_t;

#endif /* __SFDB_H */
