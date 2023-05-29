
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

typedef struct node
{
      int j;
      char name[25];
      char phone[10];
      char movie[25];
      float price;
      int no_of_seat;
      float imbd_rating;
      char date[15];
      int hall;
      char Time[15];
      struct node *next;
}NODE;

int flag=1;

NODE* book_ticket(NODE *first)
{

    int i,k,choice;
    NODE *newnode,*temp;
    newnode=(NODE*)malloc(sizeof(NODE));
    newnode->next=NULL;


    printf("CHOOSE DATE:\n1)22/01/2022\n2)23/01/2022\n3)24/01/2022\n");
    printf("Enter your choice: ");
    scanf("%d",&choice);

        switch(choice)
        {
            case 1 : strcpy(newnode->date,"23/01/2022") ;
                     break;
            case 2 : strcpy(newnode->date,"24/01/2022") ;
                     break;
            case 3 : strcpy(newnode->date,"25/01/2022") ;
                     break;
            default: printf("SHOWS ARE NOT YET AVAILABLE FOR OTHER DATES..");
                     return 0;

        }

    printf("\nEnter your name: ");
    scanf("%s",newnode->name);
    printf("\nEnter your phone number:");
    scanf("%s",newnode->phone);

    printf ("\t\t\tCHOOSE YOUR MOVIE:\n");
    printf ("\t\t\t----------------------------\n\n");
    printf ("\t\t\tPress 1 for KGF 2\n\n");
    printf ("\t\t\tPress 2 for JERSEY\n\n");
    printf ("\t\t\tPress 3 for ATTACK ON TITAN\n");
    scanf("%d",&i);
    switch(i)
    {
        case 1 : strcpy(newnode->movie,"KGF");
                 newnode->price=250.00;
                 newnode->hall=1;
                 strcpy(newnode->Time,"08:00pm");
                 newnode->imbd_rating=4;
                 printf("\nNumber of seats to be booked: ");
                 scanf("%d",&newnode->no_of_seat);
                 break;

        case 2 : strcpy(newnode->movie,"JERSEY");
                 newnode->price=200.00;
                 strcpy(newnode->Time,"08:00pm");
                 newnode->hall=2;
                 newnode->imbd_rating=3.5;
                 printf("\nNumber of seats to be booked: ");
                 scanf("%d",&newnode->no_of_seat);
                 break;

        case 3 : strcpy(newnode->movie,"ATTACK ON TITAN");
                 newnode->price=350.00;
                 strcpy(newnode->Time,"01:00pm");
                 newnode->hall=3;
                 newnode->imbd_rating=4.5;
                 printf("\nNumber of seats to be booked: ");
                 scanf("%d",&newnode->no_of_seat);
                 break;

        default: printf("Invalid option choosed ,please choose a valid option.....");
    }

    newnode->j=flag;
    flag++;
    if(first==NULL)
        first=newnode;
    else
    {
        temp=first;
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=newnode;
    }
    printf("\n%d seats for %s movie is booked successfully....🤩" ,newnode->no_of_seat,newnode->movie);

    return first;
}

void display_bookings(NODE *first)
{

    float total_amount;
    if(first==NULL)
    {
        printf("No bookings done yet..\n");
        return;
    }

     printf ("\n\n");
  printf ("\t-----------------YOUR BOOKINGS----------------\n");
  printf ("\t============================================================\n");
  while(first!=NULL)
  {
      printf("\n%d\t\t Name= %s              DATE= %s ",first->j,first->name,first->date);
      printf("\n\t\tMovie name: %s             Imbd Rating=%f",first->movie,first->imbd_rating);
      printf(" \n\n ");
      printf("\n\t\tNumber of seats : %d",first->no_of_seat);
      printf(" \n                                 Time: %s ",first->Time);
      printf(" \n                                 Hall: %d ",first->hall);
      total_amount=first->no_of_seat*first->price;
      printf("                                  Total amount= %f ",total_amount);
      printf("\t\t😊😊============================================😊😊\n");
      first=first->next;
  }

}


NODE* cancel_booking(NODE *first)
{
    NODE *temp,*r,*prev;
    int i,k;
    if(first==NULL)
    {
        printf("\nNo bookings yet..");
        return;
    }
    else
    {
        printf("Here are your bookings \n\n");
        display_bookings(first);
        printf("Select the serial number of the booking u want to cancel..");
        scanf("%d",&i);
        if (first->j==i)
        {
            r=first;
            first=first->next;

        }
        else
        {
            temp=first;
            while(temp->j!=i)
            {
                prev=temp;
                temp=temp->next;
            }

                r=temp;
                prev->next=temp->next;

        }

        printf("%s moive with serial number %d is successfully cancelled...",r->movie,r->j);


        while(prev->next!=NULL)
        {
            prev->next->j--;
            prev=prev->next;
        }
        free(r);
    }

    return(first);
}

int main()
{
    int choice;
    NODE *first=NULL;

    printf("\n...............😃  SHOW TIME.COM😃.............");
    printf("\nWE BRING THE CINEMA TO YOU\n");


        while(1)
        {
            printf ("                   WELCOME TO Show-time.com                    \n");
            printf(" ==============================================================\n");
            printf("             1- To purchase ticket                             \n");
            printf("             2- To cancel the ticket                           \n");
            printf("             3- To see your bookings                           \n");
            printf("             4- Exit system                                    \n");
            printf("===============================================================\n");
            printf ("  Enter your choice: ");
            scanf("%d", &choice);


                switch(choice)
                {
                    case 1 : first=book_ticket(first);
                             break;
                    case 2 : first=cancel_booking(first);
                             break;
                    case 3 : display_bookings(first);
                             break;
                    case 4 : exit(0);

                }
        }
}
