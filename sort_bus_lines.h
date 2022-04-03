#ifndef EX2_REPO_SORTBUSLINES_H
#define EX2_REPO_SORTBUSLINES_H
// write only between #define EX2_REPO_SORTBUSLINES_H and #endif //EX2_REPO_SORTBUSLINES_H
/**
 * @brief This struct define a row on the array
 * @param line_number represent the line number of the bus
 * @param distance represent the distance of the bus
 * @param duration represent the travel duration with this bus
 */
typedef struct BusLine
{
    int line_number, distance, duration;
} BusLine;

/**
 * @brief This function get a BusLine array and sort it by bubble sort the duration fields
 * @param start pointer to the head of the BusLine array for soring
 * @param end pointer to the tail of the BusLine array for soring
 */
void bubble_sort (BusLine *start, BusLine *end);

/**
 * @brief This function get a BusLine array and sort by quick sort algo it by the duration fields
 * @param start pointer to the head of the BusLine array for soring
 * @param end pointer to the tail of the BusLine array for soring
 *
 */
void quick_sort (BusLine *start, BusLine *end);

/**
 * @brief A helper function for the quick sort algo
 * @param start pointer to the head of the BusLine array for soring
 * @param end pointer to the tail of the BusLine array for soring
 * @return the cell that already in his place
 */
BusLine *partition (BusLine *start, BusLine *end);
// write only between #define EX2_REPO_SORTBUSLINES_H and #endif //EX2_REPO_SORTBUSLINES_H
#endif //EX2_REPO_SORTBUSLINES_H
