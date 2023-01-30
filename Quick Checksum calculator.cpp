
//=================================================
// This only displays 1 or 0
// ===============================================
//#include <iostream>
//#include <vector>
//
//unsigned char calcChecksum(const std::vector<unsigned char>& bytes) {
//    unsigned char chksum = 0x00;
//    for (int i = 1; i < bytes.size(); i++) {
//        chksum += bytes[i];
//    }
//    return -chksum;
//}
//
//bool evaluateChecksum(const std::vector<unsigned char>& bytes) {
//    if (bytes.size() > 4 && calcChecksum(bytes) == 0x00) {
//        return true;
//    }
//    else {
//        return false;
//    }
//}
//
//int main() {
//    std::vector<unsigned char> test = { 0xFA, 0xFF, 0x31, 0x00 };
//    bool result = evaluateChecksum(test);
//    std::cout << "Result: " << result << std::endl;
//    return 0;
//}
//=================================================


// 0xFA, 0xFF, 0x30, 0x00, 0xD1

#include <iostream>
#include <vector>

// Function to calculate checksum
unsigned char calcChksum(const std::vector<unsigned char>& bytes)
{
    // The preamble is excluded
    // Initialize the checksum to 0x00
    unsigned char chksum = 0x00;

    // Loop through the bytes, starting from index 1
    for (int i = 1; i < bytes.size(); i++)
    {
        // Add each byte to the checksum
        chksum += bytes[i];

        // Print the calculation for each iteration
        std::cout << "chksum so far: 0x(" << i << ") = " << (int)chksum << std::endl;
    }

    // Return the negated checksum
    return -chksum;
}

int main()
{
    // Input data
    std::vector<unsigned char> bytes = { 0xFA, 0xFF, 0x31, 0x00 };

    // Calculate the checksum
    unsigned char result = calcChksum(bytes);

    // Print the result in hexadecimal format
    std::cout << "Checksum: 0x" << std::hex << (int)result << std::endl;

    return 0;
}
