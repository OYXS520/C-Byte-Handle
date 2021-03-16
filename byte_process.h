#ifndef BYTE_PROCESS
#define BYTE_PROCESS
typedef unsigned char byte;
typedef struct bytes
{
    byte *data; //数据
    int len;    //长度
} bytes;

typedef struct tcp_package_info
{
    bytes *pag_head; //包头
    bytes *pag_tail; //包尾
    int data_bits;   //数据位长度
} tcp_package_info;

extern tcp_package_info *pack_info; //全局包头包尾信息
extern bytes *buffer_link;          //全局buffer链
extern int current_data_len;        //当前定位的数据的长度

extern size_t get_file_size(const char *filepath);
extern bytes *init_bytes();
extern bytes *create_bytes(byte *data, int len);
extern void print_bytes(bytes *src);
extern void free_bytes(bytes *src);
extern void free_bytes_array(bytes **src, int len);
extern void free_tcp_package_info(tcp_package_info *info);
extern void realloc_security(byte **src, int new_size);
extern void bytes_splicing(bytes *src, bytes *tail, int len);
extern bytes *bytes_intercept(bytes *src, int start, int end);
extern int bytes_compares(bytes *src, bytes *tar);
extern int bytes_n_compares(bytes *src, bytes *tar, int len);
extern bytes *int_to_bytes(int num);
extern int bytes_to_int(bytes *data);
extern bytes *parse_int_to_bytes(int num,int len);
extern int parse_data_bit(bytes *data_bit);
extern void set_package_info(byte *head, int head_size, byte *tail, int tail_size, int data_bit_len);
extern void print_package_info();
extern void add_bytes_to_bytess(bytes ***bytess, bytes *tail, int bytess_len);
// bytes *get_data_from_package(bytes *src);
extern int check_package_from_buffer_link(bytes *buffer, bytes ***results, int results_len);
extern void print_buffer_link();

#endif