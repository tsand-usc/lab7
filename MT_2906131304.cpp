#include <iostream>
#include <fstream>
#include <string>
#include <deque>
#include <ctime>

struct ingredient{ // hold info on a layer element
   
   int numIng; 
   std::string iname;
    
};

class Sequential{ // contains the layer elements, decoding of a layer element, and printing

   private:
      std::deque<ingredient> layer;  
   
   public:
      Sequential(); 
      ~Sequential(); 
      void get_ing(std::string, std::string); 
      void printIng(std::string); 
      void decode(std::string); 
   
};

Sequential::Sequential(){

   std::cout << "Created Class" << std::endl;

}

Sequential::~Sequential(){

   std::cout << "Destroyed Class" << std::endl; 
} 

void Sequential::get_ing(std::string input, std::string output){
   
   std::string line; 
   std::ifstream infile;
   infile.open(input.c_str()); // open file to read lines
   
   getline(infile, line); // remove the number on the front
   line.clear();
   
   while(getline(infile, line)){ // loop over every line
      decode(line);      // decode each line into line elements
      printIng(output);  // Print the Elements
   }
   infile.close(); 
}

void Sequential::printIng(std::string filename){
   
   std::ofstream outfile;
   outfile.open(filename.c_str(), std::fstream::app); // open output file to append text
   
   while(!layer.empty()){                             // look through all layer elements
      for(int i = 0; i < layer.front().numIng; i++){  // for each element run the print the number of times it says
         outfile << layer.front().iname;              // Print the name
      }
      layer.pop_front();  // remove the layer element from the list 
   }
   outfile << std::endl; 
   outfile.close(); 
}

void Sequential::decode(std::string layerLine){
   
   enum state {number, openBr, closeBr};    // create state variables
   state token = number;                    // preset state
   int strCount = 0;                        // preset string index
   int value;                               // Holds space for number of prints
   std::string name = "";                   // Holds element name
   
   while(strCount < layerLine.length()){   // interate through each string character
   
      switch(token){                       // Token state machine
         
         case number: // look at the number, save the value, if it's good, go to the open bracket state and go to the next character
            switch(layerLine.at(strCount)){
               case '1':
                  value = 1;
                  token = openBr;
                  strCount++;
               break;
               case '2':
                  value = 2;
                  token = openBr;
                  strCount++;
               break;
               case '3':
                  value = 3;
                  token = openBr;
                  strCount++;
               break;
               case '4':
                  value = 4;
                  token = openBr;
                  strCount++;
               break;
               case '5':
                  value = 5;
                  token = openBr;
                  strCount++;
               break;
               case '6':
                  value = 6;
                  token = openBr;
                  strCount++;
               break;
               case '7':
                  value = 7;
                  token = openBr;
                  strCount++;
               break;
               case '8':
                  value = 8;
                  token = openBr;
                  strCount++;
               break;
               case '9':
                  value = 9;
                  token = openBr;
                  strCount++;
               break;
               default:
               break;
            }
         break;
         
         case openBr:   // Start of token name
            switch(layerLine.at(strCount)){
               case '[':      // don't add open bracket
                  strCount++; // move to next character
               break;
               case ']':      // don't get close bracket, go to close bracket state
                  token = closeBr;
               break;
               default:       // anything else, add the character to the name, and move to the next character
                  name += layerLine.at(strCount);
                  strCount++;  
               break;
            }
         break;
         
         case closeBr:                    // close bracket is end of token
            layer.push_back(ingredient());// create space 
            layer.back().numIng = value;  // save print value
            layer.back().iname = name;    // save name string
            name.clear();                 // clear name in case of more tokens
            token = number;               // reset state to beginning
            strCount++;                   // Go to next character
         break;
         
         default:
         break; 
      }
   }
}

using namespace std;

int main(){
   
   clock_t timer;
   timer = clock(); 
   
   Sequential hamburger;                                       // create object
   hamburger.get_ing("input-Step3.txt", "MT_Step1_out.txt");   // get lines and print
   
   timer = clock() - timer;
   float sec = float(timer)/CLOCKS_PER_SEC;  
   cout << "Time Elapsed: " << sec <<  " secs" << endl;  
   return 0; 
}
