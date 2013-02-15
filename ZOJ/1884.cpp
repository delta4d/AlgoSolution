#include<stdio.h>

char message[100];

int main(void)
{
	int len;
	int i;

	while (gets(message) != NULL)
	{
		len = strlen(message);
		
		for (i=0; i<len; ++i)
		{
			switch(message[i])
			{
				case 'W': message[i] = 'Q';
				          break;
				case 'E': message[i] = 'W';
				          break;
				case 'R': message[i] = 'E';
				          break;
				case 'T': message[i] = 'R';
				          break;
				case 'Y': message[i] = 'T';
				          break;
				case 'U': message[i] = 'Y';
				          break;
				case 'I': message[i] = 'U';
				          break;
				case 'O': message[i] = 'I';
						  break;         
				case 'P': message[i] = 'O';
				          break;
				case '[': message[i] = 'P';
				          break;
				case ']': message[i] = '[';
				          break;
				case '\\': message[i] = ']';
				          break;
				case 'S': message[i] = 'A';
				          break;
				case 'D': message[i] = 'S';
				          break;
				case 'F': message[i] = 'D';
				          break;
				case 'G': message[i] = 'F';
				          break;
				case 'H': message[i] = 'G';
				          break;
				case 'J': message[i] = 'H';
				          break;
				case 'K': message[i] = 'J';
				          break;
				case 'L': message[i] = 'K';
				          break;
				case ';': message[i] = 'L';
				          break;
				case '\'': message[i] = ';';
						  break;
				case 'X': message[i] = 'Z';
				          break;
				case 'C': message[i] = 'X';
				          break;
				case 'V': message[i] = 'C';
				          break;		 
				case 'B': message[i] = 'V';
				          break;
				case 'N': message[i] = 'B';
				          break;
				case 'M': message[i] = 'N';
				          break;
				case ',': message[i] = 'M';
				          break;
				case '.': message[i] = ',';
				          break;
				case '/': message[i] = '.';
				          break;
				case '1': message[i] = '`';
				          break;
				case '2': message[i] = '1';
				          break;
				case '3': message[i] = '2';
				          break;		 
				case '4': message[i] = '3';
				          break;
				case '5': message[i] = '4';
				          break;
				case '6': message[i] = '5';
				          break;
				case '7': message[i] = '6';
				          break;
				case '8': message[i] = '7';
				          break;
				case '9': message[i] = '8';
				          break;
			    case '0': message[i] = '9';
				          break;  		           
				case '-': message[i] = '0';
				          break;
			    case '=': message[i] = '-';
				          break;  	       
				default:  break;
						  		  		  		  		  		  		  		  		  		   		  		  		            
			}
		}
		
		for (i=0; i<len; ++i)
		{
			printf("%c", message[i]);
		}
		
		printf("\n");
	}

	return 0;
}
