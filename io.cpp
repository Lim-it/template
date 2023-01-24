//to read lots of integer
void read(int &number)
{
    register int c;
    number = 0;

    c = getchar();

    for (; (c>47 && c<58); c=getchar())
        number = number *10 + c - 48;
}
