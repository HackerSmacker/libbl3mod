#include <stdio.h>                                                              
#include <stdlib.h>                                                             

/* Size tester */
/* Update 6/18/21: Why is this in here? This has NOTHING to do with */
/* BL3 modding; I think it was put here for the sole purpose of making */
/* sure that this library is more compatible. */

int main() {                                                                    
 printf("C Size Tester\n");                                                     
 printf("short: %d\n", sizeof(short));                                          
 printf("int: %d\n", sizeof(int));                                              
 printf("long: %d\n", sizeof(long));                                            
 printf("char: %d\n", sizeof(char));                                            
 printf("unsigned short: %d\n", sizeof(unsigned short));                        
 printf("unsigned int: %d\n", sizeof(unsigned int));                            
 printf("unsigned long: %d\n", sizeof(unsigned long));                          
 printf("unsigned char: %d\n", sizeof(unsigned char));                          
 return 0;                                                                      
}                                                                               
