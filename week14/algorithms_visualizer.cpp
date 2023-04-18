//Created by Jacinto Gomez
//NYU Tandon School of Engineering
//Cornell College of Engineering

#include <iostream>
#include <string>
#include <vector>
using namespace std;

void print(vector<int> ar) {
    if (ar.size() == 0) {
        cout << "[]" << endl;
        return;
    }
    cout << "[";
    for (int x = 0; x < ar.size() - 1; x++) {
        cout << ar[x] << ",";
    }
    cout << ar.back() << "]" << endl;
}

void printsameline(vector<int> ar) {
    if (ar.size() == 0) {
        cout << "[]";
        return;
    }
    cout << "[";
    for (int x = 0; x < ar.size() - 1; x++) {
        cout << ar[x] << ",";
    }
    cout << ar.back() << "]";
}

void printsortedportion(int index) {
    cout << "|";
    for (int i = 0; i < index; i++) {
        cout << "_";
    }
    cout << "| <-sorted portion... ";
}

int countspaces(vector<int> ve, int index) {
    int count = 0;
    for (int i = 0; i <= index; i++) {
        string element = to_string(ve[i]);
        count += element.size();
    }
    count += index;
    return count;
}

int countspacesmerge(vector<int> ve, int index) {
    int count = 0;
    for (int i = 0; i < index; i++) {
        string element = to_string(ve[i]);
        count += element.size();
    }
    count += index;
    return count;
}

int countspacesbubble(vector<int> ve, int index) {
    int count = 0;
    for (int i = 0; i <= index - 1; i++) {
        string element = to_string(ve[i]);
        count += element.size();
    }
    count += index + 1;
    return count;
}

int countmiddleunderscores(vector<int> ve, int start, int end) {
    int count = 0;
    for (int i = start; i <= end; i++) {
        string element = to_string(ve[i]);
        count += element.size();
    }
    count += end - start;
    return count;
}

int counttotalspaces(vector<int> ve) {
    int count = 0;
    for (int i = 0; i < ve.size(); i++) {
        string element = to_string(ve[i]);
        count += element.size();
    }
    count += ve.size() - 1 + 2;//-1 because there will be 1 less comma than elements, +2 for the 2 brackets
    return count;
}

int counttotalspacesquick(vector<int> ve) {
    int count = 0;
    for (int i = 0; i < ve.size(); i++) {
        string element = to_string(ve[i]);
        count += element.size();
    }
    count += ve.size() - 1 + 2;//-1 because there will be 1 less comma than elements, +2 for the 2 brackets
    return count;
}

void printsortedportionbubble(int index, vector<int> ve) {
    int totalchars = counttotalspaces(ve);
    int spacestoindex = countspacesbubble(ve, index);
    int sortedduration = totalchars - spacestoindex;
    for (int i = 1; i < spacestoindex; i++) {
        cout << " ";
    }
    cout << "|";
    for (int i = 1; i < sortedduration; i++) {
        cout << "_";
    }
    cout << "| <-sorted portion... ";
}

void printsortedportionmerge(int blanks, int range) {
    for (int i = 0; i < blanks; i++) {
        cout << " ";
    }
    cout << "|";
    for (int i = 0; i < range; i++) {
        cout << "_";
    }
    cout << "| <-segment just sorted... ";
}

void insertionwithoutmessages(vector<int>& ar) {
    for (int i = 1; i < ar.size(); i++) {
        int key = ar[i];
        int j = i - 1;
        while (j >= 0 && ar[j] > key) {
            ar[j + 1] = ar[j];
            j--;
        }
        ar[j + 1] = key;
    }
}

void mergesort(vector<int>& ar, int left, int mid, int right) {
    vector<int> half1 = {};
    vector<int> half2 = {};
    int half1length = mid - left + 1;
    int half2length = right - mid;
    for (int i = 0; i < half1length; i++) { half1.push_back(ar[left + i]); }
    for (int i = 0; i < half2length; i++) { half2.push_back(ar[mid + i + 1]); }
    int i = 0;
    int j = 0;
    int k = left;
    while (i < half1length && j < half2length) {
        if (half1[i] <= half2[j]) {
            ar[k] = half1[i];
            i++;
        }
        else {
            ar[k] = half2[j];
            j++;
        }
        k++;
    }
    while (i < half1length) {
        ar[k] = half1[i];
        i++;
        k++;
    }
    while (j < half2length) {
        ar[k] = half2[j];
        j++;
        k++;
    }
}

void merge(vector<int>& ar, int begin, int end, int step) {
    if (begin >= end) { return; }
    int mid = begin + (end - begin) / 2;
    merge(ar, begin, mid, step + 1);
    merge(ar, mid + 1, end, step + 1);
    mergesort(ar, begin, mid, end);
    print(ar);
    printsortedportionmerge(countspacesmerge(ar, begin), countmiddleunderscores(ar, begin, end));
    cout << " this recursive call is " << step << " level(s) deep" << endl;
}

void bubble(vector<int>& ar) {
    for (int i = ar.size() - 1; i >= 0; i--) {
        bool swap = false;
        for (int j = 0; j < i; j++) {
            if (ar[j] > ar[j + 1]) {
                int temp = ar[j + 1];
                ar[j + 1] = ar[j];
                ar[j] = temp;
                swap = true;
            }
        }
        print(ar);
        printsortedportionbubble(i, ar);
        if (swap) {
            cout << " " << ar[i] << " was the next largest, and was moved up to the end" << endl;
        }
        else {
            cout << " next largest element " << ar[i] << " was already in sorted position" << endl;
        }
    }
}

void selection(vector<int>& ar) {
    for (int i = 0; i < ar.size(); i++) {
        int min = i;
        for (int j = i + 1; j < ar.size(); j++) {
            if (ar[min] > ar[j]) {
                min = j;
            }
        }
        if (min != i) {
            int temp = ar[min];
            ar[min] = ar[i];
            ar[i] = temp;
        }
        print(ar);
        printsortedportion(countspaces(ar, i));
        if (ar[min] != ar[i]) {
            cout << " the next largest was " << ar[i] << " and was swapped with " << ar[min] << endl;
        }
        else {
            cout << " " << ar[min] << " happened to be the next smallest, so no swap occurred" << endl;
        }
    }
}

void insertion(vector<int>& ar) {
    for (int i = 1; i < ar.size(); i++) {
        int key = ar[i];
        int j = i - 1;
        while (j >= 0 && ar[j] > key) {
            ar[j + 1] = ar[j];
            j--;
        }
        int temp = ar[j + 1];
        ar[j + 1] = key;
        print(ar);
        printsortedportion(countspaces(ar, i));
        if (key != temp) {
            cout << key << " was the next element in line, and was inserted before " << temp << endl;
        }
        else {
            cout << "next element was the largest so far, no insertions were necessary" << endl;
        }
    }
}

void printsortedportionquick(int index, vector<int> ve) {
    int totalchars = counttotalspacesquick(ve) - 2; //-2 to subtract the brackets
    int spacestoindex = countspacesbubble(ve, index) - 2; //-2 to subtract the two |'s
    int spacesuptopivot = countspacesbubble(ve, index + 1) - 2;
    int pivotspaces = spacesuptopivot - spacestoindex - 1;
    int afterpiv = totalchars - spacesuptopivot - 1;
    cout << " <-- Pivot is " << ve[index] << ", numbers greater than it placed to the left, smaller to the right" << endl;
    if (index != 0) { cout << "|"; }
    else { spacestoindex++; }
    for (int i = 1; i <= spacestoindex; i++) {
        cout << "_";
    }
    cout << "|";
    for (int i = 1; i <= pivotspaces; i++) {
        cout << " ";
    }
    cout << "|";
    for (int i = 1; i <= afterpiv; i++) {
        cout << "_";
    }
    if (index != ve.size() - 1) { cout << "|"; }
}

int partition(vector<int>& ar, int low, int high, int step) {
    int pivot = ar[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (ar[j] < pivot) {
            i++;
            int temp = ar[j];
            ar[j] = ar[i];
            ar[i] = temp;
        }
    }
    int other = ar[i + 1];
    ar[i + 1] = ar[high];
    ar[high] = other;
    printsameline(ar);
    printsortedportionquick(i + 1, ar);
    cout << "     This recursive call is " << step << " level(s) deep" << endl;
    return i + 1;
}

void quick(vector<int>& ar, int low, int high, int step) {
    if (low < high) {
        int pivot = partition(ar, low, high, step);
        quick(ar, low, pivot - 1, step + 1);
        quick(ar, pivot + 1, high, step + 1);
    }
}

void heapify(vector<int>& ar, int n, int parent) {
    int max = parent;
    int left = 2 * parent + 1;
    int right = 2 * parent + 2;
    if (left<n && ar[left]>ar[max]) { max = left; }
    if (right<n && ar[right]>ar[max]) { max = right; }
    if (max != parent) {
        int temp = ar[parent];
        ar[parent] = ar[max];
        ar[max] = temp;
        heapify(ar, n, max);
    }
}

void heap(vector<int>& ar) {
    cout << "Call heapify to turn array into max heap --> ";
    int n = ar.size();
    for (int i = n / 2 - 1; i >= 0; i--) { heapify(ar, n, i); }
    print(ar);
    cout << "Keep calling heapify each time a max element is taken away.." << endl;
    for (int j = n - 1; j >= 1; j--) {
        int temp = ar[0];
        ar[0] = ar[j];
        ar[j] = temp;
        printsameline(ar);
        cout << "   Switched heap root " << temp << " with last leaf " << ar[0] << ", then call heapify on new root" << endl;
        heapify(ar, j, 0);
        print(ar);
        printsortedportionbubble(j, ar);
        cout << ar[j] << " removed from heap" << endl;
    }
}

int getmax(vector<int> ar) {
    int mx = ar[0];
    for (int i : ar) {
        if (i > mx) {
            mx = i;
        }
    }
    return mx;
}

int getmin(vector<int> ar) {
    int mn = ar[0];
    for (int i : ar) {
        if (i < mn) {
            mn = i;
        }
    }
    return mn;
}

void countsort(vector<int>& ar, int exp) {
    int n = ar.size();
    vector<int> output(n, 0);
    vector<int> count(10, 0);
    for (int i = 0; i < n; i++) { count[(ar[i] / exp) % 10]++; }
    for (int i = 1; i < 10; i++) { count[i] += count[i - 1]; }
    for (int i = n - 1; i >= 0; i--) {
        output[count[(ar[i] / exp) % 10] - 1] = ar[i];
        count[(ar[i] / exp) % 10]--;
    }
    for (int i = 0; i < n; i++) { ar[i] = output[i]; }
}

void radix(vector<int>& ar) {
    int step = 1;
    int m = getmax(ar);
    for (int exp = 1; m / exp > 0; exp *= 10) {
        countsort(ar, exp);
        printsameline(ar);
        cout << "<--- iteration " << step << " called counting sort on the " << exp << "'s digit" << endl;
        step++;
    }
}

void counting(vector<int>& ar) {
    int max = getmax(ar);
    cout << "This will use the max value of your array as the range...";
    int n = ar.size();
    vector<int> output(n, 0);
    cout << "Output array initialized as ---> ";
    print(output);
    vector<int> count(max + 1, 0);
    cout << "Count array initialized as ---> ";
    print(count);
    for (int i = 0; i < n; i++) { count[ar[i]]++; }
    cout << "Count updated with frequency of each index ---> ";
    print(count);
    for (int j = 1; j <= max; j++) { count[j] += count[j - 1]; }
    cout << "Count updated with index of each index --> ";
    print(count);
    for (int k = n - 1; k >= 0; k--) {
        cout << "Placing " << ar[k] << " into output array" << endl;
        output[count[ar[k]] - 1] = ar[k];
        count[ar[k]]--;
        cout << "Output is now --> ";
        printsameline(output);
        cout << "  Count is now --> ";
        print(count);
    }
    ar = output;
}

void bucket(vector<int>& ar) {
    double max = getmax(ar);
    double min = getmin(ar);
    int buckets;
    cout << "If you want to choose your number of buckets then enter it below,"
        "\notherwise enter 0 to use the square root of n" << endl;
    cout << "Number of buckets: ";
    cin >> buckets;
    while (buckets < 0) {
        cout << "Bucket number must be positive!" << endl;
        cout << "Re-enter the number of buckets: ";
        cin >> buckets;
    }
    if (buckets == 0) {
        buckets = int(pow(ar.size(), 0.5));
    }
    double rnge = double((max - min) / buckets);
    vector<vector<int>> all;
    for (int x = 0; x < buckets; x++) {
        all.push_back(vector<int>());
    }
    for (int i = 0; i < ar.size(); i++) {
        double diff = (ar[i] - min) / rnge - int((ar[i] - min) / rnge);
        if (diff == 0 && ar[i] != min) {
            all[int((ar[i] - min) / rnge) - 1].push_back(ar[i]);
        }
        else {
            all[int((ar[i] - min) / rnge)].push_back(ar[i]);
        }
    }
    cout << "Sort elements of specific ranges into buckets:" << endl;
    for (int j = 0; j < all.size(); j++) {
        cout << "Bucket " << j + 1 << ": ";
        print(all[j]);
    }
    for (int j = 0; j < all.size(); j++) {
        if (!all[j].empty()) {
            insertionwithoutmessages(all[j]);
        }
    }
    cout << "Sort each bucket with insertion sort, and concatenate into one array" << endl;
    int k = 0;
    for (vector<int>& l : all) {
        if (!l.empty()) {
            for (double i : l) {
                ar[k] = i;
                k++;
            }
        }
    }
}

vector<int> vecmaker(string in) {
    vector<int> out = {};
    int index = 0;
    int length = 0;
    string potentialdigit;
    if (in.size() == 0) {
        cout << "Error: cannot enter empty array";
        exit(1);
    }
    for (int i = 0; i < in.size(); i++) {
        if (in[i] == ' ') {
            potentialdigit = in.substr(index, length);
            if (!isdigit(potentialdigit[0])) {
                cout << "Error: improper formatting, try again please";
                exit(1);
            }
            out.push_back(stoi(potentialdigit));
            index = i + 1;
            length = 0;
        }
        else {
            length++;
        }
    }
    out.push_back(stoi(in.substr(index, length)));
    return out;
}

void displayoptions() {
    cout << "1. Mergesort" << endl;
    cout << "2. Insertion Sort" << endl;
    cout << "3. Selection Sort" << endl;
    cout << "4. Bubble Sort" << endl;
    cout << "5. Quicksort" << endl;
    cout << "6. Heapsort" << endl;
    cout << "7. Counting Sort" << endl;
    cout << "8. Radix Sort" << endl;
    cout << "9. Bucket Sort" << endl;
    cout << "or press 0 for algorithm info" << endl;
}

void afteroptions() {
    cout << "1. Choose new algorithm for same array" << endl;
    cout << "2. Enter new array" << endl;
    cout << "3. Exit" << endl;
}

void displayalgoinfo() {
    cout << "------------------------" << endl;
    cout << "Mergesort: " << endl;
    cout << "Recursive. This breaks the array into 2 smaller arrays until the base case of an array of size 1 is reached,"
        "\nthen merges these auxiliary arrays in sorted order. This ends up being efficient since each auxiliary array"
        "\ngoing up the call stack will already be in sorted order." << endl;
    cout << "Time Complexity: Theta(nlog(n))" << endl;
    cout << "Space Complexity: O(n)" << endl;
    cout << "------------------------" << endl;
    cout << "Insertion Sort: " << endl;
    cout << "For each element, insert it by pushing it back until it's in its proper spot in the sorted part of the array." << endl;
    cout << "Time Complexity: Omega(n), Theta(n^2), O(n^2)" << endl;
    cout << "Space Complexity: O(1)" << endl;
    cout << "------------------------" << endl;
    cout << "Selection Sort:" << endl;
    cout << "Go through the unsorted portion of the array to select the next smallest element, and swap with the current." << endl;
    cout << "Time Complexity: Theta(n^2)" << endl;
    cout << "Space Complexity: O(1)" << endl;
    cout << "------------------------" << endl;
    cout << "Bubble Sort:" << endl;
    cout << "Compare side by side elements and swap if the left one is larger; with each trial of this the next largest"
        "\nelement 'bubbles' to the top. This needs to be done for n passes, since each pass only brings the"
        "\nnext largest element to the top." << endl;
    cout << "Time Complexity: Omega(n), Theta(n^2), O(n^2)" << endl;
    cout << "Space Complexity: O(1)" << endl;
    cout << "------------------------" << endl;
    cout << "Quicksort:" << endl;
    cout << "Recursive. For each call, a random element called the pivot is chosen and all elements less than it are"
        "\nplaced to the left, and all elements greater are placed to the right. It is then recursively called on those two halves."
        "\nA function called partition is used to select the pivot either randomly, or as a fixed array index (here it is fixed, the last index)." << endl;
    cout << "Time Complexity: Omega(nlog(n)), Theta(nlog(n)), O(n^2)" << endl;
    cout << "Space Complexity: O(nlog(n))" << endl;
    cout << "------------------------" << endl;
    cout << "Heapsort:" << endl;
    cout << "This forms a max heap (a tree but with the condition that a parent is greater than a child),"
        "\nand for each node starting from the last leaf, switches it with the root node and calls"
        "\na function called heapify, which restructures the tree so that the max element is on top again. Each time a max"
        "\nelement is removed, it is essentially at the end of an array; in other words, is now in sorted position. It should"
        "\nbe noted that heapsort itself is not recursive, but it calls heapify which is." << endl;
    cout << "Time Complexity: Theta(nlog(n))" << endl;
    cout << "Space Complexity: O(1)" << endl;
    cout << "------------------------" << endl;
    cout << "Counting Sort:" << endl;
    cout << "Create two new arrays, one counting the frequency of occurrence of each number in the array (then adjusted"
        "\nto represent the array index), and the other to hold the output array. The output array at index i is updated with the"
        "\nvalue of indexarray[originalarray[i]] for each i in range n. This results in linear runtime, but it only works"
        "\nif the range of numbers is known beforehand. This is also a stable sort, meaning the order of repeated values doesn't change" << endl;
    cout << "Time Complexity: Theta(n+k) k=range of possible values" << endl;
    cout << "Space Complexity: O(k)" << endl;
    cout << "------------------------" << endl;
    cout << "Radix Sort:" << endl;
    cout << "This will first sort all elements by the digit in the 1's place, then by the digit in the 10's place.. continuing"
        "\nthrough to the last digit. The sorting is done with some stable sorting algorithm (counting sort, for example)." << endl;
    cout << "Time Complexity: Theta(d(n+k)) d=max # of digits, k=base of whatever number we are using (usually 10)" << endl;
    cout << "Space Complexity: O(n+k)" << endl;
    cout << "------------------------" << endl;
    cout << "Bucket Sort:" << endl;
    cout << "Adjust input so they are all in range [0:1), and divide range into buckets where certain ranges of values will go."
        "\nThese buckets, which will ideally be near-sorted, are then sorted using insertion sort." << endl;
    cout << "Time Complexity: Omega(n+k), Theta(n+k), O(n^2)" << endl;
    cout << "Space Complexity: O(n)" << endl;
}

void switchloop1(int choice, vector<int> list) {
    switch (choice) {
    case 0:
        displayalgoinfo();
        break;
    case 1:
        cout << "Mergesort: " << endl;
        merge(list, 0, list.size() - 1, 0);
        break;
    case 2:
        cout << "Insertion Sort: " << endl;
        insertion(list);
        break;
    case 3:
        cout << "Selection Sort:" << endl;
        selection(list);
        break;
    case 4:
        cout << "Bubble Sort:" << endl;
        bubble(list);
        break;
    case 5:
        cout << "Quicksort:" << endl;
        quick(list, 0, list.size() - 1, 0);
        break;
    case 6:
        cout << "Heapsort:" << endl;
        heap(list);
        break;
    case 7:
        cout << "Counting Sort" << endl;
        counting(list);
        break;
    case 8:
        cout << "Radix Sort:" << endl;
        radix(list);
        break;
    case 9:
        cout << "Bucket Sort" << endl;
        bucket(list);
        break;
    default:
        cout << "No selection made/Invalid selection" << endl;
    }
    cout << "Final Sorted Array: ";
    print(list);
}

void switchloop2(int choice, vector<int>& list) {
    string ar;
    int newchoice;
    switch (choice) {
    case 1:
        displayoptions();
        cin >> newchoice;
        switchloop1(newchoice, list);
        break;
    case 2:
        cout << "Pick a new array and type in the same format as before" << endl;
        cout << "Example: [3,1,2] should be entered as 3 1 2" << endl;
        cout << "Enter your array: ";
        //validateinput(ar);
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, ar);
        list = vecmaker(ar);
        displayoptions();
        cin >> newchoice;
        switchloop1(newchoice, list);
        break;
    case 3:
        cout << "Hope this was helpful :)";
        break;
    default:
        cout << "Invalid selection" << endl;
    }
}

int main() {
    string ar;
    int choice = 0;
    cout << "This program will trace the sorting of an array with whatever sorting algorithm you select," << endl;
    cout << "Note that: " << endl;
    cout << "\t1. The output will only appear properly in a compiler that is monospaced (fixed spacing)" << endl;
    cout << "\t2. This program will not work for negative numbers or inputs other than int" << endl;
    cout << "\t3. The array will be sorted in increasing order" << endl;
    cout << "Choose an array and enter without brackets or commas, and separated by spaces" << endl;
    cout << "Example: [3,1,2] should be entered as 3 1 2" << endl;
    cout << "Enter your array: ";
    getline(cin, ar);
    vector<int> list = vecmaker(ar);
    cout << "Next, choose a sorting algorithm from the options below by entering the corresponding number:" << endl;
    displayoptions();
    cin >> choice;
    cout << "Original Array: ";
    print(list);
    switchloop1(choice, list);
    do {
        afteroptions();
        cin >> choice;
        switchloop2(choice, list);
    } while (choice != 3);
    return 0;
}