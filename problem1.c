

dotp=0;

for (i=0;i < n; i++)
{
  temp= (1.0 - b[i]) * (1.0 - a[i]);
  dotp += a[i] *b[i]+ sqrt(temp);
}


