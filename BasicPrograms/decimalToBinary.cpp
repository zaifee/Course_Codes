void toBinary(int n)
{ 
    int i = 0;
    int binaryNo = 0;
  while(n){
      int bit = n & 1;
      binaryNo = bit*pow(10, i++) + binaryNo;
      n = n >> 1;
  }
  cout << binaryNo;
        
}
