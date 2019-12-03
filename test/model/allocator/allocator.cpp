#include "../../../src/model/allocator/allocator.h"

#include <catch2/catch.hpp>

TEST_CASE ("I can allocate Objects within a confined space for less overhead") {
    SECTION ("I can easily allocate and deallocate a primitive data type") {
        auto allocator = new Allocator<int>();
        auto & alloc = * allocator;
        int * first;

        REQUIRE_NOTHROW (first = alloc.allocate());

        WHEN ("I allocate a few objects") {
            for (int i = 1; i < 25; i++) {
                int * tmp;
                CHECK_NOTHROW (tmp = alloc.allocate());

                THEN ("They align next to each other") {
                    CHECK (first + i == tmp);
                }
            }
        }

        WHEN ("I allocate too many objects") {
            CHECK_THROWS_AS (alloc.allocate(PREALLOCATED_OBJECTS), std::bad_alloc);
            alloc.allocate(PREALLOCATED_OBJECTS - 1);

            THEN ("I get an exception on all allocate calls") {
                CHECK_THROWS_AS (alloc.allocate(1), std::bad_alloc);
            }
        }

        CHECK_NOTHROW (alloc.deallocate (first));
        CHECK_NOTHROW (delete allocator);
    }

    SECTION ("I can allocate and deallocate space for several objects at a time") {
        auto allocator = new Allocator<float>();
        auto & alloc = * allocator;

        int I = 20;
        float * array = alloc.allocate (I);
        for (int i = 0; i < I; i++) {
            array [i] = (float) i;
            CHECK (* (array + i) == (float) i);
        }
        CHECK_NOTHROW (alloc.deallocate (array, I));
    }

    SECTION ("I can reuse deallocated space to postpone a heap overflow") {
        auto allocator = new Allocator<std::string>();
        auto & alloc = * allocator;

        for (int i = 0; i < 10; i++) {
            std::string * ptr;
            CHECK_NOTHROW (ptr = alloc.allocate (0.2 * PREALLOCATED_OBJECTS));
            CHECK_NOTHROW (alloc.deallocate(ptr, 0.2 * PREALLOCATED_OBJECTS));
        }
    }
}
