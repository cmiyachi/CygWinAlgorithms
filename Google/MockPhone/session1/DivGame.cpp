onclusion
If N is even, can win.
If N is odd, will lose.

Recursive Prove （Top-down)
If N is even.
We can choose x = 1.
The opponent will get N - 1, which is a odd.
Reduce to the case odd and he will lose.

If N is odd,
2.1 If N = 1, lose directly.
2.2 We have to choose an odd x.
The opponent will get N - x, which is a even.
Reduce to the case even and he will win.

So the N will change odd and even alternatively until N = 1.

Mathematical Induction Prove （Bottom-up)
N = 1, lose directly
N = 2, will win choosing x = 1.
N = 3, must lose choosing x = 1.
N = 4, will win choosing x = 1.
....

For N <= n, we have find that:
If N is even, can win.
If N is odd, will lose.

For the case N = n + 1
If N is even, we can win choosing x = 1,
give the opponent an odd number N - 1 = n,
force him to lose,
because we have found that all odd N <= n will lose.

If N is odd, there is no even x that N % x == 0.
As a result, we give the opponent a even number N - x,
and the opponent can win,
because we have found that all even N <= n can win.

Now we prove that, for all N <= n,
If N is even, can win.
If N is odd, will lose.

Java/C++:

        return N % 2 == 0;
Python:

        return N % 2 == 0