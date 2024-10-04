/**
 * @param {number} n
 * @return {number}
 */
var fib = function(n) {
    var a=0
    var b=1
    var c
    for(i=0;i<n-1;i++){
    c=a+b
    a=b
    b=c
}

    if(n==0){
        return 0;
    }else if(n==1){
        return 1;
    }else if(n==2){
        return 1;
    }else{
        return c;
    }
};