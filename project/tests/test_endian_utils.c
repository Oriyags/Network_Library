#include "endian_utils.h"
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

void test_endian_conversion() {
    uint16_t value = 0x1234;
    uint16_t result = swap16(value);
    CU_ASSERT_EQUAL(result, 0x3412);
    CU_PASS("Endian conversion successful.");
}

int main() {
    CU_initialize_registry();
    CU_pSuite suite = CU_add_suite("Endian Utils Tests", 0, 0);

    CU_add_test(suite, "Endian Conversion", test_endian_conversion);

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return 0;
}
