//console.log(process.argv)
sum=0;
for(var i in process.argv) {
	if(i>=2)	
	sum= sum+ Number(process.argv[i]);
}
console.log(Number(sum));
