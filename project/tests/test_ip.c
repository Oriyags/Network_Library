#include "ip.h"
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

void test_parse_ip_header() {
    unsigned char sample_buffer[40] = { /* Sample IP packet */ };
    parse_ip_header(sample_buffer, sizeof(sample_buffer));
    CU_PASS("IP header parsed successfully.");
}

int main() {
    CU_initialize_registry();
    CU_pSuite suite = CU_add_suite("IP Tests", 0, 0);

    CU_add_test(suite, "Parse IP Header", test_parse_ip_header);

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return 0;
}
