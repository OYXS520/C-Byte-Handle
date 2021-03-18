#include <stdio.h>
#include <stdlib.h>
#include <sys/select.h>
#include <sys/time.h>
#include <unistd.h>
#include "byte_process.h"
#include "demo.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

int main(){
    printf("The program begins\n");

    byte head[2] = {0xFE,0XFF}; //包头
    byte tail[2] = {0x55,0x56}; //包尾

    byte pack1[20] ={0xFE,0xFF,0x00,0x00,0x00,0x06,0x11,0x12,0x13,0x14,0x15,0x16,0x55,0x56,0xFE,0xFF,0x00,0x00,0x00,0x07};
    byte pack2[17] = {0x11,0x12,0x13,0x14,0x15,0x16,0x17,0x55,0x56,0xFE,0xFF,0x00,0x00,0x00,0x08,0x11,0x12};
    byte pack3[8] = {0x13,0x14,0x15,0x16,0x17,0x18,0x55,0x56};

    //模拟出的三个包
    bytes *package1 = create_bytes(pack1,20);
    bytes *package2 = create_bytes(pack2,17);
    bytes *package3 = create_bytes(pack3,8);
    byte yangshu[4] = {0xFE,0xFF,0x12,0x15};
    // bytes *pack_head = create_bytes(yangshu,4);
    // int a = bytes_search(pack_head,pack_head);
    // printf("search is %d\n",a);
    // bytes **result = NULL;
    // // 设置包的包头和包尾，数据位长度
    set_package_info(head,2,tail,2,4);
    int res = check_package_from_buffer_link(package1);
    
    res = check_package_from_buffer_link(package2);
    res = check_package_from_buffer_link(package3);
    print_bytes_queue(package_queue);

    bytes *ret = get_bytes_to_queue(&package_queue);
    print_bytes(ret);
    ret = get_bytes_to_queue(&package_queue);
    print_bytes(ret);
    ret = get_bytes_to_queue(&package_queue);
    print_bytes(ret);
    print_bytes_queue(package_queue);

    return 0;
}

// int main(int argc, char const *argv[])
// {
//     strsr()
//     int len = get_file_size("/Users/shu/Desktop/image_test/图片数据.jpg");
//     bytes *data_bit = int_to_bytes(len);
//     print_bytes(data_bit);
//     int a = bytes_to_int(data_bit);
//     printf("%d\n", a);
//     return 0;
// }
