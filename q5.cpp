#include <stdio.h>
#include <stdbool.h>

#define MAX_DIGIT 8

char decode_sequence(char sequence[]) 
{
  int result[MAX_DIGIT];
  bool used_digits[MAX_DIGIT + 1] = {false}; // +1 to handle digits from 1 to 8

  int current_digit = 0;
  int result_index = 0;

  for (int i = 0; sequence[i] != '\0'; i++) 
  {
    if (sequence[i] == 'I') {
      // Check if we have reached the maximum digit
      if (current_digit == MAX_DIGIT) 
      {
        printf("Error: Sequence cannot have more than %d 'I's\n", MAX_DIGIT);
        return -1;
      }
      result[result_index++] = ++current_digit;
      used_digits[current_digit] = true;
    } 
    else if (sequence[i] == 'D') 
    {
      // Find the largest unused digit number
      for (int digit = current_digit ? current_digit - 1 : MAX_DIGIT; digit >= 1; digit--) 
      {
        if (!used_digits[digit]) 
        {
          result[result_index++] = digit;
          used_digits[digit] = true;
          break;
        }
      }
    } 
    else 
    {
      printf("Error: Invalid character in sequence: %c\n", sequence[i]);
      return -1;
    }
  }

  // Print the decoded number
  for (int i = 0; i < result_index; i++) 
  {
    printf("%d", result[i]);
  }
  printf("\n");
return 0;
}

int main() 
{
  char sequence1[] = "IIDDIDI";
  char sequence2[] = "IDDDI";
  char sequence3[] = "DDID";
  char sequence4[] = "IIDI";
  char sequence5[] = "XX"; // Invalid character

  decode_sequence(sequence1); // 
  decode_sequence(sequence2); // 
  decode_sequence(sequence3); // 
  decode_sequence(sequence4); 
  decode_sequence(sequence5); 
 return 0;
}