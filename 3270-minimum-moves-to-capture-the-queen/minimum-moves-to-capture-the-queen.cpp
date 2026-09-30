class Solution {
public:
    bool checkRook(int a, int b, int c, int d, int e, int f)
    {
        // Same column
        if(b == f)
        {
            if(a < e)
            {
                for(int i = a + 1; i <= e; i++)
                {
                    if(i == c && b == d)
                        break;

                    if(i == e)
                        return true;
                }
            }
            else
            {
                for(int i = a - 1; i >= e; i--)
                {
                    if(i == c && b == d)
                        break;

                    if(i == e)
                        return true;
                }
            }
        }

        // Same row
        if(a == e)
        {
            if(b < f)
            {
                for(int i = b + 1; i <= f; i++)
                {
                    if(a == c && i == d)
                        break;

                    if(i == f)
                        return true;
                }
            }
            else
            {
                for(int i = b - 1; i >= f; i--)
                {
                    if(a == c && i == d)
                        break;

                    if(i == f)
                        return true;
                }
            }
        }

        return false;
    }

    bool checkBishop(int a, int b, int c, int d, int e, int f)
    {
        int i = c, j = d;

        while(i >= 1 && j >= 1 && i < 9 && j < 9)
        {
            i--;
            j--;

            if(i == a && j == b)
                break;

            if(i == e && j == f)
                return true;
        }

        i = c;
        j = d;

        while(i >= 1 && j >= 1 && i < 9 && j < 9)
        {
            i++;
            j--;

            if(i == a && j == b)
                break;

            if(i == e && j == f)
                return true;
        }

        i = c;
        j = d;

        while(i >= 1 && j >= 1 && i < 9 && j < 9)
        {
            i--;
            j++;

            if(i == a && j == b)
                break;

            if(i == e && j == f)
                return true;
        }

        i = c;
        j = d;

        while(i >= 1 && j >= 1 && i < 9 && j < 9)
        {
            i++;
            j++;

            if(i == a && j == b)
                break;

            if(i == e && j == f)
                return true;
        }

        return false;
    }

    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f)
    {
        if(checkRook(a, b, c, d, e, f))
            return 1;

        if(checkBishop(a, b, c, d, e, f))
            return 1;

        return 2;
    }
};