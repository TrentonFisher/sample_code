import java.util.Scanner; 

class Assignment3 {
  
  //Trenton Fisher, 100162307
  
  public static void main(String [] args) {
    
  int tryCounter = 0; 
  int numUV = 2; //Number of "u"s and "v"s to be printed (used later in for loop)
    
  Scanner Scan = new Scanner(System.in);
  
  System.out.println("Are you a human? Enter the number of months in a year to verify you are: ");
  String userInput = Scan.nextLine();
  
  System.out.println(userInput);
    
  while (!userInput.equals("12"))  { //Continues until user inputs 12
    
    tryCounter++;
    System.out.println("\nIncorrect, try again!");
    userInput = Scan.nextLine(); 
    
  }

  if (tryCounter >= 3) {
    System.out.println("\nYou are a robot. You cannot log in"); } //If user takes more than three tries, this happens
  
  else if (tryCounter < 2) {   
   
  System.out.println("\nSuccess, you may proceed!");
  
  System.out.println("\nPlease enter a number between 4 and 19"); 
  int height = Scan.nextInt();
  
  while (!(4 <= height && height <= 19)) {
 
  System.out.println("\nPlease enter a number between 4 and 19"); //Continues until input is between 4 and 19 (Including 4 & 19)
  height = Scan.nextInt(); }
  
  for (int i = 0; i < height; i++) {
     
     if ( i % 2 == 0) { //printing "u" or "v" a number of times based on if the number is even or odd
       
       for (int x = 1; x <= numUV; x++) {
       
         System.out.print("u"); } 
     
     System.out.println();
       
     }
     
     else {
       
       for (int y = 1; y <= numUV; y++) {
       
         System.out.print("v"); } 
       
       System.out.println();
       
       numUV++; //Controls number of "u"s and "v"s get printed, goes up by 1 after every full loop
     
     } 
            
  }
    
  } 
  
  else if (tryCounter == 2) {
    System.out.print("\nThird times the charm!\n");
         
    for (int i = 0; i < 1; i++) {
      
      System.out.println("\n*)");
      
      for (int x = 0; x < 2; x++) {
      
        System.out.println("\n(*"); 
            
        for (int y = 0; y < 1; y++) {
      
          System.out.println("\n)*"); } } }    
  }
        
}
  
}