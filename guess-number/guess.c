#include <stdio.h>
#include <stdlib.h>

int main()
{
	int guess;
	int randomNumber = rand() % 10 + 1;

	printf("Guess the a number between 1 and 10!\n");

	printf("Enter your guess: ");

	scanf("%d", &guess);

	while (guess != randomNumber) {
		printf("Wrong guess, try again: ");
		scanf("%d", &guess);
	}

	printf("You guessed the number! %d", randomNumber);
}