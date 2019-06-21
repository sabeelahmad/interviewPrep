/* The method push to push element into the stack */
void QueueStack :: push(int x)
{
        q1.push(x);
}
/*The method pop which return the element poped out of the stack*/
int QueueStack :: pop()
{
        // to get top of stack from q1, reverse and put in q2
        // pop the required element, and transfer back to q1
        if(q1.empty()) {
            return -1;
        }

       // transfer all elements of q1 to q2 except the first one
       while(q1.size() != 1) {
           q2.push(q1.front());
           q1.pop();
       }
       int ans = q1.front();
       q1.pop();
       // either copy back q2 to q1
       // better we can swap their names
       queue<int> q = q1;
       q1 = q2;
       q2 = q;
       return ans;
}
