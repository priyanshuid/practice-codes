#!/usr/bin/env node

var fibonacci =function(n){
	if(n==0)	return 0;
	else if(n==2 || n==1) return 1;
	else return(fibonacci(n-1)+fibonacci(n-2))
}

console.log(fibonacci(10));
 
