/*returns min element from stack*/
int _stack :: getMin()
{
   if(s.empty()) {
       return -1;
   }
   return minEle;
}
/*returns poped element from stack*/
int _stack ::pop()
{
   if(s.empty()) {
       return -1;
   }
   int poppedElement = s.top();
   s.pop();
   // if poppedElement < minEle, make minEle previous min
   if(poppedElement < minEle) {
       int ans = minEle; // since stack doesnt store actual min
       minEle = (2*minEle) - poppedElement; // restore previous min
       return ans;
   }
   return poppedElement;
}
/*push element x into the stack*/
void _stack::push(int x)
{
   // if x < minEle, update minEle and in stack push 2*x - minEle, as it will help in
   // restoring previous min if minEle is popped
   if(s.empty()) {
       minEle = x;
       s.push(x);
       return;
   }
   if(x < minEle) {
       s.push((2*x) - minEle);
       minEle = x;
   } else {
       s.push(x);
   }
}
