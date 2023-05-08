/*
 You are climbing a staircase.It takes n steps to reach the top.Each time you can either climb 1 or
 2 steps.In how many distinct ways can you climb to the top?

 Constraint: 1 <= n <= 45
*/

class Solution
{
public:
    int climbStairs(int n)
    {
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;

        int a = 1, b = 2, sum = 0;

        for (int i = 3; i <= n; i++)
        {
            sum = a + b;
            a = b;
            b = sum;
        }
        return sum;
    }
};