//Using sieve of Erastothes
//A no always have 2 divisors, 1 and the no itself.
//So if there is a third divisor, it must be prime.

bool sieve[10000]; //stores prime or not

int count3Divisors(int N){ //How many nos are there between 2 to N having 3 divisors ?
  //build prime sieve
  for(int i=2; i<MAX; i++){
    if(sieve[i] == true){
      for(int j=i*2; j<=MAX; j+=i){
        sieve[j] = false;
      }
    }
  }
  int count = 0;
  for(int i=2; i<=N; i++){
    if(sieve[i] && i*i <= N) count++;
  }
  return count;
}
