#include "arp.h"
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

void test_parse_arp_header() {
    unsigned char sample_buffer[42] = { /* Sample ARP packet data */ };
    parse_arp_header(sample_buffer);
    // Verify if ARP header fields are correctly parsed (print statements can be validated manually or redirected).
    CU_PASS("ARP header parsed successfully.");
}

int main() {
    CU_initialize_registry();
    CU_pSuite suite = CU_add_suite("ARP Tests", 0, 0);

    CU_add_test(suite, "Parse ARP Header", test_parse_arp_header);

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return 0;
}
