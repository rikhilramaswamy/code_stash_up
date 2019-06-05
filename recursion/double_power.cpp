

float pow_helper(float dblbase, int ipower){
    if(ipower ==0){
        return 1;
    }
    if(ipower % 2 == 0 ){
        float res = pow_helper(dblbase, ipower/2);
        return res* res;
    } else {
        
        return dblbase * pow_helper(dblbase, ipower-1);
    }
    
    
}

/*
 * Complete the function below.
 */
float power_fn(float dblbase, int ipower) {
    
     float final_res;
    int buff;
    if(ipower < 0){ 
        buff = ipower*(-1);
      final_res  = pow_helper(dblbase, buff);
        return 1/(final_res);
        
    }
    
    final_res  = pow_helper(dblbase, ipower);
        return final_res;


}


