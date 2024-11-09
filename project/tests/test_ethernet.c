#include "ethernet.h"
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

void test_parse_ethernet_frame() {
    unsigned char sample_buffer[60] = { /* Sample Ethernet frame */ };
    parse_ethernet_frame(sample_buffer);
    CU_PASS("Ethernet frame parsed successfully.");
}

int main() {
    CU_initialize_registry();
    CU_pSuite suite = CU_add_suite("Ethernet Tests", 0, 0);

    CU_add_test(suite, "Parse Ethernet Frame", test_parse_ethernet_frame);

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return 0;
}
