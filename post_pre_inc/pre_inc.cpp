

int main()
{
  volatile int k;
  for(k=0; k < 5; k++){
      k = k;
   }

   return k;
}
