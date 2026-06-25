#include <iostream>
#include "../List/List.h" // Your custom path to library

int main () {
    List<int> nums1;
    List<int> nums2;
    nums1.append(1);
    nums2.append(2);
    List<int> nums3 = nums1 + nums2;
    nums3.print();
}