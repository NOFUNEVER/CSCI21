#include <iostream>





               
 void schoolCost(int year, int cost,int count = 0){    
   if (year > 1989){
   cost = cost*1.55;
   year = year - 5;
   count++;
   schoolCost( year, cost);
     }
   }
        
    



    int main(){

        
        
    int year= 0;
    int cost=0;
    int count=0;
    std::cout << "what year would you like to predict?"<< std::endl;
    std::cin >> year;
    std::cout << "what was the initial cost in 1985 in this experiment"<<std::endl;
    std::cin >> cost;


    schoolCost(year, cost);
    std::cout << "it will cost APPROX " << cost << "in the year " << year*5*count<<std::endl;
    std::cin >> cost;
    return 0;
    
   
   
   
    }


