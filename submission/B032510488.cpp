/*
 * =============================================================================
 *  BITP1123 – Data Structure and Algorithm
 *  LAB TEST 1 (LT1): Sorting & Searching
 *  Semester 2, Session 2025/2026
 *  Fakulti Teknologi Maklumat dan Komunikasi (FTMK), UTeM
 * =============================================================================
 *
 *  STUDENT INFORMATION
 *  -------------------
 *  Name       : SYARIFAH HAZIQAH ALHADY BINTI SYED MOHD SADIK
 *  Student ID : B032510488
 *  Section    : 1/2
 *
 *  INSTRUCTIONS
 *  ------------
 *  1. This lab test is to be completed within 1.5 hours.
 *  2. Fill in ALL blanks marked with  ___BLANK___  .
 *  3. Do NOT rename functions, change return types, or alter the main() logic.
 *  4. Do NOT remove or modify any comment lines beginning with // [AUTO-GRADE].
 *  5. Submit this single .cpp file with your Student ID as the filename.
 *     Example: B032310001.cpp
 *  6. The program must compile and run without errors.
 *
 *  TASK OVERVIEW
 *  -------------
 *  You are managing a list of visitor counts recorded at Melaka tourist
 *  attractions over a public holiday.  The program will:
 *
 *    Part A  – Theory (fill-in-the-blank comments)        [20 marks]
 *    Part B  – Selection Sort on an array                 [20 marks]
 *    Part C  – Bubble Sort on an array                    [20 marks]
 *    Part D  – Insertion Sort on an array                 [20 marks]
 *    Part E  – Linear Search & Binary Search on an array  [20 marks]
 *
 *  Total: 100 marks
 * =============================================================================
 */

#include <iostream>
#include <string>
using namespace std;

// ============================================================
//  PART A – THEORY (Fill-in-the-blank in the comments below)
//  Each blank is worth 2 marks.   Total: 10 x 2 = 20 marks
// ============================================================
/*
 * [A1] Selection Sort works by repeatedly finding the ___smallest___ value
 *      in the unsorted portion and placing it at the beginning.
 *
 * [A2] After the k-th pass of Bubble Sort, the ___k___ largest elements
 *      are guaranteed to be in their correct final positions.
 *
 * [A3] Insertion Sort builds the sorted list one element at a time by
 *      inserting each new element into its ___correct___ position within
 *      the already-sorted portion.
 *
 * [A4] In Selection Sort, regardless of the input order, the algorithm
 *      always performs exactly ___one___ swap(s) per pass.
 *
 * [A5] Quick Sort selects a value called the ___pivot___ around which
 *      the list is partitioned.
 *
 * [A6] A sorting algorithm is said to be ___stable___ if elements with
 *      equal keys maintain their original relative order after sorting.
 *
 * [A7] Binary Search requires the list to be ___sorted___ before it
 *      can be applied.
 *
 * [A8] After each comparison in Binary Search, the remaining search
 *      range is reduced by ___half___.
 *
 * [A9] In Selection Sort, during each pass the algorithm performs
 *      comparisons to find the minimum, but makes at most ___one___
 *      swap(s) per pass.
 *
 * [A10] In Bubble Sort, if no swap occurs during an entire pass,
 *       the list is already ___sorted___ and the algorithm can stop early.
 */


 // ============================================================
 //  HELPER: print the array with attraction names
 // ============================================================
const int SIZE = 8;
string attractions[SIZE] = {
    "A.Famosa",
    "Jonker Walk",
    "Dataran Pahlawan",
    "Baba Nyonya Museum",
    "Menara Taming Sari",
    "Stadthuys",
    "Masjid Selat Melaka",
    "Melaka River Cruise"
};

void printArray(int arr[], int n) {
    cout << "\n  Index | Attraction              | Visitors" << endl;
    cout << "  ------|-------------------------|----------" << endl;
    for (int i = 0; i < n; i++) {
        cout << "    [" << i << "]  | ";
        cout.width(23); cout << left << attractions[i] << " | ";
        cout << arr[i] << endl;
    }
    cout << endl;
}

// ============================================================
//  PART B – SELECTION SORT    [20 marks]
//  Sort visitor counts in ASCENDING order using Selection Sort.
//  Fill in the 4 blanks labelled [B1]–[B4].
// ============================================================
// [AUTO-GRADE] FUNCTION: selectionSort
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {

        // [B1] Assume the minimum is at position i
        int minIdx = i;          // [B1] 2 marks

        for (int j = i + 1; j < n; j++) {
            // [B2] Update minIdx when a smaller element is found
            if (arr[j] < arr[minIdx]) {   // [B2] 2 marks
                minIdx = j;
            }
        }

        // [B3] Swap arr[i] with arr[minIdx] (3 lines)
        int temp = arr[i];       // [B3a] 2 marks
        arr[minIdx] = arr[i];         // [B3b] 2 marks
        arr[i] = temp;

        // [B4] Print the array state after each pass (call printArray)
        cout << "  Pass " << i + 1 << ":";
        printArray(arr, n);                       // [B4] 2 marks
    }
}


// ============================================================
//  PART C – BUBBLE SORT    [20 marks]
//  Sort visitor counts in ASCENDING order using Bubble Sort.
//  Fill in the 4 blanks labelled [C1]–[C4].
// ============================================================
// [AUTO-GRADE] FUNCTION: bubbleSort
void bubbleSort(int arr[], int n) {
    bool swapped;

    for (int pass = 0; pass < n - 1; pass++) {
        swapped = false;             // [C1] 2 marks  (initial value)

        // [C2] Inner loop bound shrinks by pass to avoid re-checking sorted tail
        for (int i = 0; i < n - pass - 1; i++) {   // [C2] 2 marks
            if (arr[i] > arr[i + 1]) {
                // [C3] Swap arr[i] and arr[i+1]
                int temp = arr[i];
                arr[i] = arr [i + 1];      // [C3] 2 marks
                arr[i + 1] = temp;
                swapped = true;
            }
        }

        cout << "  Pass " << pass + 1 << ":";
        printArray(arr, n);

        // [C4] Early termination: if no swap occurred, break
        if (swapped == false) break;            // [C4] 2 marks
    }
}


// ============================================================
//  PART D – INSERTION SORT    [20 marks]
//  Sort visitor counts in ASCENDING order using Insertion Sort.
//  Fill in the 4 blanks labelled [D1]–[D4].
// ============================================================
// [AUTO-GRADE] FUNCTION: insertionSort
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];       // element to be inserted
        int j = i - 1;    // [D1] 2 marks  start comparing from position i-1

        // [D2] Shift elements that are greater than key one position to the right
        while (j >= 0 && arr[j] > key) {   // [D2] 2 marks
            arr[j + 1] = arr[j];     // [D3] 2 marks  shift element right
            j--;
        }

        // [D4] Place key at its correct position
        arr[j + 1] = key;            // [D4] 2 marks

        cout << "  Step " << i << ":";
        printArray(arr, n);
    }
}


// ============================================================
//  PART E – LINEAR SEARCH & BINARY SEARCH    [20 marks]
//  Search for a target visitor count in the SORTED array.
//  Fill in the 5 blanks labelled [E1]–[E5].
// ============================================================

// [AUTO-GRADE] FUNCTION: linearSearch
// Returns the index of target in arr, or -1 if not found.
int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        // [E1] Return index when target is found
        if (arr[i] == target) {   // [E1] 2 marks
            return i;            // [E2] 2 marks
        }
    }
    return -1;  // not found
}

// [AUTO-GRADE] FUNCTION: binarySearch
// Returns the index of target in arr (sorted ascending), or -1 if not found.
int binarySearch(int arr[], int n, int target) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        // [E3] Calculate the mid-point index
        int mid = (low + high) / 2 ;             // [E3] 2 marks

        if (arr[mid] == target) {
            return mid;
        }
        else if (arr[mid] < target) {
            // [E4] Target is in the right half – move low
            low = mid + 1;             // [E4] 2 marks
        }
        else {
            // [E5] Target is in the left half – move high
            high = mid - 1;            // [E5] 2 marks
        }
    }
    return -1;  // not found
}


// ============================================================
//  MAIN – Do NOT modify anything below this line.
// ============================================================
int main() {
    cout << "================================================================" << endl;
    cout << "  BITP1123 – Lab Test 1: Sorting & Searching" << endl;
    cout << "  Melaka Tourist Attraction Visitor Management System" << endl;
    cout << "================================================================" << endl;

    // Original visitor data (unsorted)
    int visitorsB[SIZE] = { 4200, 1850, 3600, 920, 5100, 2750, 3300, 1400 };
    int visitorsC[SIZE] = { 4200, 1850, 3600, 920, 5100, 2750, 3300, 1400 };
    int visitorsD[SIZE] = { 4200, 1850, 3600, 920, 5100, 2750, 3300, 1400 };

    cout << "\n  ORIGINAL DATA:" << endl;
    printArray(visitorsB, SIZE);

    // --- Part B: Selection Sort ---
    cout << "\n========== PART B: SELECTION SORT ==========\n" << endl;
    selectionSort(visitorsB, SIZE);
    cout << "  [RESULT – Selection Sort]" << endl;
    printArray(visitorsB, SIZE);

    // --- Part C: Bubble Sort ---
    cout << "\n========== PART C: BUBBLE SORT ==========\n" << endl;
    bubbleSort(visitorsC, SIZE);
    cout << "  [RESULT – Bubble Sort]" << endl;
    printArray(visitorsC, SIZE);

    // --- Part D: Insertion Sort ---
    cout << "\n========== PART D: INSERTION SORT ==========\n" << endl;
    insertionSort(visitorsD, SIZE);
    cout << "  [RESULT – Insertion Sort]" << endl;
    printArray(visitorsD, SIZE);

    // --- Part E: Searching (use Bubble-sorted array) ---
    cout << "\n========== PART E: SEARCHING ==========\n" << endl;

    int searchTarget1 = 3300;
    int searchTarget2 = 9999;  // not in list

    cout << "  Searching for visitor count: " << searchTarget1 << endl;
    int linResult1 = linearSearch(visitorsC, SIZE, searchTarget1);
    if (linResult1 != -1)
        cout << "  [LINEAR SEARCH]  Found at index " << linResult1 << endl;
    else
        cout << "  [LINEAR SEARCH]  Not found." << endl;

    int binResult1 = binarySearch(visitorsC, SIZE, searchTarget1);
    if (binResult1 != -1)
        cout << "  [BINARY SEARCH]  Found at index " << binResult1 << endl;
    else
        cout << "  [BINARY SEARCH]  Not found." << endl;

    cout << "\n  Searching for visitor count: " << searchTarget2 << endl;
    int linResult2 = linearSearch(visitorsC, SIZE, searchTarget2);
    if (linResult2 != -1)
        cout << "  [LINEAR SEARCH]  Found at index " << linResult2 << endl;
    else
        cout << "  [LINEAR SEARCH]  Not found." << endl;

    int binResult2 = binarySearch(visitorsC, SIZE, searchTarget2);
    if (binResult2 != -1)
        cout << "  [BINARY SEARCH]  Found at index " << binResult2 << endl;
    else
        cout << "  [BINARY SEARCH]  Not found." << endl;

    cout << "\n================================================================" << endl;
    cout << "  End of Lab Test 1" << endl;
    cout << "================================================================" << endl;

    return 0;
}