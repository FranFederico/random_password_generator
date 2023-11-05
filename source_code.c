#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>




// Function to randomly generates password
// of length N
int randomPasswordGeneration()
{

    // Prompt the user to enter the desired password length
  printf("Desired password's lenght: ");

   // Store the length entered into the password variable
  int length;
  scanf("%d", &length);

  // If the password length is not at least 4 we can't create a password,
  // so exit with an error message and status
  if (length < 4)
  {
    // Output the error message to inform the user what the problem is
    printf("Password is too short! Password length must be >= 4 characters!");

    // Returning 1 instead of 0 is a signal to the terminal something has gone wrong
    return 1;
  }

	// Initialize counter
	int i = 0;

	int randomizer = 0;

	/* Seed the random-number generator
       with current time so that the
	   numbers will be different every time */

	srand((unsigned int)(time(NULL)));

	// Array of numbers
	char numbers[] = "0123456789";

	// Array of undercase alphabets
	char letter[] = "abcdefghijklmnoqprstuvwyzx";

	// Array of uppercase alphabets
	char LETTER[] = "ABCDEFGHIJKLMNOQPRSTUYWVZX";

	// Array of some special symbols
	char symbols[] = "!@#$^&'%?§€£*|";

	// Stores the random password
	char password[length];

	// To select the randomizer inside the loop
	randomizer = rand() % 4;

	// Iterate over the range [0, length]
	for (i = 0; i < length; i++) {

		if (randomizer == 1) {
			password[i] = numbers[rand() % 10];
			randomizer = rand() % 4;
			printf("%c", password[i]);
		}
		else if (randomizer == 2) {
			password[i] = symbols[rand() % 14];
			randomizer = rand() % 4;
			printf("%c", password[i]);
		}
		else if (randomizer == 3) {
			password[i] = LETTER[rand() % 26];
			randomizer = rand() % 4;
			printf("%c", password[i]);
		}
		else {
			password[i] = letter[rand() % 26];
			randomizer = rand() % 4;
			printf("%c", password[i]);
		}
	}
}

// Driver Code
int main()
{
	// Length of the password to be generated
	 int length = length;

	// Function Call
	randomPasswordGeneration(length);

	return 0;
}
