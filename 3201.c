#include <stdio.h>
#include <math.h>

int imprime_mon(int base, int exp, int nepm) {
     
     
        if (nepm!=0 && base>0)
            printf("+");
         
        if(base!=0 && base!=1 && base!=-1){
            printf("%d", base); 
         
        }
         
        if(base==-1 && base!=0){
            printf("-"); 
         
        }
         
        if(exp>=2 && base!=0){
            printf("x^%d", exp);
            
        }
         
        if(exp==1 && base!=0){
            printf("x");
             
        }
     
        if(exp==0 && (base==1 || base==-1)){
            printf("1");
             
        }   
}


int main(){

	int num_monomios, base, exp, p_x[15], d_p[15], i, p_mon, x, y, suma; 

	for(i=0; i<=15; i++){        //Inicializa las bases en cero hasta el exponente 5
     
        	p_x[i]=0;
        	d_p[i]=0;        
    	}	
     
    	
	scanf("%d", &num_monomios);        ///Ingreso el número de monomios que tiene el polinomio
    	scanf("%d", &x);
    	scanf("%d", &y);
 
    	for(i=1; i<=num_monomios; i++){
         
        	scanf("%d", &base); 
        	scanf("%d", &exp);
         
        	p_x[exp]=base;      
   	 }
    	
	//Calcula la derivada
	for(i=1; i<=14; i++){                
            d_p[i-1]=p_x[i]*i;   
        }

	printf("<p><span style=\"font-family: verdana; font-size: large;\"><strong>Solución:</strong><br /><br />Sabemos que la función es $$f(x)=");

    	p_mon=0;
    	for(i=15; i>=0; i--){    
        	imprime_mon(p_x[i], i, p_mon);
          
        	if (p_x[i]!=0)
            		p_mon=1;        
   	 }	


	printf("$$, calculamos su derivada, entonces,<br /><br />$$f'(x)=");

    	p_mon=0;
    	for(i=15; i>=0; i--){    
        	imprime_mon(d_p[i], i, p_mon);
          
        	if (d_p[i]!=0)
            		p_mon=1;        
   	 }	

	
	printf("$$.<br /><br />Sustituímos el valor de la coordenada $$x$$ del punto $$(%d, %d)$$, en la derivada para obtener la pendiente,<br /><br />$$f'=", x, y);

    	p_mon=0;
    	for(i=15; i>=0; i--){    
        	imprime_mon(d_p[i], 0, p_mon);
          
        	if (d_p[i]!=0)
            		p_mon=1;

		if(i!=0 && d_p[i]!=0){
			printf("(%d)", x);
			if(i>1)
				printf("^%d", i);
		}
  	 }	

	
	printf("=");

	
    	p_mon=0;
    	for(i=15; i>=0; i--){    
        	imprime_mon(d_p[i]*(pow(x, i)), 0, p_mon);
          
        	if (d_p[i]!=0)
            		p_mon=1;        
   	 }

	
	
	suma=0;	

    	for(i=15; i>=0; i--){    
        	suma=suma + d_p[i]*(pow(x,i));
         }

	printf("=%d$$.<br /><br />Por lo tanto la pendiente $$m=%d$$,<br /><br />Sustituimos en la ecuación de la recta en la forma punto-pendiente, donde $$m=%d$$, $$x_1=%d$$ y $$y_1=%d$$, así que<br /><br />$$\\begin{eqnarray}y-y_1&amp;=&amp;m(x-x_1)\\\\\\\\\\\\\\\\y-(%d)&amp;=&amp;%d[x-(%d)]", suma, suma, suma, x, y, y, suma, x);

	
		
	printf("\\\\\\\\\\\\\\\\y");
	imprime_mon(y*-1, 0, 1);
	printf("&amp;=&amp;%d(x", suma);
	imprime_mon(x*-1, 0, 1);
	printf(")");

	printf("\\\\\\\\\\\\\\\\y");
	imprime_mon(y*-1, 0, 1);
	printf("&amp;=&amp;%dx", suma);
	imprime_mon(suma*x*-1, 0, 1);


	printf("\\\\\\\\\\\\\\\\y");
	printf("&amp;=&amp;%dx", suma);
	imprime_mon(suma*x*-1, 0, 1);
	imprime_mon(y, 0, 1);

	printf("\\\\\\\\\\\\\\\\y");
	printf("&amp;=&amp;%dx", suma);
	imprime_mon((suma*x*-1)+y, 0, 1);


	printf("\\end{eqnarray}$$<br /><br />Por lo tanto, la ecuación de la recta tangente que muestra la relación de las ventas de refrescos con la ganancia es $$y=");

	printf("%dx", suma);
	imprime_mon((suma*x*-1)+y, 0, 1);

	printf("$$.</span></p>");


}
