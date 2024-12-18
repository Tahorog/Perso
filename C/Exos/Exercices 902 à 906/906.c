#include <stdio.h>                                                                                               
#include <math.h>                                                                                                
void sous_programme(char *choix, float *perimetre, float *aire) {                                                
    printf("Menu\n");                                                                                            
    printf("c) Cercle\n");                                                                                       
    printf("r) Rectangle\n");                                                                                    
    printf("t) Triangle\n");                                                                                     
    printf("s) Sortie\n");                                                                                       
    printf("Choix :");                                                                                           
    scanf(" %c", choix);                                                                                         
    switch(*choix) {                                                                                             
        case 'c' : {                                                                                             
            int rayon;                                                                                           
            printf("Choisis un rayon : ");                                                                       
            scanf("%d",&rayon);                                                                                  
            *perimetre = 2*M_PI*rayon;                                                                           
            *aire = M_PI*rayon*rayon;                                                                            
            break;                                                                                               
        }                                                                                                        
        case 'r' : {                                                                                             
            int longueur, largeur;                                                                               
            printf("Choisis une longueur : ");                                                                   
            scanf("%d",&longueur);                                                                               
            printf("Choisis une largeur : ");                                                                    
            scanf("%d",&largeur);                                                                                
                                                                                                                 
            *perimetre = longueur*2 + largeur*2;                                                                 
            *aire = longueur*largeur;                                                                            
            break;                                                                                               
        }                                                                                                        
        case 't' : {                                                                                             
            int base, hauteur;                                                                                   
            printf("Choisis une base : ");                                                                       
            scanf("%d",&base);                                                                                   
            printf("Choisis une hauteur : ");                                                                    
            scanf("%d",&hauteur);                                                                                
            *perimetre = base+hauteur+sqrt(base*base+hauteur*hauteur);                                           
            *aire = base*hauteur/2;                                                                              
            break;                                                                                               
        }                                                                                                        
        case 's': {                                                                                              
            *perimetre = 0;                                                                                      
            *aire = 0;                                                                                           
            break;                                                                                               
        }                                                                                                        
        default:                                                                                                 
            printf("Erreur\n");                                                                                  
            *perimetre = 0;                                                                                      
            *aire = 0;                                                                                           
            break;                                                                                               
    }                                                                                                            
}                                                                                                                
                                                                                                                 
int main() {                                                                                                     
    char choix;                                                                                                  
    float perimetre, aire;                                                                                       
    while (1) {                                                                                                  
       sous_programme(&choix, &perimetre, &aire);                                                                
                                                                                                                 
       if (choix == 's') {                                                                                       
           break;                                                                                                
       }                                                                                                         
       printf("Perimetre = %.2f\n", perimetre);                                                                  
       printf("Aire = %.2f\n", aire);                                                                            
    }                                                                                                            
                                                                                                                 
    return 0;                                                                                                    
}                                                                                                                
