#include "tcp.h"
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

void test_parse_tcp_header() {
    unsigned char sample_buffer[40] = { /* Sample TCP segment */ };
    parse_tcp_header(sample_buffer, sizeof(sample_buffer));
    CU_PASS("TCP header parsed successfully.");
}

int main() {
    CU_initialize_registry();
    CU_pSuite suite = CU_add_suite("TCP Tests", 0, 0);

    CU_add_test(suite, "Parse TCP Header", test_parse_tcp_header);

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return 0;
}
