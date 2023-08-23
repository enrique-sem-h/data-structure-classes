/* Crie uma struct chamada "Ponto" que represente um ponto no plano cartesiano com coordenadas x e y. Em seguida, implemente funções para calcular a distância entre dois pontos e a inclinação da reta que os conecta.
*/

#include <stdio.h>
#include <math.h>

typedef struct CGPoint{
    float x;
    float y;
}CGPoint;

void setCGPoint(CGPoint *CGP, float x, float y){
    CGP->x = x;
    CGP->y = y;
}

float calculateAngle(CGPoint p1, CGPoint p2) {
    return atan2(p2.y - p1.y, p2.x - p1.x);
}

int main(){
    CGPoint p1, p2;

    setCGPoint(&p1, 1, 2);
    setCGPoint(&p2, 1, 1);

    float distance = sqrt(pow((p2.x - p1.x), 2) + pow((p2.y - p1.y), 2));
    float angle = calculateAngle(p1, p2);

    printf("distance between point 1: (%.2f, %.2f) and point 2: (%.2f, %.2f) = %.2f", p1.x, p1.y, p2.x, p2.y, distance);
    printf("Angle between the two points: %.2f radian\n", angle);

}