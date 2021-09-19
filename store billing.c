#include <stdio.h>
#include <time.h>

//final total and discount calculating
float finalTotal(float gross_total){
    if(gross_total<=3000)
    {
        return gross_total*0.05;
    }else if(gross_total>3000 && gross_total<=6000)
    {
        return gross_total*0.1;
    }else{
        return gross_total*0.15;
    }
}

// getting the gross total
float grossTot(float price[],int qty[]){
   int i = 0;
    float gross_total =0;
    while(price[i] != -99){
        gross_total += price[i] *qty[i];
        i++;
    }
      return gross_total;
}


void printBill(){
    printf("Welcome to Store");

      char name[50];   //creating name array for customer name
      printf("\n Enter the customer name:");
      scanf("%s", name);

     //creating array for price and qty
      float price[100];
      int qty[100];

      printf("\n Enter the price>>");
      scanf("%f",&price[0]);
      int i = 0;
      //creating the while loop
      while(price[i] != -99){
      printf("\n Enter the number of quantity you need>>");
      scanf("%d",&qty[i]);

      printf("\n Please enter the price>");
      scanf("%f",&price[i+1]);
      i++;

      }
      //current date and time
       time_t t = time(NULL);
      struct tm *tm = localtime(&t);
      printf("\n %s", asctime(tm));
      printf("\n Customer name is %s.", name);

      float gstot = grossTot(price,qty); //gstot = gross total
      printf("\n Gross total is %f",gstot);

      float fnltot = finalTotal(gstot); //fnltot = final total
      float discount = fnltot-gstot;
      printf("\n Discount :%f",discount);
      printf("\n Final Total: %f",fnltot);
}


int main()
{
   printBill();

  return 0;
}



