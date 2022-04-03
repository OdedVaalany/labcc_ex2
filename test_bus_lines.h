#ifndef EX2_REPO_TESTBUSLINES_H
#define EX2_REPO_TESTBUSLINES_H
#include "sort_bus_lines.h"
// write only between #define EX2_REPO_TESTBUSLINES_H and #endif //EX2_REPO_TESTBUSLINES_H
/**
 * @brief This function test if the given array sorted by the distance
 * @param start pointer to the head of the BusLine array for soring
 * @param end pointer to the tail of the BusLine array for soring
 */
int is_sorted_by_distance (BusLine *start, BusLine *end);

/**
 * @brief This function test if the given array sorted by the duration
 * @param start pointer to the head of the BusLine array for soring
 * @param end pointer to the tail of the BusLine array for soring
 */
int is_sorted_by_duration (BusLine *start, BusLine *end);

/**
 * @brief This function test if the given array equal (by values) to the sorted arrays
 * @param start_sorted pointer to the head of the BusLine array after sorting
 * @param end_sorted pointer to the tail of the BusLine array after sorting
 * @param start_original pointer to the head of the BusLine array before sorting
 * @param end_original pointer to the tail of the BusLine array before sorting
 */
int is_equal (BusLine *start_sorted,
              BusLine *end_sorted, BusLine *start_original,
              BusLine *end_original);
// write only between #define EX2_REPO_TESTBUSLINES_H and #endif //EX2_REPO_TESTBUSLINES_H
#endif //EX2_REPO_TESTBUSLINES_H
