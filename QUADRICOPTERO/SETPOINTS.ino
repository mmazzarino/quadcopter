#include "CONFIGURACAO.h"

void setPointsInclinacao(){ 
  sp_gx = map(x, -100, 100, inclinacaoMinima, inclinacaoMaxima); 
  sp_gy = map(y, -100, 100, inclinacaoMinima, inclinacaoMaxima);  
}

void setPointsGiroZ(){
  if((sp_gx == 0) and (sp_gy == 0)){
    sp_gz = map(j, -100, 100, -180, 180) + gz_ini;          
  } 
  else{
    sp_gz = sp_gz;
  }
}

void setPointsPotencia(){
  if(k != 0){
    potencia = map(k, -100, 100, 0, 255);
  }
  else if(k = 0){
     null; 
  }
}