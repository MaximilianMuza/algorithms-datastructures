#include <iostream>

bool findAnagram(char *a1, char *a2) {
	for (int i = 0; a1[i] != '\0'; i++) {
		bool indicator = false;
		for (int j = 0; a2[j] != '\0'; j++) {
			if (a1[i] == a2[j]) {
				indicator = true;
				break;
			}
		}
		if (indicator == false) {
			std::cout << "no anagram" << std::endl;
			return false;
		}
	}
	std::cout << "anagram" << std::endl;
	return true;
}

int main() {
	char a1[] = "stale";
	char a2[] = "least";
	findAnagram(a1, a2);
	return 0;
}