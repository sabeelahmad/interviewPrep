int tour(petrolPump p[],int n)
{
   // will use given array as queue
   int start = 0, end = 1;
   // if current petrol becomes negative, we move start ahead and till it becomes positibe
   int curr_petrol = p[start].petrol - p[start].distance;
   // loop till we dont get a tour
   while(end != start || curr_petrol < 0) {
       // if petrol -ve
       while(curr_petrol < 0 && start != end) {
           // remove petrol of start station
           curr_petrol -= p[start].petrol - p[start].distance;
           // increment start
           start = (start + 1)%n;
           // if start is 0, means no tour
           if(start == 0) {
               return -1;
           }
       }
       // add petrol of current tour
       curr_petrol += p[end].petrol - p[end].distance;
       end = (end + 1)%n;
   }
   return start;
}
